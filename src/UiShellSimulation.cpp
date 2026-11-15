#include "UiShell.h"
#include "ObjectWorkspace.h"
#include "IconCatalog.h"
#include <QBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QMenu>
#include <QScrollArea>
#include <QSignalBlocker>
#include <QStyle>
#include <QTabWidget>
#include <QToolButton>
#include <QTreeWidget>
#include <functional>

QWidget *UiShell::makeSimulationRibbon()
{
    auto *content=new QWidget;content->setObjectName("RibbonContent");
    auto *row=new QHBoxLayout(content);row->setContentsMargins(4,3,4,0);row->setSpacing(2);
    auto group=[&](const QString &label) {
        auto *frame=new QFrame(content);frame->setObjectName("RibbonGroup");auto *column=new QVBoxLayout(frame);column->setContentsMargins(5,0,7,0);column->setSpacing(0);
        auto *grid=new QGridLayout;grid->setSpacing(2);column->addLayout(grid,1);auto *title=new QLabel(label,frame);title->setObjectName("GroupTitle");title->setAlignment(Qt::AlignCenter);column->addWidget(title);row->addWidget(frame);return grid;
    };
    auto tool=[this,content](QGridLayout *grid,int r,int c,const QString &text,const QString &icon={}) {
        auto *button=makeButton({{"label",text},{"icon",icon},{"enabled",false}},content);if(button->icon().isNull())button->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));grid->addWidget(button,r,c);return button;
    };
    auto *flow=group(QString::fromUtf8("工艺流程"));
    auto *rotate=tool(flow,0,0,QString::fromUtf8("旋转"));
    auto *flipHorizontal=tool(flow,1,0,QString::fromUtf8("水平翻转"));
    auto *flipVertical=tool(flow,2,0,QString::fromUtf8("垂直翻转"));
    rotate->setObjectName("RotateFlowsheetBlock");
    flipHorizontal->setObjectName("FlipFlowsheetBlockHorizontal");
    flipVertical->setObjectName("FlipFlowsheetBlockVertical");
    connect(rotate,&QToolButton::clicked,this,[this]{objects_->transformSelectedBlock("rotate");});
    connect(flipHorizontal,&QToolButton::clicked,this,[this]{objects_->transformSelectedBlock("flip-horizontal");});
    connect(flipVertical,&QToolButton::clicked,this,[this]{objects_->transformSelectedBlock("flip-vertical");});
    auto *reconnect=tool(flow,0,1,QString::fromUtf8("重新连接"));reconnect->setObjectName("ReconnectFlowsheetStream");
    auto *reconnectMenu=new QMenu(reconnect);reconnect->setMenu(reconnectMenu);reconnect->setPopupMode(QToolButton::InstantPopup);
    for(const auto &end:QStringList{"from","to"}){auto *action=reconnectMenu->addAction(end=="from"?QString::fromUtf8("重新连接源"):QString::fromUtf8("重新连接目标"));connect(action,&QAction::triggered,this,[this,end]{objects_->beginReconnection(objects_->selectedFlowsheetObject(),end);});}
    tool(flow,1,1,QString::fromUtf8("打断流股"));tool(flow,2,1,QString::fromUtf8("插入"));
    tool(flow,0,2,QString::fromUtf8("连接流股"));tool(flow,1,2,QString::fromUtf8("重排流股"));tool(flow,2,2,QString::fromUtf8("对齐"));
    auto *unit=group(QString::fromUtf8("单元操作"));auto *threeD=new QCheckBox(QString::fromUtf8("3D 图标"),content);threeD->setChecked(true);unit->addWidget(threeD,0,0);
    connect(threeD,&QCheckBox::toggled,this,[this](bool checked){objects_->setThreeDimensionalIcons(checked);});
    auto *energy=new QCheckBox(QString::fromUtf8("热/功/电能"),content);energy->setEnabled(false);unit->addWidget(energy,1,0);tool(unit,2,0,QString::fromUtf8("显示状态"),"folder-incomplete");
    auto *results=group(QString::fromUtf8("流股结果"));const QStringList labels{QString::fromUtf8("温度"),QString::fromUtf8("压力"),QString::fromUtf8("汽相分率"),QString::fromUtf8("质量流率"),QString::fromUtf8("摩尔流率"),QString::fromUtf8("体积流率")};
    for(int i=0;i<labels.size();++i){auto *check=new QCheckBox(labels[i],content);check->setEnabled(false);check->setToolTip(QString::fromUtf8("尚无计算结果"));results->addWidget(check,i%3,i/3);}
    auto *display=group(QString());tool(display,0,0,QString::fromUtf8("显示选项"),"control-panel");
    auto *section=group(QString::fromUtf8("工段"));auto *global=new QComboBox(content);global->addItem("GLOBAL");global->setMinimumWidth(100);section->addWidget(global,0,0);
    auto *all=new QCheckBox(QString::fromUtf8("全部显示"),content);all->setChecked(true);all->setEnabled(false);section->addWidget(all,1,0);
    auto *lock=new QToolButton(content);lock->setText(QString::fromUtf8("锁定工艺流程"));lock->setObjectName("LockFlowsheet");lock->setCheckable(true);section->addWidget(lock,2,0);
    connect(lock,&QToolButton::toggled,this,[this](bool locked){objects_->setFlowsheetLocked(locked);});
    const auto updateTransforms=[this,rotate,flipHorizontal,flipVertical,lock,reconnect] {
        const bool enabled=!objects_->flowsheetLocked() && objects_->object(objects_->selectedFlowsheetObject()).value("kind").toString()=="blocks";
        for(auto *button:{rotate,flipHorizontal,flipVertical}) button->setEnabled(enabled);
        reconnect->setEnabled(!objects_->flowsheetLocked() && objects_->object(objects_->selectedFlowsheetObject()).value("kind")=="streams");
    };
    connect(objects_,&ObjectWorkspace::flowsheetSelectionChanged,content,updateTransforms);
    connect(lock,&QToolButton::toggled,content,updateTransforms);
    auto *sub=group(QString::fromUtf8("子流程"));tool(sub,0,0,QString::fromUtf8("查看父项"));tool(sub,1,0,QString::fromUtf8("查看子项"));tool(sub,2,0,QString::fromUtf8("导入"));tool(sub,0,1,QString::fromUtf8("导出"));tool(sub,1,1,QString::fromUtf8("移动选择"));
    row->addStretch();auto *scroll=new QScrollArea;scroll->setWidget(content);scroll->setWidgetResizable(true);scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);return scroll;
}

QWidget *UiShell::makeSimulationNavigator()
{
    simulationNavigation_=new QTreeWidget;simulationNavigation_->setObjectName("SimulationNavigation");simulationNavigation_->setHeaderHidden(true);simulationNavigation_->setIndentation(16);simulationNavigation_->setIconSize(QSize(16,16));
    connect(simulationNavigation_,&QTreeWidget::itemClicked,this,[this](QTreeWidgetItem *item){dispatch(item->data(0,Qt::UserRole+3).toString());});
    connect(simulationNavigation_,&QTreeWidget::itemActivated,this,[this](QTreeWidgetItem *item){dispatch(item->data(0,Qt::UserRole+3).toString());});
    connect(simulationNavigation_,&QTreeWidget::currentItemChanged,this,[this](QTreeWidgetItem *item){if(item)dispatch(item->data(0,Qt::UserRole+3).toString());});
    syncSimulationNavigation();return simulationNavigation_;
}

void UiShell::syncSimulationNavigation()
{
    if(!simulationNavigation_ || !objects_) return;
    const QSignalBlocker blocker(simulationNavigation_);
    QSet<QString> expanded;QString current;
    std::function<void(QTreeWidgetItem *)> remember=[&](QTreeWidgetItem *item){
        const auto route=item->data(0,Qt::UserRole+3).toString();if(item->isExpanded())expanded.insert(route);if(item==simulationNavigation_->currentItem())current=route;
        for(int i=0;i<item->childCount();++i)remember(item->child(i));
    };
    for(int i=0;i<simulationNavigation_->topLevelItemCount();++i)remember(simulationNavigation_->topLevelItem(i));
    simulationNavigation_->clear();
    const QList<QPair<QString,QString>> roots{
        {QString::fromUtf8("设置"),"page:MMSetup_Setup"},{QString::fromUtf8("物性组"),"objects:property-sets"},
        {QString::fromUtf8("分析"),"objects:analysis"},{QString::fromUtf8("工艺流程"),"flowsheet"},
        {QString::fromUtf8("流股"),"objects:streams"},{QString::fromUtf8("模块"),"objects:blocks"},
        {QString::fromUtf8("传感器"),"catalog:Sensor"},{QString::fromUtf8("公用工程"),"catalog:Utility"},
        {QString::fromUtf8("反应"),"objects:reactions"},{QString::fromUtf8("收敛"),"catalog:Convergence"},
        {QString::fromUtf8("工艺流程选项"),"catalog:FlowsheetingOptions"},{QString::fromUtf8("模型分析工具"),"objects:sensitivity"},
        {QString::fromUtf8("EO 配置"),"catalog:EO"},{QString::fromUtf8("结果摘要"),"catalog:Results"},{QString::fromUtf8("动态配置"),"catalog:Dynamics"}
    };
    auto add=[&](QTreeWidgetItem *parent,const QString &label,const QString &route,const QString &icon="folder") {
        auto *item=parent?new QTreeWidgetItem(parent,{label}):new QTreeWidgetItem(simulationNavigation_,{label});item->setData(0,Qt::UserRole+3,route);item->setIcon(0,aspenIcon(icon));item->setExpanded(expanded.contains(route));if(route==current)simulationNavigation_->setCurrentItem(item);return item;
    };
    std::function<void(QTreeWidgetItem *,const QString &,const QString &)> addObjects;
    addObjects=[&](QTreeWidgetItem *parent,const QString &kind,const QString &parentKey) {
        for(const auto &v:objects_->objects()) {
            const auto d=v.toObject();if(d.value("kind")!=kind || d.value("parent").toString()!=parentKey)continue;
            const auto key=d.value("key").toString();
            auto *object=add(parent,d.value("name").toString(),"object:"+key,"folder-incomplete");
            object->setData(0,Qt::UserRole+11,key);
            for(const auto &p:objects_->typeDefinition(kind,d.value("type").toString()).value("pages").toArray()) {
                const auto page=p.toObject();add(object,page.value("label").toString(),"object:"+key+":"+page.value("page").toString());
            }
            for(const auto &definition:objects_->definitions()) {
                const auto def=definition.toObject();if(!def.value("parentTypes").toArray().contains(d.value("type")))continue;
                const auto childKind=def.value("id").toString();
                auto *collection=add(object,def.value("label").toString(),"objects:"+childKind+":"+key);
                addObjects(collection,childKind,key);
            }
        }
    };
    for(const auto &root:roots) {
        auto *item=add(nullptr,root.first,root.second,root.second=="flowsheet" || root.second=="page:MMSetup_Setup"?"folder-incomplete":"folder");
        if(root.second=="page:MMSetup_Setup") for(const auto &v:interactions_.value("navigation").toObject().value(root.first).toObject().value("children").toArray())add(item,v.toObject().value("label").toString(),v.toObject().value("action").toString());
        if(root.second=="flowsheet")add(item,QString::fromUtf8("主工艺流程"),"flowsheet");
        if(root.first==QString::fromUtf8("模型分析工具")) {
            for(const auto &v:objects_->definitions()) {const auto d=v.toObject();const auto kind=d.value("id").toString();if(QStringList{"sensitivity","design-specs","calculators","optimizations"}.contains(kind)) {auto *collection=add(item,d.value("label").toString(),"objects:"+kind);addObjects(collection,kind,{});}}
        } else if(root.second.startsWith("objects:")) addObjects(item,root.second.mid(8),{});
    }
    applyNavigationFilter();
}
