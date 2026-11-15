#include "UiShell.h"
#include "ProjectDocument.h"
#include "ObjectWorkspace.h"
#include "ComponentWorkspace.h"
#include "RecoveredWorkspace.h"
#include <QCloseEvent>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QShortcut>
#include <QStackedWidget>
#include <QStatusBar>
#include <QToolButton>
#include <QScopedValueRollback>

void UiShell::initializeProject() {
    project_=new ProjectDocument(this); project_->setObjectName("ProjectDocument");
    connect(objects_,&ObjectWorkspace::objectsChanged,this,&UiShell::captureProject);
    connect(objects_,&ObjectWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(components_,&ComponentWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(recovered_,&RecoveredWorkspace::inputsChanged,this,&UiShell::captureProject);
    connect(project_,&ProjectDocument::restored,this,&UiShell::restoreProject);
    connect(project_,&ProjectDocument::changed,this,[this] {
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
    state["unverifiedInputs"]=QJsonObject{{"recovered",recovered},{"components",components_->sessionState()}};
    project_->edit(state);
}
void UiShell::restoreProject() {
    const QScopedValueRollback<bool> guard(restoringProject_,true);
    const auto s=project_->state(); setUnits(s.value("units").toString());
    objects_->restoreProjectObjects(s.value("objects").toArray());
    const auto inputs=s.value("unverifiedInputs").toObject();
    QMap<QString,QVariantMap> recovered; const auto pages=inputs.value("recovered").toObject();
    for(auto it=pages.begin();it!=pages.end();++it) recovered[it.key()]=it.value().toObject().toVariantMap();
    recovered_->setSessionState(recovered);
    components_->restoreSessionState(inputs.value("components").toObject());
    locations_.clear(); locationIndex_=-1; syncObjectNavigation();
}
bool UiShell::saveProject(const QString &path,QString *error) { return project_->save(path,error); }
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
    if(!project_->isModified()) return true;
    const auto answer=QMessageBox::warning(this,QString::fromUtf8("未保存的项目"),QString::fromUtf8("保存当前项目的更改？"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save);
    return answer==QMessageBox::Discard || (answer==QMessageBox::Save && saveProjectDialog(false));
}
void UiShell::closeEvent(QCloseEvent *event) { if(confirmProjectReplacement()) event->accept(); else event->ignore(); }
bool UiShell::projectAction(const QString &action) {
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
