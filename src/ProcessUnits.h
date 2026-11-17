#pragma once
#include <QJsonObject>
#include <QStringList>
namespace ProcessUnits {
QStringList units(const QString &field);
QString forSet(const QString &field,const QString &set);
bool toSI(const QString &field,const QJsonObject &quantity,double *value);
// On failure output remains unchanged. Empty input remains unspecified.
bool convert(const QString &field,const QJsonObject &quantity,const QString &unit,QJsonObject *output);
}
