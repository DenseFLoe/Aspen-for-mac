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
#include <QScrollArea>
#include <QScrollBar>
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
private:
    QString databaseFixture(const QString &directory) {
        const auto path=directory+"/catalog.sqlite";
        {
            auto db=QSqlDatabase::addDatabase("QSQLITE","fixture-writer");db.setDatabaseName(path);if(!db.open()) return {};
            QSqlQuery q(db);
            const QStringList statements{
                "CREATE TABLE metadata(key TEXT,value TEXT)",
                "INSERT INTO metadata VALUES ('schema_version','1'),('dataset_id','aspen-v15-synthetic-test'),('validation','query-only-unverified-for-calculation')",
                "CREATE TABLE compounds(db TEXT,id TEXT,name TEXT,alias TEXT,cas TEXT)",
                "INSERT INTO compounds VALUES ('TEST','1','TEST-WATER','H2O','7732-18-5')",
                "CREATE TABLE identifiers(db TEXT,compound_id TEXT,kind TEXT,value TEXT)",
                "INSERT INTO identifiers VALUES ('TEST','1','NAME','TEST-WATER'),('TEST','1','ALIAS','H2O'),('TEST','1','CASRN','7732-18-5'),('TEST','1','SYNONYM','A%_literal')",
                "CREATE TABLE parameters(db TEXT,cp_id INTEGER,compound_id TEXT,property_id INTEGER)",
                "INSERT INTO parameters VALUES ('TEST',7,'1',3)",
                "CREATE TABLE properties(db TEXT,id INTEGER,name TEXT,description TEXT,units TEXT,metadata TEXT)",
                "INSERT INTO properties VALUES ('TEST',3,'FAKE','Synthetic parameter','[]','{}')",
                "CREATE TABLE parameter_values(db TEXT,cp_id INTEGER,element_index INTEGER,value_text TEXT)",
                "INSERT INTO parameter_values VALUES ('TEST',7,100,'123.456789012345678901')",
                "CREATE TABLE refs(db TEXT,dbc_id INTEGER,cp_id INTEGER,bank_id INTEGER)",
                "INSERT INTO refs VALUES ('TEST',11,7,9)",
                "CREATE TABLE databanks(db TEXT,id INTEGER,name TEXT)",
                "INSERT INTO databanks VALUES ('TEST',9,'SYNTHETIC')",
                "CREATE TABLE citations(db TEXT,id INTEGER,record TEXT)",
                "CREATE TABLE citation_links(db TEXT,dbc_id INTEGER,citation_id INTEGER)",
                "CREATE TABLE notes(db TEXT,dbc_id INTEGER,note TEXT)",
                "INSERT INTO notes VALUES ('TEST',11,'Synthetic provenance')",
                "CREATE TABLE data_info(db TEXT,dbc_id INTEGER,record TEXT)",
                "CREATE TABLE sources(db TEXT,table_name TEXT,file TEXT,sha256 TEXT,row_count INTEGER)",
                "INSERT INTO sources VALUES ('TEST','active_Compounds','synthetic.jsonl','test-only',1)"
            };
            for(const auto &sql:statements) if(!q.exec(sql)) {qWarning()<<q.lastError();return {};}
        }
        QSqlDatabase::removeDatabase("fixture-writer");return path;
    }
private slots:
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
        auto *selected=dialog->findChild<QListWidget *>("SelectedDatabaseComponents");selected->setCurrentRow(0);dialog->findChild<QPushButton *>("RemoveDatabaseComponent")->click();QCOMPARE(shell.project()->state().value("components").toArray().size(),0);
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
        shell.dispatch("methods");auto *method= shell.findChild<RecoveredWorkspace *>()->findChild<QComboBox *>("MMComboBox4");QVERIFY(method);method->setCurrentText("NRTL");QCOMPARE(method->currentText(),QString("NRTL"));
        auto *components=shell.findChild<ComponentWorkspace *>();QVERIFY(components->showPage("specifications"));components->currentTabs()->setCurrentIndex(4);components->currentTabs()->currentWidget()->findChild<QTextEdit *>("comments-editor")->setPlainText("project notes");
        QVERIFY2(shell.saveProject(temp.filePath("input.afmp"),&error),qPrintable(error));
        UiShell other(spec);QVERIFY(other.loadProject(temp.filePath("input.afmp"),&error));auto *ow=other.findChild<ObjectWorkspace *>();QVERIFY(ow->openObject(key));
        auto *ov=qobject_cast<RecoveredWorkspace *>(ow->findChild<QTabWidget *>("ObjectDocuments")->currentWidget());QCOMPARE(ov->findChild<QTextEdit *>("commentsDescription")->toPlainText(),QString::fromUtf8("持久输入"));
        QCOMPARE(ov->findChild<QTableWidget *>("grdSelection")->item(0,0)->text(),QString("TEMP"));
        other.dispatch("methods");QCOMPARE(other.findChild<RecoveredWorkspace *>()->findChild<QComboBox *>("MMComboBox4")->currentText(),QString("NRTL"));
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
#ifdef Q_OS_WIN
    // The offscreen plugin has no Windows system-font fallback of its own.
    QFontDatabase::addApplicationFont("C:/Windows/Fonts/msyh.ttc");
    QApplication::setFont(QFont("Microsoft YaHei", 9));
#endif
    applyLightTheme(app);
    UiSmokeTest tests;
    return QTest::qExec(&tests, argc, argv);
}

#include "UiSmokeTest.moc"
