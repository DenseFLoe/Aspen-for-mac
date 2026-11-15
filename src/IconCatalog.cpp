#include "IconCatalog.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPixmap>

QIcon aspenIcon(const QString &id)
{
    static const QJsonObject recovered = [] {
        QFile file(":/ui/icons/recovered.json");
        if (!file.open(QIODevice::ReadOnly)) return QJsonObject{};
        return QJsonDocument::fromJson(file.readAll()).object().value("references").toObject();
    }();
    if (recovered.contains(id)) return QIcon(":/ui/icons/" + recovered.value(id).toString());
    static const QPixmap atlas(":/ui/icons/aspen-v15.png");
    static const QJsonObject icons = [] {
        QFile file(":/ui/icons/manifest.json");
        if (!file.open(QIODevice::ReadOnly)) return QJsonObject{};
        return QJsonDocument::fromJson(file.readAll()).object().value("icons").toObject();
    }();
    const auto rect = icons.value(id).toObject().value("rect").toArray();
    if (rect.size() != 4 || atlas.isNull()) return {};
    return QIcon(atlas.copy(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt()));
}
