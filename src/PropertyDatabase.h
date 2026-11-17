#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QObject>
#include <optional>

class PropertyDatabase final : public QObject {
public:
    enum class MatchMode { Contains, StartsWith, Equals };
    struct SearchOptions {
        MatchMode mode=MatchMode::Contains;
        QJsonArray databanks;
        bool restrictDatabanks=false;
        std::optional<double> molecularWeightMin, molecularWeightMax;
        std::optional<double> boilingPointMinK, boilingPointMaxK;
        QString compoundClass;
    };
    explicit PropertyDatabase(QObject *parent=nullptr);
    ~PropertyDatabase();
    PropertyDatabase(const PropertyDatabase &)=delete;
    PropertyDatabase &operator=(const PropertyDatabase &)=delete;
    bool open(const QString &path,QString *error);
    bool isOpen() const { return connection_.isOpen(); }
    QString datasetId() const { return datasetId_; }
    QString path() const { return connection_.databaseName(); }
    bool supportsCompoundFilters() const { return compoundFilters_; }
    QStringList compoundClasses(QString *error);
    QJsonArray search(const QString &text,QString *error,int limit=101);
    QJsonArray search(const QString &text,QString *error,const SearchOptions &options,int limit=101);
    QJsonArray databanks(QString *error);
    QJsonArray parameters(const QString &database,const QString &compoundId,int offset,QString *error,int limit=201);
    QJsonObject provenance(const QString &database,int referenceId,QString *error);
private:
    QSqlDatabase connection_;
    QString connectionName_, datasetId_;
    bool compoundFilters_=false;
    void close();
};
