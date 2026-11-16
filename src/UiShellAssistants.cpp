#include "UiShell.h"
#include "ProjectDocument.h"
#include "RecoveredWorkspace.h"
#include "PropertyAssistant.h"
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

namespace {
QString componentName(const QJsonObject &c) {
    return c.value("alias").toString().isEmpty()?c.value("name").toString():c.value("alias").toString();
}

}

void UiShell::reorderComponents() {
    auto *dialog=new QDialog(this);dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setObjectName("dialog-ReorderComp");dialog->setWindowTitle(QString::fromUtf8("重新排序组分"));dialog->resize(400,380);
    auto *layout=new QVBoxLayout(dialog);auto *list=new QListWidget(dialog);list->setObjectName("lvSelectedComps");
    const auto original=project_->state().value("components").toArray();
    for(const auto &v:original){auto *item=new QListWidgetItem(componentName(v.toObject()),list);item->setData(Qt::UserRole,v.toObject());}
    layout->addWidget(list);auto *row=new QHBoxLayout;
    for(int direction:{-1,1}) {
        auto *button=new QPushButton(direction<0?QString::fromUtf8("上移"):QString::fromUtf8("下移"),dialog);
        button->setObjectName(direction<0?"btnUp":"btnDown");row->addWidget(button);
        connect(button,&QPushButton::clicked,dialog,[=]{const int r=list->currentRow(),to=r+direction;if(r<0 || to<0 || to>=list->count())return;list->insertItem(to,list->takeItem(r));list->setCurrentRow(to);});
        const auto update=[=]{button->setEnabled(list->currentRow()>=0 && list->currentRow()+direction>=0 && list->currentRow()+direction<list->count());};
        connect(list,&QListWidget::currentRowChanged,dialog,update);update();
    }
    layout->addLayout(row);auto *buttons=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,dialog);layout->addWidget(buttons);
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[=]{
        if(project_->state().value("components").toArray()!=original){dialog->reject();return;}
        QJsonArray components;for(int i=0;i<list->count();++i)components.append(list->item(i)->data(Qt::UserRole).toJsonObject());
        auto state=project_->state();state["components"]=components;project_->edit(state);dialog->accept();
    });
    dialog->open();
}

void UiShell::openPropertyAssistant(const QString &name) {
    const auto spec=interactions_.value("wizards").toObject().value(name).toObject();
    auto *dialog=new PropertyAssistant(name,spec,project_,[this]{restoreProject();},this);
    dialog->open();
}
