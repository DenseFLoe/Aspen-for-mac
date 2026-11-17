#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>

namespace ProcessInput {
struct Issue { QString object, field, message; };
bool supported(const QJsonObject &object);
QString componentKey(const QJsonObject &component);
QStringList fields(const QJsonObject &object);
QString defaultUnit(const QString &field);
QString label(const QString &field);
QJsonObject quantity(const QString &text, const QString &unit);
bool number(const QString &text, double *value);
QVector<Issue> issues(const QJsonObject &object, const QJsonArray &components);
QString validateStructure(const QJsonObject &state);
}
