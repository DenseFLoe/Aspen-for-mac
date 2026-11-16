#pragma once
#include <QJsonObject>
class QWidget;
QWidget *makeChemicalSystemView(const QJsonObject &record,const QJsonObject &state,QWidget *parent);
