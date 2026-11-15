#include "DatabaseDialog.h"
#include "DatabaseFixture.h"
#include "PropertyDatabase.h"
#include "ProjectDocument.h"
#ifdef Q_OS_MACOS
#include "CocoaAccessibilityCheck.h"
#endif
#include <QAccessible>
#include <private/qguiapplication_p.h>
#include <qpa/qplatformintegration.h>
#include <qpa/qplatformaccessibility.h>
#include <QApplication>
#include <QCryptographicHash>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QTemporaryDir>
#include <QTextEdit>
#include <QtTest>

class DatabaseAccessibilityTest : public QObject {
    Q_OBJECT
private:
    void inspect(QTableWidget *table) {
        auto *iface = QAccessible::queryAccessibleInterface(table);
        QVERIFY(iface);
        auto *accessible = iface->tableInterface();
        QVERIFY(accessible);
        QCOMPARE(accessible->rowCount(), table->rowCount());
        QCOMPARE(accessible->columnCount(), table->columnCount());
        const int expected = table->selectionModel()->selectedIndexes().size();
        QCOMPARE(accessible->selectedCellCount(), expected);
        const auto cells = accessible->selectedCells();
        QCOMPARE(cells.size(), expected);
        for (auto *cell : cells) {
            QVERIFY(cell);
            QVERIFY(cell->isValid());
            QVERIFY(cell->tableCellInterface());
            QVERIFY(cell->tableCellInterface()->isSelected());
            QVERIFY(cell->tableCellInterface()->rowIndex() < table->rowCount());
        }
#ifdef Q_OS_MACOS
        if (QGuiApplication::platformName() == "cocoa") {
            QString error;
            QVERIFY2(checkCocoaSelection(table, expected, &error), qPrintable(error));
        }
#endif
    }
private slots:
    void initTestCase() {
        // setActive on QAccessible only notifies observers; activate the backend.
        QGuiApplicationPrivate::platformIntegration()->accessibility()->setActive(true);
        QVERIFY(QAccessible::isActive());
        qInfo() << "Qt" << qVersion() << "platform" << QGuiApplication::platformName();
    }
    void nativeOwnership() {
#ifdef Q_OS_MACOS
        if (QGuiApplication::platformName() == "cocoa") {
            QString error;
            QVERIFY2(checkCocoaTableLifecycle(&error), qPrintable(error));
        }
#endif
    }
    void databaseSelectionLifecycle() {
        QTemporaryDir temp;
        QVERIFY(temp.isValid());
        const auto path = databaseFixture(temp.path());
        QVERIFY(!path.isEmpty());
        // More than one parameter page exercises selected cell cache invalidation.
        {
            auto writer = QSqlDatabase::addDatabase("QSQLITE", "paging-fixture");
            writer.setDatabaseName(path);
            QVERIFY(writer.open());
            QSqlQuery query(writer);
            QVERIFY(query.exec("WITH RECURSIVE n(x) AS (SELECT 101 UNION ALL SELECT x+1 FROM n WHERE x<301) INSERT INTO parameter_values SELECT 'TEST',7,x,'0.123456789012345678901' FROM n"));
        }
        QSqlDatabase::removeDatabase("paging-fixture");
        QFile file(path);
        QVERIFY(file.open(QIODevice::ReadOnly));
        const auto before = QCryptographicHash::hash(file.readAll(), QCryptographicHash::Sha256);
        file.close();
        PropertyDatabase database;
        ProjectDocument project;
        QString error;
        for (int repeat = 0; repeat < 3; ++repeat) {
            // Open dialog before connecting: same refresh path as choosing a DB.
            DatabaseDialog dialog(&database, &project);
            dialog.show();
            QCoreApplication::processEvents();
            auto *results = dialog.findChild<QTableWidget *>("DatabaseResults");
            auto *parameters = dialog.findChild<QTableWidget *>("DatabaseParameters");
            auto *term = dialog.findChild<QLineEdit *>("compound-query");
            auto *search = dialog.findChild<QPushButton *>("SearchDatabase");
            auto *source = dialog.findChild<QTextEdit *>("ParameterProvenance");
            QVERIFY(results && parameters && term && search && source);
            inspect(results);
            inspect(parameters);
            QVERIFY2(database.open(path, &error), qPrintable(error));
            term->setText("7732-18-5");
            search->click();
            QCOMPARE(results->rowCount(), 1);
            QCOMPARE(parameters->rowCount(), 200);
            inspect(results);
            inspect(parameters);
            parameters->selectRow(0);
            QVERIFY(source->toPlainText().contains("123.456789012345678901"));
            inspect(parameters);
            auto *next = dialog.findChild<QPushButton *>("NextDatabaseParameters");
            auto *previous = dialog.findChild<QPushButton *>("PreviousDatabaseParameters");
            QVERIFY(next && previous);
            QVERIFY(next->isEnabled());
            next->click();
            QCOMPARE(parameters->rowCount(), 2);
            QVERIFY(!next->isEnabled());
            QVERIFY(source->toPlainText().isEmpty());
            inspect(parameters);
            parameters->selectRow(1);
            inspect(parameters);
            previous->click();
            QCOMPARE(parameters->rowCount(), 200);
            inspect(parameters);
            dialog.findChild<QPushButton *>("AddDatabaseComponent")->click();
            auto *selected = dialog.findChild<QListWidget *>("SelectedDatabaseComponents");
            QCOMPARE(selected->count(), 1);
            selected->setCurrentRow(0);
#ifdef Q_OS_MACOS
            if (QGuiApplication::platformName() == "cocoa")
                QVERIFY2(checkCocoaSelection(selected, 1, &error), qPrintable(error));
#endif
            dialog.findChild<QPushButton *>("RemoveDatabaseComponent")->click();
            QCOMPARE(selected->count(), 0);
            for (const auto &query : {"no-such-compound", "", "H2O", "TEST-WATER"}) {
                term->setText(query);
                search->click();
                inspect(results);
                inspect(parameters);
            }
            QVERIFY(!database.open(temp.filePath("missing.sqlite"), &error));
            search->click();
            QCOMPARE(results->rowCount(), 0);
            QCOMPARE(parameters->rowCount(), 0);
            QVERIFY(!dialog.findChild<QPushButton *>("AddDatabaseComponent")->isEnabled());
            inspect(results);
            inspect(parameters);
            dialog.close();
            QCoreApplication::processEvents();
        }
        QVERIFY(file.open(QIODevice::ReadOnly));
        QCOMPARE(QCryptographicHash::hash(file.readAll(), QCryptographicHash::Sha256), before);
    }
};
QTEST_MAIN(DatabaseAccessibilityTest)
#include "DatabaseAccessibilityTest.moc"
