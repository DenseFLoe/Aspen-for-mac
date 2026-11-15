#include "UiShell.h"
#include "ComponentWorkspace.h"
#include "IconCatalog.h"
#include "LightTheme.h"
#include "RecoveredWorkspace.h"
#include <QApplication>
#include <QBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QMenu>
#include <QStackedWidget>
#include <QListWidget>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QJsonDocument>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QGroupBox>
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
    void recoveredImagesAndInteractiveForms()
    {
        QFile manifest(":/ui/icons/recovered.json"); QVERIFY(manifest.open(QIODevice::ReadOnly));
        const auto images=QJsonDocument::fromJson(manifest.readAll()).object();
        QVERIFY(images.value("assets").toArray().size()>=170);
        const auto references=images.value("references").toObject();
        for (auto it=references.begin();it!=references.end();++it) QVERIFY2(!aspenIcon(it.key()).isNull(),qPrintable(it.key()));
        RecoveredWorkspace workspace;
        const auto setup=workspace.idForName("MMSetup_Setup"); QVERIFY(!setup.isEmpty());
        QVERIFY(workspace.showPage(setup));
        auto *phase=workspace.findChild<QComboBox *>("cboPhase"); QVERIFY(phase); QCOMPARE(phase->count(),4); QCOMPARE(phase->currentIndex(),-1);
        phase->setCurrentIndex(2);
        QVERIFY(!workspace.findChild<QWidget *>("cboInpMode"));
        auto *title=workspace.findChild<QWidget *>("lbtuTitle")->findChild<QLineEdit *>(); QVERIFY(!title->isReadOnly()); title->setText("Session title");
        auto *comments=workspace.findChild<QTextEdit *>("commentsDescription"); QVERIFY(comments); comments->setPlainText("Setup notes");
        auto *tabs=workspace.findChild<QTabWidget *>("tabSetup"); QVERIFY(tabs); tabs->setCurrentIndex(4);
        QVERIFY(workspace.showPage(workspace.idForName("MMProp_Spec_Input")));
        QVERIFY(workspace.findChild<QCheckBox *>("MMCheckBox1")->isChecked());
        auto *filter=workspace.findChild<QComboBox *>("cboGPProcessType");
        filter->setCurrentText("ELECTROL");
        QVERIFY(!workspace.findChild<QComboBox *>("MMComboBox4")->isEnabled());
        QCOMPARE(workspace.findChild<QComboBox *>("MMComboBox4")->count(),0);
        filter->setCurrentText("COMMON"); QCOMPARE(workspace.findChild<QComboBox *>("MMComboBox4")->count(),20);
        workspace.setGlobalUnits("SI");
        QVERIFY(workspace.showPage(setup));
        QCOMPARE(workspace.findChild<QComboBox *>("cboPhase")->currentIndex(),2);
        QCOMPARE(workspace.findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString("Setup notes"));
        QCOMPARE(workspace.findChild<QTabWidget *>("tabSetup")->currentIndex(),4);
        QCOMPARE(workspace.findChild<QComboBox *>("cboInputData")->currentText(),QString("SI"));
        QCOMPARE(workspace.findChild<QWidget *>("lbtuTitle")->findChild<QLineEdit *>()->text(),QString("Session title"));
        // Comments in different host pages must remain independent despite sharing a COM form.
        QVERIFY(workspace.showPage(workspace.idForName("MMProp_Spec_Input")));
        QCOMPARE(workspace.findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString());
    }

    void shellCommandsMenusAndWizardState()
    {
        QFile file(":/ui/aspen-plus.json"); QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object()); shell.show();
        auto *recovered=shell.findChild<RecoveredWorkspace *>(); QVERIFY(recovered);
        shell.findChild<QToolButton *>("setup")->click();
        shell.findChild<QToolButton *>("methods")->click();
        shell.findChild<QToolButton *>("window-back")->click();
        QCOMPARE(recovered->currentPage(),recovered->idForName("MMSetup_Setup"));
        shell.findChild<QToolButton *>("window-forward")->click();
        QCOMPARE(recovered->currentPage(),recovered->idForName("MMProp_Spec_Input"));
        auto *units=shell.findChild<QToolButton *>("unit-selector");
        for (auto *action:units->menu()->actions()) if (action->text()=="SI") action->trigger();
        shell.findChild<QToolButton *>("setup")->click();
        QCOMPARE(recovered->findChild<QComboBox *>("cboInputData")->currentText(),QString("SI"));
        auto *ribbon=shell.findChild<QTabWidget *>("Ribbon");
        shell.dispatch("ribbon-collapse"); QCOMPARE(ribbon->height(),28);
        shell.dispatch("ribbon-collapse"); QCOMPARE(ribbon->height(),122);
        auto *quick=shell.findChild<QWidget *>("QuickBar");
        shell.dispatch("quick-below"); QCOMPARE(quick->parentWidget()->layout()->indexOf(quick),1);
        shell.dispatch("quick-below"); QCOMPARE(quick->parentWidget()->layout()->indexOf(quick),0);
        shell.dispatch("find-component");
        auto *find=shell.findChild<QDialog *>("dialog-FindComounds"); QVERIFY(find); find->reject();
        shell.dispatch("clean-parameters");
        auto *dialog=shell.findChild<QDialog *>("dialog-CleanParametersDialog"); QVERIFY(dialog); QVERIFY(dialog->isVisible()); dialog->reject();
        shell.dispatch("user-components");
        auto *wizard=shell.findChild<QDialog *>("wizard-user-component"); QVERIFY(wizard);
        auto *next=wizard->findChild<QPushButton *>("WizardNext"); QVERIFY(!next->isEnabled());
        wizard->findChild<QLineEdit *>("txtCompID")->setText("TEST"); QVERIFY(next->isEnabled()); next->click();
        QCOMPARE(wizard->findChild<QStackedWidget *>("WizardSteps")->currentIndex(),1);
        wizard->findChild<QPushButton *>("WizardBack")->click();
        QCOMPARE(wizard->findChild<QLineEdit *>("txtCompID")->text(),QString("TEST")); wizard->reject();
        shell.dispatch("options"); auto *options=shell.findChild<QDialog *>("OptionsDialog"); QVERIFY(options); options->reject();
    }

    void allRecoveredLayoutsInstantiate()
    {
        RecoveredWorkspace workspace;
        const auto pages=workspace.catalog().value("pages").toArray();
        QCOMPARE(pages.size(),2947);
        for (const auto &value:pages) {
            const auto id=value.toObject().value("id").toString();
            QVERIFY2(workspace.showPage(id),qPrintable(id));
            QVERIFY2(workspace.findChild<QScrollArea *>("RecoveredScroll")->widget(),qPrintable(id));
            if (value.toObject().value("name").toString()=="Plot3DAxesPropertiesDlg")
                QVERIFY(workspace.findChild<QWidget *>("ncbMajorGrid3D"));
        }
        for (int i=0;i<workspace.nativeDialogs().size();++i) QVERIFY(workspace.showPage("dialog:"+QString::number(i)));
        for (int i=0;i<workspace.menuCatalog().size();++i) QVERIFY(workspace.showPage("menu:"+QString::number(i)));
    }

    void recoveredCatalogNavigationAndRendering()
    {
        QFile style(":/ui/shell.qss"); QVERIFY(style.open(QIODevice::ReadOnly)); qApp->setStyleSheet(QString::fromUtf8(style.readAll()));
        QFile file(":/ui/aspen-plus.json"); QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object()); shell.show();
        auto *recovered=shell.findChild<RecoveredWorkspace *>(); QVERIFY(recovered);
        const auto pages=recovered->catalog().value("pages").toArray();
        QVERIFY(pages.size()>2500);
        auto *tree=shell.findChild<QTreeWidget *>("RecoveredNavigation"); QVERIFY(tree);
        auto *nav=shell.findChild<QTabWidget *>("NavigationTabs"); QVERIFY(nav); nav->setCurrentIndex(1);
        const auto captureDir=qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if (!captureDir.isEmpty()) QVERIFY(QDir().mkpath(captureDir));
        QSet<QString> modules;
        for (QTreeWidgetItemIterator it(tree); *it; ++it) {
            const auto id=(*it)->data(0,Qt::UserRole).toString();
            if (id.isEmpty() || id.contains(':')) continue;
            const auto module=(*it)->parent()->toolTip(0);
            if (modules.contains(module)) continue;
            tree->setCurrentItem(*it); QCoreApplication::processEvents();
            QCOMPARE(recovered->currentPage(),id); QVERIFY(recovered->isVisible());
            QVERIFY(recovered->findChild<QScrollArea *>("RecoveredScroll")->widget());
            modules.insert(module);
        }
        QCOMPARE(modules.size(),recovered->catalog().value("modules").toArray().size());
        // Explicit representative tabbed forms exercise cross-resource ContentType links.
        const QSet<QString> examples{"MMHenryComps_Input","MMSetup_Setup","MMComp_Spec_Input","MMSetup_Units","MMRCSTR_Setup","MMRadfrac_Conver","MMProp_Spec_Input"};
        for (const auto &v:pages) {
            const auto page=v.toObject(); const auto name=page.value("name").toString();
            if (!examples.contains(name)) continue;
            QVERIFY(recovered->showPage(page.value("id").toString())); QCoreApplication::processEvents();
            QVERIFY(recovered->findChild<QTabWidget *>());
            if (name=="MMProp_Spec_Input") {
                // The original Properties mode shows the methods group directly.
                QVERIFY(!recovered->findChild<QTabWidget *>("ConditionalAlternatives"));
                auto *models=recovered->findChild<QGroupBox *>("fraModels"); QVERIFY(models);
                QVERIFY(models->findChild<QWidget *>("cboLiquidGamma"));
            }
            if (name=="MMRCSTR_Setup") {
                bool scrolls=false;
                for (auto *area:recovered->findChildren<QScrollArea *>()) if(area->isVisible() && area->verticalScrollBar()->maximum()>0) scrolls=true;
                QVERIFY(scrolls);
            }
            if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir+"/recovered-"+name+".png"));
        }
        QVERIFY(!recovered->showPage("missing"));
        QVERIFY(recovered->nativeDialogs().size()>200); QVERIFY(recovered->menuCatalog().size()>50);
        QVERIFY(recovered->showPage("dialog:0")); QVERIFY(recovered->showPage("menu:0"));
        QVERIFY(!recovered->showPage("menu:-1")); QVERIFY(!recovered->showPage("dialog:999999"));
        auto *query=shell.findChild<QLineEdit *>("RecoverySearch"); QVERIFY(query);
        query->setText("MMHenryComps_Input");
        int visibleLeaves=0;
        for (QTreeWidgetItemIterator it(tree); *it; ++it)
            if (!(*it)->childCount() && !(*it)->isHidden()) ++visibleLeaves;
        QVERIFY(visibleLeaves>=1); QVERIFY(visibleLeaves<20);
        query->clear();
        // Existing ribbon entry points must reach recovered forms and return to Components.
        const QMap<QString,QString> targets{{"setup","MMSetup_Setup"},{"methods","MMProp_Spec_Input"},{"property-sets","MMPropSets_Input"}};
        for (auto it=targets.cbegin();it!=targets.cend();++it) {
            auto *button=shell.findChild<QToolButton *>(it.key()); QVERIFY(button);
            button->click(); QVERIFY(recovered->isVisible());
            QVERIFY(recovered->findChild<QLabel *>("RecoveredTitle")->text().contains(it.value()));
        }
        auto *componentsButton=shell.findChild<QToolButton *>("components"); QVERIFY(componentsButton);
        componentsButton->click(); QVERIFY(!recovered->isVisible());
        QVERIFY(shell.findChild<ComponentWorkspace *>()->isVisible());
        shell.findChild<QToolButton *>("setup")->click();
        shell.resize(800,540); QCoreApplication::processEvents();
        QVERIFY(recovered->width()>400);
    }

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
    applyLightTheme(app);
    UiSmokeTest tests;
    return QTest::qExec(&tests, argc, argv);
}

#include "UiSmokeTest.moc"
