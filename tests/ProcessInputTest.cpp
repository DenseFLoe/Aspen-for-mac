#include "ProcessInput.h"
#include "ProcessGuidance.h"
#include "ProcessTopology.h"
#include "Flash2Fixture.h"
#include "ProcessUnits.h"
#include "ProjectDocument.h"
#include <QtTest>
#include <QTemporaryDir>

class ProcessInputTest : public QObject {
    Q_OBJECT
private slots:
    void dutySpecificationsUseSignedPowerAndRejectIncompatiblePairs() {
        const auto reference=flash2Fixture();
        for(const auto &spec:QStringList{"TD","PD"})for(const auto &text:QStringList{"-2.5","0","3.0"}) {
            auto state=reference;auto objects=state.value("objects").toArray();auto block=objects[0].toObject();auto input=block.value("processInput").toObject();
            input["specification"]=spec;input["duty"]=ProcessInput::quantity(text,"kW");
            input[spec=="TD"?"pressure":"temperature"]=ProcessInput::quantity("bad",spec=="TD"?"Pa":"K");
            block["processInput"]=input;objects[0]=block;state["objects"]=objects;
            QVERIFY(ProcessGuidance::issues(state).isEmpty());QVERIFY(ProjectDocument::validate(state).isEmpty());
            ProjectDocument doc;doc.edit(reference);doc.edit(state);doc.undo();QCOMPARE(doc.state(),reference);doc.redo();
            QTemporaryDir dir;QString error;QVERIFY(doc.save(dir.filePath("duty.afmp"),&error));QVERIFY(doc.load(dir.filePath("duty.afmp"),&error));QCOMPARE(doc.state(),state);
            input["duty"]=ProcessInput::quantity("","W");block["processInput"]=input;
            QCOMPARE(ProcessInput::issues(block,state.value("components").toArray()).first().field,QString("duty"));
            auto feed=objects[1].toObject();auto feedInput=feed.value("processInput").toObject();feedInput["specification"]=spec;feed["processInput"]=feedInput;objects[1]=feed;state["objects"]=objects;
            QVERIFY(!ProjectDocument::validate(state).isEmpty());
        }
        QVERIFY(ProcessInput::specificationFor("duty","vaporFraction").isEmpty());
        QCOMPARE(ProcessInput::specificationFor("duty","temperature"),QString("TD"));QCOMPARE(ProcessInput::specificationFor("pressure","duty"),QString("PD"));
        QJsonObject result;QVERIFY(ProcessUnits::convert("duty",ProcessInput::quantity("-2.5","kW"),"W",&result));QCOMPARE(result,ProcessInput::quantity("-2500","W"));
        QVERIFY(ProcessUnits::convert("duty",result,"MW",&result));double watts=0;QVERIFY(ProcessUnits::toSI("duty",result,&watts));QCOMPARE(watts,-2500.0);
        QVERIFY(!ProcessUnits::convert("duty",ProcessInput::quantity("NaN","W"),"kW",&result));
    }
    void specificationsControlRequiredInputsAndPersist() {
        const auto reference=flash2Fixture();
        for(const auto &spec:QStringList{"TP","TV","PV"})for(int objectIndex:{0,1}) {
            auto state=reference;auto objects=state.value("objects").toArray();auto object=objects[objectIndex].toObject();
            auto input=object.value("processInput").toObject();input["specification"]=spec;
            input["vaporFraction"]=ProcessInput::quantity("0.50","1");
            // An inactive retained input must not become a third required condition.
            for(const auto &f:QStringList{"temperature","pressure","vaporFraction"})
                if(!ProcessInput::specificationFields(spec).contains(f))input[f]=ProcessInput::quantity("bad",ProcessInput::defaultUnit(f));
            object["processInput"]=input;objects[objectIndex]=object;state["objects"]=objects;
            QVERIFY(ProcessInput::issues(object,state.value("components").toArray()).isEmpty());QVERIFY(ProcessGuidance::issues(state).isEmpty());
            ProjectDocument doc;doc.edit(reference);doc.edit(state);doc.undo();QCOMPARE(doc.state(),reference);doc.redo();QCOMPARE(doc.state(),state);
            QTemporaryDir dir;QString error;QVERIFY2(doc.save(dir.filePath("spec.afmp"),&error),qPrintable(error));
            QVERIFY(doc.load(dir.filePath("spec.afmp"),&error));QCOMPARE(doc.state(),state);
            if(spec=="TP")continue;
            for(const auto &text:QStringList{"0","1"}) {
                input["vaporFraction"]=ProcessInput::quantity(text,"1");object["processInput"]=input;
                QVERIFY(ProcessInput::issues(object,state.value("components").toArray()).isEmpty());
            }
            for(const auto &text:QStringList{"","-0.01","1.01","NaN","1e999"}) {
                input["vaporFraction"]=ProcessInput::quantity(text,"1");object["processInput"]=input;
                const auto problems=ProcessInput::issues(object,state.value("components").toArray());
                QCOMPARE(problems.size(),1);QCOMPARE(problems.first().field,QString("vaporFraction"));
            }
            input["vaporFraction"]=ProcessInput::quantity("0.5","%");object["processInput"]=input;
            QCOMPARE(ProcessInput::issues(object,state.value("components").toArray()).first().field,QString("vaporFraction"));
        }
        for(const auto &spec:QStringList{"TP","TV","PV"}) {
            const auto pair=ProcessInput::specificationFields(spec);
            QCOMPARE(ProcessInput::specificationFor(pair[0],pair[1]),spec);
            QCOMPARE(ProcessInput::specificationFor(pair[1],pair[0]),spec);
        }
        QVERIFY(ProcessInput::specificationFor("temperature","temperature").isEmpty());
        for(const QJsonValue bad:QList<QJsonValue>{"", "TT", "TQ", 1, QJsonValue(QJsonValue::Null)}) {
            auto state=reference;auto objects=state.value("objects").toArray();auto object=objects[0].toObject();auto input=object.value("processInput").toObject();
            input["specification"]=bad;object["processInput"]=input;objects[0]=object;state["objects"]=objects;
            QVERIFY(!ProjectDocument::validate(state).isEmpty());QCOMPARE(ProcessGuidance::next(state,"B").field,QString("specification"));
        }
        // Malformed inactive fields cannot bypass project structure validation.
        auto state=reference;auto objects=state.value("objects").toArray();auto object=objects[0].toObject();auto input=object.value("processInput").toObject();
        input["vaporFraction"]=2;object["processInput"]=input;objects[0]=object;state["objects"]=objects;QVERIFY(!ProjectDocument::validate(state).isEmpty());
        double fraction=0;QVERIFY(ProcessUnits::toSI("vaporFraction",ProcessInput::quantity("0.5","1"),&fraction));QCOMPARE(fraction,0.5);
        for(const auto &units:QStringList{"SI","ENG","MET","CBAR"})QCOMPARE(ProcessUnits::forSet("vaporFraction",units),QString("1"));
    }
    void referenceTopologyRequiresDistinctVerifiedPorts() {
        const auto reference=flash2Fixture();
        QVERIFY(ProcessGuidance::issues(reference).isEmpty());
        // Legacy connections remain loadable and saveable, but cannot pass readiness.
        auto legacy=reference;auto objects=legacy.value("objects").toArray();
        for(int i=1;i<objects.size();++i){auto o=objects[i].toObject();o.remove("fromPort");o.remove("toPort");objects[i]=o;}
        legacy["objects"]=objects;QVERIFY(ProjectDocument::validate(legacy).isEmpty());
        QCOMPARE(ProcessGuidance::next(legacy,{}).field,QString("flowsheet"));
        QTemporaryDir dir;ProjectDocument doc;doc.edit(legacy);QString error;
        QVERIFY2(doc.save(dir.filePath("legacy.afmp"),&error),qPrintable(error));
        QVERIFY(doc.load(dir.filePath("legacy.afmp"),&error));QCOMPARE(doc.state(),legacy);
        // Duplicate phase, reversed direction, missing phase and nonmaterial connection.
        for(const auto &role:QStringList{"LIQUID","FEED","","unknown"}) {
            objects=reference.value("objects").toArray();auto vapor=objects[2].toObject();vapor["fromPort"]=role;objects[2]=vapor;
            auto state=reference;state["objects"]=objects;
            QVERIFY(!ProcessGuidance::issues(state).isEmpty());QCOMPARE(ProcessGuidance::next(state,{}).object,QString("V"));
        }
        objects=reference.value("objects").toArray();auto vapor=objects[2].toObject();vapor["type"]="HEAT";objects[2]=vapor;
        QVERIFY(!ProcessTopology::issues(objects).isEmpty());
        vapor=reference.value("objects").toArray()[2].toObject();vapor["to"]="B";vapor["toPort"]="FEED";objects[2]=vapor;
        QVERIFY(!ProcessTopology::issues(objects).isEmpty());
        // Malformed metadata fails before replacing a saved document.
        objects=reference.value("objects").toArray();vapor=objects[2].toObject();vapor["fromPort"]=12;objects[2]=vapor;
        auto bad=reference;bad["objects"]=objects;QVERIFY(!ProjectDocument::validate(bad).isEmpty());
        doc.edit(bad);QVERIFY(!doc.save(dir.filePath("legacy.afmp"),&error));
        QVERIFY(doc.load(dir.filePath("legacy.afmp"),&error));QCOMPARE(doc.state(),legacy);
    }
    void endpointEditsRespectDirectionOccupancyAndIdentity() {
        auto objects=flash2Fixture().value("objects").toArray();
        const auto vapor=objects[2].toObject();
        QVERIFY(ProcessTopology::endpointError(objects,vapor,"from","B","VAPOR").isEmpty());
        QVERIFY(!ProcessTopology::endpointError(objects,vapor,"from","B","LIQUID").isEmpty());
        QVERIFY(!ProcessTopology::endpointError(objects,vapor,"from","B","FEED").isEmpty());
        QVERIFY(!ProcessTopology::endpointError(objects,vapor,"to","B","FEED").isEmpty());
        QVERIFY(!ProcessTopology::endpointError(objects,vapor,"from","missing","VAPOR").isEmpty());
        QVERIFY(ProcessTopology::endpointError(objects,vapor,"from","","").isEmpty());
        QVERIFY(!ProcessTopology::endpointError(objects,vapor,"from","","VAPOR").isEmpty());
        auto block=objects[0].toObject();block["name"]="RENAMED";objects[0]=block;
        QVERIFY(ProcessTopology::endpointError(objects,vapor,"from","B","VAPOR").isEmpty());
    }
    void guidanceTracksDataAndCurrentObject() {
        auto state=flash2Fixture();QVERIFY(ProjectDocument::validate(state).isEmpty());QVERIFY(ProcessGuidance::issues(state).isEmpty());
        auto missing=state;missing["components"]=QJsonArray();QCOMPARE(ProcessGuidance::next(missing,"B").field,QString("components"));
        missing=state;missing.remove("process");QCOMPARE(ProcessGuidance::next(missing,"B").field,QString("method"));
        missing=flash2Fixture(false);QCOMPARE(ProcessGuidance::next(missing,"B").object,QString("B"));QCOMPARE(ProcessGuidance::next(missing,"B").field,QString("temperature"));
        QCOMPARE(ProcessGuidance::next(missing,"F").object,QString("F"));QVERIFY(ProcessGuidance::next(missing,"F").field.startsWith("fraction:"));
        auto objects=state.value("objects").toArray();auto feed=objects[1].toObject();feed["to"]="";objects[1]=feed;missing=state;missing["objects"]=objects;
        QVERIFY(!ProcessGuidance::issues(missing).isEmpty());QCOMPARE(ProcessGuidance::next(missing,{}).field,QString("flowsheet"));
        objects=state.value("objects").toArray();auto block=objects[0].toObject();auto input=block.value("processInput").toObject();input["temperature"]=ProcessInput::quantity("-500","F");block["processInput"]=input;objects[0]=block;missing=state;missing["objects"]=objects;
        QCOMPARE(ProcessGuidance::next(missing,"B").field,QString("temperature"));
        block["type"]="Heater";block.remove("processInput");objects[0]=block;missing["objects"]=objects;QCOMPARE(ProcessGuidance::next(missing,"B").field,QString("unsupported"));
    }

    void referenceUnitsAndRoundTrips() {
        double value=0;
        QVERIFY(ProcessUnits::toSI("temperature",ProcessInput::quantity("185","F"),&value));QVERIFY(qAbs(value-358.15)<1e-10);
        QVERIFY(ProcessUnits::toSI("temperature",ProcessInput::quantity("200","F"),&value));QVERIFY(qAbs(value-366.4833333333333)<1e-10);
        QVERIFY(ProcessUnits::toSI("pressure",ProcessInput::quantity("50","psia"),&value));QVERIFY(qAbs(value-344737.864658418)<1e-6);
        QVERIFY(ProcessUnits::toSI("moleFlow",ProcessInput::quantity("100","lbmol/hr"),&value));QVERIFY(qAbs(value-12.59978805555556)<1e-12);
        auto q=ProcessInput::quantity("185","F");
        for(int i=0;i<100;++i)for(const auto &u:{"K","C","F"}){QJsonObject result;QVERIFY(ProcessUnits::convert("temperature",q,u,&result));q=result;}
        QVERIFY(ProcessUnits::toSI("temperature",q,&value));QVERIFY(qAbs(value-358.15)<1e-10);
        QJsonObject result{{"unchanged",true}};QVERIFY(!ProcessUnits::convert("pressure",ProcessInput::quantity("bad","psia"),"bar",&result));QVERIFY(result.value("unchanged").toBool());
        QVERIFY(!ProcessUnits::convert("pressure",ProcessInput::quantity("1","psia"),"C",&result));
        QVERIFY(ProcessUnits::convert("temperature",ProcessInput::quantity("","F"),"C",&result));QVERIFY(result.value("text").toString().isEmpty());
    }

    void fieldsRejectMissingInvalidAndOutOfRange() {
        QJsonObject feed{{"key","feed"},{"kind","streams"},{"type","MATERIAL"}};
        QJsonArray components{QJsonObject{{"database","TEST"},{"compoundId","1"},{"name","A"}},QJsonObject{{"database","TEST"},{"compoundId","2"},{"name","B"}}};
        QCOMPARE(ProcessInput::issues(feed,components).size(),5);
        QJsonObject input{{"version",1},{"temperature",ProcessInput::quantity("300","K")},{"pressure",ProcessInput::quantity("101325","Pa")},{"moleFlow",ProcessInput::quantity("1","mol/s")},{"fractions",QJsonObject{{"TEST:1","0.5"},{"TEST:2","0.5"}}}};
        feed["processInput"]=input;QVERIFY(ProcessInput::issues(feed,components).isEmpty());
        for(const auto &text:{"","0","-1","NaN","1e999","12garbage","1,000"}) {
            auto bad=input;bad["pressure"]=ProcessInput::quantity(text,"Pa");feed["processInput"]=bad;QVERIFY(!ProcessInput::issues(feed,components).isEmpty());
        }
        input["fractions"]=QJsonObject{{"TEST:1","0"},{"TEST:2","1"}};feed["processInput"]=input;QVERIFY(ProcessInput::issues(feed,components).isEmpty());
        input["fractions"]=QJsonObject{{"TEST:1","0.5"},{"TEST:2","0.4"}};feed["processInput"]=input;QCOMPARE(ProcessInput::issues(feed,components).first().field,QString("fractions"));
        feed["from"]="block";QVERIFY(ProcessInput::issues(feed,components).isEmpty());
    }
    void typedInputsRoundTripAndUndo() {
        ProjectDocument doc;auto state=doc.state();
        QJsonObject block{{"key","B1"},{"name","B1"},{"kind","blocks"},{"type","Flash2"},{"parent",""},{"inputs",QJsonObject{{"old-page",QJsonObject{{"old-text","preserved"}}}}},
            {"processInput",QJsonObject{{"version",1},{"temperature",ProcessInput::quantity("358.1500","K")}}}};
        state["objects"]=QJsonArray{block};state["process"]=QJsonObject{{"version",1},{"method","NRTL"}};doc.edit(state);
        doc.undo();QVERIFY(doc.state().value("objects").toArray().isEmpty());doc.redo();QCOMPARE(doc.state(),state);
        QTemporaryDir dir;QString error;QVERIFY2(doc.save(dir.filePath("case.afmp"),&error),qPrintable(error));
        ProjectDocument reopened;QVERIFY2(reopened.load(dir.filePath("case.afmp"),&error),qPrintable(error));QCOMPARE(reopened.state(),state);
        block["processInput"]=QJsonObject{{"version",2}};state["objects"]=QJsonArray{block};QVERIFY(!ProjectDocument::validate(state).isEmpty());
    }
};
QTEST_MAIN(ProcessInputTest)
#include "ProcessInputTest.moc"
