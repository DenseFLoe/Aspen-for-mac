#pragma once
#include "ProjectDocument.h"
#include "ProcessInput.h"
// Synthetic component identities; only the documented reference input conditions.
inline QJsonObject flash2Fixture(bool filled=true) {
    auto state=ProjectDocument::emptyState();state["units"]="ENG";
    state["dependencies"]=QJsonObject{{"propertyDatabase","synthetic-flash2"}};
    QJsonArray components;
    for(const auto &id:{"METHANOL","WATER"})components.append(QJsonObject{{"database","TEST"},{"compoundId",id},{"name",id},{"datasetId","synthetic-flash2"}});
    state["components"]=components;state["process"]=QJsonObject{{"version",1},{"method","NRTL"}};
    QJsonObject block{{"key","B"},{"name","B1"},{"kind","blocks"},{"type","Flash2"},{"parent",""},{"inputs",QJsonObject()}};
    QJsonObject feed{{"key","F"},{"name","1"},{"kind","streams"},{"type","MATERIAL"},{"parent",""},{"inputs",QJsonObject()},{"from",""},{"to","B"}};
    auto vapor=feed;vapor["key"]="V";vapor["name"]="2";vapor["from"]="B";vapor["to"]="";
    auto liquid=vapor;liquid["key"]="L";liquid["name"]="3";
    if(filled) {
        block["processInput"]=QJsonObject{{"version",1},{"temperature",ProcessInput::quantity("185","F")},{"pressure",ProcessInput::quantity("14.7","psia")}};
        feed["processInput"]=QJsonObject{{"version",1},{"temperature",ProcessInput::quantity("200","F")},{"pressure",ProcessInput::quantity("50","psia")},{"moleFlow",ProcessInput::quantity("100","lbmol/hr")},{"fractions",QJsonObject{{"TEST:METHANOL","0.5"},{"TEST:WATER","0.5"}}}};
    }
    state["objects"]=QJsonArray{block,feed,vapor,liquid};return state;
}
