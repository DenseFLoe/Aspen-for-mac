#include "UiShell.h"
#include "ProjectDocument.h"
#include "ProcessGuidance.h"
#include "ProcessInputWidget.h"
#include "ObjectWorkspace.h"
#include "RecoveredWorkspace.h"
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabWidget>

void UiShell::updateProcessStatus() {
    if(!project_)return;
    const auto problems=ProcessGuidance::issues(project_->state());
    if(auto *label=findChild<QLabel *>("Incomplete")) {
        label->setText(problems.isEmpty()?QString::fromUtf8("参考案例输入完整 · 未接入计算"):QString::fromUtf8("输入待完成（%1 项）").arg(problems.size()));
        label->setToolTip(problems.isEmpty()?QString::fromUtf8("已通过本轮字段与基本拓扑检查；物性参数和计算尚未验证。"):problems.first().message);
        label->setProperty("inputComplete",problems.isEmpty());
        label->setStyleSheet(problems.isEmpty()?"background: #d7eadb; color: #214f2f; padding: 1px;":"");
    }
}
void UiShell::nextProcessInput() {
    if(auto *editor=QApplication::focusWidget();editor && isAncestorOf(editor))editor->clearFocus();
    objects_->commitProcessEditors();
    captureProject();
    const auto current=documents_->currentWidget()==objects_?objects_->currentObject():QString();
    const auto issue=ProcessGuidance::next(project_->state(),current);
    statusBar()->clearMessage();
    if(issue.message.isEmpty()) {
        auto *message=new QMessageBox(QMessageBox::Information,QString::fromUtf8("参考案例输入完整"),
            QString::fromUtf8("Flash2 参考流程的字段和基本连接检查已通过。\n物性参数校验与闪蒸求解尚未接入，目前不能运行模拟或生成结果。"),QMessageBox::Ok,this);
        message->setObjectName("ProcessInputComplete");message->setAttribute(Qt::WA_DeleteOnClose);message->open();
    } else {
        if(issue.field=="components")dispatch("component:specifications");
        else if(issue.field=="method") {
            dispatch("methods");setWorkspaceMode(false);
            if(auto *method=recovered_->findChild<QComboBox *>("ProcessMethod"))method->setFocus();
        } else if(issue.field=="flowsheet" || issue.field=="unsupported")dispatch("flowsheet");
        else {
            dispatch("object:"+issue.object);
            auto *tabs=objects_->findChild<QTabWidget *>("ObjectDocuments");
            if(tabs && tabs->currentWidget())if(auto *editor=tabs->currentWidget()->findChild<ProcessInputWidget *>())editor->focusField(issue.field);
        }
        statusBar()->showMessage(issue.message,15000);
    }
    updateProcessStatus();
}
