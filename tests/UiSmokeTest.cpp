#include "ChemicalSystem.h"
#include "Flash2Fixture.h"
#include "ProcessInputWidget.h"
#include "ProcessGuidance.h"
#include "DatabaseFixture.h"
#include "UiShell.h"
#include "ProjectDocument.h"
#include "PropertyDatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTemporaryDir>
#include <QMessageBox>
#include "ComponentWorkspace.h"
#include "IconCatalog.h"
#include "LightTheme.h"
#include "RecoveredWorkspace.h"
#include "ObjectWorkspace.h"
#include <QContextMenuEvent>
#include <QGraphicsItem>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTableWidget>
#include <QApplication>
#include <QBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QMenu>
#include <QStackedWidget>
#include <QListWidget>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QJsonDocument>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QInputDialog>
#include <QScrollArea>
#include <QScrollBar>
#include <QSettings>
#include <QSlider>
#include <QGroupBox>
#include <QTabBar>
#include <QTabWidget>
#include <QTextEdit>
#include <QTimer>
#include <QTreeWidget>
#include <QTreeWidgetItemIterator>
#include <QtTest>

class UiSmokeTest : public QObject
{
    Q_OBJECT

private slots:
    void flash2PortsRejectInvalidEditsAndSurviveProjectOperations() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();shell.dispatch("flowsheet");
        auto *objects=shell.findChild<ObjectWorkspace *>();auto *canvas=objects->findChild<QGraphicsView *>("FlowsheetCanvas");
        const auto block=objects->createObject("blocks","B1","Flash2");objects->moveBlock(block,{200,150});
        objects->beginPlacement("streams","MATERIAL");objects->placeAt({50,150});objects->placeAt({160,150},block);
        const auto feed=objects->objects().last().toObject().value("key").toString();QCOMPARE(objects->object(feed).value("toPort").toString(),QString("FEED"));
        // Real canvas port hits convey direction and phase without relying on names.
        QTest::mouseClick(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,canvas->mapFromScene(QPointF(240,132)));
        objects->placeAt({450,80});const auto vapor=objects->objects().last().toObject().value("key").toString();
        QCOMPARE(objects->object(vapor).value("fromPort").toString(),QString("VAPOR"));
        const auto count=objects->objects().size();
        objects->placeAt({200,150},block);auto *choice=objects->findChild<QDialog *>("Flash2PortDialog");QVERIFY(choice);
        choice->findChild<QComboBox *>("Flash2PortChoice")->setCurrentIndex(1);QVERIFY(!choice->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->isEnabled());
        choice->reject();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);QCOMPARE(objects->objects().size(),count);
        objects->placeAt({200,150},block);choice=objects->findChild<QDialog *>("Flash2PortDialog");QVERIFY(choice);
        choice->findChild<QComboBox *>("Flash2PortChoice")->setCurrentIndex(2);choice->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();
        objects->placeAt({450,250});const auto liquid=objects->objects().last().toObject().value("key").toString();
        QCOMPARE(objects->object(liquid).value("fromPort").toString(),QString("LIQUID"));objects->beginPlacement({},{});
        const auto before=shell.project()->state();
        QVERIFY(!objects->connectStreamEndpoint(vapor,"from",block,"LIQUID",{240,168}));QCOMPARE(shell.project()->state(),before);
        QVERIFY(!objects->connectStreamEndpoint(vapor,"to",block,"FEED",{160,150}));QCOMPARE(shell.project()->state(),before);
        objects->beginPlacement("streams","HEAT");objects->placeAt({50,220});objects->placeAt({160,150},block);QCOMPARE(shell.project()->state(),before);objects->beginPlacement({},{});
        QVERIFY(objects->connectStreamEndpoint(vapor,"from","","",{400,80}));QVERIFY(!objects->object(vapor).contains("fromPort"));
        shell.project()->undo();QCOMPARE(objects->object(vapor).value("fromPort").toString(),QString("VAPOR"));
        shell.project()->redo();QVERIFY(!objects->object(vapor).contains("fromPort"));
        QVERIFY(objects->connectStreamEndpoint(vapor,"from",block,"VAPOR",{240,132}));
        objects->moveBlock(block,{250,180});QCOMPARE(objects->object(liquid).value("fromPort").toString(),QString("LIQUID"));
        QTemporaryDir dir;QString error;QVERIFY2(shell.saveProject(dir.filePath("ports.afmp"),&error),qPrintable(error));
        const auto saved=shell.project()->state();QVERIFY(shell.loadProject(dir.filePath("ports.afmp"),&error));QCOMPARE(shell.project()->state(),saved);
        objects->showFlowsheet();const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);QVERIFY(shell.grab().save(capture+"/flash2-ports.png"));}
        QVERIFY(objects->removeObject(block));QVERIFY(objects->object(vapor).value("from").toString().isEmpty());QVERIFY(!objects->object(vapor).contains("fromPort"));QVERIFY(!objects->object(feed).contains("toPort"));
        shell.project()->undo();QCOMPARE(objects->object(vapor).value("fromPort").toString(),QString("VAPOR"));
        objects->setFlowsheetLocked(true);QVERIFY(!objects->connectStreamEndpoint(vapor,"from","","",{400,80}));
    }
    void nextLocatesLegacyStreamNeedingPhaseAssignment() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto state=flash2Fixture();auto data=state.value("objects").toArray();auto vapor=data[2].toObject();vapor.remove("fromPort");
        vapor["startX"]=240;vapor["startY"]=100;vapor["endX"]=400;vapor["endY"]=100;data[2]=vapor;state["objects"]=data;
        shell.project()->edit(state);QTemporaryDir dir;QString error;QVERIFY(shell.project()->save(dir.filePath("legacy.afmp"),&error));QVERIFY(shell.loadProject(dir.filePath("legacy.afmp"),&error));
        shell.dispatch("next");auto *objects=shell.findChild<ObjectWorkspace *>();QCOMPARE(objects->selectedFlowsheetObject(),QString("V"));
        QVERIFY(!shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());
        QVERIFY(objects->connectStreamEndpoint("V","from","B","VAPOR",{240,100}));QVERIFY(shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());
        shell.project()->undo();QVERIFY(!shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());
    }
    void nextGuidesFlash2AndCommitsActiveComposition() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        shell.dispatch("next");QVERIFY(!shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());
        auto state=flash2Fixture();auto objectsData=state.value("objects").toArray();auto block=objectsData[0].toObject();block.remove("processInput");objectsData[0]=block;
        auto feed=objectsData[1].toObject();auto input=feed.value("processInput").toObject();input.remove("fractions");feed["processInput"]=input;objectsData[1]=feed;state["objects"]=objectsData;
        shell.project()->edit(state);QTemporaryDir dir;QString error;QVERIFY(shell.project()->save(dir.filePath("guided.afmp"),&error));QVERIFY(shell.loadProject(dir.filePath("guided.afmp"),&error));
        auto *objects=shell.findChild<ObjectWorkspace *>();shell.dispatch("object:B");shell.dispatch("next");QCoreApplication::processEvents();
        auto *tabs=objects->findChild<QTabWidget *>("ObjectDocuments");auto editor=[&](){return tabs->currentWidget()->findChild<ProcessInputWidget *>();};
        auto *temperature=editor()->findChild<QLineEdit *>("Process_temperature");QVERIFY(temperature->hasFocus());QTest::keyClicks(temperature,"185");shell.dispatch("next");
        QCOMPARE(objects->currentObject(),QString("B"));auto *pressure=editor()->findChild<QLineEdit *>("Process_pressure");QVERIFY(pressure->hasFocus());QTest::keyClicks(pressure,"14.7");shell.dispatch("quick-next");
        QCOMPARE(objects->currentObject(),QString("F"));auto *fractions=editor()->findChild<QTableWidget *>("ProcessFractions");QVERIFY(fractions);fractions->item(0,1)->setText("0.5");
        fractions->setCurrentCell(1,1);fractions->editItem(fractions->item(1,1));QCoreApplication::processEvents();auto *cell=fractions->findChild<QLineEdit *>();QVERIFY(cell);cell->setFocus();cell->setText("0.5");shell.dispatch("next");
        QVERIFY(shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());if(!qEnvironmentVariable("ASPEN_CAPTURE_DIR").isEmpty())QVERIFY(shell.grab().save(qEnvironmentVariable("ASPEN_CAPTURE_DIR")+"/flash2-input-complete.png"));auto *complete=shell.findChild<QMessageBox *>("ProcessInputComplete");QVERIFY(complete);complete->accept();QCoreApplication::processEvents();
        QVERIFY(shell.saveProject(dir.filePath("complete.afmp"),&error));QVERIFY(shell.loadProject(dir.filePath("complete.afmp"),&error));QVERIFY(shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());
        shell.dispatch("object:B");temperature=editor()->findChild<QLineEdit *>("Process_temperature");temperature->setFocus();temperature->setText("-500");shell.dispatch("next");QVERIFY(!shell.findChild<QLabel *>("Incomplete")->property("inputComplete").toBool());QCOMPARE(objects->currentObject(),QString("B"));
    }

    void processUnitsPreserveQuantityAndUndo() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        shell.dispatch("units:ENG");auto *objects=shell.findChild<ObjectWorkspace *>();const auto key=objects->createObject("blocks","B1","Flash2");shell.dispatch("object:"+key);QCoreApplication::processEvents();
        auto *temperature=objects->findChild<QTabWidget *>("ObjectDocuments")->currentWidget()->findChild<QLineEdit *>("Process_temperature");auto *unit=objects->findChild<QTabWidget *>("ObjectDocuments")->currentWidget()->findChild<QComboBox *>("ProcessUnit_temperature");QCOMPARE(unit->currentText(),QString("F"));
        temperature->setFocus();QTest::keyClicks(temperature,"185");shell.dispatch("units:SI");
        QVERIFY(qAbs(objects->object(key).value("processInput").toObject().value("temperature").toObject().value("text").toString().toDouble()-358.15)<1e-10);
        shell.project()->undo();QCOMPARE(objects->object(key).value("processInput").toObject().value("temperature").toObject().value("unit").toString(),QString("F"));
        shell.project()->redo();shell.dispatch("object:"+key);unit=objects->findChild<QTabWidget *>("ObjectDocuments")->currentWidget()->findChild<QComboBox *>("ProcessUnit_temperature");unit->setCurrentText("C");
        QVERIFY(qAbs(objects->object(key).value("processInput").toObject().value("temperature").toObject().value("text").toString().toDouble()-85)<1e-10);
        temperature=objects->findChild<QTabWidget *>("ObjectDocuments")->currentWidget()->findChild<QLineEdit *>("Process_temperature");temperature->setFocus();temperature->setText("bad");temperature->clearFocus();objects->commitProcessEditors();QCOMPARE(objects->object(key).value("processInput").toObject().value("temperature").toObject().value("text").toString(),QString("bad"));const auto before=shell.project()->state();shell.dispatch("units:ENG");QCOMPARE(shell.project()->state(),before);
    }

    void typedFlashFieldsSaveActiveEditor() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();const auto key=objects->createObject("blocks","B1","Flash2");shell.dispatch("object:"+key);QCoreApplication::processEvents();
        auto *temperature=objects->findChild<QLineEdit *>("Process_temperature");QVERIFY(temperature);temperature->setFocus();QTest::keyClicks(temperature,"358.15");
        QTemporaryDir dir;QString error;QVERIFY2(shell.saveProject(dir.filePath("typed.afmp"),&error),qPrintable(error));
        const auto data=objects->object(key).value("processInput").toObject();QCOMPARE(data.value("temperature").toObject().value("text").toString(),QString("358.15"));
        QVERIFY(shell.loadProject(dir.filePath("typed.afmp"),&error));QCOMPARE(objects->object(key).value("processInput").toObject(),data);
        shell.dispatch("methods");auto *method=shell.findChild<QComboBox *>("ProcessMethod");QVERIFY(method);method->setCurrentText("NRTL");
        QCOMPARE(shell.project()->state().value("process").toObject().value("method").toString(),QString("NRTL"));
        shell.project()->undo();QCOMPARE(shell.findChild<QComboBox *>("ProcessMethod")->currentText(),QString());shell.project()->redo();QCOMPARE(shell.findChild<QComboBox *>("ProcessMethod")->currentText(),QString("NRTL"));
    }

    void reconnectAndStreamAppearanceAreUndoable() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();shell.dispatch("flowsheet");
        auto *objects=shell.findChild<ObjectWorkspace *>();const auto a=objects->createObject("blocks","A","Mixer"),b=objects->createObject("blocks","B","Mixer");QVERIFY(!a.isEmpty() && !b.isEmpty());
        objects->beginPlacement("streams","MATERIAL");objects->placeAt({140,100},a);objects->placeAt({300,200},{});objects->beginPlacement({},{});
        QString stream;for(const auto &v:objects->objects())if(v.toObject().value("kind")=="streams")stream=v.toObject().value("key").toString();QVERIFY(!stream.isEmpty());
        objects->beginReconnection(stream,"to");objects->placeAt({300,200},b);QCOMPARE(objects->object(stream).value("to").toString(),b);
        shell.project()->undo();QVERIFY(objects->object(stream).value("to").toString().isEmpty());shell.project()->redo();QCOMPARE(objects->object(stream).value("to").toString(),b);
        objects->beginReconnection(stream,"from");objects->beginPlacement({},{});QCOMPARE(objects->object(stream).value("from").toString(),a);
        const auto beforeStyle=objects->object(stream);
        objects->showStreamAppearance(stream);auto *style=objects->findChild<QDialog *>("StreamAppearanceDialog");QVERIFY(style);
        style->findChild<QToolButton *>("StreamColor-2")->click();style->reject();QCOMPARE(objects->object(stream),beforeStyle);
        QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        objects->showStreamAppearance(stream);style=objects->findChild<QDialog *>("StreamAppearanceDialog");
        style->findChild<QToolButton *>("StreamColor-2")->click();style->findChild<QToolButton *>("StreamWidth-4")->click();style->findChild<QToolButton *>("StreamStyle-3")->click();
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);QVERIFY(style->grab().save(capture+"/stream-appearance.png"));}
        style->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();QCOMPARE(objects->object(stream).value("lineColor").toString(),QString("#ff0000"));
        shell.project()->undo();QCOMPARE(objects->object(stream),beforeStyle);
        objects->setStreamAppearance(stream,"lineWidth",4);objects->setStreamAppearance(stream,"lineStyle",3);objects->setStreamAppearance(stream,"lineColor","#ff0000");
        QCOMPARE(objects->object(stream).value("lineWidth").toInt(),4);shell.project()->undo();QVERIFY(!objects->object(stream).contains("lineColor"));shell.project()->redo();
        objects->setFlowsheetLocked(true);objects->beginReconnection(stream,"to");objects->placeAt({400,100},a);objects->setStreamAppearance(stream,"lineWidth",5);QCOMPARE(objects->object(stream).value("to").toString(),b);QCOMPARE(objects->object(stream).value("lineWidth").toInt(),4);
        QTemporaryDir temp;QString error;QVERIFY2(shell.saveProject(temp.filePath("flow.afmp"),&error),qPrintable(error));
        QVERIFY2(shell.loadProject(temp.filePath("flow.afmp"),&error),qPrintable(error));QCOMPARE(objects->object(stream).value("lineColor").toString(),QString("#ff0000"));QCOMPARE(objects->object(stream).value("lineStyle").toInt(),3);
    }

    void assistantsWriteBusinessDataAtConfirmedSteps() {
        QTemporaryDir temp;const auto db=databaseFixture(temp.path());QString error;
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));const auto catalog=QJsonDocument::fromJson(file.readAll()).object();UiShell shell(catalog);shell.show();
        QVERIFY(shell.openPropertyDatabase(db,&error));shell.dispatch("find-component");
        auto *search=shell.findChild<QDialog *>("FindCompoundDialog");search->findChild<QLineEdit *>("compound-query")->setText("WATER");search->findChild<QPushButton *>("SearchDatabase")->click();
        auto *results=search->findChild<QTableWidget *>("DatabaseResults");QVERIFY(results);QCOMPARE(results->rowCount(),1);QTest::qWait(20);results->clearSelection();QTest::mouseDClick(results->viewport(),Qt::LeftButton,Qt::NoModifier,results->visualItemRect(results->item(0,3)).center());QCOMPARE(shell.project()->state().value("components").toArray().size(),1);search->reject();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        shell.dispatch("component:specifications");auto *componentPage=shell.findChild<ComponentWorkspace *>();
        auto *type=componentPage->findChild<QComboBox *>("ComponentType-TEST-1");QVERIFY(type);type->setCurrentText("CONV");
        const auto original=shell.project()->state();
        shell.dispatch("electrolyte-wizard");auto *wizard=shell.findChild<QDialog *>("wizard-electrolyte");QVERIFY(wizard);
        auto *steps=wizard->findChild<QStackedWidget *>("WizardSteps");auto *next=wizard->findChild<QPushButton *>("WizardNext");
        next->click();QCOMPARE(steps->currentIndex(),1);QCOMPARE(steps->widget(1)->findChild<QListWidget *>("lstSelectedComp")->count(),1);
        next->click();QCOMPARE(steps->currentIndex(),1);QCOMPARE(shell.project()->state(),original);
        wizard->findChild<QCheckBox *>("chkWaterDissociation")->setChecked(true);next->click();QCOMPARE(steps->currentIndex(),2);
        QCOMPARE(wizard->findChild<QListWidget *>("lstAqueousSpecies")->count(),2);QCOMPARE(wizard->findChild<QListWidget *>("lstReactions")->count(),1);
        next->click();QCOMPARE(steps->currentIndex(),3);QCOMPARE(shell.project()->state(),original);
        QVERIFY(steps->widget(3)->findChild<QLineEdit *>("txtChemID")->isReadOnly());next->click();QCOMPARE(steps->currentIndex(),4);
        const auto committed=shell.project()->state();QVERIFY(committed!=original);QCOMPARE(committed.value("components"),original.value("components"));
        QCOMPARE(ChemicalSystem::globalChemistryId(committed),QString("GLOBAL"));QVERIFY(!wizard->findChild<QPushButton *>("WizardBack")->isEnabled());QVERIFY(!wizard->findChild<QPushButton *>("WizardCancel")->isEnabled());
        wizard->findChild<QPushButton *>("btnModifyAddRxns")->click();auto *review=wizard->findChild<QDialog *>("ChemistryReview");QVERIFY(review);QCOMPARE(review->findChild<QTableWidget *>("ChemistryRecords")->rowCount(),3);review->reject();
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);QVERIFY(wizard->grab().save(capture+"/electrolyte-committed.png"));}
        wizard->reject();QCOMPARE(shell.project()->state(),committed);QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        shell.project()->undo();QCOMPARE(shell.project()->state(),original);shell.project()->redo();QCOMPARE(shell.project()->state(),committed);
        const auto record=ChemicalSystem::chemistry(committed,"GLOBAL");shell.dispatch("object:"+record.value("key").toString());
        auto *objects=shell.findChild<ObjectWorkspace *>();QVERIFY(objects->findChild<QWidget *>("ChemicalSystemView"));
        shell.dispatch("units:SI");QCOMPARE(ChemicalSystem::chemistry(shell.project()->state(),"GLOBAL"),record);
        const auto path=temp.filePath("assistants.afmp");QVERIFY2(shell.saveProject(path,&error),qPrintable(error));
        UiShell reopened(catalog);QVERIFY2(reopened.loadProject(path,&error),qPrintable(error));QCOMPARE(reopened.project()->state(),shell.project()->state());
        reopened.dispatch("object:"+record.value("key").toString());QCOMPARE(reopened.findChild<QTableWidget *>("ChemistryRecords")->rowCount(),3);
        // SFE submits only on Finish, preserves input identity and rebuilds names on re-entry.
        shell.dispatch("sfe-assistant");wizard=shell.findChild<QDialog *>("wizard-sfe");steps=wizard->findChild<QStackedWidget *>("WizardSteps");next=wizard->findChild<QPushButton *>("WizardNext");
        const auto beforeSfe=shell.project()->state();QVERIFY(next->isEnabled());next->click();QCOMPARE(steps->currentIndex(),0);
        steps->widget(0)->findChild<QPushButton *>("btnMoveAll")->click();next->click();QCOMPARE(steps->currentIndex(),1);
        auto *solids=wizard->findChild<QTableWidget *>("grdSolidComponent");QCOMPARE(solids->rowCount(),1);QCOMPARE(solids->item(0,1)->text(),QString("H2O(S)"));
        solids->item(0,1)->setText("ICE");wizard->findChild<QPushButton *>("WizardBack")->click();next->click();QCOMPARE(solids->item(0,1)->text(),QString("H2O(S)"));QCOMPARE(shell.project()->state(),beforeSfe);
        wizard->findChild<QRadioButton *>("radioExistChemistry")->setChecked(true);QVERIFY(wizard->findChild<QLineEdit *>("txtChemName")->text().isEmpty());QVERIFY(!wizard->findChild<QCheckBox *>("globalChecked")->isEnabled());
        wizard->findChild<QRadioButton *>("radioNewChemistry")->setChecked(true);wizard->findChild<QLineEdit *>("txtChemName")->setText("C-1");
        solids->item(0,1)->setText("");wizard->findChild<QPushButton *>("WizardFinish")->click();QCOMPARE(shell.project()->state(),beforeSfe);
        solids->item(0,1)->setText("H2O(S)");if(!capture.isEmpty())QVERIFY(wizard->grab().save(capture+"/sfe-before-finish.png"));
        solids->editItem(solids->item(0,1));QCoreApplication::processEvents();auto *active=solids->findChild<QLineEdit *>();QVERIFY(active);
        active->selectAll();QTest::keyClicks(active,"ICE");
        wizard->findChild<QPushButton *>("WizardFinish")->click();QVERIFY(!ChemicalSystem::chemistry(shell.project()->state(),"C-1").isEmpty());
        QCOMPARE(shell.project()->state().value("chemicalSystem").toObject().value("generatedComponents").toArray().size(),3);
        QCOMPARE(shell.project()->state().value("chemicalSystem").toObject().value("generatedComponents").toArray().last().toObject().value("id").toString(),QString("ICE"));
        QVERIFY2(shell.saveProject(path,&error),qPrintable(error));QVERIFY(reopened.loadProject(path,&error));QCOMPARE(reopened.project()->state(),shell.project()->state());
        shell.project()->undo();QCOMPARE(shell.project()->state(),beforeSfe);
    }

    void electrolyteExclusionEarlyFinishAndCollisionCancel() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto state=ProjectDocument::emptyState();state["dependencies"]=QJsonObject{{"propertyDatabase","synthetic"}};
        state["components"]=QJsonArray{QJsonObject{{"database","TEST"},{"compoundId","1"},{"datasetId","synthetic"},{"name","WATER"},{"alias","H2O"},{"cas","7732-18-5"}}};shell.project()->edit(state);
        const auto start=[&]() {
            shell.dispatch("electrolyte-wizard");auto *w=shell.findChild<QDialog *>("wizard-electrolyte");w->findChild<QPushButton *>("WizardNext")->click();w->findChild<QCheckBox *>("chkWaterDissociation")->setChecked(true);w->findChild<QPushButton *>("WizardNext")->click();return w;
        };
        auto *wizard=start();auto *steps=wizard->findChild<QStackedWidget *>("WizardSteps");
        wizard->findChild<QListWidget *>("lstAqueousSpecies")->setCurrentRow(0);steps->widget(2)->findChild<QPushButton *>("btnRemove")->click();
        QVERIFY(!wizard->findChild<QPushButton *>("WizardNext")->isEnabled());QCOMPARE(wizard->findChild<QListWidget *>("lstReactions")->count(),0);QCOMPARE(shell.project()->state(),state);
        wizard->findChild<QPushButton *>("WizardBack")->click();wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(wizard->findChild<QListWidget *>("lstReactions")->count(),1);
        wizard->findChild<QRadioButton *>("radioGenChemHenry")->setChecked(true);QVERIFY(wizard->findChild<QCheckBox *>("chkGenHenryChem")->isChecked());
        wizard->findChild<QCheckBox *>("chkGenHenryChem")->setChecked(false);QVERIFY(wizard->findChild<QPushButton *>("WizardFinish")->isEnabled());QVERIFY(!wizard->findChild<QPushButton *>("WizardNext")->isEnabled());
        wizard->findChild<QPushButton *>("WizardFinish")->click();QVERIFY(shell.project()->state().value("objects").toArray().isEmpty());QCOMPARE(shell.project()->state().value("chemicalSystem").toObject().value("generatedComponents").toArray().size(),2);
        shell.project()->undo();QCOMPARE(shell.project()->state(),state);QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        auto *objects=shell.findChild<ObjectWorkspace *>();QVERIFY(!objects->createObject("chemistry","GLOBAL","Chemistry").isEmpty());const auto withExisting=shell.project()->state();wizard=start();steps=wizard->findChild<QStackedWidget *>("WizardSteps");
        QTimer::singleShot(0,[&]{auto *box=qobject_cast<QMessageBox *>(QApplication::activeModalWidget());QVERIFY(box);box->button(QMessageBox::Cancel)->click();});
        wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(steps->currentIndex(),2);QCOMPARE(shell.project()->state(),withExisting);wizard->reject();
        QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        // Explicitly unverified H+ cannot reach a commit.
        wizard=start();wizard->findChild<QPushButton *>("WizardBack")->click();wizard->findChild<QRadioButton *>("radioHydrogenIon")->setChecked(true);wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(wizard->findChild<QStackedWidget *>("WizardSteps")->currentIndex(),1);QCOMPARE(shell.project()->state(),withExisting);wizard->reject();
    }

    void componentOrderKeepsEqualAliasesDistinct() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());
        auto state=ProjectDocument::emptyState();state["dependencies"]=QJsonObject{{"propertyDatabase","synthetic"}};
        QJsonArray components;for(const auto *id:{"first","second"})components.append(QJsonObject{{"database","TEST"},{"compoundId",id},{"datasetId","synthetic"},{"name","SAME"},{"alias","SAME"}});state["components"]=components;shell.project()->edit(state);
        shell.dispatch("reorder");auto *order=shell.findChild<QDialog *>("dialog-ReorderComp");QVERIFY(order);auto *list=order->findChild<QListWidget *>("lvSelectedComps");list->setCurrentRow(1);order->findChild<QPushButton *>("btnUp")->click();
        order->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();QCOMPARE(shell.project()->state().value("components").toArray()[0].toObject().value("compoundId").toString(),QString("second"));shell.project()->undo();QCOMPARE(shell.project()->state(),state);
    }

    void componentRecordEntryPointsAndUnifiedMultiSelection() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();const auto user=objects->createObject("user-components","CUSTOM","CONVENTIONAL");QVERIFY(!user.isEmpty());
        auto state=shell.project()->state();state["dependencies"]=QJsonObject{{"propertyDatabase","synthetic"}};
        state["components"]=QJsonArray{QJsonObject{{"database","TEST"},{"compoundId","1"},{"datasetId","synthetic"},{"name","WATER"},{"alias","WATER"},{"componentId","WATER"},{"cas","7732-18-5"},{"componentType","CONV"}}};
        auto result=ChemicalSystem::applySfe(state,QJsonArray{QJsonObject{{"fluid","db:TEST:1"},{"solidId","WATER(S)"}}},"C-1",false,true);QVERIFY2(result,qPrintable(result.error));
        shell.project()->edit(result.state);QTemporaryDir setup;QString setupError;
        QVERIFY(shell.project()->save(setup.filePath("initial.afmp"),&setupError));QVERIFY(shell.loadProject(setup.filePath("initial.afmp"),&setupError));
        shell.dispatch("component:specifications");auto *workspace=shell.findChild<ComponentWorkspace *>();auto *table=workspace->findChild<QTableWidget *>("ProjectComponents");
        const auto before=shell.project()->state();QCOMPARE(table->rowCount(),4);table->setCurrentCell(1,0);
        auto *title=workspace->findChild<QLabel *>("ComponentSelectionTitle");QVERIFY(title);QTest::mouseDClick(title,Qt::LeftButton);
        QTRY_VERIFY(shell.findChild<QDialog *>("FindCompoundDialog"));shell.findChild<QDialog *>("FindCompoundDialog")->reject();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        const auto point=table->visualItemRect(table->item(1,0)).center();
        QVERIFY(QMetaObject::invokeMethod(table,"customContextMenuRequested",Qt::DirectConnection,Q_ARG(QPoint,point)));
        auto *menu=table->findChild<QMenu *>("ComponentContextMenu");QVERIFY(menu);menu->actions().first()->trigger();menu->close();
        QTRY_VERIFY(shell.findChild<QDialog *>("dialog-ReorderComp"));auto *dialog=shell.findChild<QDialog *>("dialog-ReorderComp");
        auto *list=dialog->findChild<QListWidget *>("lvSelectedComps");QCOMPARE(list->count(),3);QCOMPARE(list->currentRow(),1);
        list->item(2)->setSelected(true);dialog->findChild<QPushButton *>("btnUp")->click();
        QCOMPARE(list->item(0)->data(Qt::UserRole).toString(),"object:"+user);QVERIFY(list->item(0)->isSelected());QVERIFY(list->item(1)->isSelected());
        QVERIFY(!dialog->findChild<QPushButton *>("btnUp")->isEnabled());
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);QVERIFY(dialog->grab().save(capture+"/component-order.png"));}
        dialog->reject();QCOMPARE(shell.project()->state(),before);QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        shell.dispatch("reorder");dialog=shell.findChild<QDialog *>("dialog-ReorderComp");list=dialog->findChild<QListWidget *>("lvSelectedComps");
        list->clearSelection();list->item(1)->setSelected(true);list->item(2)->setSelected(true);dialog->findChild<QPushButton *>("btnUp")->click();
        dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();
        const auto committed=shell.project()->state();QCOMPARE(table->item(0,0)->text(),QString("CUSTOM"));QCOMPARE(table->item(1,0)->text(),QString("WATER(S)"));
        shell.project()->undo();QCOMPARE(shell.project()->state(),before);shell.project()->redo();QCOMPARE(shell.project()->state(),committed);
        QTemporaryDir dir;QString error;QVERIFY(shell.saveProject(dir.filePath("mixed.afmp"),&error));QVERIFY(shell.loadProject(dir.filePath("mixed.afmp"),&error));
        QCOMPARE(table->item(0,0)->text(),QString("CUSTOM"));QCOMPARE(table->item(1,0)->text(),QString("WATER(S)"));
        QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);shell.dispatch("reorder");dialog=shell.findChild<QDialog *>("dialog-ReorderComp");
        QVERIFY(objects->renameObject(user,"RENAMED"));const auto renamed=shell.project()->state();
        dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();QVERIFY(dialog->isVisible());QCOMPARE(shell.project()->state(),renamed);
        QVERIFY(!dialog->findChild<QLabel *>("ComponentOrderStatus")->text().isEmpty());dialog->reject();
        QCOMPARE(table->item(0,0)->text(),QString("RENAMED"));
        if(!capture.isEmpty())QVERIFY(shell.grab().save(capture+"/component-records.png"));
    }

    void navigationCommitsActiveEditorsBeforeReplacingViews() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();const auto flash=objects->createObject("blocks","FLASH","Flash2");QVERIFY(!flash.isEmpty());
        shell.dispatch("object:"+flash);auto *tabs=objects->findChild<QTabWidget *>("ObjectDocuments");
        auto *temperature=tabs->currentWidget()->findChild<QLineEdit *>("Process_temperature");QVERIFY(temperature);
        temperature->setFocus();temperature->setText("330");shell.dispatch("methods");
        QCOMPARE(objects->object(flash).value("processInput").toObject().value("temperature").toObject().value("text").toString(),QString("330"));
        shell.dispatch("object:"+flash);temperature=tabs->currentWidget()->findChild<QLineEdit *>("Process_temperature");
        temperature->setFocus();temperature->setText("335");QVERIFY(objects->openObject(flash));
        QCOMPARE(tabs->currentWidget()->findChild<QLineEdit *>("Process_temperature")->text(),QString("335"));
        const auto property=objects->createObject("property-sets","EDIT","PropertySet");shell.dispatch("object:"+property);
        auto *view=qobject_cast<RecoveredWorkspace *>(tabs->currentWidget());QVERIFY(view);const auto first=view->currentPage();
        auto *grid=view->findChild<QTableWidget *>("grdSelection");QVERIFY(grid);grid->setItem(0,0,new QTableWidgetItem("OLD"));grid->setCurrentCell(0,0);grid->editItem(grid->item(0,0));QCoreApplication::processEvents();
        auto *editor=grid->findChild<QLineEdit *>();QVERIFY(editor);editor->setFocus();editor->setText("COMMITTED ON NAVIGATION");
        QVERIFY(view->showPage(view->idForName("MMProp_Spec_Input")));QVERIFY(view->showPage(first));
        QCOMPARE(view->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("COMMITTED ON NAVIGATION"));
        grid=view->findChild<QTableWidget *>("grdSelection");grid->setCurrentCell(0,0);grid->editItem(grid->item(0,0));QCoreApplication::processEvents();
        editor=grid->findChild<QLineEdit *>();QVERIFY(editor);editor->setFocus();editor->setText("BEFORE DIALOG");shell.dispatch("database-search");
        QCOMPARE(grid->item(0,0)->text(),QString("BEFORE DIALOG"));auto *dialog=shell.findChild<QDialog *>("FindCompoundDialog");QVERIFY(dialog);dialog->reject();
        QTemporaryDir dir;QString error;QVERIFY(shell.saveProject(dir.filePath("navigation.afmp"),&error));QVERIFY(shell.loadProject(dir.filePath("navigation.afmp"),&error));
        QVERIFY(objects->openObject(property));view=qobject_cast<RecoveredWorkspace *>(tabs->currentWidget());QCOMPARE(view->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("BEFORE DIALOG"));
        QCOMPARE(objects->object(flash).value("processInput").toObject().value("temperature").toObject().value("text").toString(),QString("335"));
    }

    void wizardReferenceStateLocalIdsAndStaleProject() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        shell.dispatch("electrolyte-wizard");auto *wizard=shell.findChild<QDialog *>("wizard-electrolyte");wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(wizard->findChild<QStackedWidget *>("WizardSteps")->currentIndex(),0);wizard->reject();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        auto state=ProjectDocument::emptyState();state["dependencies"]=QJsonObject{{"propertyDatabase","synthetic"}};
        state["components"]=QJsonArray{QJsonObject{{"database","TEST"},{"compoundId","1"},{"datasetId","synthetic"},{"name","WATER"},{"alias","H2O"},{"cas","7732-18-5"},{"componentType","CONV"}}};shell.project()->edit(state);
        shell.dispatch("electrolyte-wizard");wizard=shell.findChild<QDialog *>("wizard-electrolyte");auto *steps=wizard->findChild<QStackedWidget *>("WizardSteps");
        wizard->findChild<QComboBox *>("cboRefStateSelect")->setCurrentIndex(1);wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(steps->widget(1)->findChild<QListWidget *>("lstSelectedComp")->count(),0);
        steps->widget(1)->findChild<QPushButton *>("btnMoveAll")->click();wizard->findChild<QCheckBox *>("chkWaterDissociation")->setChecked(true);wizard->findChild<QPushButton *>("WizardNext")->click();
        auto *method=wizard->findChild<QComboBox *>("cboOptSet");QCOMPARE(method->count(),1);QCOMPARE(method->currentText(),QString("ENRTL-SR"));
        wizard->findChild<QRadioButton *>("radioGenChemHenry")->setChecked(true);
        QTimer::singleShot(0,[&]{auto *input=qobject_cast<QInputDialog *>(QApplication::activeModalWidget());QVERIFY(input);input->setTextValue("LOCAL");input->accept();});
        wizard->findChild<QPushButton *>("WizardNext")->click();QCOMPARE(steps->currentIndex(),3);QVERIFY(!wizard->findChild<QRadioButton *>("radioTrueComponent")->isEnabled());
        QCOMPARE(steps->widget(3)->findChild<QLineEdit *>("txtChemID")->text(),QString("LOCAL"));QCOMPARE(shell.project()->state(),state);
        wizard->findChild<QPushButton *>("WizardNext")->click();const auto local=shell.project()->state();QVERIFY(!ChemicalSystem::chemistry(local,"LOCAL").isEmpty());QVERIFY(ChemicalSystem::globalChemistryId(local).isEmpty());
        wizard->findChild<QPushButton *>("WizardFinish")->click();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        shell.dispatch("sfe-assistant");wizard=shell.findChild<QDialog *>("wizard-sfe");steps=wizard->findChild<QStackedWidget *>("WizardSteps");steps->widget(0)->findChild<QPushButton *>("btnMoveAll")->click();wizard->findChild<QPushButton *>("WizardNext")->click();
        auto changed=local;changed["units"]="SI";shell.project()->edit(changed);wizard->findChild<QPushButton *>("WizardFinish")->click();QCOMPARE(shell.project()->state(),changed);QVERIFY(wizard->isVisible());
        QTest::keyClick(wizard,Qt::Key_Escape);QCOMPARE(shell.project()->state(),changed);
    }

    void recoveredMenusKeepEveryLevel() {
        RecoveredWorkspace workspace;const auto menus=workspace.menuCatalog();
        for(int i=0;i<menus.size();++i) {
            QVERIFY(workspace.showPage("menu:"+QString::number(i)));
            std::function<void(const QJsonArray &)> check=[&](const QJsonArray &items){for(const auto &v:items){const auto e=v.toObject();const bool separator=e.contains("separator")?e.value("separator").toBool():e.value("text").toString().isEmpty() && !e.contains("items");
                if(!separator){auto *action=workspace.findChild<QAction *>("RecoveredMenuItem-"+QString::number(e.value("id").toInt()));
                    // Top-level submenus are represented by their toolbar button.
                    if(!e.contains("items")){QVERIFY(action);QVERIFY(!action->isSeparator());}}
                check(e.value("items").toArray());}};check(menus[i].toObject().value("items").toArray());
        }
    }

    void databaseInteractionParity() {
        QTemporaryDir temp;const auto path=databaseFixture(temp.path());QVERIFY(!path.isEmpty());
        {
            auto db=QSqlDatabase::addDatabase("QSQLITE","parity-fixture");db.setDatabaseName(path);QVERIFY(db.open());QSqlQuery q(db);
            for(const auto &sql:{
                "INSERT INTO compounds VALUES ('TEST','2','TEST-ETHANOL','ETHANOL','64-17-5')",
                "INSERT INTO identifiers VALUES ('TEST','2','NAME','TEST-ETHANOL'),('TEST','2','ALIAS','ETHANOL')",
                "INSERT INTO parameters VALUES ('TEST',8,'2',3)",
                "INSERT INTO refs VALUES ('TEST',12,8,10)",
                "INSERT INTO databanks VALUES ('TEST',10,'SECOND')"})QVERIFY2(q.exec(sql),qPrintable(q.lastError().text()));
        }
        QSqlDatabase::removeDatabase("parity-fixture");
        PropertyDatabase database;QString error;QVERIFY(database.open(path,&error));
        PropertyDatabase::SearchOptions options;options.mode=PropertyDatabase::MatchMode::StartsWith;
        QCOMPARE(database.search("WATER",&error,options).size(),0);QCOMPARE(database.search("test-w",&error,options).size(),1);
        options.mode=PropertyDatabase::MatchMode::Equals;QCOMPARE(database.search("TEST-W",&error,options).size(),0);QCOMPARE(database.search("h2o",&error,options).size(),1);QCOMPARE(database.search("A%_literal",&error,options).size(),1);
        const QJsonObject firstBank{{"database","TEST"},{"bankId",9}},secondBank{{"database","TEST"},{"bankId",10}};
        options.mode=PropertyDatabase::MatchMode::Contains;options.databanks={firstBank,secondBank};options.restrictDatabanks=true;
        auto matches=database.search("TEST-",&error,options);QVERIFY2(error.isEmpty(),qPrintable(error));QCOMPARE(matches.size(),2);QCOMPARE(matches[0].toObject().value("compoundId").toString(),QString("1"));
        options.databanks={secondBank,firstBank};matches=database.search("TEST-",&error,options);QCOMPARE(matches[0].toObject().value("compoundId").toString(),QString("2"));
        options.databanks={firstBank};QCOMPARE(database.search("ETHANOL",&error,options).size(),0);QCOMPARE(database.search("WATER",&error,options).size(),1);
        options.databanks={};QCOMPARE(database.search("WATER",&error,options).size(),0);

        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();QVERIFY(shell.openPropertyDatabase(path,&error));shell.dispatch("database-search");
        auto *dialog=shell.findChild<QDialog *>("FindCompoundDialog");QVERIFY(dialog);QTest::qWait(30);
        auto *query=dialog->findChild<QLineEdit *>("compound-query");auto *results=dialog->findChild<QTableWidget *>("DatabaseResults");auto *add=dialog->findChild<QPushButton *>("AddDatabaseComponent");auto *tabs=dialog->findChild<QTabWidget *>("FindCompoundTabs");
        QVERIFY(query && results && add && tabs);QCOMPARE(results->columnCount(),8);QVERIFY(!add->isEnabled());QCOMPARE(tabs->count(),3);QVERIFY(!tabs->isTabEnabled(2));
        query->setText("7732-18-5");query->setFocus();QTest::keyClick(query,Qt::Key_Return);QCOMPARE(results->rowCount(),1);QVERIFY(add->isEnabled());
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);QVERIFY(dialog->grab().save(capture+"/compound-search-parity.png"));}
        dialog->findChild<QPushButton *>("ShowDatabaseParameters")->click();auto *details=dialog->findChild<QDialog *>("DatabaseParameterDialog");QVERIFY(details->isVisible());auto *parameters=details->findChild<QTableWidget *>("DatabaseParameters");QCOMPARE(parameters->rowCount(),1);parameters->selectRow(0);QVERIFY(details->findChild<QTextEdit *>("ParameterProvenance")->toPlainText().contains("123.456789012345678901"));
        if(!capture.isEmpty())QVERIFY(details->grab().save(capture+"/compound-parameters-parity.png"));QTest::keyClick(details,Qt::Key_Escape);QVERIFY(!details->isVisible());QVERIFY(dialog->isVisible());
        results->setFocus();QTest::keyClick(results,Qt::Key_Return);QCOMPARE(shell.project()->state().value("components").toArray().size(),1);QVERIFY(!add->isEnabled());
        query->setText("no-such-component");QCOMPARE(parameters->rowCount(),0);QVERIFY(details->findChild<QTextEdit *>("ParameterProvenance")->toPlainText().isEmpty());QCOMPARE(results->rowCount(),0);QVERIFY(!add->isEnabled());QVERIFY(!dialog->findChild<QPushButton *>("ShowDatabaseParameters")->isEnabled());
        dialog->findChild<QPushButton *>("NewDatabaseSearch")->click();QVERIFY(query->text().isEmpty());QVERIFY(query->hasFocus());
        dialog->findChild<QPushButton *>("ManageDatabaseComponents")->click();auto *selection=dialog->findChild<QDialog *>("DatabaseSelectionDialog");QVERIFY(selection->isVisible());auto *selected=selection->findChild<QListWidget *>("SelectedDatabaseComponents");auto *remove=selection->findChild<QPushButton *>("RemoveDatabaseComponent");QVERIFY(!remove->isEnabled());selected->setCurrentRow(0);QVERIFY(remove->isEnabled());QTest::keyClick(selected,Qt::Key_Delete);QCOMPARE(shell.project()->state().value("components").toArray().size(),0);QVERIFY(!remove->isEnabled());selection->reject();
        const int compoundWidth=dialog->width();tabs->setCurrentIndex(1);QVERIFY(dialog->width()<compoundWidth);QVERIFY(dialog->width()>=dialog->minimumSizeHint().width());QVERIFY(!dialog->findChild<QPushButton *>("FindAddDatabank")->isEnabled());if(!capture.isEmpty())QVERIFY(dialog->grab().save(capture+"/compound-databanks-parity.png"));
        dialog->findChild<QPushButton *>("FindRemoveAllDatabanks")->click();QCOMPARE(dialog->findChild<QListWidget *>("FindSelectedDatabanks")->count(),0);
        tabs->setCurrentIndex(0);QCOMPARE(dialog->width(),compoundWidth);query->setText("WATER");dialog->findChild<QPushButton *>("SearchDatabase")->click();QCOMPARE(results->rowCount(),0);
        tabs->setCurrentIndex(1);dialog->findChild<QPushButton *>("FindAddAllDatabanks")->click();tabs->setCurrentIndex(0);dialog->findChild<QPushButton *>("SearchDatabase")->click();QCOMPARE(results->rowCount(),1);
        QTest::qWait(20);const auto resultPoint=results->visualItemRect(results->item(0,0)).center();
        QTest::mouseClick(results->viewport(),Qt::LeftButton,Qt::NoModifier,resultPoint);
        QTest::mouseDClick(results->viewport(),Qt::LeftButton,Qt::NoModifier,resultPoint);QCOMPARE(shell.project()->state().value("components").toArray().size(),1);
        QTest::keyClick(dialog,Qt::Key_Escape);QVERIFY(!dialog->isVisible());
    }

    void flowsheetGroupDragIsOneUndoStep()
    {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();auto *document=shell.findChild<ProjectDocument *>();
        const auto first=objects->createObject("blocks","M1","Mixer"),second=objects->createObject("blocks","M2","Mixer");
        shell.dispatch("flowsheet");QTest::qWait(30);objects->setFlowsheetZoom(100);
        auto *canvas=objects->findChild<QGraphicsView *>("FlowsheetCanvas");canvas->setFocus();
        QTest::keySequence(canvas,QKeySequence::SelectAll);QCOMPARE(canvas->scene()->selectedItems().size(),2);
        QSignalSpy mutations(objects,&ObjectWorkspace::objectsChanged),selection(objects,&ObjectWorkspace::flowsheetSelectionChanged);
        const auto from=canvas->mapFromScene(QPointF(100,100)),to=canvas->mapFromScene(QPointF(140,130));
        QTest::mousePress(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,from);
        QTest::mouseMove(canvas->viewport(),to,30);QTest::mouseRelease(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,to);
        QCOMPARE(objects->object(first).value("x").toInt(),140);QCOMPARE(objects->object(second).value("x").toInt(),270);
        QCOMPARE(mutations.count(),1);QCOMPARE(canvas->scene()->selectedItems().size(),2);
        document->undo();QCOMPARE(objects->object(first).value("x").toInt(),100);QCOMPARE(objects->object(second).value("x").toInt(),230);
        QVERIFY(selection.count()>0);QCOMPARE(canvas->scene()->selectedItems().size(),2);
        // Undoing a deletion must notify ribbon listeners even though restoration itself is blocked.
        objects->removeObject(first);selection.clear();document->undo();QVERIFY(selection.count()>0);QVERIFY(!objects->object(first).isEmpty());
    }

    void flowsheetContextMenusAndKeyboard()
    {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();auto *document=shell.findChild<ProjectDocument *>();
        const auto first=objects->createObject("blocks","M1","Mixer");
        const auto second=objects->createObject("blocks","M2","Mixer");
        shell.dispatch("flowsheet");QTest::qWait(30);
        auto *canvas=objects->findChild<QGraphicsView *>("FlowsheetCanvas");objects->setFlowsheetZoom(100);
        const auto at=canvas->mapFromScene(QPointF(100,100));
        auto context=[&](QPoint point) {
            QContextMenuEvent event(QContextMenuEvent::Mouse,point,canvas->viewport()->mapToGlobal(point));
            QCoreApplication::sendEvent(canvas->viewport(),&event);
            return objects->findChild<QMenu *>("FlowsheetContextMenu");
        };
        auto dismiss=[](QMenu *menu){menu->close();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);};
        const auto before=document->state();QSignalSpy mutations(objects,&ObjectWorkspace::objectsChanged);
        QTest::mouseClick(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,at);
        QCOMPARE(document->state(),before);QCOMPARE(mutations.count(),0);QCOMPARE(objects->selectedFlowsheetObject(),first);
        auto *menu=context(at);QVERIFY(menu);QVERIFY(menu->isVisible());
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);shell.grab().save(capture+"/flowsheet-device-selected.png");menu->grab().save(capture+"/flowsheet-device-menu.png");}
        QCOMPARE(objects->selectedFlowsheetObject(),first);QVERIFY(menu->findChild<QAction *>("FlowInput")->isEnabled());
        auto *rotate=menu->findChild<QAction *>("FlowTransform-rotate");QVERIFY(rotate);rotate->trigger();dismiss(menu);
        QCOMPARE(objects->object(first).value("iconRotation").toInt(),90);QCOMPARE(objects->selectedFlowsheetObject(),first);
        QTest::keySequence(canvas,QKeySequence::Undo);
        QCOMPARE(objects->object(first).value("iconRotation").toInt(),0);QCOMPARE(objects->selectedFlowsheetObject(),first);
        QTest::keyClick(canvas,Qt::Key_F2);
        auto *rename=objects->findChild<QDialog *>("ObjectNameDialog");QVERIFY(rename);rename->findChild<QLineEdit *>("ObjectId")->setText("RENAMED");
        rename->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        QCOMPARE(objects->object(first).value("name").toString(),QString("RENAMED"));
        // The label must resolve to the same owner as its icon.
        menu=context(canvas->mapFromScene(QPointF(100,139)));QVERIFY(menu);QCOMPARE(objects->selectedFlowsheetObject(),first);dismiss(menu);
        canvas->setFocus();QTest::keyClick(canvas,Qt::Key_Menu);menu=objects->findChild<QMenu *>("FlowsheetContextMenu");QVERIFY(menu);dismiss(menu);
        QTest::keySequence(canvas,QKeySequence::SelectAll);QCOMPARE(canvas->scene()->selectedItems().size(),2);
        menu=context(at);QVERIFY(menu);QCOMPARE(canvas->scene()->selectedItems().size(),2);
        QVERIFY(!menu->findChild<QAction *>("FlowCopy")->isEnabled());QVERIFY(!menu->findChild<QAction *>("FlowCut")->isEnabled());dismiss(menu);
        QTest::keyClick(canvas,Qt::Key_Delete);auto *deletion=objects->findChild<QDialog *>("ObjectDeleteDialog");QVERIFY(deletion);
        deletion->reject();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);QCOMPARE(objects->objects().size(),2);
        objects->setFlowsheetLocked(true);menu=context(canvas->mapFromScene(QPointF(230,100)));QVERIFY(menu);
        QVERIFY(!menu->findChild<QAction *>("FlowDelete")->isEnabled());QVERIFY(!menu->findChild<QAction *>("FlowRename")->isEnabled());dismiss(menu);
        QTest::keyClick(canvas,Qt::Key_Delete);QVERIFY(!objects->findChild<QDialog *>("ObjectDeleteDialog"));
        QTest::keyClick(canvas,Qt::Key_Escape);QVERIFY(canvas->scene()->selectedItems().isEmpty());
        QVERIFY(!objects->object(second).isEmpty());
        QTemporaryDir temp;QString error;QVERIFY2(shell.saveProject(temp.filePath("menus.afmp"),&error),qPrintable(error));
    }

    void flowsheetStreamHitTargetsAndCancel()
    {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();shell.dispatch("flowsheet");QTest::qWait(30);
        auto *objects=shell.findChild<ObjectWorkspace *>();auto *canvas=objects->findChild<QGraphicsView *>("FlowsheetCanvas");objects->setFlowsheetZoom(100);
        objects->beginPlacement("streams","MATERIAL");objects->placeAt({200,200});
        const auto blank=canvas->mapFromScene(QPointF(550,180));
        QTest::mouseClick(canvas->viewport(),Qt::RightButton,Qt::NoModifier,blank);
        QContextMenuEvent canceled(QContextMenuEvent::Mouse,blank,canvas->viewport()->mapToGlobal(blank));QCoreApplication::sendEvent(canvas->viewport(),&canceled);
        QCOMPARE(objects->objects().size(),0);QVERIFY(!objects->findChild<QMenu *>("FlowsheetContextMenu"));
        QVERIFY(objects->findChild<QPushButton *>("FlowSelect")->isChecked());QCOMPARE(canvas->cursor().shape(),Qt::ArrowCursor);
        objects->beginPlacement("blocks","Mixer");QTest::keyClick(canvas,Qt::Key_Escape);QCOMPARE(canvas->cursor().shape(),Qt::ArrowCursor);
        objects->beginPlacement("streams","MATERIAL");auto *notice=objects->findChild<QLabel *>("FlowPlacementNotice");QVERIFY(notice);
        const auto startHint=notice->text();objects->placeAt({220,200});QVERIFY(notice->text()!=startHint);
        objects->placeAt({500,280});QCOMPARE(notice->text(),startHint);objects->beginPlacement({},{});
        const auto stream=objects->objects().last().toObject().value("key").toString();
        auto context=[&](QPoint point) {
            QContextMenuEvent event(QContextMenuEvent::Mouse,point,canvas->viewport()->mapToGlobal(point));QCoreApplication::sendEvent(canvas->viewport(),&event);
            return objects->findChild<QMenu *>("FlowsheetContextMenu");
        };
        auto dismiss=[](QMenu *menu){menu->close();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);};
        auto *menu=context(canvas->mapFromScene(QPointF(280,204)));QVERIFY(menu);QCOMPARE(objects->selectedFlowsheetObject(),stream);
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()){QDir().mkpath(capture);shell.grab().save(capture+"/flowsheet-stream-selected.png");menu->grab().save(capture+"/flowsheet-stream-menu.png");}
        QCOMPARE(menu->findChild<QAction *>("FlowRename")->text(),QString::fromUtf8("重命名流股"));dismiss(menu);
        QTest::keySequence(canvas,QKeySequence::Copy);menu=context(blank);QVERIFY(menu);
        if(!capture.isEmpty())menu->grab().save(capture+"/flowsheet-background-menu.png");
        auto *paste=menu->findChild<QAction *>("FlowPaste");QVERIFY(paste);QVERIFY(paste->isEnabled());paste->trigger();dismiss(menu);
        auto *conflict=objects->findChild<QDialog *>("ObjectPasteDialog");QVERIFY(conflict);conflict->findChild<QPushButton *>("PasteEditId")->click();
        auto *id=conflict->findChild<QDialog *>("PasteIdDialog");QVERIFY(id);id->findChild<QLineEdit *>("ObjectId")->setText("S_COPY");
        id->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();conflict->findChild<QPushButton *>("PasteConfirm")->click();QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        QCOMPARE(objects->objects().size(),2);QVERIFY(objects->currentObject().isEmpty());
        const auto clone=objects->object(objects->selectedFlowsheetObject());QCOMPARE(clone.value("name").toString(),QString("S_COPY"));
        QVERIFY(clone.value("from").toString().isEmpty());QCOMPARE(clone.value("startX").toInt(),250);
        QTest::keyClick(canvas,Qt::Key_Return);QCOMPARE(objects->currentObject(),clone.value("key").toString());
    }

void shellNavigationAndCommandFeedback()
{
    QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
    UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();QTest::qWait(30);
    auto *objects=shell.findChild<ObjectWorkspace *>();
    const auto key=objects->createObject("blocks","COL1","RadFrac");QVERIFY(!key.isEmpty());
    shell.dispatch("flowsheet");
    auto *tree=shell.findChild<QTreeWidget *>("SimulationNavigation");
    auto findRoute=[tree](const QString &route) {for(QTreeWidgetItemIterator it(tree);*it;++it)if((*it)->data(0,Qt::UserRole+3).toString()==route)return *it;return static_cast<QTreeWidgetItem *>(nullptr);};
    auto *object=findRoute("object:"+key);QVERIFY(object);QVERIFY(object->childCount()>1);
    auto *children=findRoute("objects:pumparounds:"+key);QVERIFY(children);
    const auto type=objects->definition("pumparounds").value("types").toArray().first().toObject().value("id").toString();
    const auto child=objects->createObject("pumparounds","P1",type,key);QVERIFY(!child.isEmpty());
    QVERIFY(findRoute("object:"+child));
    shell.dispatch("object:"+child);QVERIFY(tree->currentItem()->data(0,Qt::UserRole+3).toString().startsWith("object:"+child));
    auto *results=findRoute("catalog:Results");QVERIFY(results);
    shell.dispatch(QString::fromUtf8("navigation-filter:仅输入"));QVERIFY(results->isHidden());
    QVERIFY(!objects->createObject("blocks","M1","Mixer").isEmpty());QVERIFY(findRoute("catalog:Results")->isHidden());
    shell.dispatch("catalog:Sensor");QCOMPARE(shell.findChild<QLabel *>("NavigationHeading")->text(),QString::fromUtf8("物性"));
    shell.dispatch("flowsheet");QVERIFY(tree->isVisible());
    auto *ribbon=shell.findChild<QTabWidget *>("Ribbon");QCOMPARE(ribbon->tabText(ribbon->currentIndex()),QString::fromUtf8("修改"));
    shell.dispatch(QString::fromUtf8("navigation-filter:所有项"));QVERIFY(!findRoute("catalog:Results")->isHidden());
    auto *streams=findRoute("objects:streams");QVERIFY(streams);tree->setCurrentItem(streams);tree->setFocus();
    QTest::keyClick(tree,Qt::Key_Down);QCOMPARE(tree->currentItem()->data(0,Qt::UserRole+3).toString(),QString("objects:blocks"));
    QCOMPARE(objects->findChild<QTableWidget *>("ObjectTable")->rowCount(),2);
    auto *zoom=shell.findChild<QSlider *>("FlowsheetZoom");shell.dispatch("zoom-in");QCOMPARE(zoom->value(),110);
    shell.dispatch("zoom-out");QCOMPARE(zoom->value(),100);objects->setFlowsheetZoom(130);QCOMPARE(zoom->value(),130);
    auto *collapse=shell.findChild<QToolButton *>("CollapseNavigator");QVERIFY(collapse);collapse->click();QVERIFY(!tree->isVisible());collapse->click();QVERIFY(tree->isVisible());
    // Entering the New panel must not reset a modified project or prompt to save it.
    const auto before=shell.project()->state();shell.dispatch("backstage");
    QToolButton *newPanel=nullptr;for(auto *button:shell.findChildren<QToolButton *>("FileEntry"))if(button->text()==QString::fromUtf8("新建"))newPanel=button;
    QVERIFY(newPanel);newPanel->click();QCOMPARE(shell.project()->state(),before);QVERIFY(!shell.findChild<QMessageBox *>());
}

void shellKeepsNativeTextUndo()
{
    QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
    auto *objects=shell.findChild<ObjectWorkspace *>();const auto key=objects->createObject("blocks","M1","Mixer");QVERIFY(!key.isEmpty());
    shell.dispatch("components");auto *components=shell.findChild<ComponentWorkspace *>();components->currentTabs()->setCurrentIndex(4);
    auto *edit=components->findChild<QTextEdit *>("comments-editor");QVERIFY(edit);edit->setFocus();QTest::keyClicks(edit,"comment");
    QVERIFY(!edit->toPlainText().isEmpty());QTest::keySequence(edit,QKeySequence::Undo);QVERIFY(edit->toPlainText().isEmpty());
    QCOMPARE(objects->objects().size(),1);QTest::keySequence(edit,QKeySequence::Redo);QCOMPARE(edit->toPlainText(),QString("comment"));
    QCOMPARE(objects->objects().size(),1);
}

    void databaseReadOnlyAndProjectIntegration() {
        QTemporaryDir temp;const auto path=databaseFixture(temp.path());QVERIFY(!path.isEmpty());QString error;
        const auto before=QSqlDatabase::connectionNames();PropertyDatabase database;QVERIFY2(database.open(path,&error),qPrintable(error));
        for(const auto &name:QSqlDatabase::connectionNames()) if(!before.contains(name)) {QSqlQuery write(QSqlDatabase::database(name));QVERIFY(!write.exec("DELETE FROM compounds"));}
        for(const auto &term:{"TEST-WATER","h2o","7732-18-5","A%_literal"}) QCOMPARE(database.search(term,&error).size(),1);
        QCOMPARE(database.search("' OR 1=1 --",&error).size(),0);QVERIFY(error.isEmpty());
        const auto parameters=database.parameters("TEST","1",0,&error);QCOMPARE(parameters.size(),1);
        QCOMPARE(parameters[0].toObject().value("valueText").toString(),QString("123.456789012345678901"));
        QCOMPARE(database.provenance("TEST",11,&error).value("notes").toArray()[0].toString(),QString("Synthetic provenance"));
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));const auto spec=QJsonDocument::fromJson(file.readAll()).object();UiShell shell(spec);
        QVERIFY(shell.openPropertyDatabase(path,&error));shell.dispatch("database-search");auto *dialog=shell.findChild<QDialog *>("FindCompoundDialog");QVERIFY(dialog);
        dialog->findChild<QLineEdit *>("compound-query")->setText("7732-18-5");dialog->findChild<QPushButton *>("SearchDatabase")->click();
        QCOMPARE(dialog->findChild<QTableWidget *>("DatabaseResults")->rowCount(),1);
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");if(!capture.isEmpty()) {QDir().mkpath(capture);QTest::qWait(40);QVERIFY(dialog->grab().save(capture+"/database-query.png"));}
        dialog->findChild<QPushButton *>("AddDatabaseComponent")->click();QCOMPARE(shell.project()->state().value("components").toArray().size(),1);
        dialog->findChild<QPushButton *>("AddDatabaseComponent")->click();QCOMPARE(shell.project()->state().value("components").toArray().size(),1);
        const QJsonValue component=shell.project()->state().value("components").toArray().at(0);QVERIFY(shell.saveProject(temp.filePath("test.afmp"),&error));
        dialog->findChild<QPushButton *>("ManageDatabaseComponents")->click();
        auto *selectionDialog=dialog->findChild<QDialog *>("DatabaseSelectionDialog");QVERIFY(selectionDialog && selectionDialog->isVisible());
        auto *selected=dialog->findChild<QListWidget *>("SelectedDatabaseComponents");selected->setCurrentRow(0);dialog->findChild<QPushButton *>("RemoveDatabaseComponent")->click();QCOMPARE(shell.project()->state().value("components").toArray().size(),0);
        selectionDialog->reject();
        shell.project()->undo();QCOMPARE(shell.project()->state().value("components").toArray()[0],component);dialog->reject();
        UiShell other(spec);QVERIFY(other.loadProject(temp.filePath("test.afmp"),&error));QCOMPARE(other.project()->state().value("components").toArray()[0],component);
        QVERIFY(other.findChild<QLabel *>("DatabaseStatus")->text().contains(QString::fromUtf8("未连接")));
        QVERIFY(!database.open(temp.filePath("missing.sqlite"),&error));QVERIFY(!QFile::exists(temp.filePath("missing.sqlite")));QVERIFY(!error.isEmpty());
        {auto db=QSqlDatabase::addDatabase("QSQLITE","fixture-version");db.setDatabaseName(path);QVERIFY(db.open());QSqlQuery q(db);QVERIFY(q.exec("UPDATE metadata SET value='999' WHERE key='schema_version'"));}
        QSqlDatabase::removeDatabase("fixture-version");QVERIFY(!database.open(path,&error));QVERIFY(error.contains(QString::fromUtf8("版本")));
        {auto db=QSqlDatabase::addDatabase("QSQLITE","fixture-version");db.setDatabaseName(path);QVERIFY(db.open());QSqlQuery q(db);QVERIFY(q.exec("UPDATE metadata SET value='1' WHERE key='schema_version'"));QVERIFY(q.exec("UPDATE metadata SET value='aspen-v15-other-version' WHERE key='dataset_id'"));}
        QSqlDatabase::removeDatabase("fixture-version");QVERIFY(other.openPropertyDatabase(path,&error));QVERIFY(other.findChild<QLabel *>("DatabaseStatus")->text().contains(QString::fromUtf8("不符")));
        other.dispatch("database-search");auto *mismatch=other.findChild<QDialog *>("FindCompoundDialog");QVERIFY(mismatch);mismatch->findChild<QLineEdit *>("compound-query")->setText("TEST-WATER");mismatch->findChild<QPushButton *>("SearchDatabase")->click();const auto old=other.project()->state();mismatch->findChild<QPushButton *>("AddDatabaseComponent")->click();QCOMPARE(other.project()->state(),old);mismatch->reject();
    }
    void realDatabaseSmoke() {
        const auto path=qEnvironmentVariable("ASPEN_TEST_DATABASE");if(path.isEmpty()) QSKIP("Local protected data is not distributed to CI");
        PropertyDatabase database;QString error;QVERIFY2(database.open(path,&error),qPrintable(error));
        const auto water=database.search("7732-18-5",&error);QVERIFY2(!water.isEmpty(),qPrintable(error));
        bool found=false;for(const auto &v:water) {const auto c=v.toObject();if(c.value("database")!="APV150") continue;
            QCOMPARE(c.value("cas").toString(),QString("7732-18-5"));const auto p=database.parameters("APV150",c.value("compoundId").toString(),0,&error,500);QVERIFY2(!p.isEmpty(),qPrintable(error));found=true;}
        QVERIFY(found);QVERIFY(!database.search("ETHANOL",&error).isEmpty());
    }
    void projectRoundTripAndUndo()
    {
        QFile catalog(":/ui/aspen-plus.json"); QVERIFY(catalog.open(QIODevice::ReadOnly));
        const auto spec=QJsonDocument::fromJson(catalog.readAll()).object();
        QTemporaryDir temp; QVERIFY(temp.isValid()); const auto path=temp.filePath(QString::fromUtf8("中文 case.afmp"));
        QString key, child, stream; QJsonObject saved; QString error;
        {
            UiShell shell(spec); auto *w=shell.findChild<ObjectWorkspace *>();
            QVERIFY(!shell.project()->isModified());
            key=w->createObject("blocks","COLUMN","RadFrac"); QVERIFY(!key.isEmpty());
            const auto definitions=w->definitions();
            for(const auto &v:definitions) { const auto d=v.toObject();
                if(d.value("parentTypes").toArray().contains("RadFrac")) {
                    child=w->createObject(d.value("id").toString(),"CHILD",d.value("types").toArray().first().toObject().value("id").toString(),key); break;
                }
            }
            QVERIFY(!child.isEmpty());
            w->beginPlacement("streams","MATERIAL"); w->placeAt({20,50}); w->placeAt({100,100},key);
            for(const auto &v:w->objects()) if(v.toObject().value("kind")=="streams") stream=v.toObject().value("key").toString();
            QVERIFY(!stream.isEmpty());
            w->setObjectState(key,{{"unverified-page",{{"zero","0"},{"empty",""},{"precise","1.234567890123456789"},{"note",QString::fromUtf8("中文输入")}}}});
            shell.dispatch("units:SI");
            w->moveBlock(key,{377,222});
            QCOMPARE(w->object(key).value("x").toInt(),377);
            shell.project()->undo(); QCOMPARE(w->object(key).value("x").toInt(),100);
            shell.project()->redo(); QCOMPARE(w->object(key).value("x").toInt(),377);
            QVERIFY(w->renameObject(key,"RENAMED")); shell.project()->undo(); QCOMPARE(w->object(key).value("name").toString(),QString("COLUMN")); shell.project()->redo();
            QVERIFY(w->removeObject(key)); QVERIFY(w->object(child).isEmpty()); QVERIFY(w->object(stream).value("to").toString().isEmpty());
            shell.project()->undo(); QCOMPARE(w->object(child).value("parent").toString(),key); QCOMPARE(w->object(stream).value("to").toString(),key);
            QVERIFY2(shell.saveProject(path,&error),qPrintable(error)); QVERIFY(!shell.project()->isModified()); saved=shell.project()->state();
            auto invalid=saved; invalid["version"]=999; shell.project()->edit(invalid);
            QVERIFY(!shell.saveProject(path,&error)); QFile unchanged(path); QVERIFY(unchanged.open(QIODevice::ReadOnly)); QCOMPARE(QJsonDocument::fromJson(unchanged.readAll()).object(),saved);
        }
        UiShell reopened(spec); QVERIFY2(reopened.loadProject(path,&error),qPrintable(error)); QCOMPARE(reopened.project()->state(),saved);
        auto *w=reopened.findChild<ObjectWorkspace *>(); QCOMPARE(w->object(child).value("parent").toString(),key);
        QCOMPARE(w->projectObjects(),saved.value("objects").toArray());
        QFile corrupt(temp.filePath("bad.afmp")); QVERIFY(corrupt.open(QIODevice::WriteOnly));corrupt.write("{broken");corrupt.close();
        QVERIFY(!reopened.loadProject(corrupt.fileName(),&error)); QCOMPARE(reopened.project()->state(),saved);
        auto bad=saved;auto objs=bad.value("objects").toArray();auto obj=objs[0].toObject();obj["parent"]="missing";objs[0]=obj;bad["objects"]=objs;QVERIFY(!ProjectDocument::validate(bad).isEmpty());
        w->createObject("blocks","NEW","Mixer");
        QTimer::singleShot(0,[] { for(auto *widget:QApplication::topLevelWidgets()) if(auto *message=qobject_cast<QMessageBox *>(widget)) message->done(QMessageBox::Cancel); });
        QVERIFY(!reopened.close()); QVERIFY(reopened.project()->isModified());
    }
    void saveCommitsActiveTableEditor() {
        QFile catalog(":/ui/aspen-plus.json");QVERIFY(catalog.open(QIODevice::ReadOnly));const auto spec=QJsonDocument::fromJson(catalog.readAll()).object();
        UiShell shell(spec);shell.show();auto *w=shell.findChild<ObjectWorkspace *>();const auto key=w->createObject("property-sets","EDIT","PropertySet");shell.dispatch("object:"+key);QCoreApplication::processEvents();
        auto *view=qobject_cast<RecoveredWorkspace *>(w->findChild<QTabWidget *>("ObjectDocuments")->currentWidget());QVERIFY(view);auto *grid=view->findChild<QTableWidget *>("grdSelection");QVERIFY(grid);
        grid->setItem(0,0,new QTableWidgetItem("OLD"));grid->scrollToItem(grid->item(0,0));grid->setCurrentCell(0,0);grid->editItem(grid->item(0,0));QCoreApplication::processEvents();
        auto *editor=grid->findChild<QLineEdit *>();QVERIFY(editor);editor->setFocus();editor->setText("UNCOMMITTED");QCOMPARE(grid->item(0,0)->text(),QString("OLD"));
        QTemporaryDir temp;QString error;QVERIFY2(shell.saveProject(temp.filePath("active.afmp"),&error),qPrintable(error));
        QCOMPARE(grid->item(0,0)->text(),QString("UNCOMMITTED"));UiShell other(spec);QVERIFY(other.loadProject(temp.filePath("active.afmp"),&error));auto *ow=other.findChild<ObjectWorkspace *>();QVERIFY(ow->openObject(key));
        auto *restored=qobject_cast<RecoveredWorkspace *>(ow->findChild<QTabWidget *>("ObjectDocuments")->currentWidget());QCOMPARE(restored->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("UNCOMMITTED"));
        QVERIFY(!other.findChild<QToolButton *>("window-back")->isEnabled());
    }
    void projectLiveInputs()
    {
        QFile catalog(":/ui/aspen-plus.json"); QVERIFY(catalog.open(QIODevice::ReadOnly));const auto spec=QJsonDocument::fromJson(catalog.readAll()).object();
        QTemporaryDir temp;QString error;UiShell shell(spec);auto *w=shell.findChild<ObjectWorkspace *>();
        const auto key=w->createObject("property-sets","P1","PropertySet");QVERIFY(w->openObject(key));
        auto *tabs=w->findChild<QTabWidget *>("ObjectDocuments");auto *view=qobject_cast<RecoveredWorkspace *>(tabs->currentWidget());QVERIFY(view);
        auto *notes=view->findChild<QTextEdit *>("commentsDescription");QVERIFY(notes);notes->setPlainText(QString::fromUtf8("持久输入"));
        auto *grid=view->findChild<QTableWidget *>("grdSelection");QVERIFY(grid);grid->setItem(0,0,new QTableWidgetItem("TEMP"));
        const auto after=shell.project()->state();shell.project()->undo();QVERIFY(shell.project()->state()!=after);shell.project()->redo();
        shell.dispatch("methods");auto *method= shell.findChild<RecoveredWorkspace *>()->findChild<QComboBox *>("ProcessMethod");QVERIFY(method);method->setCurrentText("NRTL");QCOMPARE(method->currentText(),QString("NRTL"));
        auto *components=shell.findChild<ComponentWorkspace *>();QVERIFY(components->showPage("specifications"));components->currentTabs()->setCurrentIndex(4);components->currentTabs()->currentWidget()->findChild<QTextEdit *>("comments-editor")->setPlainText("project notes");
        QVERIFY2(shell.saveProject(temp.filePath("input.afmp"),&error),qPrintable(error));
        UiShell other(spec);QVERIFY(other.loadProject(temp.filePath("input.afmp"),&error));auto *ow=other.findChild<ObjectWorkspace *>();QVERIFY(ow->openObject(key));
        auto *ov=qobject_cast<RecoveredWorkspace *>(ow->findChild<QTabWidget *>("ObjectDocuments")->currentWidget());QCOMPARE(ov->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString::fromUtf8("持久输入"));
        QCOMPARE(ov->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("TEMP"));
        other.dispatch("methods");QCOMPARE(other.findChild<RecoveredWorkspace *>()->findChild<QComboBox *>("ProcessMethod")->currentText(),QString("NRTL"));
        auto *oc=other.findChild<ComponentWorkspace *>();QVERIFY(oc->showPage("specifications"));oc->currentTabs()->setCurrentIndex(4);QCOMPARE(oc->currentTabs()->currentWidget()->findChild<QTextEdit *>("comments-editor")->toPlainText(),QString("project notes"));
    }
    void objectLifecycleAndIndependentInputs()
    {
        QFile file(":/ui/aspen-plus.json"); QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();QVERIFY(objects);
        auto *documents=objects->findChild<QTabWidget *>("ObjectDocuments");
        auto *table=objects->findChild<QTableWidget *>("ObjectTable");
        auto cleanDialogs=[] {QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);};
        shell.dispatch("property-sets");
        objects->findChild<QPushButton *>("Objectnew")->click();
        auto *dialog=objects->findChild<QDialog *>("ObjectNameDialog");QVERIFY(dialog);
        QCOMPARE(dialog->findChild<QLineEdit *>("ObjectId")->text(),QString("PS-1"));
        dialog->reject();cleanDialogs();QCOMPARE(objects->objects().size(),0);
        objects->findChild<QPushButton *>("Objectnew")->click();
        dialog=objects->findChild<QDialog *>("ObjectNameDialog");
        auto *id=dialog->findChild<QLineEdit *>("ObjectId");auto *ok=dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok);
        id->setText("bad name");QVERIFY(!ok->isEnabled());id->setText("PS-1");QVERIFY(ok->isEnabled());ok->click();cleanDialogs();
        QCOMPARE(objects->objects().size(),1);QCOMPARE(documents->count(),3);QCOMPARE(table->rowCount(),1);
        const auto first=objects->objects().first().toObject().value("key").toString();
        auto *view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());QVERIFY(view);
        auto *notes=view->findChild<QTextEdit *>("commentsDescription");QVERIFY(notes);notes->setPlainText("first object");
        auto *selection=view->findChild<QTableWidget *>("grdSelection");QVERIFY(selection);QCOMPARE(selection->rowCount(),1);
        selection->setItem(0,0,new QTableWidgetItem("TEMP"));QCOMPARE(selection->rowCount(),2);
        const auto second=objects->createObject("property-sets","PS-2","PropertySet");QVERIFY(!second.isEmpty());
        QVERIFY(objects->openObject(second));view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());
        QCOMPARE(view->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString());
        view->findChild<QTextEdit *>("commentsDescription")->setPlainText("second object");
        QVERIFY(objects->openObject(first));view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());
        QCOMPARE(view->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString("first object"));
        objects->closeObject(first);cleanDialogs();QVERIFY(objects->openObject(first));
        view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());
        QCOMPARE(view->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("TEMP"));
        QVERIFY(objects->createObject("property-sets","ps-1","PropertySet").isEmpty());
        objects->requestRename(first);dialog=objects->findChild<QDialog *>("ObjectNameDialog");
        id=dialog->findChild<QLineEdit *>("ObjectId");ok=dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok);
        id->setText("ps-2");QVERIFY(!ok->isEnabled());id->setText("RENAMED");ok->click();cleanDialogs();
        QVERIFY(documents->tabText(documents->currentIndex()).contains("RENAMED"));
        bool inTree=false;for(QTreeWidgetItemIterator it(shell.findChild<QTreeWidget *>("PropertiesNavigation"));*it;++it)
            if((*it)->text(0)=="RENAMED") inTree=true;QVERIFY(inTree);
        objects->copyObject(first);objects->showCollection("property-sets");objects->requestPaste();
        auto *conflict=objects->findChild<QDialog *>("ObjectPasteDialog");QVERIFY(conflict);QVERIFY(!conflict->findChild<QPushButton *>("PasteConfirm")->isEnabled());
        conflict->findChild<QPushButton *>("PasteEditId")->click();
        dialog=conflict->findChild<QDialog *>("PasteIdDialog");dialog->findChild<QLineEdit *>("ObjectId")->setText("COPY");
        dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();cleanDialogs();
        QCOMPARE(objects->objects().size(),2);conflict->findChild<QPushButton *>("PasteConfirm")->click();cleanDialogs();
        const auto copied=objects->currentObject();QVERIFY(copied!=first);
        view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());
        QCOMPARE(view->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString("first object"));
        view->findChild<QTextEdit *>("commentsDescription")->setPlainText("copied notes");
        objects->openObject(first);view=qobject_cast<RecoveredWorkspace *>(documents->currentWidget());
        QCOMPARE(view->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString("first object"));
        objects->requestDelete(first);dialog=objects->findChild<QDialog *>("ObjectDeleteDialog");dialog->reject();cleanDialogs();QVERIFY(!objects->object(first).isEmpty());
        objects->requestDelete(first);dialog=objects->findChild<QDialog *>("ObjectDeleteDialog");
        dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Yes)->click();cleanDialogs();
        QVERIFY(objects->object(first).isEmpty());QVERIFY(!objects->openObject(first));
        shell.dispatch("window-back");shell.dispatch("window-forward");QVERIFY(objects->currentObject()!=first);
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if(!capture.isEmpty()) {QDir().mkpath(capture);objects->openObject(copied);QTest::qWait(40);shell.grab().save(capture+"/object-input.png");}
    }

    void objectTypesFlowsheetAndWizard()
    {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();
        auto *objects=shell.findChild<ObjectWorkspace *>();RecoveredWorkspace resources;
        for(const auto &v:objects->definitions()) for(const auto &t:v.toObject().value("types").toArray())
            for(const auto &p:t.toObject().value("pages").toArray()) QVERIFY2(!resources.idForName(p.toObject().value("page").toString()).isEmpty(),qPrintable(p.toObject().value("page").toString()));
        // Every advertised model must create an editable input document and cleanly close.
        int modelNumber=0;
        for(const auto &v:objects->definition("blocks").value("types").toArray()) {
            const auto type=v.toObject().value("id").toString();
            const auto key=objects->createObject("blocks","CHECK"+QString::number(++modelNumber),type);
            QVERIFY2(!key.isEmpty(),qPrintable(type));QVERIFY2(objects->openObject(key),qPrintable(type));QVERIFY(objects->removeObject(key));
            QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        }
        objects->requestNew("blocks");auto *dialog=objects->findChild<QDialog *>("ObjectNameDialog");
        auto *ok=dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok);QVERIFY(!ok->isEnabled());
        dialog->findChild<QComboBox *>("ObjectType")->setCurrentIndex(0);QVERIFY(ok->isEnabled());dialog->reject();
        QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);
        shell.dispatch("flowsheet");QTest::qWait(30);
        auto *canvas=objects->findChild<QGraphicsView *>("FlowsheetCanvas");QVERIFY(canvas);
        objects->findChild<QToolButton *>("Model-Mixer")->click();
        const auto point=canvas->mapToScene(QPoint(140,100));
        QTest::mouseClick(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,QPoint(140,100));
        QCOMPARE(objects->objects().size(),1);const auto mixer=objects->objects()[0].toObject().value("key").toString();
        QCOMPARE(objects->object(mixer).value("type").toString(),QString("Mixer"));
        objects->findChild<QPushButton *>("FlowSelect")->click();
        QTest::mouseDClick(canvas->viewport(),Qt::LeftButton,Qt::NoModifier,canvas->mapFromScene(point));
        QCOMPARE(objects->currentObject(),mixer);
        const auto column=objects->createObject("blocks","T1","RadFrac");QVERIFY(!column.isEmpty());
        QVERIFY(objects->createObject("column-designs","DS-1","Design",mixer).isEmpty());
        const auto child=objects->createObject("column-designs","DS-1","Design",column);QVERIFY(!child.isEmpty());
        objects->copyObject(column);objects->showCollection("blocks");objects->requestPaste();
        auto *conflict=objects->findChild<QDialog *>("ObjectPasteDialog");conflict->findChild<QPushButton *>("PasteEditId")->click();
        dialog=conflict->findChild<QDialog *>("PasteIdDialog");dialog->findChild<QLineEdit *>("ObjectId")->setText("T2");
        dialog->findChild<QDialogButtonBox *>()->button(QDialogButtonBox::Ok)->click();
        conflict->findChild<QPushButton *>("PasteConfirm")->click();
        QCoreApplication::sendPostedEvents(nullptr,QEvent::DeferredDelete);const auto clone=objects->currentObject();
        int children=0;for(const auto &v:objects->objects()) if(v.toObject().value("parent").toString()==clone) ++children;QCOMPARE(children,1);
        objects->showFlowsheet();objects->beginPlacement("streams","MATERIAL");objects->placeAt(point,mixer);objects->placeAt(QPointF(400,160),column);
        const auto stream=objects->objects().last().toObject().value("key").toString();
        QCOMPARE(objects->object(stream).value("from").toString(),mixer);QCOMPARE(objects->object(stream).value("to").toString(),column);
        objects->moveBlock(mixer,QPointF(220,220));QCOMPARE(objects->object(mixer).value("x").toInt(),220);
        objects->beginPlacement({},{});
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if(!capture.isEmpty()) {QDir().mkpath(capture);QTest::qWait(40);shell.grab().save(capture+"/flowsheet-objects.png");}
        QVERIFY(objects->removeObject(column));QVERIFY(objects->object(child).isEmpty());QVERIFY(objects->object(stream).value("to").toString().isEmpty());QVERIFY(!objects->object(clone).isEmpty());
        shell.dispatch("user-components");auto *wizard=shell.findChild<QDialog *>("wizard-user-component");QVERIFY(wizard);
        wizard->findChild<QLineEdit *>("txtCompID")->setText("CUSTOM");wizard->findChild<QComboBox *>("cboType")->setCurrentIndex(1);
        auto *next=wizard->findChild<QPushButton *>("WizardNext");auto *steps=wizard->findChild<QStackedWidget *>("WizardSteps");
        while(steps->currentIndex()<steps->count()-1) {QVERIFY(next->isEnabled());next->click();}
        auto *finish=wizard->findChild<QPushButton *>("WizardFinish");QVERIFY(finish->isEnabled());finish->click();
        const auto custom=objects->object(objects->currentObject());QCOMPARE(custom.value("name").toString(),QString("CUSTOM"));QCOMPARE(custom.value("type").toString(),QString("SOLID"));
        shell.dispatch("components");auto *components=shell.findChild<ComponentWorkspace *>();
        bool found=false;for(auto *table:components->findChildren<QTableWidget *>())
            for(int row=0;row<table->rowCount();++row) if(table->item(row,0) && table->item(row,0)->text()=="CUSTOM") found=true;QVERIFY(found);
        objects->removeObject(custom.value("key").toString());
        for(auto *table:components->findChildren<QTableWidget *>()) for(int row=0;row<table->rowCount();++row)
            QVERIFY(!table->item(row,0) || table->item(row,0)->text()!="CUSTOM");
    }

    void recoveredImagesAndInteractiveForms()
    {
        QFile manifest(":/ui/icons/recovered.json"); QVERIFY(manifest.open(QIODevice::ReadOnly));
        const auto images=QJsonDocument::fromJson(manifest.readAll()).object();
        QVERIFY(images.value("assets").toArray().size()>=170);
        const auto references=images.value("references").toObject();
        for (auto it=references.begin();it!=references.end();++it) QVERIFY2(!aspenIcon(it.key()).isNull(),qPrintable(it.key()));
        RecoveredWorkspace workspace;
        const auto setup=workspace.idForName("MMSetup_Setup"); QVERIFY(!setup.isEmpty());
        QVERIFY(workspace.showPage(setup));
        auto *phase=workspace.findChild<QComboBox *>("cboPhase"); QVERIFY(phase); QCOMPARE(phase->count(),4); QCOMPARE(phase->currentIndex(),-1);
        phase->setCurrentIndex(2);
        QVERIFY(!workspace.findChild<QWidget *>("cboInpMode"));
        auto *title=workspace.findChild<QWidget *>("lbtuTitle")->findChild<QLineEdit *>(); QVERIFY(!title->isReadOnly()); title->setText("Session title");
        auto *comments=workspace.findChild<QTextEdit *>("commentsDescription"); QVERIFY(comments); comments->setPlainText("Setup notes");
        auto *tabs=workspace.findChild<QTabWidget *>("tabSetup"); QVERIFY(tabs); tabs->setCurrentIndex(4);
        QVERIFY(workspace.showPage(workspace.idForName("MMProp_Spec_Input")));
        QVERIFY(workspace.findChild<QCheckBox *>("MMCheckBox1")->isChecked());
        auto *filter=workspace.findChild<QComboBox *>("cboGPProcessType");
        filter->setCurrentText("ELECTROL");
        QVERIFY(!workspace.findChild<QComboBox *>("MMComboBox4")->isEnabled());
        QCOMPARE(workspace.findChild<QComboBox *>("MMComboBox4")->count(),0);
        filter->setCurrentText("COMMON"); QCOMPARE(workspace.findChild<QComboBox *>("MMComboBox4")->count(),20);
        workspace.setGlobalUnits("SI");
        QVERIFY(workspace.showPage(setup));
        QCOMPARE(workspace.findChild<QComboBox *>("cboPhase")->currentIndex(),2);
        QCOMPARE(workspace.findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString("Setup notes"));
        QCOMPARE(workspace.findChild<QTabWidget *>("tabSetup")->currentIndex(),4);
        QCOMPARE(workspace.findChild<QComboBox *>("cboInputData")->currentText(),QString("SI"));
        QCOMPARE(workspace.findChild<QWidget *>("lbtuTitle")->findChild<QLineEdit *>()->text(),QString("Session title"));
        // Comments in different host pages must remain independent despite sharing a COM form.
        QVERIFY(workspace.showPage(workspace.idForName("MMProp_Spec_Input")));
        QCOMPARE(workspace.findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString());
    }

    void shellCommandsMenusAndWizardState()
    {
        QFile file(":/ui/aspen-plus.json"); QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object()); shell.show();
        auto *recovered=shell.findChild<RecoveredWorkspace *>(); QVERIFY(recovered);
        shell.findChild<QToolButton *>("setup")->click();
        shell.findChild<QToolButton *>("methods")->click();
        shell.findChild<QToolButton *>("window-back")->click();
        QCOMPARE(recovered->currentPage(),recovered->idForName("MMSetup_Setup"));
        shell.findChild<QToolButton *>("window-forward")->click();
        QCOMPARE(recovered->currentPage(),recovered->idForName("MMProp_Spec_Input"));
        auto *units=shell.findChild<QToolButton *>("unit-selector");
        for (auto *action:units->menu()->actions()) if (action->text()=="SI") action->trigger();
        shell.findChild<QToolButton *>("setup")->click();
        QCOMPARE(recovered->findChild<QComboBox *>("cboInputData")->currentText(),QString("SI"));
        auto *ribbon=shell.findChild<QTabWidget *>("Ribbon");
        shell.dispatch("ribbon-collapse"); QCOMPARE(ribbon->height(),28);
        shell.dispatch("ribbon-collapse"); QCOMPARE(ribbon->height(),122);
        auto *quick=shell.findChild<QWidget *>("QuickBar");
        shell.dispatch("quick-below"); QCOMPARE(quick->parentWidget()->layout()->indexOf(quick),1);
        shell.dispatch("quick-below"); QCOMPARE(quick->parentWidget()->layout()->indexOf(quick),0);
        shell.dispatch("find-component");
        auto *find=shell.findChild<QDialog *>("FindCompoundDialog"); QVERIFY(find); find->reject();
        shell.dispatch("clean-parameters");
        auto *dialog=shell.findChild<QDialog *>("dialog-CleanParametersDialog"); QVERIFY(dialog); QVERIFY(dialog->isVisible()); dialog->reject();
        shell.dispatch("user-components");
        auto *wizard=shell.findChild<QDialog *>("wizard-user-component"); QVERIFY(wizard);
        auto *next=wizard->findChild<QPushButton *>("WizardNext"); QVERIFY(!next->isEnabled());
        wizard->findChild<QLineEdit *>("txtCompID")->setText("TEST"); QVERIFY(next->isEnabled()); next->click();
        QCOMPARE(wizard->findChild<QStackedWidget *>("WizardSteps")->currentIndex(),1);
        wizard->findChild<QPushButton *>("WizardBack")->click();
        QCOMPARE(wizard->findChild<QLineEdit *>("txtCompID")->text(),QString("TEST")); wizard->reject();
        shell.dispatch("options"); auto *options=shell.findChild<QDialog *>("OptionsDialog"); QVERIFY(options); options->reject();
    }

    void allRecoveredLayoutsInstantiate()
    {
        RecoveredWorkspace workspace;
        const auto pages=workspace.catalog().value("pages").toArray();
        QCOMPARE(pages.size(),3086);
        for (const auto &value:pages) {
            const auto id=value.toObject().value("id").toString();
            QVERIFY2(workspace.showPage(id),qPrintable(id));
            QVERIFY2(workspace.findChild<QScrollArea *>("RecoveredScroll")->widget(),qPrintable(id));
            if (value.toObject().value("name").toString()=="Plot3DAxesPropertiesDlg")
                QVERIFY(workspace.findChild<QWidget *>("ncbMajorGrid3D"));
        }
        for (int i=0;i<workspace.nativeDialogs().size();++i) QVERIFY(workspace.showPage("dialog:"+QString::number(i)));
        for (int i=0;i<workspace.menuCatalog().size();++i) QVERIFY(workspace.showPage("menu:"+QString::number(i)));
    }

    void recoveredCatalogNavigationAndRendering()
    {
        QFile style(":/ui/shell.qss"); QVERIFY(style.open(QIODevice::ReadOnly)); qApp->setStyleSheet(QString::fromUtf8(style.readAll()));
        QFile file(":/ui/aspen-plus.json"); QVERIFY(file.open(QIODevice::ReadOnly));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object()); shell.show();
        auto *recovered=shell.findChild<RecoveredWorkspace *>(); QVERIFY(recovered);
        const auto pages=recovered->catalog().value("pages").toArray();
        QVERIFY(pages.size()>2500);
        auto *tree=shell.findChild<QTreeWidget *>("RecoveredNavigation"); QVERIFY(tree);
        auto *nav=shell.findChild<QTabWidget *>("NavigationTabs"); QVERIFY(nav); nav->setCurrentIndex(1);
        const auto captureDir=qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if (!captureDir.isEmpty()) QVERIFY(QDir().mkpath(captureDir));
        QSet<QString> modules;
        for (QTreeWidgetItemIterator it(tree); *it; ++it) {
            const auto id=(*it)->data(0,Qt::UserRole).toString();
            if (id.isEmpty() || id.contains(':')) continue;
            const auto module=(*it)->parent()->toolTip(0);
            if (modules.contains(module)) continue;
            tree->setCurrentItem(*it); QCoreApplication::processEvents();
            QCOMPARE(recovered->currentPage(),id); QVERIFY(recovered->isVisible());
            QVERIFY(recovered->findChild<QScrollArea *>("RecoveredScroll")->widget());
            modules.insert(module);
        }
        QCOMPARE(modules.size(),recovered->catalog().value("modules").toArray().size());
        // Explicit representative tabbed forms exercise cross-resource ContentType links.
        const QSet<QString> examples{"MMHenryComps_Input","MMSetup_Setup","MMComp_Spec_Input","MMSetup_Units","MMRCSTR_Setup","MMRadfrac_Conver","MMProp_Spec_Input"};
        for (const auto &v:pages) {
            const auto page=v.toObject(); const auto name=page.value("name").toString();
            if (!examples.contains(name)) continue;
            QVERIFY(recovered->showPage(page.value("id").toString())); QCoreApplication::processEvents();
            QVERIFY(recovered->findChild<QTabWidget *>());
            if (name=="MMProp_Spec_Input") {
                // The original Properties mode shows the methods group directly.
                QVERIFY(!recovered->findChild<QTabWidget *>("ConditionalAlternatives"));
                auto *models=recovered->findChild<QGroupBox *>("fraModels"); QVERIFY(models);
                QVERIFY(models->findChild<QWidget *>("cboLiquidGamma"));
            }
            if (name=="MMRCSTR_Setup") {
                bool scrolls=false;
                for (auto *area:recovered->findChildren<QScrollArea *>()) if(area->isVisible() && area->verticalScrollBar()->maximum()>0) scrolls=true;
                QVERIFY(scrolls);
            }
            if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir+"/recovered-"+name+".png"));
        }
        QVERIFY(!recovered->showPage("missing"));
        QVERIFY(recovered->nativeDialogs().size()>200); QVERIFY(recovered->menuCatalog().size()>50);
        QVERIFY(recovered->showPage("dialog:0")); QVERIFY(recovered->showPage("menu:0"));
        QVERIFY(!recovered->showPage("menu:-1")); QVERIFY(!recovered->showPage("dialog:999999"));
        auto *query=shell.findChild<QLineEdit *>("RecoverySearch"); QVERIFY(query);
        query->setText("MMHenryComps_Input");
        int visibleLeaves=0;
        for (QTreeWidgetItemIterator it(tree); *it; ++it)
            if (!(*it)->childCount() && !(*it)->isHidden()) ++visibleLeaves;
        QVERIFY(visibleLeaves>=1); QVERIFY(visibleLeaves<20);
        query->clear();
        // Existing ribbon entry points must reach recovered forms and return to Components.
        const QMap<QString,QString> targets{{"setup","MMSetup_Setup"},{"methods","MMProp_Spec_Input"}};
        for (auto it=targets.cbegin();it!=targets.cend();++it) {
            auto *button=shell.findChild<QToolButton *>(it.key()); QVERIFY(button);
            button->click(); QVERIFY(recovered->isVisible());
            QVERIFY(recovered->findChild<QLabel *>("RecoveredTitle")->text().contains(it.value()));
        }
        shell.findChild<QToolButton *>("property-sets")->click();
        auto *objects=shell.findChild<ObjectWorkspace *>();QVERIFY(objects->isVisible());
        QVERIFY(objects->findChild<QWidget *>("ObjectManager")->isVisible());
        QCOMPARE(objects->findChild<QTableWidget *>("ObjectTable")->rowCount(),0);
        auto *componentsButton=shell.findChild<QToolButton *>("components"); QVERIFY(componentsButton);
        componentsButton->click(); QVERIFY(!recovered->isVisible());
        QVERIFY(shell.findChild<ComponentWorkspace *>()->isVisible());
        shell.findChild<QToolButton *>("setup")->click();
        shell.resize(800,540); QCoreApplication::processEvents();
        QVERIFY(recovered->width()>400);
    }

    void iconsAndPageNavigation()
    {
        QFile catalog(":/ui/aspen-plus.json");
        QVERIFY(catalog.open(QIODevice::ReadOnly));
        QFile styles(":/ui/shell.qss");
        QVERIFY(styles.open(QIODevice::ReadOnly));
        qApp->setStyleSheet(QString::fromUtf8(styles.readAll()));
        UiShell shell(QJsonDocument::fromJson(catalog.readAll()).object());
        shell.show();
        QTest::qWait(50);
        auto *workspace = shell.findChild<ComponentWorkspace *>();
        QVERIFY(workspace);
        QCOMPARE(workspace->pageIds().size(), 17);
        auto *tree = shell.findChild<QTreeWidget *>("PropertiesNavigation");
        QVERIFY(tree);
        QFile manifest(":/ui/icons/manifest.json");
        QVERIFY(manifest.open(QIODevice::ReadOnly));
        const auto icons = QJsonDocument::fromJson(manifest.readAll()).object().value("icons").toObject();
        QCOMPARE(icons.size(), 97);
        for (const auto &id : icons.keys()) QVERIFY2(!aspenIcon(id).isNull(), qPrintable(id));

        const auto captureDir = qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if (!captureDir.isEmpty()) QVERIFY(QDir().mkpath(captureDir));
        QSet<QString> visited;
        for (QTreeWidgetItemIterator it(tree); *it; ++it) {
            const auto id = (*it)->data(0, Qt::UserRole).toString();
            if (id.isEmpty() || visited.contains(id)) continue;
            tree->setCurrentItem(*it);
            QCoreApplication::processEvents();
            QCOMPARE(workspace->currentPage(), id);
            QVERIFY(!shell.findChild<QLabel *>("DocumentTitle")->text().isEmpty());
            visited.insert(id);
            auto *tabs = workspace->currentTabs();
            const int count = tabs ? tabs->count() : 1;
            for (int i = 0; i < count; ++i) {
                if (tabs && !tabs->isTabEnabled(i)) continue;
                if (tabs) {
                    QTest::mouseClick(tabs->tabBar(), Qt::LeftButton, Qt::NoModifier, tabs->tabBar()->tabRect(i).center());
                    QCOMPARE(tabs->currentIndex(), i);
                }
                QCoreApplication::processEvents();
                if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir + "/" + id + "-" + QString::number(i) + ".png"));
            }
        }
        QCOMPARE(visited.size(), 17);

        // Switching pages must preserve independent form widgets and tab state.
        QVERIFY(workspace->showPage("specifications"));
        auto *tabs = workspace->currentTabs();
        tabs->setCurrentIndex(4);
        auto *edit = tabs->currentWidget()->findChild<QTextEdit *>("comments-editor");
        QVERIFY(edit);
        edit->setPlainText(QString::fromUtf8("组分注释测试"));
        QVERIFY(workspace->showPage("biomass"));
        QVERIFY(workspace->showPage("specifications"));
        QCOMPARE(tabs->currentIndex(), 4);
        QCOMPARE(edit->toPlainText(), QString::fromUtf8("组分注释测试"));
        QVERIFY(!workspace->showPage("unknown-page"));
        QCOMPARE(workspace->currentPage(), QString("specifications"));

        // Real query dialog is available even when the local data is absent.
        tabs->setCurrentIndex(0);
        auto *find=tabs->findChild<QPushButton *>("find-component");QVERIFY(find);find->click();
        auto *queryDialog=shell.findChild<QDialog *>("FindCompoundDialog");QVERIFY(queryDialog);QVERIFY(queryDialog->isVisible());queryDialog->reject();

        shell.resize(800, 540);
        QVERIFY(workspace->showPage("petroleum-analysis"));
        QCoreApplication::processEvents();
        QVERIFY(workspace->width() > 400);
        QVERIFY(workspace->height() > 250);
        if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir + "/narrow-800.png"));
    }
    void simulationWorkspaceParity() {
        QFile file(":/ui/aspen-plus.json");QVERIFY(file.open(QIODevice::ReadOnly));
        QFile style(":/ui/shell.qss");QVERIFY(style.open(QIODevice::ReadOnly));qApp->setStyleSheet(QString::fromUtf8(style.readAll()));
        UiShell shell(QJsonDocument::fromJson(file.readAll()).object());shell.show();shell.dispatch("flowsheet");QTest::qWait(60);
        auto *objects=shell.findChild<ObjectWorkspace *>();auto *tree=shell.findChild<QTreeWidget *>("SimulationNavigation");
        QVERIFY(tree->isVisible());QCOMPARE(tree->topLevelItemCount(),15);QVERIFY(!shell.findChild<QTreeWidget *>("PropertiesNavigation")->isVisible());
        auto *ribbon=shell.findChild<QTabWidget *>("Ribbon");QCOMPARE(ribbon->tabText(ribbon->currentIndex()),QString::fromUtf8("修改"));
        auto *tabs=objects->findChild<QTabWidget *>("ObjectDocuments");QVERIFY(!tabs->isTabVisible(0));
        auto *categories=objects->findChild<QTabWidget *>("ModelCategories");QCOMPARE(categories->count(),11);
        auto *palette=objects->findChild<QWidget *>("ModelPalette");QVERIFY(palette->isVisible());
        const auto capture=qEnvironmentVariable("ASPEN_CAPTURE_DIR");
        if(!capture.isEmpty()) {QDir().mkpath(capture);QVERIFY(shell.grab().save(capture+"/simulation-parity.png"));}
        // Each advertised model remains reachable from a category, with its original type identity.
        for(const auto &v:objects->definition("blocks").value("types").toArray()) QVERIFY(objects->findChild<QToolButton *>("Model-"+v.toObject().value("id").toString()));
        categories->setCurrentIndex(2);objects->findChild<QToolButton *>("Model-Heater")->click();objects->placeAt({180,120});
        QCOMPARE(objects->objects().size(),1);const auto key=objects->objects()[0].toObject().value("key").toString();QCOMPARE(objects->object(key).value("type").toString(),QString("Heater"));
        auto *lock=shell.findChild<QToolButton *>("LockFlowsheet");lock->click();objects->beginPlacement("blocks","Mixer");objects->placeAt({300,120});QCOMPARE(objects->objects().size(),1);
        lock->click();objects->findChild<QToolButton *>("StreamPaletteButton")->click();objects->placeAt({40,120});objects->placeAt({180,120},key);QCOMPARE(objects->objects().size(),2);
        objects->findChild<QPushButton *>("FlowSelect")->click();
        shell.findChild<QSlider *>("FlowsheetZoom")->setValue(134);QCOMPARE(objects->findChild<QGraphicsView *>("FlowsheetCanvas")->transform().m11(),1.34);
        objects->setModelPaletteVisible(false);QVERIFY(!palette->isVisible());shell.dispatch("model-palette");QVERIFY(palette->isVisible());
        shell.dispatch("components");QVERIFY(!tree->isVisible());QVERIFY(shell.findChild<QTreeWidget *>("PropertiesNavigation")->isVisible());
        shell.dispatch("flowsheet");QVERIFY(tree->isVisible());QCOMPARE(objects->objects().size(),2);
        for(const auto size:{QSize(1101,650),QSize(800,540)}) {shell.resize(size);QTest::qWait(30);QVERIFY(objects->findChild<QGraphicsView *>("FlowsheetCanvas")->height()>150);QVERIFY(categories->width()>350);}
        if(!capture.isEmpty()) QVERIFY(shell.grab().save(capture+"/simulation-narrow.png"));
    }

};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    // UI fixtures select their own databases. Never inherit or change user settings.
    QTemporaryDir settings;
    if(!settings.isValid())qFatal("Cannot create isolated UI test settings");
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings::setPath(QSettings::IniFormat,QSettings::UserScope,settings.path());
    qunsetenv("ASPEN_PROPERTY_DATABASE");
#ifdef Q_OS_WIN
    // The offscreen plugin has no Windows system-font fallback of its own.
    QFontDatabase::addApplicationFont("C:/Windows/Fonts/msyh.ttc");
    QApplication::setFont(QFont("Microsoft YaHei", 9));
#endif
    applyLightTheme(app);
    if(!qEnvironmentVariable("ASPEN_CAPTURE_DIR").isEmpty()) {
        QFile styles(":/ui/shell.qss");if(styles.open(QIODevice::ReadOnly))app.setStyleSheet(QString::fromUtf8(styles.readAll()));
    }
    UiSmokeTest tests;
    return QTest::qExec(&tests, argc, argv);
}

#include "UiSmokeTest.moc"
