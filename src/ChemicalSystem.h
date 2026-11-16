#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>

// Portable project semantics. No Aspen DLLs, database writes or solver calls.
namespace ChemicalSystem {
struct Result {
    QJsonObject state;
    QString error;
    explicit operator bool() const { return error.isEmpty(); }
};
struct ElectrolyteOptions {
    bool symmetric=false, hydronium=true, waterDissociation=false, ice=false;
    bool setMethod=true, componentsOnly=false, trueComponents=true;
    QString method="ELECNRTL", chemistryId="GLOBAL";
    bool replaceChemistry=false;
};
struct Candidates {
    QJsonArray species, reactions;
    QString error;
};
QString normalizedId(const QString &id);
bool validSolidId(const QString &id);
bool validChemistryId(const QString &id);
QString databaseKey(const QJsonObject &component);
QJsonArray components(const QJsonObject &state);
QJsonArray sfeComponents(const QJsonObject &state);
bool isWater(const QJsonObject &component);
QString defaultSolidId(const QJsonObject &component);
QString defaultChemistryId(const QJsonObject &state);
QJsonObject chemistry(const QJsonObject &state,const QString &name);
QString globalChemistryId(const QJsonObject &state);
Candidates electrolyteCandidates(const QJsonObject &state,const QStringList &selected,const ElectrolyteOptions &options);
Result applyElectrolyte(const QJsonObject &state,const QStringList &selected,const ElectrolyteOptions &options,const Candidates &candidates);
// rows: {fluid: stable component key, solidId: project identifier}
Result applySfe(const QJsonObject &state,const QJsonArray &rows,const QString &chemistryId,bool existing,bool makeGlobal);
QString validate(const QJsonObject &state);
bool componentReferenced(const QJsonObject &state,const QString &key);
QJsonObject removeMissingGlobalReferences(QJsonObject state);
}
