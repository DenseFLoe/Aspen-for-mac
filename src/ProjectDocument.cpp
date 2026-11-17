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

namespace {
QString describeEdit(const QJsonObject &before,const QJsonObject &after) {
    if(before.value("componentOrder")!=after.value("componentOrder")) {
        QSet<QString> oldKeys,newKeys;
        for(const auto &v:ChemicalSystem::components(before))oldKeys.insert(v.toObject().value("key").toString());
        for(const auto &v:ChemicalSystem::components(after))newKeys.insert(v.toObject().value("key").toString());
        if(oldKeys==newKeys)return QString::fromUtf8("重新排序组分");
    }
    if(before.value("units")!=after.value("units"))return QString::fromUtf8("切换单位：")+after.value("units").toString();
    if(before.value("process")!=after.value("process"))return QString::fromUtf8("修改物性方法");
    if(before.value("components")!=after.value("components"))return QString::fromUtf8("修改组分");
    if(before.value("compoundSearch")!=after.value("compoundSearch"))return QString::fromUtf8("修改数据库检索顺序");
    if(before.value("chemicalSystem")!=after.value("chemicalSystem"))return QString::fromUtf8("修改化学系统");
    QMap<QString,QJsonObject> oldObjects,newObjects;
    for(const auto &v:before.value("objects").toArray())oldObjects[v.toObject().value("key").toString()]=v.toObject();
    for(const auto &v:after.value("objects").toArray())newObjects[v.toObject().value("key").toString()]=v.toObject();
    QStringList added,removed,changed;
    for(auto it=newObjects.cbegin();it!=newObjects.cend();++it) {
        if(!oldObjects.contains(it.key()))added<<it.value().value("name").toString();
        else if(oldObjects.value(it.key())!=it.value())changed<<it.key();
    }
    for(auto it=oldObjects.cbegin();it!=oldObjects.cend();++it)if(!newObjects.contains(it.key()))removed<<it.value().value("name").toString();
    if(!added.isEmpty())return QString::fromUtf8("新建：")+added.join(", ");
    if(!removed.isEmpty())return QString::fromUtf8("删除：")+removed.join(", ");
    if(changed.size()==1) {
        const auto old=oldObjects.value(changed.first()),current=newObjects.value(changed.first());
        const auto name=current.value("name").toString();
        if(old.value("name")!=current.value("name"))return QString::fromUtf8("重命名：%1 → %2").arg(old.value("name").toString(),name);
        if(old.value("x")!=current.value("x") || old.value("y")!=current.value("y"))return QString::fromUtf8("移动：")+name;
        return QString::fromUtf8("修改：")+name;
    }
    return changed.isEmpty()?QString::fromUtf8("修改页面输入"):QString::fromUtf8("修改多个对象");
}
}

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
    if(s.contains("compoundSearch")) {
        const auto preferences=s.value("compoundSearch").toObject();
        if(!s.value("compoundSearch").isObject() || !preferences.value("datasetId").isString() || preferences.value("datasetId").toString().isEmpty() || !preferences.value("databanks").isArray())return QString::fromUtf8("数据库检索设置结构无效。");
        QSet<QString> banks;
        for(const auto &v:preferences.value("databanks").toArray()) {
            const auto b=v.toObject();const auto id=b.value("bankId");const auto key=b.value("database").toString()+":"+QString::number(id.toInt(-1));
            if(!v.isObject() || !b.value("database").isString() || b.value("database").toString().isEmpty() || !id.isDouble() || id.toDouble()<0 || id.toDouble()!=id.toInt(-1) || banks.contains(key))return QString::fromUtf8("数据库检索设置含无效或重复子库。");
            banks.insert(key);
        }
    }
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
void ProjectDocument::initialize(const QJsonObject &s) { state_=saved_=s; history_={s}; index_=0; ++historyRevision_; }
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
    ++historyRevision_;
    emit changed();
}
void ProjectDocument::reset() { initialize(emptyState()); fileName_.clear(); emit restored(); emit changed(); }
void ProjectDocument::undo(int steps) {
    const int count=qBound(0,steps,index_);if(!count)return;
    index_-=count;state_=history_[index_];++historyRevision_;emit restored();emit changed();
}
void ProjectDocument::redo(int steps) {
    const int count=qBound(0,steps,int(history_.size())-1-index_);if(!count)return;
    index_+=count;state_=history_[index_];++historyRevision_;emit restored();emit changed();
}
QStringList ProjectDocument::undoHistory() const {
    QStringList result;for(int i=index_;i>0;--i)result<<describeEdit(history_[i-1],history_[i]);return result;
}
QStringList ProjectDocument::redoHistory() const {
    QStringList result;for(int i=index_+1;i<history_.size();++i)result<<describeEdit(history_[i-1],history_[i]);return result;
}
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
