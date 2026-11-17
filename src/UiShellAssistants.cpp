#include "UiShell.h"
#include "ProjectDocument.h"
#include "RecoveredWorkspace.h"
#include "PropertyAssistant.h"
#include "ChemicalSystem.h"
#include "ComponentWorkspace.h"
#include <QBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QRegularExpression>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTabWidget>
#include <QStatusBar>
#include <algorithm>

void UiShell::reorderComponents() {
    const auto original=project_->state();
    const auto records=ChemicalSystem::components(original);
    if(records.size()<2) {statusBar()->showMessage(QString::fromUtf8("至少需要两个组分才能重新排序。"),6000);return;}
    for(const auto &v:records)if(v.toObject().value("id").toString().trimmed().isEmpty()) {
        statusBar()->showMessage(QString::fromUtf8("请先为所有组分指定 ID。"),6000);return;
    }
    auto *dialog=new QDialog(this);dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setObjectName("dialog-ReorderComp");dialog->setWindowTitle(QString::fromUtf8("重新排序组分"));dialog->resize(400,380);
    auto *layout=new QVBoxLayout(dialog);auto *list=new QListWidget(dialog);list->setObjectName("lvSelectedComps");
    list->setSelectionMode(QAbstractItemView::ExtendedSelection);
    for(const auto &v:records){const auto c=v.toObject();auto *item=new QListWidgetItem(c.value("id").toString(),list);item->setData(Qt::UserRole,c.value("key").toString());item->setToolTip(c.value("key").toString());
        if(c.value("key").toString()==components_->selectedComponentKey())list->setCurrentItem(item);}
    auto *status=new QLabel(dialog);status->setObjectName("ComponentOrderStatus");status->setWordWrap(true);
    layout->addWidget(list);auto *row=new QHBoxLayout;
    for(int direction:{-1,1}) {
        auto *button=new QPushButton(direction<0?QString::fromUtf8("上移"):QString::fromUtf8("下移"),dialog);
        button->setObjectName(direction<0?"btnUp":"btnDown");row->addWidget(button);
        const auto update=[=]{const auto items=list->selectedItems();bool ready=!items.isEmpty();
            for(auto *item:items)if(list->row(item)+direction<0 || list->row(item)+direction>=list->count())ready=false;button->setEnabled(ready);};
        connect(button,&QPushButton::clicked,dialog,[=]{
            auto items=list->selectedItems();if(items.isEmpty())return;
            for(auto *item:items)if(list->row(item)+direction<0 || list->row(item)+direction>=list->count())return;
            std::sort(items.begin(),items.end(),[=](auto *a,auto *b){return direction<0?list->row(a)<list->row(b):list->row(a)>list->row(b);});
            auto *current=list->currentItem();
            for(auto *item:items){const int from=list->row(item);list->insertItem(from+direction,list->takeItem(from));}
            if(current)list->setCurrentItem(current,QItemSelectionModel::NoUpdate);
            for(auto *item:items)item->setSelected(true);update();
        });
        connect(list,&QListWidget::itemSelectionChanged,dialog,update);update();
    }
    layout->addLayout(row);layout->addWidget(status);auto *buttons=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,dialog);layout->addWidget(buttons);
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[=]{
        if(project_->state()!=original){status->setText(QString::fromUtf8("项目已改变，请取消并重新打开排序窗口。"));return;}
        QJsonArray order,previous;for(int i=0;i<list->count();++i)order.append(list->item(i)->data(Qt::UserRole).toString());
        for(const auto &v:records)previous.append(v.toObject().value("key"));
        if(order!=previous) {
            auto state=original;state["componentOrder"]=order;
            // Keep legacy consumers of the database-only array in the same relative order.
            QJsonArray database;
            for(const auto &key:order)for(const auto &v:original.value("components").toArray())
                if(ChemicalSystem::databaseKey(v.toObject())==key.toString())database.append(v);
            state["components"]=database;project_->edit(state);
        }
        dialog->accept();
    });
    dialog->open();
}

void UiShell::openPropertyAssistant(const QString &name) {
    const auto spec=interactions_.value("wizards").toObject().value(name).toObject();
    auto *dialog=new PropertyAssistant(name,spec,project_,[this]{restoreProject();},this);
    dialog->open();
}
