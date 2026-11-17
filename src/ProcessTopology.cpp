#include "ProcessTopology.h"
#include <QMap>

namespace ProcessTopology {
bool isFlash2(const QJsonObject &object) {
    return object.value("kind")=="blocks" && object.value("type")=="Flash2";
}
QStringList ports(const QString &end) {
    if(end=="from")return {"VAPOR","LIQUID"};
    if(end=="to")return {"FEED"};
    return {};
}
QString portLabel(const QString &port) {
    if(port=="FEED")return QString::fromUtf8("物料进料");
    if(port=="VAPOR")return QString::fromUtf8("汽相出口");
    if(port=="LIQUID")return QString::fromUtf8("液相出口");
    return port;
}
QString endpointError(const QJsonArray &objects,const QJsonObject &stream,
                      const QString &end,const QString &block,const QString &port) {
    if(stream.value("kind")!="streams" || !QStringList{"from","to"}.contains(end))
        return QString::fromUtf8("请选择有效的流股端点。");
    if(block.isEmpty())return port.isEmpty()?QString():QString::fromUtf8("空白端点不能指定模块端口。");
    QJsonObject target;
    for(const auto &v:objects)if(v.toObject().value("key")==block){target=v.toObject();break;}
    if(target.value("kind")!="blocks")return QString::fromUtf8("连接的模块已不存在。");
    if(stream.value(end=="from"?"to":"from").toString()==block)
        return QString::fromUtf8("流股不能将同一模块的出口连回其入口。");
    if(!isFlash2(target))return port.isEmpty()?QString():QString::fromUtf8("此模块尚未接入该端口规则。");
    if(stream.value("type")!="MATERIAL")
        return QString::fromUtf8("当前 Flash2 参考案例只支持物料连接；热量和功连接尚未接入。");
    if(!ports(end).contains(port))
        return end=="from"?QString::fromUtf8("请选择 Flash2 的汽相或液相出口。"):QString::fromUtf8("流股目标必须连接 Flash2 的物料进料端口。");
    for(const auto &v:objects) {
        const auto other=v.toObject();
        if(other.value("kind")!="streams" || other.value("key")==stream.value("key"))continue;
        if(other.value(end)==block && other.value(end+"Port")==port)
            return QString::fromUtf8("%1 的%2已被流股 %3 占用。").arg(target.value("name").toString(),portLabel(port),other.value("name").toString());
    }
    return {};
}
QVector<ProcessInput::Issue> issues(const QJsonArray &objects) {
    QVector<ProcessInput::Issue> result;
    for(const auto &v:objects) {
        const auto stream=v.toObject();if(stream.value("kind")!="streams")continue;
        for(const auto &end:QStringList{"from","to"}) {
            const auto error=endpointError(objects,stream,end,stream.value(end).toString(),stream.value(end+"Port").toString());
            if(!error.isEmpty())result.append({stream.value("key").toString(),"flowsheet",QString::fromUtf8("%1：%2").arg(stream.value("name").toString(),error)});
        }
    }
    return result;
}
QString validateStructure(const QJsonArray &objects) {
    for(const auto &v:objects) {
        const auto object=v.toObject();
        for(const auto &end:QStringList{"from","to"}) {
            if(object.contains(end) && !object.value(end).isString())return QString::fromUtf8("流程图端点必须为对象标识字符串。");
            const auto field=end+"Port";
            if(object.contains(field) && (!object.value(field).isString() || object.value("kind")!="streams"))
                return QString::fromUtf8("流股端口字段结构无效。");
        }
    }
    return {};
}
}
