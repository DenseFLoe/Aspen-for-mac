#include "ProcessInput.h"
#include "ProcessUnits.h"
#include <QLocale>
#include <QRegularExpression>
#include <cmath>

namespace ProcessInput {
bool supported(const QJsonObject &o) {
    return (o.value("kind")=="blocks" && o.value("type")=="Flash2") ||
           (o.value("kind")=="streams" && o.value("type")=="MATERIAL");
}
QString componentKey(const QJsonObject &c) { return c.value("database").toString()+":"+c.value("compoundId").toString(); }
QStringList fields(const QJsonObject &o) {
    QStringList result{"temperature","pressure","vaporFraction"};
    if(o.value("kind")=="blocks") result.append("duty");
    if(o.value("kind")=="streams") result.append("moleFlow");
    return result;
}
QString specification(const QJsonObject &input) { return input.contains("specification")?input.value("specification").toString():QString("TP"); }
QStringList specificationFields(const QString &spec) {
    if(spec=="TP")return {"temperature","pressure"};
    if(spec=="TV")return {"temperature","vaporFraction"};
    if(spec=="PV")return {"pressure","vaporFraction"};
    if(spec=="TD")return {"temperature","duty"};
    if(spec=="PD")return {"pressure","duty"};
    return {};
}
QString specificationFor(const QString &first,const QString &second) {
    for(const auto &spec:QStringList{"TP","TV","PV","TD","PD"}) {
        const auto pair=specificationFields(spec);
        if(first!=second && pair.contains(first) && pair.contains(second))return spec;
    }
    return {};
}
QStringList specifications(const QJsonObject &o) {
    return o.value("kind")=="blocks"?QStringList{"TP","TV","PV","TD","PD"}:QStringList{"TP","TV","PV"};
}
QStringList requiredFields(const QJsonObject &o) {
    auto result=specificationFields(specification(o.value("processInput").toObject()));
    if(o.value("kind")=="streams")result.append("moleFlow");
    return result;
}
QString defaultUnit(const QString &f) { return f=="temperature"?"K":f=="pressure"?"Pa":f=="vaporFraction"?"1":f=="duty"?"W":"mol/s"; }
QString label(const QString &f) {
    if(f=="temperature") return QString::fromUtf8("温度");
    if(f=="pressure") return QString::fromUtf8("绝对压力");
    if(f=="moleFlow") return QString::fromUtf8("总摩尔流量");
    if(f=="vaporFraction") return QString::fromUtf8("汽相摩尔分率");
    if(f=="duty") return QString::fromUtf8("热负荷");
    return QString::fromUtf8("摩尔分率");
}
QJsonObject quantity(const QString &text,const QString &unit) { return {{"text",text},{"unit",unit}}; }
bool number(const QString &text,double *value) {
    static const QRegularExpression syntax("^[+-]?(?:[0-9]+(?:\\.[0-9]*)?|\\.[0-9]+)(?:[eE][+-]?[0-9]+)?$");
    if(!syntax.match(text.trimmed()).hasMatch()) return false;
    bool ok=false;*value=QLocale::c().toDouble(text.trimmed(),&ok);return ok && std::isfinite(*value);
}
QVector<Issue> issues(const QJsonObject &o,const QJsonArray &components) {
    QVector<Issue> result;
    const auto input=o.value("processInput").toObject();const auto key=o.value("key").toString();
    const auto add=[&](const QString &field,const QString &message){result.append({key,field,message});};
    if(!supported(o)) return result;
    // Connected product/intermediate streams are calculated, not independent feeds.
    if(o.value("kind")=="streams" && !o.value("from").toString().isEmpty()) return result;
    if(!specifications(o).contains(specification(input)))add("specification",QString::fromUtf8("闪蒸规定无效；请选择该对象支持的两项规定。"));
    for(const auto &f:requiredFields(o)) {
        const auto q=input.value(f).toObject();double value=0;
        if(q.value("text").toString().trimmed().isEmpty()) add(f,QString::fromUtf8("必须指定%1。").arg(label(f)));
        else if(!ProcessUnits::toSI(f,q,&value)) add(f,QString::fromUtf8("%1的数值或单位无效。").arg(label(f)));
        else if(f=="vaporFraction") {
            if(value<0 || value>1)add(f,QString::fromUtf8("汽相摩尔分率必须在 0–1 之间（包含端点）。"));
        } else if(f!="duty" && value<=0) add(f,QString::fromUtf8("%1必须大于零（温度按绝对温标）。").arg(label(f)));
    }
    if(o.value("kind")=="streams") {
        const auto scalarIssues=result;result.clear();
        const auto fractions=input.value("fractions").toObject();double sum=0;bool valid=!components.isEmpty();
        for(const auto &v:components) {
            const auto c=v.toObject();const auto id=componentKey(c);double x=0;
            if(!number(fractions.value(id).toString(),&x) || x<0 || x>1) {
                add("fraction:"+id,QString::fromUtf8("请填写 %1 的摩尔分率（0–1）。").arg(c.value("name").toString()));valid=false;
            } else sum+=x;
        }
        if(valid && std::abs(sum-1)>1e-8) add("fractions",QString::fromUtf8("摩尔分率之和必须为 1；当前为 %1。").arg(sum,0,'g',12));
        for(auto it=fractions.begin();it!=fractions.end();++it) {
            bool exists=false;for(const auto &c:components) if(componentKey(c.toObject())==it.key()) exists=true;
            if(!exists) add("fractions",QString::fromUtf8("组成含已移除组分，请在组成表中移除失效项。"));
        }
        result+=scalarIssues;
    }
    return result;
}
QString validateStructure(const QJsonObject &state) {
    if(state.contains("process") && (!state.value("process").isObject() || state.value("process").toObject().value("version")!=1 ||
        !state.value("process").toObject().value("method").isString())) return QString::fromUtf8("流程方法结构或版本无效。");
    for(const auto &v:state.value("objects").toArray()) {
        const auto o=v.toObject();if(!o.contains("processInput")) continue;
        const auto input=o.value("processInput").toObject();
        if(!o.value("processInput").isObject() || !supported(o) || input.value("version")!=1) return QString::fromUtf8("流程输入类型或版本无效。");
        if(!specifications(o).contains(specification(input)))return QString::fromUtf8("该对象的流程闪蒸规定无效或尚不支持。");
        if(o.value("kind")=="streams" && input.contains("duty"))return QString::fromUtf8("物料流股不支持热负荷输入。");
        for(const auto &f:fields(o)) if(input.contains(f)) {
            const auto q=input.value(f).toObject();
            if(!q.value("text").isString() || !q.value("unit").isString()) return QString::fromUtf8("流程数值字段结构无效。");
        }
        if(input.contains("fractions")) {
            if(!input.value("fractions").isObject()) return QString::fromUtf8("组成结构无效。");
            for(const auto &x:input.value("fractions").toObject()) if(!x.isString()) return QString::fromUtf8("组成数值结构无效。");
        }
    }
    return {};
}
}
