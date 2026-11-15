#include "UiShell.h"
#include "ProjectDocument.h"
#include "RecoveredWorkspace.h"
#include "WidgetState.h"
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
QStringList listText(QListWidget *list) {
    QStringList result;for(int i=0;i<list->count();++i)result<<list->item(i)->text();return result;
}
void moveItems(QListWidget *from,QListWidget *to,bool all) {
    auto items=from->selectedItems();
    if(all){items.clear();for(int i=0;i<from->count();++i)items<<from->item(i);}
    for(auto *item:items)to->addItem(from->takeItem(from->row(item)));
}
void wirePicker(QWidget *page) {
    auto *available=page->findChild<QListWidget *>("lstAvailableComp");
    auto *selected=page->findChild<QListWidget *>("lstSelectedComp");
    if(!available || !selected)return;
    available->setEnabled(true);selected->setEnabled(true);
    const QStringList names{"btnMove","btnMoveAll","btnRemove","btnClearAll"};
    for(int i=0;i<names.size();++i)if(auto *button=page->findChild<QPushButton *>(names[i])) {
        button->setEnabled(true);button->setToolTip({});
        QObject::connect(button,&QPushButton::clicked,page,[=]{moveItems(i<2?available:selected,i<2?selected:available,i%2);});
    }
    QObject::connect(available,&QListWidget::itemDoubleClicked,page,[=]{moveItems(available,selected,false);});
    QObject::connect(selected,&QListWidget::itemDoubleClicked,page,[=]{moveItems(selected,available,false);});
    const auto update=[=]{
        const QList<bool> enabled{!available->selectedItems().isEmpty(),available->count()>0,!selected->selectedItems().isEmpty(),selected->count()>0};
        for(int i=0;i<names.size();++i)if(auto *button=page->findChild<QPushButton *>(names[i]))button->setEnabled(enabled[i]);
    };
    for(auto *list:{available,selected}) {
        QObject::connect(list,&QListWidget::itemSelectionChanged,page,update);
        QObject::connect(list->model(),&QAbstractItemModel::rowsInserted,page,update);
        QObject::connect(list->model(),&QAbstractItemModel::rowsRemoved,page,update);
    }
    update();
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
    auto *dialog=new QDialog(this);dialog->setAttribute(Qt::WA_DeleteOnClose);dialog->setObjectName("wizard-"+name);
    dialog->setWindowTitle(spec.value("title").toString());dialog->resize(740,650);
    auto *layout=new QVBoxLayout(dialog);auto *steps=new QStackedWidget(dialog);steps->setObjectName("WizardSteps");layout->addWidget(steps,1);
    for(const auto &p:spec.value("pages").toArray()) {
        auto *page=new RecoveredWorkspace(steps);page->setSessionEditable(true);page->showPage(page->idForName(p.toString()));
        page->findChild<QLabel *>("RecoveredTitle")->hide();
        page->findChild<QLabel *>("RecoveredNotice")->hide();steps->addWidget(page);
    }
    // These are editable project inputs. Generated chemical systems and solver
    // output remain distinct; the assistant never fabricates a reaction database.
    auto *notice=new QLabel(QString::fromUtf8("向导配置可编辑并随项目保存。自动生成反应、物性估算和计算尚未接入。"),dialog);
    notice->setObjectName("WizardStatus");notice->setWordWrap(true);layout->addWidget(notice);
    auto *row=new QHBoxLayout;row->addStretch();layout->addLayout(row);
    auto *cancel=new QPushButton(QString::fromUtf8("取消"),dialog);cancel->setObjectName("WizardCancel");
    auto *back=new QPushButton(QString::fromUtf8("< 后退"),dialog);back->setObjectName("WizardBack");
    auto *next=new QPushButton(QString::fromUtf8("下一步 >"),dialog);next->setObjectName("WizardNext");
    auto *finish=new QPushButton(QString::fromUtf8("完成"),dialog);finish->setObjectName("WizardFinish");
    for(auto *b:{cancel,back,next,finish}){b->setAutoDefault(false);row->addWidget(b);}
    auto *picker=steps->widget(name=="electrolyte"?1:0);
    auto *available=picker->findChild<QListWidget *>("lstAvailableComp");auto *selected=picker->findChild<QListWidget *>("lstSelectedComp");
    const auto components=project_->state().value("components").toArray();QStringList names;
    for(const auto &c:components)names<<(name=="sfe"?c.toObject().value("name").toString():componentName(c.toObject()));
    for(const auto &v:project_->state().value("objects").toArray())if(v.toObject().value("kind")=="user-components")names<<v.toObject().value("name").toString();
    names.removeDuplicates();(name=="electrolyte"?selected:available)->addItems(names);wirePicker(picker);
    const auto setOptions=[=](const char *id,const QStringList &values){if(auto *combo=dialog->findChild<QComboBox *>(id)){combo->clear();combo->addItems(values);combo->setEditable(false);combo->setEnabled(!values.isEmpty());}};
    if(name=="electrolyte") {
        setOptions("cboDBSelect",{"APV150 REACTIONS"});setOptions("cboRefStateSelect",{QString::fromUtf8("非对称"),QString::fromUtf8("对称")});
        setOptions("cboOptSet",{"ELECNRTL","ENRTL-RK"});
        for(const auto *id:{"radioHydroniumIon","radioGenSpecRxns","radioTrueComponent"})dialog->findChild<QRadioButton *>(id)->setChecked(true);
        dialog->findChild<QCheckBox *>("chkSaltFormation")->setChecked(true);
        for(auto *edit:steps->widget(3)->findChildren<QLineEdit *>())edit->setText("GLOBAL");
        auto *generated=steps->widget(2);
        auto *empty=new QLabel(QString::fromUtf8("尚未生成离子、盐或反应。可继续指定方法和模拟方式并保存配置。"),generated);
        empty->setWordWrap(true);generated->layout()->addWidget(empty);
        auto *setMethod=generated->findChild<QRadioButton *>("radioGenSpecRxns");
        auto *method=generated->findChild<QComboBox *>("cboOptSet");auto *chem=generated->findChild<QCheckBox *>("chkGenHenryChem");
        const auto updateMethod=[=]{method->setEnabled(setMethod->isChecked());chem->setEnabled(!setMethod->isChecked());};
        connect(setMethod,&QRadioButton::toggled,dialog,updateMethod);updateMethod();
        auto *summary=steps->widget(4);
        if(auto *label=summary->findChild<QLabel *>("lblFinishElec"))label->setText(QString::fromUtf8("单击完成保存向导配置。"));
        // Replace source claims of generation with the actual state of this app.
        for(auto *label:summary->findChildren<QLabel *>()) {
            if(label->text().contains(QString::fromUtf8("生成的组分")) || label->text().contains("ASPENPCD"))label->setText(QString::fromUtf8("所选组分和数据库保持不变；当前保存配置，未生成反应。"));
            if(label->text().contains(QString::fromUtf8("已完成电解质向导")))label->setText(QString::fromUtf8("配置步骤已完成，单击完成保存并退出。"));
        }
        for(const auto &pair:{qMakePair("btnReviewHenryList","MMComp_Henry"),qMakePair("btnModifyAddRxns","MMChem_Stoic")}) {
            auto *button=summary->findChild<QPushButton *>(pair.first);if(!button)continue;button->setEnabled(true);button->setToolTip({});
            connect(button,&QPushButton::clicked,dialog,[=]{
                auto *review=new QDialog(dialog);review->setAttribute(Qt::WA_DeleteOnClose);review->setWindowTitle(button->text());review->resize(600,400);
                auto *column=new QVBoxLayout(review);auto *text=new QLabel(QString::fromUtf8("当前没有自动生成的数据。向导配置将在完成后保存。"),review);column->addWidget(text);
                auto *close=new QDialogButtonBox(QDialogButtonBox::Close,review);column->addWidget(close);connect(close,&QDialogButtonBox::rejected,review,&QDialog::reject);review->open();
            });
        }
    } else {
        QStringList chemistry;
        for(const auto &v:project_->state().value("objects").toArray())if(v.toObject().value("kind")=="chemistry")chemistry<<v.toObject().value("name").toString();
        setOptions("cmbexistingChemistry",chemistry);
        auto *page=steps->widget(1);auto *existing=page->findChild<QRadioButton *>("radioExistChemistry");
        auto *combo=page->findChild<QComboBox *>("cmbexistingChemistry");existing->setEnabled(!chemistry.isEmpty());
        auto *chemName=page->findChild<QLineEdit *>("txtChemName");chemName->setText("C-1");
        const auto update=[=]{combo->setEnabled(existing->isChecked() && !chemistry.isEmpty());chemName->setEnabled(!existing->isChecked());};connect(existing,&QRadioButton::toggled,dialog,update);update();
        if(auto *table=page->findChild<QTableWidget *>("grdSolidComponent"))table->setEnabled(true);
    }
    const auto saved=project_->state().value("unverifiedInputs").toObject().value("assistants").toObject().value(name).toObject();
    WidgetState::capture(steps);WidgetState::restore(steps,saved);
    // Prune selections from a previous project component set and retain identity
    // through the current component names rather than keeping phantom entries.
    QStringList remaining=names;
    for(auto *list:{selected,available})for(int i=list->count()-1;i>=0;--i){if(!remaining.removeOne(list->item(i)->text()))delete list->takeItem(i);}
    available->addItems(remaining);
    const auto update=[=]{
        const int i=steps->currentIndex();back->setEnabled(i>0);next->setEnabled(i+1<steps->count() && (i!=(name=="electrolyte"?1:0) || selected->count()>0));finish->setEnabled(i==steps->count()-1 && selected->count()>0);
        if(name=="electrolyte") {
            const bool setMethod=dialog->findChild<QRadioButton *>("radioGenSpecRxns")->isChecked();
            dialog->findChild<QComboBox *>("cboOptSet")->setEnabled(setMethod);
            dialog->findChild<QCheckBox *>("chkGenHenryChem")->setEnabled(!setMethod);
        } else {
            const bool existing=dialog->findChild<QRadioButton *>("radioExistChemistry")->isChecked();
            auto *combo=dialog->findChild<QComboBox *>("cmbexistingChemistry");
            combo->setEnabled(existing && combo->count()>0);
            dialog->findChild<QLineEdit *>("txtChemName")->setEnabled(!existing);
        }
    };
    connect(selected->model(),&QAbstractItemModel::rowsInserted,dialog,update);connect(selected->model(),&QAbstractItemModel::rowsRemoved,dialog,update);
    connect(back,&QPushButton::clicked,dialog,[=]{steps->setCurrentIndex(steps->currentIndex()-1);});
    connect(next,&QPushButton::clicked,dialog,[=]{
        if(name=="sfe" && steps->currentIndex()==0) {
            auto *table=steps->widget(1)->findChild<QTableWidget *>("grdSolidComponent");
            QMap<QString,QString> solids;for(int r=0;r<table->rowCount();++r)if(table->item(r,0))solids[table->item(r,0)->text()]=table->item(r,1)?table->item(r,1)->text():QString();
            table->setRowCount(selected->count());for(int r=0;r<selected->count();++r){auto *item=new QTableWidgetItem(selected->item(r)->text());item->setFlags(item->flags()&~Qt::ItemIsEditable);table->setItem(r,0,item);table->setItem(r,1,new QTableWidgetItem(solids.value(item->text(),item->text()+"(S)")));}
        }
        if(name=="electrolyte" && steps->currentIndex()==3) {
            for(auto *edit:steps->widget(3)->findChildren<QLineEdit *>())if(!QRegularExpression("^[A-Za-z0-9][A-Za-z0-9_-]{0,7}$").match(edit->text()).hasMatch()) {
                notice->setText(QString::fromUtf8("ID 必须为 1–8 位字母、数字、下划线或连字符，并以字母或数字开头。"));return;
            }
            auto *summary=steps->widget(4);
            summary->findChild<QLineEdit *>("txtBaseOption")->setText(dialog->findChild<QComboBox *>("cboOptSet")->isEnabled()?dialog->findChild<QComboBox *>("cboOptSet")->currentText():QString::fromUtf8("不设置"));
            summary->findChild<QLineEdit *>("txtSimApproach")->setText(dialog->findChild<QRadioButton *>("radioTrueComponent")->isChecked()?QString::fromUtf8("真实组分"):QString::fromUtf8("表观组分"));
            for(const char *id:{"txtChemID","txtHenryID"})summary->findChild<QLineEdit *>(id)->setText(steps->widget(3)->findChild<QLineEdit *>(id)->text());
            for(auto *edit:summary->findChildren<QLineEdit *>())edit->setReadOnly(true);
        }
        steps->setCurrentIndex(steps->currentIndex()+1);
    });
    connect(steps,&QStackedWidget::currentChanged,dialog,update);connect(cancel,&QPushButton::clicked,dialog,&QDialog::reject);
    connect(finish,&QPushButton::clicked,dialog,[=]{auto state=project_->state();auto inputs=state.value("unverifiedInputs").toObject();auto assistants=inputs.value("assistants").toObject();assistants[name]=WidgetState::capture(steps);inputs["assistants"]=assistants;state["unverifiedInputs"]=inputs;project_->edit(state);dialog->accept();});
    update();dialog->open();
}
