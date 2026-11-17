#include "ProcessInput.h"
#include "ProcessUnits.h"
#include "ProjectDocument.h"
#include <QtTest>
#include <QTemporaryDir>

class ProcessInputTest : public QObject {
    Q_OBJECT
private slots:
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
