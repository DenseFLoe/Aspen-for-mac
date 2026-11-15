#include "UiShell.h"
#ifdef Q_OS_MACOS
#include "CocoaAccessibilityCheck.h"
#endif
#include "LightTheme.h"
#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QTemporaryDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("Aspen Plus UI Shell");
    QApplication::setApplicationVersion("0.1.0");
    applyLightTheme(app);
#ifdef Q_OS_MACOS
    if (QString::fromLatin1(qVersion()) != QString::fromLatin1(QT_VERSION_STR)) {
        qCritical() << "Qt build/runtime mismatch:" << QT_VERSION_STR << qVersion();
        return 4;
    }
    if (app.arguments().contains("--accessibility-self-check")) {
        QString problem;
        if (!checkCocoaTableLifecycle(&problem)) {
            qCritical().noquote() << problem;
            return 5;
        }
        qInfo() << "Cocoa accessibility lifecycle passed; Qt" << qVersion();
        return 0;
    }
#endif

    QFile catalogFile(":/ui/aspen-plus.json");
    if (!catalogFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, "UI Shell", "Cannot read the embedded UI catalog.");
        return 1;
    }
    QJsonParseError error;
    const auto document = QJsonDocument::fromJson(catalogFile.readAll(), &error);
    if (error.error != QJsonParseError::NoError || !document.isObject()
        || document.object().value("ribbons").toArray().isEmpty()) {
        QMessageBox::critical(nullptr, "UI Shell", "The embedded UI catalog is invalid.");
        return 1;
    }
    QFile stylesheet(":/ui/shell.qss");
    if (stylesheet.open(QIODevice::ReadOnly))
        app.setStyleSheet(QString::fromUtf8(stylesheet.readAll()));

    UiShell window(document.object());
    // Exercise the deployed Qt SQL plugin and project IO without a desktop.
    if(app.arguments().contains("--self-check")) {
        auto database=QSqlDatabase::addDatabase("QSQLITE","package-check");
        database.setDatabaseName(":memory:");
        if(!database.open()) {qCritical()<<"SQLite plugin could not open a database";return 2;}
        QTemporaryDir temporary;QString problem;
        if(!temporary.isValid() || !window.saveProject(temporary.filePath("roundtrip.afmp"),&problem) ||
            !window.loadProject(temporary.filePath("roundtrip.afmp"),&problem)) {qCritical()<<problem;return 3;}
        return 0;
    }
    window.show();
    return app.exec();
}
