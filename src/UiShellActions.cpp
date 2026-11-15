#include "UiShell.h"
#include "ComponentWorkspace.h"
#include "RecoveredWorkspace.h"
#include "ObjectWorkspace.h"
#include "IconCatalog.h"
#include <QAction>
#include <QBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QPushButton>
#include <QScrollArea>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabWidget>
#include <QTextEdit>
#include <QToolButton>
#include <QTreeWidget>
#include <QTreeWidgetItemIterator>

void UiShell::remember(const QString &location)
{
    if (!traversing_ && locations_.value(locationIndex_)!=location) {
        locations_=locations_.mid(0,locationIndex_+1);
        locations_.append(location); locationIndex_=locations_.size()-1;
    }
    if (auto *back=findChild<QToolButton *>("window-back")) back->setEnabled(locationIndex_>0);
    if (auto *forward=findChild<QToolButton *>("window-forward")) forward->setEnabled(locationIndex_+1<locations_.size());
}

void UiShell::setUnits(const QString &units)
{
    if (!QStringList{"ENG","MET","METCBAR","SI"}.contains(units)) return;
    globalUnits_=units; recovered_->setGlobalUnits(units); objects_->setGlobalUnits(units);
    if (auto *button=findChild<QToolButton *>("unit-selector")) {
        button->setText(units);
        for (auto *action:button->menu()->actions()) action->setChecked(action->text()==units);
    }
    captureProject();
}

void UiShell::notifyUnavailable(const QString &label)
{
    statusBar()->showMessage(label+QString::fromUtf8("：此功能需要 Aspen 服务或案例数据，当前外壳未执行该操作。"),8000);
}

void UiShell::openDialog(const QString &name)
{
    const auto id=recovered_->idForName(name);
    if (id.isEmpty()) { notifyUnavailable(name); return; }
    auto *dialog=new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setObjectName("dialog-"+name);
    dialog->resize(780,600);
    auto *layout=new QVBoxLayout(dialog);
    auto *workspace=new RecoveredWorkspace(dialog);
    workspace->setGlobalUnits(globalUnits_); workspace->showPage(id);
    dialog->setWindowTitle(workspace->findChild<QLabel *>("RecoveredTitle")->text().section("  ",0,0));
    connect(workspace,&RecoveredWorkspace::actionRequested,this,&UiShell::dispatch,Qt::QueuedConnection);
    connect(workspace,&RecoveredWorkspace::closeRequested,dialog,&QDialog::reject);
    layout->addWidget(workspace,1);
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Close,dialog);
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject); layout->addWidget(buttons);
    dialog->open();
}

void UiShell::openWizard(const QString &name)
{
    const auto spec=interactions_.value("wizards").toObject().value(name).toObject();
    if (spec.isEmpty()) return;
    auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setObjectName("wizard-"+name); dialog->setWindowTitle(spec.value("title").toString()); dialog->resize(760,570);
    auto *layout=new QVBoxLayout(dialog);
    auto *steps=new QStackedWidget(dialog); steps->setObjectName("WizardSteps");
    for (const auto &page:spec.value("pages").toArray()) {
        auto *workspace=new RecoveredWorkspace(steps);
        workspace->setSessionEditable(name=="user-component");
        workspace->showPage(workspace->idForName(page.toString()));
        workspace->findChild<QLabel *>("RecoveredTitle")->hide();
        connect(workspace,&RecoveredWorkspace::actionRequested,this,&UiShell::dispatch,Qt::QueuedConnection);
        steps->addWidget(workspace);
    }
    layout->addWidget(steps,1);
    auto *status=new QLabel(name=="user-component"?QString::fromUtf8("完成后将添加用户定义组分并保留本次会话的输入。"):
        QString::fromUtf8("当前未连接反应生成或物性估算服务。"),dialog); status->setWordWrap(true); layout->addWidget(status);
    auto *row=new QHBoxLayout; row->addStretch();
    auto *back=new QPushButton(QString::fromUtf8("< 后退"),dialog); back->setObjectName("WizardBack");
    auto *next=new QPushButton(QString::fromUtf8("下一步 >"),dialog); next->setObjectName("WizardNext");
    auto *finish=new QPushButton(QString::fromUtf8("完成"),dialog); finish->setObjectName("WizardFinish"); finish->setEnabled(false);
    auto *cancel=new QPushButton(QString::fromUtf8("取消"),dialog);
    for(auto *b:{back,next,finish,cancel}) row->addWidget(b); layout->addLayout(row);
    const auto update=[this,steps,back,next,finish,name,status] {
        back->setEnabled(steps->currentIndex()>0);
        bool ready=steps->currentIndex()+1<steps->count();
        if (name=="sfe") ready=false; // Empty case has no species to select.
        if (name=="user-component" && steps->currentIndex()==0) {
            const auto *id=steps->widget(0)->findChild<QLineEdit *>("txtCompID");
            ready=ready && id && !id->text().trimmed().isEmpty();
        }
        if (name=="electrolyte" && steps->currentIndex()>=1) ready=false; // Reaction generation is an engine operation.
        if(name=="user-component") {
            const auto *id=steps->widget(0)->findChild<QLineEdit *>("txtCompID");
            const auto problem=objects_->nameError("user-components",id?id->text().trimmed():QString());
            if(!problem.isEmpty()) ready=false;
            finish->setEnabled(problem.isEmpty() && steps->currentIndex()==steps->count()-1);
            status->setText(problem.isEmpty()?QString::fromUtf8("完成后将添加用户定义组分并保留本次会话的输入。"):problem);
        }
        next->setEnabled(ready);
    };
    connect(back,&QPushButton::clicked,dialog,[steps] { steps->setCurrentIndex(steps->currentIndex()-1); });
    connect(next,&QPushButton::clicked,dialog,[steps] { steps->setCurrentIndex(steps->currentIndex()+1); });
    connect(steps,&QStackedWidget::currentChanged,dialog,update);
    if (auto *id=steps->widget(0)->findChild<QLineEdit *>("txtCompID")) connect(id,&QLineEdit::textChanged,dialog,update);
    connect(cancel,&QPushButton::clicked,dialog,&QDialog::reject);
    connect(finish,&QPushButton::clicked,dialog,[this,name,steps,dialog]{
        if(name!="user-component") return;
        auto *id=steps->widget(0)->findChild<QLineEdit *>("txtCompID");if(!id) return;
        const auto *type=steps->widget(0)->findChild<QComboBox *>("cboType");
        const auto key=objects_->createObject("user-components",id->text(),QStringList{"CONVENTIONAL","SOLID","NONCONVENTIONAL"}.value(type?type->currentIndex():0,"CONVENTIONAL"));if(key.isEmpty()) return;
        QMap<QString,QVariantMap> values;
        for(int i=0;i<steps->count();++i) {
            const auto state=qobject_cast<RecoveredWorkspace *>(steps->widget(i))->sessionState();
            for(auto it=state.cbegin();it!=state.cend();++it) values[it.key()]=it.value();
        }
        objects_->setObjectState(key,values);dialog->accept();dispatch("object:"+key);
    });
    update(); dialog->open();
}

void UiShell::dispatch(const QString &requested)
{
    if (projectAction(requested)) return;
    auto action=requested;
    const auto commands=interactions_.value("commands").toObject();
    if (commands.contains(action)) action=commands.value(action).toString();
    if (projectAction(action)) return;
    if (dispatchObjectAction(action)) return;
    if (action.startsWith("component:")) {
        setWorkspaceMode(false);
        pages_->setCurrentIndex(0); documents_->setCurrentIndex(0); components_->showPage(action.mid(10));
    } else if (action.startsWith("page:")) openRecovered(action.mid(5));
    else if (action.startsWith("dialog:")) openDialog(action.mid(7));
    else if (action.startsWith("wizard:")) openWizard(action.mid(7));
    else if (action.startsWith("units:")) setUnits(action.mid(6));
    else if (action.startsWith("navigation-filter:")) {
        const bool inputs=action.mid(18)==QString::fromUtf8("仅输入");
        for (QTreeWidgetItemIterator it(navigation_);*it;++it) {
            const auto label=(*it)->text(0);
            (*it)->setHidden(inputs && (label==QString::fromUtf8("结果") || label==QString::fromUtf8("所选方法")));
        }
        for (auto *button:findChildren<QToolButton *>())
            if (button->menu() && (button->text()==QString::fromUtf8("所有项") || button->text()==QString::fromUtf8("仅输入"))) button->setText(action.mid(18));
    }
    else if (action=="model-palette") {objects_->setModelPaletteVisible(true);}
    else if (action.startsWith("catalog:")) {
        pages_->setCurrentIndex(0);
        navigationPages_->setCurrentIndex(0);
        findChild<QTabWidget *>("NavigationTabs")->setCurrentIndex(1);
        auto *search=findChild<QLineEdit *>("RecoverySearch"); search->setText(action.mid(8)); search->setFocus();
    } else if (action=="window-back" || action=="window-forward") {
        const int next=locationIndex_+(action=="window-back"?-1:1);
        if (next<0 || next>=locations_.size()) return;
        traversing_=true; locationIndex_=next; dispatch(locations_[next]); traversing_=false; remember(locations_[next]);
    } else if (action=="ribbon-collapse") {
        auto *ribbon=findChild<QTabWidget *>("Ribbon"); const bool collapsed=ribbon->height()>40;
        ribbon->setFixedHeight(collapsed?28:122);
        if (auto *button=findChild<QToolButton *>("ribbon-collapse")) button->setIcon(aspenIcon(collapsed?"ribbon-expand":"ribbon-collapse"));
    } else if (action.startsWith("toggle-quick:")) {
        if (auto *button=findChild<QToolButton *>(action.mid(13))) button->setVisible(!button->isVisible());
    } else if (action=="quick-below") {
        auto *quick=findChild<QWidget *>("QuickBar");
        auto *column=qobject_cast<QVBoxLayout *>(quick->parentWidget()->layout());
        const bool below=column->indexOf(quick)==0;
        column->removeWidget(quick); column->insertWidget(below?1:0,quick);
        if (auto *menu=findChild<QToolButton *>("quick-menu")->menu())
            for (auto *item:menu->actions())
                if (item->text()==QString::fromUtf8("显示在功能区下方") || item->text()==QString::fromUtf8("显示在功能区上方"))
                    item->setText(below?QString::fromUtf8("显示在功能区上方"):QString::fromUtf8("显示在功能区下方"));
    } else if (action=="next") {
        dispatch("component:specifications"); statusBar()->showMessage(QString::fromUtf8("请先选择组分，再指定物性方法。"),7000);
    } else if (action=="control-panel" || action=="messages") {
        auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("ControlPanel"); dialog->setWindowTitle(QString::fromUtf8("控制面板")); dialog->resize(680,400);
        auto *layout=new QVBoxLayout(dialog); auto *text=new QTextEdit(dialog); text->setReadOnly(true);
        text->setPlainText(QString::fromUtf8("所需输入不完整\n\n当前界面未连接 Aspen 计算引擎，没有运行记录或模拟结果。")); layout->addWidget(text);
        auto *close=new QDialogButtonBox(QDialogButtonBox::Close,dialog); connect(close,&QDialogButtonBox::rejected,dialog,&QDialog::reject); layout->addWidget(close); dialog->open();
    } else if (action=="options-dialog") {
        auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("OptionsDialog"); dialog->setWindowTitle(QString::fromUtf8("选项")); dialog->resize(900,600);
        auto *layout=new QVBoxLayout(dialog); auto *tabs=new QTabWidget(dialog); layout->addWidget(tabs);
        const QStringList names{"SimulationDialog","PropertiesBasisDialog","FilesDialog","FlowsheetDialog","PlotsDialog","UpwardCompatibilityDialog","AdvancedDialog"};
        const QStringList labels{QString::fromUtf8("模拟"),QString::fromUtf8("物性"),QString::fromUtf8("文件"),QString::fromUtf8("流程图"),QString::fromUtf8("绘图"),QString::fromUtf8("向上兼容"),QString::fromUtf8("高级")};
        for(int i=0;i<names.size();++i) { auto *workspace=new RecoveredWorkspace(tabs); workspace->showPage(workspace->idForName(names[i])); tabs->addTab(workspace,labels[i]); }
        auto *close=new QDialogButtonBox(QDialogButtonBox::Close,dialog); connect(close,&QDialogButtonBox::rejected,dialog,&QDialog::reject); layout->addWidget(close); dialog->open();
    } else if (action=="about-dialog" || action.startsWith("help:") || action=="help" || action=="quick-help") {
        auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("ShellHelpDialog"); dialog->setWindowTitle(QString::fromUtf8("Aspen Plus 界面外壳"));
        auto *layout=new QVBoxLayout(dialog); auto *text=new QLabel(action=="help:method-assistant"?QString::fromUtf8("原版方法助手打开帮助系统的 Property Method Selection Assistant。\n此跨平台外壳未包含原版帮助系统；可通过“方法 → 规定”查看方法设置。") : QString::fromUtf8("Aspen Plus V15 界面研究 · Qt 6\n页面、选项与图像来自原版资源及实际界面观察。\n本程序不含 Aspen 计算引擎。"),dialog);
        text->setWordWrap(true); layout->addWidget(text); auto *close=new QDialogButtonBox(QDialogButtonBox::Close,dialog); connect(close,&QDialogButtonBox::rejected,dialog,&QDialog::reject); layout->addWidget(close); dialog->open();
    } else if (action=="backstage") pages_->setCurrentIndex(1);
    else if (action=="file-close") { pages_->setCurrentIndex(0); documents_->setCurrentIndex(2); }
    else if (action=="unit-selector" || action=="quick-menu" || action=="analysis-menu" || action=="window-list") return;
    else {
        const auto *button=findChild<QToolButton *>(requested);
        notifyUnavailable(action.startsWith("unavailable:")?action.mid(12):button?button->text():requested);
    }
}
