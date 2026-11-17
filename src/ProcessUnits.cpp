#include "ProcessUnits.h"
#include "ProcessInput.h"
#include <cmath>

namespace {
bool coefficients(const QString &field,const QString &unit,double *scale,double *offset) {
    *scale=1;*offset=0;
    if(field=="temperature") {
        if(unit=="K")return true;
        if(unit=="C"){*offset=273.15;return true;}
        if(unit=="F"){*scale=5.0/9;*offset=273.15-32*(*scale);return true;}
    } else if(field=="pressure") {
        if(unit=="Pa")return true;
        if(unit=="kPa"){*scale=1000;return true;}
        if(unit=="bar"){*scale=100000;return true;}
        if(unit=="atm"){*scale=101325;return true;}
        if(unit=="psia"){*scale=6894.757293168361;return true;}
    } else if(field=="moleFlow") {
        if(unit=="mol/s")return true;
        if(unit=="kmol/hr"){*scale=1000.0/3600;return true;}
        if(unit=="lbmol/hr"){*scale=453.59237/3600;return true;}
    }
    return false;
}
}
namespace ProcessUnits {
QStringList units(const QString &field) {
    if(field=="temperature")return {"K","C","F"};
    if(field=="pressure")return {"Pa","kPa","bar","atm","psia"};
    if(field=="moleFlow")return {"mol/s","kmol/hr","lbmol/hr"};
    return {};
}
QString forSet(const QString &field,const QString &set) {
    if(set=="SI")return ProcessInput::defaultUnit(field);
    if(field=="temperature")return set=="ENG"?"F":"C";
    if(field=="pressure")return set=="ENG"?"psia":set=="MET"?"atm":"bar";
    return set=="ENG"?"lbmol/hr":"kmol/hr";
}
bool toSI(const QString &field,const QJsonObject &q,double *value) {
    double scale,offset,x;
    if(!coefficients(field,q.value("unit").toString(),&scale,&offset) || !ProcessInput::number(q.value("text").toString(),&x))return false;
    *value=x*scale+offset;return std::isfinite(*value);
}
bool convert(const QString &field,const QJsonObject &q,const QString &unit,QJsonObject *output) {
    double scale,offset,x,oldScale,oldOffset;
    if(!coefficients(field,unit,&scale,&offset) || !coefficients(field,q.value("unit").toString(),&oldScale,&oldOffset))return false;
    if(q.value("text").toString().trimmed().isEmpty()){*output=ProcessInput::quantity("",unit);return true;}
    if(!toSI(field,q,&x))return false;
    const auto value=(x-offset)/scale;if(!std::isfinite(value))return false;
    *output=unit==q.value("unit")?q:ProcessInput::quantity(QString::number(value,'g',17),unit);return true;
}
}
