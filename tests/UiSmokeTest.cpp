#include "UiShell.h"
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
        objects->findChild<QPushButton *>("Place-blocks")->click();
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
        auto *find=shell.findChild<QDialog *>("dialog-FindComounds"); QVERIFY(find); find->reject();
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

        // Modal wiring: Find opens; close ends the modal loop without a backend.
        tabs->setCurrentIndex(0);
        auto *find = tabs->findChild<QPushButton *>("find-component");
        QVERIFY(find);
        bool dialogSeen = false;
        QTimer::singleShot(30, [&dialogSeen] {
            if (auto *dialog = qobject_cast<QDialog *>(QApplication::activeModalWidget())) {
                dialogSeen = dialog->objectName() == "FindCompoundDialog";
                dialog->reject();
            }
        });
        find->click();
        QVERIFY(dialogSeen);

        shell.resize(800, 540);
        QVERIFY(workspace->showPage("petroleum-analysis"));
        QCoreApplication::processEvents();
        QVERIFY(workspace->width() > 400);
        QVERIFY(workspace->height() > 250);
        if (!captureDir.isEmpty()) QVERIFY(shell.grab().save(captureDir + "/narrow-800.png"));
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
