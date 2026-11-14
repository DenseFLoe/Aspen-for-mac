#include "UiShell.h"
#include "ComponentWorkspace.h"
#include "IconCatalog.h"
#include <QApplication>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QJsonDocument>
#include <QLabel>
#include <QPushButton>
#include <QTabBar>
#include <QTabWidget>
#include <QTextEdit>
#include <QTimer>
#include <QTreeWidget>
#include <QTreeWidgetItemIterator>
#include <QtTest>

class UiSmokeTest : public QObject
{
    Q_OBJECT
private slots:
    void iconsAndPageNavigation()
    {
        QFile catalog(":/ui/aspen-plus.json");
        QVERIFY(catalog.open(QIODevice::ReadOnly));
        QFile styles(":/ui/shell.qss");
        QVERIFY(styles.open(QIODevice::ReadOnly));
        qApp->setStyleSheet(QString::fromUtf8(styles.readAll()));
        UiShell shell(QJsonDocument::fromJson(catalog.readAll()).object());
        shell.show();
        QTest::qWait(50);
        auto *workspace = shell.findChild<ComponentWorkspace *>();
        QVERIFY(workspace);
        QCOMPARE(workspace->pageIds().size(), 17);
        auto *tree = shell.findChild<QTreeWidget *>("PropertiesNavigation");
        QVERIFY(tree);
        QFile manifest(":/ui/icons/manifest.json");
        QVERIFY(manifest.open(QIODevice::ReadOnly));
        const auto icons = QJsonDocument::fromJson(manifest.readAll()).object().value("icons").toObject();
        QCOMPARE(icons.size(), 97);
        for (const auto &id : icons.keys()) QVERIFY2(!aspenIcon(id).isNull(), qPrintable(id));

        const auto captureDir = qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if (!captureDir.isEmpty()) QVERIFY(QDir().mkpath(captureDir));
        QSet<QString> visited;
        for (QTreeWidgetItemIterator it(tree); *it; ++it) {
            const auto id = (*it)->data(0, Qt::UserRole).toString();
            if (id.isEmpty() || visited.contains(id)) continue;
            tree->setCurrentItem(*it);
            QCoreApplication::processEvents();
            QCOMPARE(workspace->currentPage(), id);
            QVERIFY(!shell.findChild<QLabel *>("DocumentTitle")->text().isEmpty());
            visited.insert(id);
            auto *tabs = workspace->currentTabs();
            const int count = tabs ? tabs->count() : 1;
            for (int i = 0; i < count; ++i) {
                if (tabs && !tabs->isTabEnabled(i)) continue;
                if (tabs) {
                    QTest::mouseClick(tabs->tabBar(), Qt::LeftButton, Qt::NoModifier, tabs->tabBar()->tabRect(i).center());
                    QCOMPARE(tabs->currentIndex(), i);
                }
                QCoreApplication::processEvents();
                if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir + "/" + id + "-" + QString::number(i) + ".png"));
            }
        }
        QCOMPARE(visited.size(), 17);

        // Switching pages must preserve independent form widgets and tab state.
        QVERIFY(workspace->showPage("specifications"));
        auto *tabs = workspace->currentTabs();
        tabs->setCurrentIndex(4);
        auto *edit = tabs->currentWidget()->findChild<QTextEdit *>("comments-editor");
        QVERIFY(edit);
        edit->setPlainText(QString::fromUtf8("组分注释测试"));
        QVERIFY(workspace->showPage("biomass"));
        QVERIFY(workspace->showPage("specifications"));
        QCOMPARE(tabs->currentIndex(), 4);
        QCOMPARE(edit->toPlainText(), QString::fromUtf8("组分注释测试"));
        QVERIFY(!workspace->showPage("unknown-page"));
        QCOMPARE(workspace->currentPage(), QString("specifications"));

        // Modal wiring: Find opens; close ends the modal loop without a backend.
        tabs->setCurrentIndex(0);
        auto *find = tabs->findChild<QPushButton *>("find-component");
        QVERIFY(find);
        bool dialogSeen = false;
        QTimer::singleShot(30, [&dialogSeen] {
            if (auto *dialog = qobject_cast<QDialog *>(QApplication::activeModalWidget())) {
                dialogSeen = dialog->objectName() == "FindCompoundDialog";
                dialog->reject();
            }
        });
        find->click();
        QVERIFY(dialogSeen);

        shell.resize(800, 540);
        QVERIFY(workspace->showPage("petroleum-analysis"));
        QCoreApplication::processEvents();
        QVERIFY(workspace->width() > 400);
        QVERIFY(workspace->height() > 250);
        if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir + "/narrow-800.png"));
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
#ifdef Q_OS_WIN
    // The offscreen plugin has no Windows system-font fallback of its own.
    QFontDatabase::addApplicationFont("C:/Windows/Fonts/msyh.ttc");
    QApplication::setFont(QFont("Microsoft YaHei", 9));
#endif
    QApplication::setStyle("Fusion");
    UiSmokeTest tests;
    return QTest::qExec(&tests, argc, argv);
}

#include "UiSmokeTest.moc"
