#include "ProjectDocument.h"
#include "ChemicalSystem.h"
#include "ProcessInput.h"
#include "ProcessTopology.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSaveFile>
#include <QSet>
#include <QRegularExpression>

ProjectDocument::ProjectDocument(QObject *parent):QObject(parent) { initialize(emptyState()); }
QJsonObject ProjectDocument::emptyState() {
    return {{"format","aspen-for-mac-project"},{"version",1},{"units","METCBAR"},
        {"objects",QJsonArray()},{"components",QJsonArray()},{"dependencies",QJsonObject()},
        {"unverifiedInputs",QJsonObject{{"recovered",QJsonObject()},{"components",QJsonObject()}}}};
}
QString ProjectDocument::validate(const QJsonObject &s) {
    if(s.value("format")!="aspen-for-mac-project" || s.value("version")!=1)
        return QString::fromUtf8("不支持的项目格式或版本；原文件未修改。");
    if(!QStringList{"ENG","MET","METCBAR","SI"}.contains(s.value("units").toString()) ||
       !s.value("objects").isArray() || !s.value("components").isArray() ||
       !s.value("dependencies").isObject() || !s.value("unverifiedInputs").isObject())
        return QString::fromUtf8("项目字段不完整或类型无效。");
    const auto unverified=s.value("unverifiedInputs").toObject();
    if(!unverified.value("recovered").isObject() || !unverified.value("components").isObject())
        return QString::fromUtf8("未验证输入结构无效。");
    for(const auto &v:unverified.value("recovered").toObject())
        if(!v.isObject()) return QString::fromUtf8("页面输入结构无效。");
    QFile f(":/ui/object-types.json"); f.open(QIODevice::ReadOnly);
    const auto definitions=QJsonDocument::fromJson(f.readAll()).object().value("collections").toArray();
    QMap<QString,QJsonObject> objects, kinds;
    for(const auto &v:definitions) kinds[v.toObject().value("id").toString()]=v.toObject();
    QSet<QString> names;
    for(const auto &v:s.value("objects").toArray()) {
        const auto d=v.toObject(); const auto key=d.value("key").toString();
        const auto name=d.value("name").toString(), kind=d.value("kind").toString();
        const auto identity=kind+"/"+d.value("parent").toString()+"/"+name.toUpper();
        bool known=false;
        for(const auto &t:kinds.value(kind).value("types").toArray()) if(t.toObject().value("id")==d.value("type")) known=true;
        if(key.isEmpty() || objects.contains(key) || names.contains(identity) || !known ||
           !QRegularExpression("^[A-Za-z0-9][A-Za-z0-9_-]{0,7}$").match(name).hasMatch() ||
           !d.value("inputs").isObject() || !d.value("parent").isString())
            return QString::fromUtf8("项目含重复身份、未知对象类型或无效输入。");
        for(const auto &input:d.value("inputs").toObject())
            if(!input.isObject()) return QString::fromUtf8("对象页面输入结构无效。");
        for(const auto &field:{"x","y","startX","startY","endX","endY"})
            if(d.contains(field) && !d.value(field).isDouble()) return QString::fromUtf8("无效的流程图坐标。");
        objects[key]=d; names.insert(identity);
    }
    for(const auto &d:objects) {
        const auto parent=d.value("parent").toString();
        const auto allowed=kinds.value(d.value("kind").toString()).value("parentTypes").toArray();
        if((allowed.isEmpty() && !parent.isEmpty()) || (!allowed.isEmpty() &&
           (!objects.contains(parent) || !allowed.contains(objects[parent].value("type")))))
            return QString::fromUtf8("项目含失效的父子关系。");
        QSet<QString> seen{d.value("key").toString()}; auto p=parent;
        while(!p.isEmpty()) { if(seen.contains(p)) return QString::fromUtf8("父子关系存在循环。"); seen.insert(p); p=objects.value(p).value("parent").toString(); }
        for(const auto &end:{"from","to"}) {
            const auto ref=d.value(end).toString();
            if(!ref.isEmpty() && (d.value("kind")!="streams" || !objects.contains(ref) || objects[ref].value("kind")!="blocks"))
                return QString::fromUtf8("项目含失效的流程图连接。");
        }
    }
    const auto topologyError=ProcessTopology::validateStructure(s.value("objects").toArray());
    if(!topologyError.isEmpty())return topologyError;
    QSet<QString> componentIds;
    for(const auto &v:s.value("components").toArray()) {
        const auto c=v.toObject(); const auto key=c.value("database").toString()+":"+c.value("compoundId").toString();
        if(c.value("database").toString().isEmpty() || c.value("compoundId").toString().isEmpty() ||
           c.value("name").toString().isEmpty() || c.value("datasetId").toString().isEmpty() || c.value("datasetId")!=s.value("dependencies").toObject().value("propertyDatabase") || componentIds.contains(key))
            return QString::fromUtf8("组分身份或数据来源无效。");
        componentIds.insert(key);
    }
    const auto processError=ProcessInput::validateStructure(s);
    if(s.contains("componentOrder")) {
        if(!s.value("componentOrder").isArray()) return QString::fromUtf8("组分顺序结构无效。");
        QSet<QString> available,seen;
        for(const auto &v:ChemicalSystem::components(s)) available.insert(v.toObject().value("key").toString());
        for(const auto &v:s.value("componentOrder").toArray()) {
            if(!v.isString() || !available.contains(v.toString()) || seen.contains(v.toString()))
                return QString::fromUtf8("组分顺序含失效或重复身份。");
            seen.insert(v.toString());
        }
    }
    return processError.isEmpty()?ChemicalSystem::validate(s):processError;
}
void ProjectDocument::initialize(const QJsonObject &s) { state_=saved_=s; history_={s}; index_=0; }
void ProjectDocument::edit(const QJsonObject &s) {
    auto normalized=s;
    if(s.value("componentOrder").isArray()) {
        QJsonArray order;
        for(const auto &v:ChemicalSystem::components(s)) order.append(v.toObject().value("key"));
        normalized["componentOrder"]=order;
    }
    if(state_==normalized) return;
    state_=normalized; history_.resize(index_+1); history_.append(state_); ++index_;
    if(history_.size()>101) { history_.removeFirst(); --index_; }
    emit changed();
}
void ProjectDocument::reset() { initialize(emptyState()); fileName_.clear(); emit restored(); emit changed(); }
void ProjectDocument::undo() { if(!canUndo()) return; state_=history_[--index_]; emit restored(); emit changed(); }
void ProjectDocument::redo() { if(!canRedo()) return; state_=history_[++index_]; emit restored(); emit changed(); }
bool ProjectDocument::save(const QString &path, QString *error) {
    *error=validate(state_); if(!error->isEmpty()) return false;
    QSaveFile file(path); file.setDirectWriteFallback(false);
    if(!file.open(QIODevice::WriteOnly)) { *error=file.errorString(); return false; }
    const auto bytes=QJsonDocument(state_).toJson();
    if(bytes.size()>64*1024*1024) { *error=QString::fromUtf8("项目文件超过 64 MiB 限制。");file.cancelWriting();return false; }
    if(file.write(bytes)!=bytes.size() || !file.commit()) { *error=file.errorString(); return false; }
    fileName_=path; saved_=state_; emit changed(); return true;
}
bool ProjectDocument::load(const QString &path, QString *error) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) { *error=file.errorString(); return false; }
    if(file.size()>64*1024*1024) { *error=QString::fromUtf8("项目文件超过 64 MiB 限制。"); return false; }
    QJsonParseError parse; const auto json=QJsonDocument::fromJson(file.readAll(),&parse);
    if(parse.error!=QJsonParseError::NoError || !json.isObject()) { *error=QString::fromUtf8("项目 JSON 无效：")+parse.errorString(); return false; }
    *error=validate(json.object()); if(!error->isEmpty()) return false;
    initialize(json.object()); fileName_=path; emit restored(); emit changed(); return true;
}
