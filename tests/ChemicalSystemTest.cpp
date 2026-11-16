#include "ChemicalSystem.h"
#include "ProjectDocument.h"
#include <QFile>
#include <QJsonDocument>
#include <QTemporaryDir>
#include <QtTest>

using namespace ChemicalSystem;
namespace {
QJsonObject fixture() {
    auto s=ProjectDocument::emptyState();s["dependencies"]=QJsonObject{{"propertyDatabase","test-only"}};
    s["components"]=QJsonArray{
        QJsonObject{{"database","TEST"},{"compoundId","1"},{"datasetId","test-only"},{"name","WATER"},{"alias","H2O"},{"componentId","WATER"},{"componentType","CONV"},{"cas","7732-18-5"}},
        QJsonObject{{"database","TEST"},{"compoundId","2"},{"datasetId","test-only"},{"name","ETHANOL"},{"alias","C2H6O"},{"componentId","ETHANOL"},{"componentType","CONV"},{"cas","64-17-5"}}};return s;
}
QJsonArray rows(QString solid="WATER(S)") {return {QJsonObject{{"fluid","db:TEST:1"},{"solidId",solid}}};}
QJsonObject data(const QJsonObject &state,const QString &name) {return chemistry(state,name).value("chemistryData").toObject();}
}
class ChemicalSystemTest:public QObject {
    Q_OBJECT
private slots:
    void newSfeWritesBusinessFieldsAndRoundTrips() {
        const auto before=fixture();auto result=applySfe(before,rows()," c-1 ",false,true);QVERIFY2(result,qPrintable(result.error));
        QCOMPARE(result.state.value("components"),before.value("components"));
        const auto solid=result.state.value("chemicalSystem").toObject().value("generatedComponents").toArray().first().toObject();
        QCOMPARE(solid.value("id").toString(),QString("WATER(S)"));QCOMPARE(solid.value("type").toString(),QString("SOLID"));
        QCOMPARE(solid.value("dbName").toString(),QString("WATER"));QCOMPARE(solid.value("alias").toString(),QString("H2O"));
        const auto input=data(result.state,"C-1");QVERIFY(input.value("gammaBasis").isNull());
        const auto salt=input.value("saltCoefficients").toArray().first().toObject();QCOMPARE(salt.value("solid"),solid.value("key"));
        QCOMPARE(salt.value("coefficients").toObject().value("db:TEST:1").toString(),QString("1"));QCOMPARE(salt.value("option").toString(),QString("NO"));
        QCOMPARE(globalChemistryId(result.state),QString("C-1"));QVERIFY(result.state.value("chemicalSystem").toObject().value("global").toObject().value("trueComponents").toBool());
        QTemporaryDir dir;ProjectDocument document;document.edit(before);document.edit(result.state);document.undo();QCOMPARE(document.state(),before);document.redo();
        QString error;QVERIFY2(document.save(dir.filePath("sfe.afmp"),&error),qPrintable(error));ProjectDocument loaded;QVERIFY(loaded.load(dir.filePath("sfe.afmp"),&error));QCOMPARE(loaded.state(),result.state);
    }
    void existingSfePreservesInputsTrueFlagAndSaltKeys() {
        auto o=ElectrolyteOptions();o.waterDissociation=true;o.trueComponents=false;
        const auto initial=fixture();auto e=applyElectrolyte(initial,{"db:TEST:1"},o,electrolyteCandidates(initial,{"db:TEST:1"},o));QVERIFY(e);
        auto first=applySfe(e.state,rows(),"GLOBAL",true,true);QVERIFY(first);
        QCOMPARE(data(first.state,"GLOBAL").value("reactions"),data(e.state,"GLOBAL").value("reactions"));
        QVERIFY(!first.state.value("chemicalSystem").toObject().value("global").toObject().value("trueComponents").toBool());
        auto repeat=applySfe(first.state,rows(),"GLOBAL",true,true);QVERIFY(repeat);QCOMPARE(repeat.state,first.state);
        auto second=applySfe(first.state,QJsonArray{QJsonObject{{"fluid","db:TEST:2"},{"solidId","ETHAN(S)"}}},"GLOBAL",true,false);QVERIFY(second);
        QCOMPARE(data(second.state,"GLOBAL").value("saltCoefficients").toArray().size(),2);
    }
    void sfeValidationIsAtomicIncludingLastRowDuplicate() {
        const auto state=fixture();const QJsonArray duplicate{rows().first(),QJsonObject{{"fluid","db:TEST:2"},{"solidId","water(s)"}}};
        for(const auto &r:QList<QJsonArray>{duplicate,rows(""),rows("INVALID_ID"),rows("X X"),rows("WATER"),QJsonArray{QJsonObject{{"fluid","missing"},{"solidId","SOLID"}}}}) {
            const auto result=applySfe(state,r,"C-1",false,true);QVERIFY(!result);QCOMPARE(result.state,state);
        }
        const auto done=applySfe(state,rows(),"C-1",false,true);QVERIFY(done);
        auto collision=applySfe(done.state,rows(),"C-1",false,true);QVERIFY(!collision);QCOMPARE(collision.state,done.state);
        QVERIFY(!applySfe(state,rows(),"MISSING",true,true));
    }
    void sfeIdentityFilteringAndNaming() {
        auto state=fixture();auto c=state.value("components").toArray();auto water=c[0].toObject();water.remove("componentType");c[0]=water;
        auto ethanol=c[1].toObject();ethanol["componentType"]="ION";c[1]=ethanol;state["components"]=c;QVERIFY(sfeComponents(state).isEmpty());
        for(const auto &type:{"CONV","PSEUDO","OLIGOMER"}){ethanol["componentType"]=type;c[1]=ethanol;state["components"]=c;QCOMPARE(sfeComponents(state).size(),1);}
        QCOMPARE(defaultSolidId(QJsonObject{{"id","LONGNAME"},{"dbName","AB"}}),QString("AB(S)"));
        QCOMPARE(defaultSolidId(QJsonObject{{"id","longname"},{"dbName",""}}),QString("LONGN(S)"));
        QCOMPARE(defaultSolidId(QJsonObject{{"id","WATER"},{"dbName","OTHER"}}),QString("WATER(S)"));
        QVERIFY(validSolidId(QString::fromUtf8("水(S)")));QVERIFY(validSolidId("A$&*+{}"));QVERIFY(!validSolidId("A_B"));QVERIFY(!validSolidId("(S)"));
        auto done=applySfe(fixture(),rows(),"C-1",false,false);QVERIFY(done);QCOMPARE(defaultChemistryId(done.state),QString("C-2"));
    }
    void equalAliasesRetainDistinctIdentity() {
        auto s=fixture();auto c=s.value("components").toArray();auto second=c[1].toObject();second["componentId"]="WATER";second["alias"]="H2O";c[1]=second;s["components"]=c;
        const auto candidates=sfeComponents(s);QCOMPARE(candidates.size(),2);QVERIFY(candidates[0].toObject().value("key")!=candidates[1].toObject().value("key"));
        auto r=applySfe(s,QJsonArray{rows("SOLID1").first(),QJsonObject{{"fluid","db:TEST:2"},{"solidId","SOLID2"}}},"C-1",false,false);QVERIFY(r);
        const auto salts=data(r.state,"C-1").value("saltCoefficients").toArray();QVERIFY(salts[1].toObject().value("coefficients").toObject().contains("db:TEST:2"));
    }
    void electrolyteKnownBoundaryAndConservation() {
        const auto s=fixture();ElectrolyteOptions o;
        QVERIFY(!electrolyteCandidates(s,{"db:TEST:1"},o).error.isEmpty());o.waterDissociation=true;
        QVERIFY(!electrolyteCandidates(s,{"db:TEST:1","db:TEST:2"},o).error.isEmpty());
        auto c=electrolyteCandidates(s,{"db:TEST:1"},o);QVERIFY(c.error.isEmpty());
        auto r=applyElectrolyte(s,{"db:TEST:1"},o,c);QVERIFY2(r,qPrintable(r.error));
        const auto coeff=data(r.state,"GLOBAL").value("reactions").toArray().first().toObject().value("coefficients").toObject();
        // Independent H/O/charge accounting; persisted references must resolve.
        int h=0,oxygen=0,charge=0;
        for(const auto &v:components(r.state)) {
            const auto atom=v.toObject();const int n=coeff.value(atom.value("key").toString()).toString().toInt();const auto id=atom.value("id").toString();
            if(id=="WATER"){h+=2*n;oxygen+=n;}if(id=="H3O+"){h+=3*n;oxygen+=n;charge+=n;}if(id=="OH-"){h+=n;oxygen+=n;charge-=n;}
        }
        QCOMPARE(h,0);QCOMPARE(oxygen,0);QCOMPARE(charge,0);QCOMPARE(coeff.value("db:TEST:1").toString(),QString("-2"));
        o.hydronium=false;QVERIFY(!electrolyteCandidates(s,{"db:TEST:1"},o).error.isEmpty());o.hydronium=true;o.ice=true;QVERIFY(!electrolyteCandidates(s,{"db:TEST:1"},o).error.isEmpty());
    }
    void electrolyteEarlyFinishAndMethodBranches() {
        const auto s=fixture();ElectrolyteOptions o;o.waterDissociation=true;o.setMethod=false;o.componentsOnly=true;
        const auto c=electrolyteCandidates(s,{"db:TEST:1"},o);auto early=applyElectrolyte(s,{"db:TEST:1"},o,c);QVERIFY(early);
        QVERIFY(early.state.value("objects").toArray().isEmpty());QVERIFY(early.state.value("chemicalSystem").toObject().value("global").toObject().isEmpty());
        o.componentsOnly=false;o.chemistryId="LOCAL";auto local=applyElectrolyte(s,{"db:TEST:1"},o,c);QVERIFY(local);QVERIFY(globalChemistryId(local.state).isEmpty());
        o.setMethod=true;o.symmetric=true;QVERIFY(!applyElectrolyte(s,{"db:TEST:1"},o,c));o.method="ENRTL-SR";auto symmetric=applyElectrolyte(s,{"db:TEST:1"},o,c);QVERIFY(symmetric);
        QCOMPARE(data(symmetric.state,"LOCAL").value("referenceState").toString(),QString("symmetric"));
        QVERIFY(!applyElectrolyte(symmetric.state,{"db:TEST:1"},o,c));o.replaceChemistry=true;QVERIFY(applyElectrolyte(symmetric.state,{"db:TEST:1"},o,c));
        Candidates removed;QVERIFY(!applyElectrolyte(s,{"db:TEST:1"},o,removed));
    }
    void corruptReferencesRejectedWithoutReplacingDocument() {
        const auto valid=applySfe(fixture(),rows(),"C-1",false,true);QVERIFY(valid);
        auto broken=valid.state;broken["components"]=QJsonArray();QVERIFY(!ProjectDocument::validate(broken).isEmpty());
        QTemporaryDir dir;QFile f(dir.filePath("bad.afmp"));QVERIFY(f.open(QIODevice::WriteOnly));f.write(QJsonDocument(broken).toJson());f.close();
        ProjectDocument document;document.edit(valid.state);QString error;QVERIFY(!document.load(f.fileName(),&error));QCOMPARE(document.state(),valid.state);
        QVERIFY(componentReferenced(valid.state,"db:TEST:1"));
        broken=valid.state;broken["objects"]=QJsonArray();QVERIFY(!ProjectDocument::validate(broken).isEmpty());
        const auto cleaned=removeMissingGlobalReferences(broken);QVERIFY(ProjectDocument::validate(cleaned).isEmpty());
    }
};
QTEST_MAIN(ChemicalSystemTest)
#include "ChemicalSystemTest.moc"
