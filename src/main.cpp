#include "UiShell.h"
#include "LightTheme.h"
#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("Aspen Plus UI Shell");
    QApplication::setApplicationVersion("0.1.0");
    applyLightTheme(app);

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
    window.show();
    return app.exec();
}
