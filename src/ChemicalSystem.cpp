#include "ChemicalSystem.h"
#include <QMap>
#include <QRegularExpression>
#include <QSet>
#include <QUuid>
#include <cmath>

namespace ChemicalSystem {
namespace {
QString uid() { return QUuid::createUuid().toString(QUuid::WithoutBraces); }
QJsonObject system(const QJsonObject &s) {
    auto c=s.value("chemicalSystem").toObject();
    if(c.isEmpty()) c={{"version",1},{"generatedComponents",QJsonArray()},{"global",QJsonObject()}};
    return c;
}
QJsonObject objectRecord(const QString &name) {
    return {{"key",uid()},{"name",name},{"kind","chemistry"},{"type","Chemistry"},{"parent",""},{"inputs",QJsonObject()}};
}
QJsonObject emptyChemistry() {
    return {{"version",1},{"reactions",QJsonArray()},{"saltCoefficients",QJsonArray()}};
}
void putChemistry(QJsonObject &state,const QJsonObject &record) {
    auto objects=state.value("objects").toArray();
    for(int i=0;i<objects.size();++i) if(objects[i].toObject().value("key")==record.value("key")) {
        objects[i]=record;state["objects"]=objects;return;
    }
    objects.append(record);state["objects"]=objects;
}
QMap<QString,QJsonObject> byKey(const QJsonArray &items) {
    QMap<QString,QJsonObject> result;
    for(const auto &v:items) result[v.toObject().value("key").toString()]=v.toObject();
    return result;
}
QString collision(const QJsonArray &all,const QString &id) {
    for(const auto &v:all) if(normalizedId(v.toObject().value("id").toString())==id) return v.toObject().value("key").toString();
    return {};
}
}
QString normalizedId(const QString &id) { return id.trimmed().toUpper(); }
bool validSolidId(const QString &id) {
    if(id.isEmpty() || id.size()>8 || !(id[0].isLetter() || id[0].isDigit())) return false;
    for(const auto ch:id) if(!(ch.isLetter() || ch.isDigit()) && !QString("$&*()+{}-=][:><").contains(ch)) return false;
    return true;
}
bool validChemistryId(const QString &id) {
    // Project object ID contract; the original OneIdDialog's full validator is not ported.
    return QRegularExpression("^[A-Z0-9][A-Z0-9_-]{0,7}$").match(id).hasMatch();
}
QString databaseKey(const QJsonObject &c) { return "db:"+c.value("database").toString()+":"+c.value("compoundId").toString(); }
QJsonArray components(const QJsonObject &state) {
    QJsonArray result;
    for(const auto &v:state.value("components").toArray()) {
        const auto c=v.toObject();
        const auto fallback=c.value("alias").toString().isEmpty()?c.value("name").toString():c.value("alias").toString();
        result.append(QJsonObject{{"key",databaseKey(c)},{"id",c.value("componentId").toString(fallback)},
            {"type",c.value("componentType").toString("UNKNOWN")},{"dbName",c.value("name")},{"alias",c.value("alias")},
            {"cas",c.value("cas")},{"database",c.value("database")},{"compoundId",c.value("compoundId")}});
    }
    for(const auto &v:state.value("objects").toArray()) {
        const auto c=v.toObject();if(c.value("kind")!="user-components") continue;
        auto type=c.value("type").toString();if(type=="CONVENTIONAL") type="CONV";
        result.append(QJsonObject{{"key","object:"+c.value("key").toString()},{"id",c.value("name")},{"type",type},
            {"dbName",c.value("dbName").toString()},{"alias",c.value("alias").toString()}});
    }
    for(const auto &v:system(state).value("generatedComponents").toArray()) result.append(v);
    return result;
}
QJsonArray sfeComponents(const QJsonObject &state) {
    QJsonArray result;
    for(const auto &v:components(state)) if(QStringList{"CONV","PSEUDO","OLIGOMER"}.contains(v.toObject().value("type").toString())) result.append(v);
    return result;
}
bool isWater(const QJsonObject &c) {
    // A project ID can be renamed to WATER; it is not evidence of chemical identity.
    return c.value("cas")=="7732-18-5" && c.contains("database") && QStringList{"UNKNOWN","CONV"}.contains(c.value("type").toString());
}
QString defaultSolidId(const QJsonObject &c) {
    const auto id=c.value("id").toString().trimmed(), db=c.value("dbName").toString().trimmed();
    return (id.size()<=5?id:db.isEmpty()?id.left(5).toUpper():db.left(5))+"(S)";
}
QJsonObject chemistry(const QJsonObject &state,const QString &name) {
    for(const auto &v:state.value("objects").toArray()) if(v.toObject().value("kind")=="chemistry" && normalizedId(v.toObject().value("name").toString())==normalizedId(name)) return v.toObject();
    return {};
}
QString defaultChemistryId(const QJsonObject &state) {
    for(int i=1;;++i) {const auto name="C-"+QString::number(i);if(chemistry(state,name).isEmpty())return name;}
}
QString globalChemistryId(const QJsonObject &state) {
    const auto key=system(state).value("global").toObject().value("chemistry");
    for(const auto &v:state.value("objects").toArray()) if(v.toObject().value("key")==key) return v.toObject().value("name").toString();
    return {};
}
Candidates electrolyteCandidates(const QJsonObject &state,const QStringList &selected,const ElectrolyteOptions &o) {
    Candidates result;const auto all=byKey(components(state));
    if(selected.size()!=1 || !all.contains(selected.value(0)) || !isWater(all.value(selected.value(0)))) {
        result.error=QString::fromUtf8("当前已核实的候选生成仅支持单一 WATER（CAS 7732-18-5）；其他体系的反应库规则尚未接入。");return result;
    }
    if(!o.hydronium || o.ice) {result.error=QString::fromUtf8("H+ 或成冰分支尚未完成原版核验，不能生成。");return result;}
    if(!o.waterDissociation) {result.error=QString::fromUtf8("无可用反应；纯水案例需选择水离解。");return result;}
    const auto water=selected.first();
    for(const auto &id:QStringList{"H3O+","OH-"}) result.species.append(QJsonObject{
        {"id",id},{"type","ION"},{"dbName",""},{"alias",id},{"source",water},
        {"origin","electrolyte-water-dissociation"},{"evidence","water-hydronium-v1"}});
    result.reactions.append(QJsonObject{{"id","water-dissociation"},{"equation","2 H2O <===> OH- + H3O+"},
        {"base",water},{"coefficients",QJsonObject{{"water","-2"},{"H3O+","1"},{"OH-","1"}}},
        {"evidence","water-hydronium-v1"}});
    return result;
}
Result applyElectrolyte(const QJsonObject &state,const QStringList &selected,const ElectrolyteOptions &o,const Candidates &c) {
    auto fail=[&](const QString &e){return Result{state,e};};
    const auto allowed=electrolyteCandidates(state,selected,o);
    if(!allowed.error.isEmpty()) return fail(allowed.error);
    // Only complete, verified candidates can be committed. Exclusion removes this
    // single coupled reaction and both ions; no dangling species are generated.
    if(c.species!=allowed.species || c.reactions!=allowed.reactions) return fail(QString::fromUtf8("没有完整、已核实的候选反应可提交；请返回重新生成。"));
    const auto name=normalizedId(o.chemistryId);
    if(!o.componentsOnly && !validChemistryId(name)) return fail(QString::fromUtf8("Chemistry ID 须为 1–8 位字母、数字、下划线或连字符。"));
    const auto methods=o.symmetric?QStringList{"ENRTL-SR"}:QStringList{"ELECNRTL","ENRTL-RK"};
    if(o.setMethod && !o.componentsOnly && !methods.contains(o.method)) return fail(QString::fromUtf8("物性方法与参考态不一致。"));
    auto record=chemistry(state,name);
    if(!o.componentsOnly && !record.isEmpty() && !o.replaceChemistry) return fail(QString::fromUtf8("Chemistry 已存在，需明确确认替换。"));
    auto result=state, cs=system(state);auto generated=cs.value("generatedComponents").toArray();auto all=components(state);
    QJsonObject refs{{"water",selected.first()}};
    for(const auto &v:c.species) {
        auto species=v.toObject();const auto id=species.value("id").toString();auto key=collision(all,id);
        if(!key.isEmpty()) {
            const auto old=byKey(all).value(key);
            if(old.value("origin")!=species.value("origin") || old.value("source")!=species.value("source")) return fail(QString::fromUtf8("组分 ID 冲突：")+id);
        } else {key="generated:"+uid();species["key"]=key;generated.append(species);all.append(species);}
        refs[id]=key;
    }
    cs["generatedComponents"]=generated;
    if(!o.componentsOnly) {
        if(record.isEmpty()) record=objectRecord(name);
        auto data=emptyChemistry();auto reaction=c.reactions.first().toObject();QJsonObject coefficients;
        const auto source=reaction.take("coefficients").toObject();
        for(auto it=source.begin();it!=source.end();++it) coefficients[refs.value(it.key()).toString()]=it.value();
        reaction.remove("base");reaction["coefficients"]=coefficients;data["reactions"]=QJsonArray{reaction};
        data["referenceState"]=o.symmetric?"symmetric":"asymmetric";
        data["approach"]=o.setMethod?(o.trueComponents?"true":"apparent"):"apparent";
        data["origin"]="electrolyte";record["chemistryData"]=data;putChemistry(result,record);
        if(o.setMethod) {
            auto global=cs.value("global").toObject();global["chemistry"]=record.value("key");global["method"]=o.method;
            global["trueComponents"]=o.trueComponents;global["electrolyteWizard"]=true;cs["global"]=global;
        }
    }
    result["chemicalSystem"]=cs;
    const auto error=validate(result);return error.isEmpty()?Result{result,{}}:fail(error);
}
Result applySfe(const QJsonObject &state,const QJsonArray &rows,const QString &chemistryId,bool existing,bool makeGlobal) {
    auto fail=[&](const QString &e){return Result{state,e};};
    if(rows.isEmpty()) return fail(QString::fromUtf8("请选择至少一个流体组分。"));
    const auto name=normalizedId(chemistryId);
    if(!validChemistryId(name)) return fail(QString::fromUtf8("Chemistry ID 须为 1–8 位字母、数字、下划线或连字符。"));
    auto record=chemistry(state,name);
    if(existing && record.isEmpty()) return fail(QString::fromUtf8("所选 Chemistry 已不存在。"));
    if(!existing && !record.isEmpty()) return fail(QString::fromUtf8("Chemistry ID 已存在；请选择已有集合或更换 ID。"));
    auto data=record.value("chemistryData").toObject();if(data.isEmpty()) data=emptyChemistry();
    auto result=state,cs=system(state);auto generated=cs.value("generatedComponents").toArray();auto all=components(state);
    const auto eligible=byKey(sfeComponents(state));QSet<QString> ids,fluids;auto salts=data.value("saltCoefficients").toArray();
    for(const auto &v:rows) {
        const auto row=v.toObject();const auto fluid=row.value("fluid").toString(),id=normalizedId(row.value("solidId").toString());
        if(!eligible.contains(fluid) || fluids.contains(fluid)) return fail(QString::fromUtf8("流体身份无效、重复或类别不属于 CONV/PSEUDO/OLIGOMER。"));
        if(!validSolidId(id)) return fail(QString::fromUtf8("固体 ID 必须为 1–8 个字符，首位为字母或数字，不能包含空格或下划线。"));
        if(ids.contains(id)) return fail(QString::fromUtf8("固体 ID 重复：")+id);
        ids.insert(id);fluids.insert(fluid);auto key=collision(all,id);const auto source=eligible.value(fluid);
        if(!key.isEmpty()) {
            const auto old=byKey(all).value(key);
            if(old.value("origin")!="sfe" || old.value("source")!=fluid) return fail(QString::fromUtf8("固体 ID 与项目组分冲突：")+id);
        } else {
            key="generated:"+uid();QJsonObject solid{{"key",key},{"id",id},{"type","SOLID"},{"dbName",source.value("dbName")},
                {"alias",source.value("alias")},{"source",fluid},{"origin","sfe"},{"evidence","sfe-main-il-v1"}};
            generated.append(solid);all.append(solid);
        }
        bool present=false;for(const auto &s:salts) if(s.toObject().value("solid")==key) present=true;
        if(!present) salts.append(QJsonObject{{"solid",key},{"coefficients",QJsonObject{{fluid,"1"}}},{"option","NO"}});
    }
    if(record.isEmpty()) {record=objectRecord(name);data["gammaBasis"]=QJsonValue(QJsonValue::Null);data["origin"]="sfe";}
    data["saltCoefficients"]=salts;record["chemistryData"]=data;putChemistry(result,record);cs["generatedComponents"]=generated;
    if(makeGlobal) {
        auto global=cs.value("global").toObject();global["chemistry"]=record.value("key");
        if(!existing) global["trueComponents"]=true;cs["global"]=global;
    }
    result["chemicalSystem"]=cs;const auto error=validate(result);return error.isEmpty()?Result{result,{}}:fail(error);
}
bool componentReferenced(const QJsonObject &state,const QString &key) {
    for(const auto &v:system(state).value("generatedComponents").toArray()) if(v.toObject().value("source")==key) return true;
    for(const auto &v:state.value("objects").toArray()) {
        const auto data=v.toObject().value("chemistryData").toObject();
        for(const auto &r:data.value("reactions").toArray()) if(r.toObject().value("coefficients").toObject().contains(key)) return true;
        for(const auto &r:data.value("saltCoefficients").toArray()) if(r.toObject().value("solid")==key || r.toObject().value("coefficients").toObject().contains(key)) return true;
    }
    return false;
}
QJsonObject removeMissingGlobalReferences(QJsonObject state) {
    if(!state.contains("chemicalSystem")) return state;
    auto cs=system(state),global=cs.value("global").toObject();const auto key=global.value("chemistry");bool found=false;
    for(const auto &v:state.value("objects").toArray()) if(v.toObject().value("key")==key && v.toObject().value("kind")=="chemistry")found=true;
    if(!found)global.remove("chemistry");cs["global"]=global;state["chemicalSystem"]=cs;return state;
}
QString validate(const QJsonObject &state) {
    const auto invalid=QString::fromUtf8("化学系统含无效结构、身份或失效引用。");
    const auto all=byKey(components(state));
    for(const auto &v:state.value("components").toArray()) {
        const auto c=v.toObject();
        if(c.contains("componentType") && !QStringList{"UNKNOWN","CONV","PSEUDO","OLIGOMER","ION","SOLID","NONCONVENTIONAL"}.contains(c.value("componentType").toString()))return invalid;
        if(c.contains("componentId") && c.value("componentId").toString().isEmpty())return invalid;
    }
    if(state.contains("chemicalSystem")) {
        const auto cs=state.value("chemicalSystem").toObject();
        if(cs.value("version")!=1 || !cs.value("generatedComponents").isArray() || !cs.value("global").isObject())return invalid;
        QSet<QString> keys,ids;
        for(const auto &v:cs.value("generatedComponents").toArray()) {
            const auto c=v.toObject();const auto key=c.value("key").toString(),id=c.value("id").toString(),source=c.value("source").toString();
            if(!key.startsWith("generated:") || key.size()<=10 || keys.contains(key) || !validSolidId(id) || ids.contains(normalizedId(id)) ||
                !QStringList{"SOLID","ION"}.contains(c.value("type").toString()) || !all.contains(source) || source.startsWith("generated:") ||
                !c.value("dbName").isString() || !c.value("alias").isString() || !c.value("origin").isString())return invalid;
            for(const auto &other:components(state)) if(other.toObject().value("key")!=key && normalizedId(other.toObject().value("id").toString())==normalizedId(id))return invalid;
            if(c.value("origin")=="sfe") {
                if(c.value("type")!="SOLID" || !QStringList{"CONV","PSEUDO","OLIGOMER"}.contains(all.value(source).value("type").toString()))return invalid;
            } else if(c.value("origin")=="electrolyte-water-dissociation") {
                if(c.value("type")!="ION" || !QStringList{"H3O+","OH-"}.contains(id) || !isWater(all.value(source)))return invalid;
            } else return invalid;
            keys.insert(key);ids.insert(normalizedId(id));
        }
        const auto global=cs.value("global").toObject();
        if(global.contains("chemistry")) {
            bool found=false;for(const auto &v:state.value("objects").toArray())if(v.toObject().value("key")==global.value("chemistry") && v.toObject().value("kind")=="chemistry")found=true;
            if(!found)return invalid;
        }
        if(global.contains("method") && !QStringList{"ELECNRTL","ENRTL-RK","ENRTL-SR"}.contains(global.value("method").toString()))return invalid;
        for(const auto &field:{"trueComponents","electrolyteWizard"})if(global.contains(field) && !global.value(field).isBool())return invalid;
    }
    const auto validCoefficients=[&](const QJsonValue &v) {
        if(!v.isObject() || v.toObject().isEmpty())return false;
        const auto coeff=v.toObject();for(auto it=coeff.begin();it!=coeff.end();++it) {
            bool ok=false;const auto number=it.value().toString().toDouble(&ok);
            if(!all.contains(it.key()) || !it.value().isString() || !ok || !std::isfinite(number) || number==0)return false;
        }return true;
    };
    for(const auto &v:state.value("objects").toArray()) {
        const auto o=v.toObject();if(!o.contains("chemistryData"))continue;const auto d=o.value("chemistryData").toObject();
        if(o.value("kind")!="chemistry" || d.value("version")!=1 || !d.value("reactions").isArray() || !d.value("saltCoefficients").isArray())return invalid;
        QSet<QString> reactions,salts;
        for(const auto &r:d.value("reactions").toArray()) {
            const auto rx=r.toObject();const auto id=rx.value("id").toString();
            if(id.isEmpty() || reactions.contains(id) || !validCoefficients(rx.value("coefficients")))return invalid;reactions.insert(id);
        }
        for(const auto &r:d.value("saltCoefficients").toArray()) {
            const auto salt=r.toObject();const auto solid=salt.value("solid").toString();
            if(!all.contains(solid) || all.value(solid).value("type")!="SOLID" || salts.contains(solid) || !validCoefficients(salt.value("coefficients")) || salt.value("option")!="NO")return invalid;salts.insert(solid);
        }
        if(d.contains("referenceState") && !QStringList{"symmetric","asymmetric"}.contains(d.value("referenceState").toString()))return invalid;
        if(d.contains("approach") && !QStringList{"true","apparent"}.contains(d.value("approach").toString()))return invalid;
        if(d.contains("gammaBasis") && !d.value("gammaBasis").isNull())return invalid;
    }
    return {};
}
}
