#pragma once
#include <QJsonObject>
#include <QWidget>
#include <functional>

// Adapter for legacy, semantically unverified form controls.
namespace WidgetState {
QJsonObject capture(QWidget *root);
void restore(QWidget *root,const QJsonObject &state);
void observe(QWidget *root,QObject *receiver,const std::function<void()> &changed);
}
