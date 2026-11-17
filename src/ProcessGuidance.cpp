#include "ProcessGuidance.h"
#include "ProcessTopology.h"

namespace ProcessGuidance {
QVector<ProcessInput::Issue> issues(const QJsonObject &state) {
    QVector<ProcessInput::Issue> result;
    const auto components=state.value("components").toArray();
    if(components.isEmpty())result.append({{},"components",QString::fromUtf8("必须从数据库选择组分。")});
    const auto method=state.value("process").toObject().value("method").toString();
    if(method.isEmpty())result.append({{},"method",QString::fromUtf8("必须指定全局物性方法。")});
    else if(!QStringList{"NRTL","IDEAL"}.contains(method))result.append({{},"method",QString::fromUtf8("当前输入检查只覆盖 NRTL / IDEAL 方法。")});
    if(!state.value("chemicalSystem").toObject().value("generatedComponents").toArray().isEmpty())
        result.append({{},"unsupported",QString::fromUtf8("本轮输入检查尚不覆盖向导生成的固体或电解质组分。")});
    const auto objects=state.value("objects").toArray();QJsonArray blocks,streams;
    for(const auto &v:objects) {
        const auto o=v.toObject();const auto kind=o.value("kind").toString();
        if(kind=="blocks")blocks.append(o);
        if(kind=="streams")streams.append(o);
        if(kind=="user-components" || kind=="chemistry" || ((kind=="blocks" || kind=="streams") && !ProcessInput::supported(o)))
            result.append({o.value("key").toString(),"unsupported",QString::fromUtf8("%1：本轮引导仅覆盖数据库组分、物料流股和 Flash2 温压规定。").arg(o.value("name").toString())});
    }
    if(blocks.size()!=1 || blocks.first().toObject().value("type")!="Flash2")
        result.append({{},"flowsheet",QString::fromUtf8("本轮参考流程需要一个 Flash2、一个进料和两个产品流股。")});
    else {
        const auto block=blocks.first().toObject();const auto key=block.value("key").toString();int feeds=0,products=0;
        for(const auto &v:streams) {
            const auto o=v.toObject();const auto from=o.value("from").toString(),to=o.value("to").toString();
            if(o.value("type")!="MATERIAL")continue;
            if(from.isEmpty() && to==key)++feeds;
            else if(from==key && to.isEmpty())++products;
            else result.append({o.value("key").toString(),"flowsheet",QString::fromUtf8("%1：流股连接不属于本轮 Flash2 参考拓扑，请重新连接。").arg(o.value("name").toString())});
        }
        if(feeds!=1 || products!=2)result.append({key,"flowsheet",QString::fromUtf8("Flash2 需要一个外部进料和两个外部产品连接。")});
    }
    result+=ProcessTopology::issues(objects);
    for(const auto &v:blocks) result+=ProcessInput::issues(v.toObject(),components);
    for(const auto &v:streams) result+=ProcessInput::issues(v.toObject(),components);
    return result;
}
ProcessInput::Issue next(const QJsonObject &state,const QString &currentObject) {
    const auto all=issues(state);if(all.isEmpty())return {};
    // Global prerequisites and topology must hold before reporting an input-ready case.
    for(const auto &issue:all)if(issue.field=="components" || issue.field=="method")return issue;
    if(!currentObject.isEmpty())for(const auto &issue:all)if(issue.object==currentObject && issue.field!="flowsheet" && issue.field!="unsupported")return issue;
    return all.first();
}
}
