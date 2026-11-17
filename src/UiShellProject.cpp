#include <QComboBox>
#include <QVBoxLayout>
#include <QSignalBlocker>
#include "UiShell.h"
#include "ProjectDocument.h"
#include "ChemicalSystem.h"
#include "PropertyDatabase.h"
#include "DatabaseDialog.h"
#include <QLabel>
#include <QSettings>
#include "ObjectWorkspace.h"
#include "ComponentWorkspace.h"
#include "RecoveredWorkspace.h"
#include <QCloseEvent>
#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QShortcut>
#include <QStackedWidget>
#include <QStatusBar>
#include <QToolButton>
#include <QScopedValueRollback>

void UiShell::initializeProject() {
    database_=new PropertyDatabase(this);
    QString error; const auto dbPath=qEnvironmentVariable("ASPEN_PROPERTY_DATABASE",QSettings("AspenForMac","UIShell").value("databasePath").toString());
    if(!dbPath.isEmpty()) database_->open(dbPath,&databaseError_);
    auto *dbStatus=new QLabel(this);dbStatus->setObjectName("DatabaseStatus");statusBar()->addPermanentWidget(dbStatus);
    project_=new ProjectDocument(this); project_->setObjectName("ProjectDocument");
    connect(components_,&ComponentWorkspace::componentTypeChanged,this,[this](const QString &db,const QString &id,const QString &type) {
        auto state=project_->state();auto components=state.value("components").toArray();
        for(int i=0;i<components.size();++i) {
            auto c=components[i].toObject();if(c.value("database")!=db || c.value("compoundId")!=id)continue;
            c["componentType"]=type;components[i]=c;break;
        }
        state["components"]=components;
        if(!ChemicalSystem::validate(state).isEmpty()) {
            statusBar()->showMessage(QString::fromUtf8("该类别与已生成化学系统不兼容；请先撤销相关向导生成。"),6000);
            components_->setUserComponents(objects_->objects());return;
        }
        project_->edit(state);
    });
    connect(objects_,&ObjectWorkspace::objectsChanged,this,&UiShell::captureProject);
    connect(objects_,&ObjectWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(components_,&ComponentWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(recovered_,&RecoveredWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(project_,&ProjectDocument::restored,this,&UiShell::restoreProject);
    connect(project_,&ProjectDocument::changed,this,[this] {
        components_->setDatabaseComponents(project_->state().value("components").toArray());
        components_->setGeneratedComponents(project_->state().value("chemicalSystem").toObject().value("generatedComponents").toArray());
        objects_->setChemicalSystemState(project_->state());
        components_->setUserComponents(objects_->objects());
        const auto global=project_->state().value("chemicalSystem").toObject().value("global").toObject();
        components_->setChemicalSummary(global.isEmpty()?QString():QString::fromUtf8("全局 Chemistry：%1  ·  物性方法：%2  ·  %3（未接入计算）")
            .arg(ChemicalSystem::globalChemistryId(project_->state()),global.value("method").toString(QString::fromUtf8("未设置")),
                global.contains("trueComponents")?(global.value("trueComponents").toBool()?QString::fromUtf8("真实组分"):QString::fromUtf8("表观组分")):QString::fromUtf8("模拟方式未设置")));
        if(auto *method=recovered_->findChild<QComboBox *>("ProcessMethod")) {
            const QSignalBlocker blocked(method);
            const auto value=project_->state().value("process").toObject().value("method").toString();
            if(method->findText(value)<0)method->addItem(value);method->setCurrentText(value);
        }
        updateDatabaseStatus();
        const auto name=project_->fileName().isEmpty()?QString::fromUtf8("未命名项目"):QFileInfo(project_->fileName()).fileName();
        setWindowTitle(name+(project_->isModified()?" *":"")+QString::fromUtf8(" — Aspen for Mac"));
        for(const auto &id:{"undo","quick-undo"}) if(auto *b=findChild<QToolButton *>(id)) b->setEnabled(project_->canUndo());
        for(const auto &id:{"redo","quick-redo"}) if(auto *b=findChild<QToolButton *>(id)) b->setEnabled(project_->canRedo());
    });
    const QList<QPair<QKeySequence,QString>> keys{{QKeySequence::New,"file-new"},{QKeySequence::Open,"file-open"},
        {QKeySequence::Save,"file-save"},{QKeySequence::SaveAs,"file-save-as"},{QKeySequence::Undo,"undo"},{QKeySequence::Redo,"redo"}};
    for(const auto &k:keys) {auto *s=new QShortcut(k.first,this);connect(s,&QShortcut::activated,this,[this,k]{projectAction(k.second);});}
    project_->reset();
}
void UiShell::captureProject() {
    if(!project_ || restoringProject_) return;
    auto state=project_->state(); state["objects"]=objects_->projectObjects(); state["units"]=globalUnits_;
    QJsonObject recovered;
    const auto values=recovered_->sessionState();
    for(auto it=values.cbegin();it!=values.cend();++it) recovered[it.key()]=QJsonObject::fromVariantMap(it.value());
    auto inputs=state.value("unverifiedInputs").toObject();
    inputs["recovered"]=recovered;inputs["components"]=components_->sessionState();
    state["unverifiedInputs"]=inputs;
    project_->edit(ChemicalSystem::removeMissingGlobalReferences(state));
}
void UiShell::restoreProject() {
    const QScopedValueRollback<bool> guard(restoringProject_,true);
    const auto s=project_->state(); setUnits(s.value("units").toString());
    objects_->setChemicalSystemState(s);
    components_->setDatabaseComponents(s.value("components").toArray());
    components_->setGeneratedComponents(s.value("chemicalSystem").toObject().value("generatedComponents").toArray());
    objects_->restoreProjectObjects(s.value("objects").toArray());
    const auto inputs=s.value("unverifiedInputs").toObject();
    QMap<QString,QVariantMap> recovered; const auto pages=inputs.value("recovered").toObject();
    for(auto it=pages.begin();it!=pages.end();++it) recovered[it.key()]=it.value().toObject().toVariantMap();
    recovered_->setSessionState(recovered);
    installMethodEditor();
    components_->restoreSessionState(inputs.value("components").toObject());
    locations_.clear(); locationIndex_=-1; syncObjectNavigation();
    for(const auto &id:{"window-back","window-forward"}) if(auto *button=findChild<QToolButton *>(id)) button->setEnabled(false);
}
bool UiShell::saveProject(const QString &path,QString *error) {
    // Commit an active item delegate before serializing the document.
    if(auto *editor=QApplication::focusWidget();editor && isAncestorOf(editor)) editor->clearFocus();
    return project_->save(path,error);
}
bool UiShell::loadProject(const QString &path,QString *error) { return project_->load(path,error); }
bool UiShell::saveProjectDialog(bool saveAs) {
    auto path=project_->fileName();
    if(saveAs || path.isEmpty()) path=QFileDialog::getSaveFileName(this,QString::fromUtf8("保存项目"),path.isEmpty()?"Untitled.afmp":path,QString::fromUtf8("Aspen for Mac 项目 (*.afmp)"));
    if(path.isEmpty()) return false;
    if(QFileInfo(path).suffix().isEmpty()) path+=".afmp";
    QString error;
    if(!saveProject(path,&error)) {QMessageBox::warning(this,QString::fromUtf8("保存失败"),error); return false;}
    pages_->setCurrentIndex(0); statusBar()->showMessage(QString::fromUtf8("项目已保存：")+path,6000); return true;
}
bool UiShell::confirmProjectReplacement() {
    if(auto *editor=QApplication::focusWidget();editor && isAncestorOf(editor)) editor->clearFocus();
    if(!project_->isModified()) return true;
    const auto answer=QMessageBox::warning(this,QString::fromUtf8("未保存的项目"),QString::fromUtf8("保存当前项目的更改？"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save);
    return answer==QMessageBox::Discard || (answer==QMessageBox::Save && saveProjectDialog(false));
}
void UiShell::closeEvent(QCloseEvent *event) { if(confirmProjectReplacement()) event->accept(); else event->ignore(); }
bool UiShell::projectAction(const QString &action) {
    if(action=="database-search" || action=="find-component" || action=="dialog:FindComounds") {showDatabaseSearch();return true;}
    if(action=="undo" || action=="quick-undo") project_->undo();
    else if(action=="redo" || action=="quick-redo") project_->redo();
    else if(action=="file-save" || action=="save" || action=="quick-save") saveProjectDialog(false);
    else if(action=="file-save-as" || action=="file-saveas") saveProjectDialog(true);
    else if(action=="file-open" || action=="open") {
        const auto path=QFileDialog::getOpenFileName(this,QString::fromUtf8("打开项目"),{},QString::fromUtf8("Aspen for Mac 项目 (*.afmp)"));
        if(!path.isEmpty() && confirmProjectReplacement()) {QString error; if(!loadProject(path,&error)) QMessageBox::warning(this,QString::fromUtf8("打开失败"),error); else pages_->setCurrentIndex(0);}
    } else if(action=="file-new" || action=="new-simulation" || action=="file-close" || action=="new") {if(confirmProjectReplacement()) {project_->reset();pages_->setCurrentIndex(0);}}
    else return false;
    return true;
}

bool UiShell::openPropertyDatabase(const QString &path,QString *error) {
    const bool result=database_->open(path,error);databaseError_=*error;updateDatabaseStatus();return result;
}
void UiShell::updateDatabaseStatus() {
    auto *label=findChild<QLabel *>("DatabaseStatus");if(!label || !project_) return;
    const auto expected=project_->state().value("dependencies").toObject().value("propertyDatabase").toString();
    label->setText(!database_->isOpen()?(databaseError_.isEmpty()?QString::fromUtf8("物性库未连接；组分身份仍可保存"):databaseError_):
        !expected.isEmpty() && expected!=database_->datasetId()?QString::fromUtf8("物性库版本与项目不符；请连接原数据版本"):QString::fromUtf8("物性库只读 · 未接入计算"));
    label->setToolTip(database_->isOpen()?database_->path()+"\n"+database_->datasetId():QString::fromUtf8("在组分查找窗口选择 catalog.sqlite"));
}
void UiShell::showDatabaseSearch() {
    auto *dialog=new DatabaseDialog(database_,project_,this);dialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(dialog,&DatabaseDialog::databaseChanged,this,[this] {databaseError_.clear();updateDatabaseStatus();});dialog->open();
}

void UiShell::installMethodEditor() {
    if(!project_ || recovered_->currentPage()!=recovered_->idForName("MMProp_Spec_Input"))return;
    auto *method=recovered_->findChild<QComboBox *>("MMComboBox4");if(!method)return;
    const QSignalBlocker blocked(method);
    disconnect(method,nullptr,recovered_,nullptr);
    method->setProperty("projectDerived",true);method->setObjectName("ProcessMethod");
    method->setAccessibleName(QString::fromUtf8("全局物性方法"));method->setEditable(false);
    method->clear();method->addItems({"","NRTL","IDEAL"});
    const auto value=project_->state().value("process").toObject().value("method").toString();
    if(method->findText(value)<0)method->addItem(value);method->setCurrentText(value);
    method->setToolTip(QString::fromUtf8("本轮支持记录 NRTL / IDEAL；参数校验与计算尚未接入。其他设置仍为未校验输入。"));
    connect(method,&QComboBox::currentTextChanged,method,[this](const QString &value){auto state=project_->state();state["process"]=QJsonObject{{"version",1},{"method",value}};project_->edit(state);});
}
