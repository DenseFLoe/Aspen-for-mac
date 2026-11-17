#pragma once
#include "ProcessInput.h"

// Port semantics verified for the one-feed Flash2 reference case only.
namespace ProcessTopology {
bool isFlash2(const QJsonObject &object);
QStringList ports(const QString &end);
QString portLabel(const QString &port);
QString endpointError(const QJsonArray &objects, const QJsonObject &stream,
                      const QString &end, const QString &block, const QString &port);
QVector<ProcessInput::Issue> issues(const QJsonArray &objects);
QString validateStructure(const QJsonArray &objects);
}
