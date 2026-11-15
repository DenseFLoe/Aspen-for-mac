#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QObject>

class PropertyDatabase final : public QObject {
public:
    explicit PropertyDatabase(QObject *parent=nullptr);
    ~PropertyDatabase();
    PropertyDatabase(const PropertyDatabase &)=delete;
    PropertyDatabase &operator=(const PropertyDatabase &)=delete;
    bool open(const QString &path,QString *error);
    bool isOpen() const { return connection_.isOpen(); }
    QString datasetId() const { return datasetId_; }
    QString path() const { return connection_.databaseName(); }
    QJsonArray search(const QString &text,QString *error,int limit=101);
    QJsonArray parameters(const QString &database,const QString &compoundId,int offset,QString *error,int limit=201);
    QJsonObject provenance(const QString &database,int referenceId,QString *error);
private:
    QSqlDatabase connection_;
    QString connectionName_, datasetId_;
    void close();
};
