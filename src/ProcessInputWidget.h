#pragma once
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
class QLineEdit;
class QLabel;
class QTableWidget;
class ProcessInputWidget final : public QWidget {
    Q_OBJECT
public:
    ProcessInputWidget(const QJsonObject &object,const QJsonArray &components,QWidget *parent=nullptr);
    void setComponents(const QJsonArray &components);
    void focusField(const QString &field);
signals:
    void inputChanged(const QJsonObject &input);
private:
    QJsonObject object_,input_;
    QJsonArray components_;
    QMap<QString,QLineEdit *> edits_;
    QTableWidget *fractions_=nullptr;
    QLabel *status_=nullptr;
    void publish();
    void updateStatus();
};
