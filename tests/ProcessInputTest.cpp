#include "ProcessInput.h"
#include "ProjectDocument.h"
#include <QtTest>
#include <QTemporaryDir>

class ProcessInputTest : public QObject {
    Q_OBJECT
private slots:
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
