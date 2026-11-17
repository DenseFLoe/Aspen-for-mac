#pragma once
#include "ProcessInput.h"
namespace ProcessGuidance {
QVector<ProcessInput::Issue> issues(const QJsonObject &state);
ProcessInput::Issue next(const QJsonObject &state,const QString &currentObject);
}
