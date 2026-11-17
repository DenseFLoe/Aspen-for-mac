#include "UiShell.h"
#include "ObjectWorkspace.h"
#include "RecoveredWorkspace.h"
#include "ComponentWorkspace.h"
#include "IconCatalog.h"
#include <QAction>
#include <QMenu>
#include <QSignalBlocker>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItemIterator>
#include <functional>
#include <QLabel>
#include <QToolButton>
#include <QStyle>
#include <QTabWidget>
#include <QTabBar>

void UiShell::applyNavigationFilter()
{
    for(auto *tree:{navigation_,simulationNavigation_}) {
        if(!tree) continue;
        for(QTreeWidgetItemIterator it(tree);*it;++it) {
            const auto label=(*it)->text(0);
            const auto route=(*it)->data(0,Qt::UserRole+3).toString();
            const bool objectName=route.startsWith("object:") && route.count(':')==1;
            const bool result=!objectName && (label.contains(QString::fromUtf8("结果")) || label==QString::fromUtf8("所选方法") || route.contains("Results",Qt::CaseInsensitive));
            (*it)->setHidden(inputsOnly_ && result);
        }
    }
    if(auto *button=findChild<QToolButton *>("NavigationFilter")) {
        button->setText(inputsOnly_?QString::fromUtf8("仅输入"):QString::fromUtf8("所有项"));
        for(auto *action:button->menu()->actions()) {action->setCheckable(true);action->setChecked(action->text()==button->text());}
    }
}

void UiShell::selectNavigationRoute(const QString &route)
{
    for(auto *tree:{navigation_,simulationNavigation_}) {
        if(!tree) continue;
        const QSignalBlocker blocker(tree);
        QTreeWidgetItem *fallback=nullptr;
        for(QTreeWidgetItemIterator it(tree);*it;++it) {
            const auto candidate=(*it)->data(0,Qt::UserRole+3).toString();
            if(candidate==route || (candidate.startsWith("page:") && route.startsWith("page:") && recovered_->idForName(candidate.mid(5))==recovered_->idForName(route.mid(5)))) {
                fallback=*it;break;
            }
            if(route.startsWith("object:") && candidate==route.section(':',0,1)) fallback=*it;
        }
        if(fallback) {tree->setCurrentItem(fallback);tree->scrollToItem(fallback);}
    }
}

void UiShell::setWorkspaceMode(bool simulation)
{
    const bool changed=simulationMode_!=simulation;simulationMode_=simulation;
    if(navigationPages_) navigationPages_->setCurrentIndex(simulation?1:0);
    updateProcessStatus();
    if(auto *label=findChild<QLabel *>("FlowsheetContext"))label->setVisible(simulation);
    if(auto *label=findChild<QLabel *>("DatabaseStatus"))label->setVisible(!simulation);
    if(auto *ribbon=findChild<QTabWidget *>("Ribbon")) {
        for(int i=0;i<ribbon->count();++i) if(ribbon->widget(i)->property("simulationOnly").toBool()) ribbon->setTabVisible(i,simulation);
        if(changed) {
            for(int i=0;i<ribbon->count();++i) if(ribbon->widget(i)->property("ribbonId").toString()==(simulation?"flowsheet-modify":"home"))ribbon->setCurrentIndex(i);
        }
    }

    if(auto *label=findChild<QLabel *>("NavigationHeading")) label->setText(simulation?QString::fromUtf8("模拟"):QString::fromUtf8("物性"));
    for(auto *button:findChildren<QToolButton *>()) {
        if(!button->property("workspaceMode").isValid()) continue;
        button->setObjectName(button->property("workspaceMode").toInt()==(simulation?1:0)?"ActiveMode":"NavigationMode");
        button->style()->unpolish(button);button->style()->polish(button);
    }
}

void UiShell::syncObjectNavigation()
{
    if(!navigation_ || !objects_) return;
    syncSimulationNavigation();
    components_->setUserComponents(objects_->objects());
    const QSignalBlocker blocker(navigation_);
    const auto selected=navigation_->currentItem()?navigation_->currentItem()->data(0,Qt::UserRole+3).toString():QString();
    // Remove only generated object nodes; preserve the resource/navigation catalog.
    QList<QTreeWidgetItem *> generated;
    for(QTreeWidgetItemIterator it(navigation_);*it;++it)
        if((*it)->data(0,Qt::UserRole+10).toBool() && !((*it)->parent() && (*it)->parent()->data(0,Qt::UserRole+10).toBool())) generated.append(*it);
    for(auto *item:generated) delete item;
    std::function<void(QTreeWidgetItem *,const QString &,const QString &)> addObjects;
    addObjects=[&](QTreeWidgetItem *root,const QString &kind,const QString &parent){
        for(const auto &v:objects_->objects()) {
            const auto d=v.toObject(); if(d.value("kind")!=kind || d.value("parent")!=parent) continue;
            const auto key=d.value("key").toString();
            auto *item=new QTreeWidgetItem(root,{d.value("name").toString()});
            item->setIcon(0,aspenIcon("folder-incomplete")); item->setData(0,Qt::UserRole+10,true);
            item->setData(0,Qt::UserRole+11,key); item->setData(0,Qt::UserRole+3,"object:"+key);
            const auto pages=objects_->typeDefinition(kind,d.value("type").toString()).value("pages").toArray();
            for(const auto &p:pages) {
                const auto page=p.toObject(); auto *child=new QTreeWidgetItem(item,{page.value("label").toString()});
                child->setData(0,Qt::UserRole+10,true);
                child->setData(0,Qt::UserRole+3,"object:"+key+":"+page.value("page").toString());
            }
            for(const auto &definition:objects_->definitions()) {
                const auto def=definition.toObject();
                if(!def.value("parentTypes").toArray().contains(d.value("type"))) continue;
                auto *child=new QTreeWidgetItem(item,{def.value("label").toString()});
                child->setData(0,Qt::UserRole+10,true);
                child->setData(0,Qt::UserRole+3,"objects:"+def.value("id").toString()+":"+key);
                addObjects(child,def.value("id").toString(),key);
            }
            item->setExpanded(true);
        }
    };
    for(const auto &v:objects_->definitions()) {
        const auto def=v.toObject(); if(!def.value("parentTypes").toArray().isEmpty()) continue;
        const auto kind=def.value("id").toString(),route="objects:"+kind;
        QTreeWidgetItem *root=nullptr;
        for(QTreeWidgetItemIterator it(navigation_);*it;++it)
            if((*it)->data(0,Qt::UserRole+3).toString()==route) {root=*it;break;}
        if(!root) {
            root=new QTreeWidgetItem(navigation_,{def.value("label").toString()});
            root->setIcon(0,aspenIcon("folder"));root->setData(0,Qt::UserRole+3,route);
        }
        addObjects(root,kind,{}); if(root->childCount()) root->setExpanded(true);
    }
    for(QTreeWidgetItemIterator it(navigation_);*it;++it)
        if((*it)->data(0,Qt::UserRole+3).toString()==selected) {navigation_->setCurrentItem(*it);break;}
    applyNavigationFilter();
}

bool UiShell::dispatchObjectAction(const QString &action)
{
    if(!objects_) return false;
    QString kind;
    if(action.startsWith("objects:")) {kind=action.section(':',1,1);objects_->showCollection(kind,action.section(':',2,2));}
    else if(action.startsWith("object:")) {
        if(!objects_->openObject(action.section(':',1,1),action.section(':',2,2))) return true;
        kind=objects_->object(action.section(':',1,1)).value("kind").toString();
    } else if(action=="flowsheet") {objects_->showFlowsheet();remember(action);setWorkspaceMode(true);}
    else return false;
    if(!kind.isEmpty()) {
        if(QStringList{"blocks","streams","reactions","sensitivity","design-specs","calculators","optimizations","column-designs","column-adjustments","pumparounds"}.contains(kind)) setWorkspaceMode(true);
        else if(QStringList{"chemistry","user-components"}.contains(kind)) setWorkspaceMode(false);
    }
    selectNavigationRoute(action);
    pages_->setCurrentIndex(0);documents_->setCurrentWidget(objects_); return true;
}
