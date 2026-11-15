#include "PropertyDatabase.h"
#include <QFileInfo>
#include <QMap>
#include <QJsonDocument>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>

PropertyDatabase::PropertyDatabase(QObject *parent):QObject(parent),connectionName_(QUuid::createUuid().toString()) {}
PropertyDatabase::~PropertyDatabase() { close(); }
void PropertyDatabase::close() {
    if(connection_.isValid()) {connection_.close(); connection_=QSqlDatabase(); QSqlDatabase::removeDatabase(connectionName_);}
    datasetId_.clear();
}
bool PropertyDatabase::open(const QString &path,QString *error) {
    close(); error->clear();
    if(!QFileInfo(path).isFile()) { *error=QString::fromUtf8("运行数据库不存在，请选择已生成的 catalog.sqlite。"); return false; }
    connection_=QSqlDatabase::addDatabase("QSQLITE",connectionName_);
    connection_.setConnectOptions("QSQLITE_OPEN_READONLY"); connection_.setDatabaseName(path);
    if(!connection_.open()) { *error=connection_.lastError().text(); close(); return false; }
    bool valid=false;
    {
        QSqlQuery query(connection_);
        if(query.exec("SELECT key,value FROM metadata")) {
            QMap<QString,QString> metadata;
            while(query.next()) metadata[query.value(0).toString()]=query.value(1).toString();
            datasetId_=metadata.value("dataset_id");
            valid=metadata.value("schema_version")=="1" && datasetId_.startsWith("aspen-v15-") &&
                metadata.value("validation")=="query-only-unverified-for-calculation";
        }
        if(valid) valid=query.exec("SELECT c.db,c.id,c.name,c.alias,c.cas,i.kind,i.value,p.cp_id,p.property_id,v.element_index,v.value_text,r.dbc_id,r.bank_id,b.name,m.units,m.metadata FROM compounds c LEFT JOIN identifiers i ON 0 LEFT JOIN parameters p ON 0 LEFT JOIN parameter_values v ON 0 LEFT JOIN refs r ON 0 LEFT JOIN databanks b ON 0 LEFT JOIN properties m ON 0 LIMIT 0");
    }
    if(!valid) { *error=QString::fromUtf8("数据库版本不兼容、结构损坏或构建未完成；需要 schema_version=1 的运行数据库。"); close(); }
    return valid;
}
QJsonArray PropertyDatabase::search(const QString &text,QString *error,int limit) {
    error->clear(); QJsonArray results;
    if(!isOpen()) { *error=QString::fromUtf8("未连接运行数据库。"); return results; }
    if(text.trimmed().isEmpty()) return results;
    auto escaped=text.trimmed(); escaped.replace('\\',"\\\\"); escaped.replace('%',"\\%"); escaped.replace('_',"\\_");
    QSqlQuery query(connection_);
    query.prepare("SELECT c.db,c.id,c.name,c.alias,c.cas FROM compounds c WHERE c.name IS NOT NULL AND EXISTS (SELECT 1 FROM identifiers i WHERE i.db=c.db AND i.compound_id=c.id AND i.kind IN ('NAME','ALIAS','CASRN','SYNONYM') AND i.value LIKE ? ESCAPE '\\') ORDER BY CASE WHEN EXISTS (SELECT 1 FROM identifiers exact WHERE exact.db=c.db AND exact.compound_id=c.id AND exact.kind IN ('NAME','ALIAS','CASRN','SYNONYM') AND exact.value=? COLLATE NOCASE) THEN 0 ELSE 1 END,c.name,c.db,c.id LIMIT ?");
    query.addBindValue("%"+escaped+"%");query.addBindValue(text.trimmed());query.addBindValue(qBound(1,limit,501));
    if(!query.exec()) { *error=query.lastError().text(); return results; }
    while(query.next()) results.append(QJsonObject{{"database",query.value(0).toString()},{"compoundId",query.value(1).toString()},
        {"name",query.value(2).toString()},{"alias",query.value(3).toString()},{"cas",query.value(4).toString()},
        {"datasetId",datasetId_},{"sourceTable","active_Compounds"}});
    return results;
}
QJsonArray PropertyDatabase::parameters(const QString &database,const QString &compoundId,int offset,QString *error,int limit) {
    error->clear();QJsonArray result;
    if(!isOpen()) { *error=QString::fromUtf8("未连接运行数据库。"); return result; }
    QSqlQuery query(connection_);
    query.prepare("SELECT p.cp_id,m.name,m.description,v.element_index,v.value_text,m.units,b.name,r.dbc_id,m.metadata FROM parameters p JOIN properties m ON m.db=p.db AND m.id=p.property_id LEFT JOIN parameter_values v ON v.db=p.db AND v.cp_id=p.cp_id LEFT JOIN refs r ON r.db=p.db AND r.cp_id=p.cp_id LEFT JOIN databanks b ON b.db=r.db AND b.id=r.bank_id WHERE p.db=? AND p.compound_id=? ORDER BY m.name,p.cp_id,r.dbc_id,v.element_index LIMIT ? OFFSET ?");
    query.addBindValue(database);query.addBindValue(compoundId);query.addBindValue(qBound(1,limit,501));query.addBindValue(qMax(0,offset));
    if(!query.exec()) { *error=query.lastError().text(); return result; }
    while(query.next()) result.append(QJsonObject{{"cpId",query.value(0).toInt()},{"property",query.value(1).toString()},
        {"description",query.value(2).toString()},{"elementIndex",query.value(3).isNull()?QJsonValue():QJsonValue(query.value(3).toInt())},
        {"valueText",query.value(4).isNull()?QJsonValue():QJsonValue(query.value(4).toString())},
        {"units",QJsonDocument::fromJson(query.value(5).toByteArray()).array()},{"databank",query.value(6).toString()},
        {"referenceId",query.value(7).isNull()?QJsonValue():QJsonValue(query.value(7).toInt())},
        {"metadata",QJsonDocument::fromJson(query.value(8).toByteArray()).object()}});
    return result;
}
QJsonObject PropertyDatabase::provenance(const QString &database,int referenceId,QString *error) {
    error->clear(); QJsonObject result{{"datasetId",datasetId_},{"database",database},{"dbcId",referenceId},
        {"validation",QString::fromUtf8("仅供查询；参数解释与计算适用性未验证")}};
    if(!isOpen()) { *error=QString::fromUtf8("未连接运行数据库。"); return result; }
    const QList<QPair<QString,QString>> queries{
        {"citations","SELECT c.record FROM citation_links l JOIN citations c ON c.db=l.db AND c.id=l.citation_id WHERE l.db=? AND l.dbc_id=?"},
        {"notes","SELECT note FROM notes WHERE db=? AND dbc_id=?"},
        {"dataInfo","SELECT record FROM data_info WHERE db=? AND dbc_id=?"}};
    for(const auto &spec:queries) {
        QSqlQuery q(connection_);q.prepare(spec.second);q.addBindValue(database);q.addBindValue(referenceId);
        if(!q.exec()) { *error=q.lastError().text(); return {}; }
        QJsonArray records;while(q.next()) records.append(spec.first=="notes"?QJsonValue(q.value(0).toString()):QJsonValue(QJsonDocument::fromJson(q.value(0).toByteArray()).object()));result[spec.first]=records;
    }
    QSqlQuery q(connection_);q.prepare("SELECT table_name,file,sha256,row_count FROM sources WHERE db=? ORDER BY table_name");q.addBindValue(database);
    if(!q.exec()) { *error=q.lastError().text(); return {}; }
    QJsonArray files;while(q.next()) files.append(QJsonObject{{"table",q.value(0).toString()},{"file",q.value(1).toString()},{"sha256",q.value(2).toString()},{"rows",q.value(3).toInt()}}); result["sourceFiles"]=files;
    return result;
}
