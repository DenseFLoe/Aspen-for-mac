#include "PropertyAssistant.h"
#include "ProjectDocument.h"
#include "RecoveredWorkspace.h"
#include "ChemicalSystemView.h"
#include <QApplication>
#include <QBoxLayout>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSignalBlocker>
#include <QStackedWidget>
#include <QStyledItemDelegate>
#include <QTableWidget>
#include <QValidator>

namespace {
class SolidIdValidator final:public QValidator {
public:
    using QValidator::QValidator;
    State validate(QString &text,int &) const override {
        if(text.isEmpty())return Intermediate;
        return ChemicalSystem::validSolidId(text)?Acceptable:Invalid;
    }
};
class SolidIdDelegate final:public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &,const QModelIndex &) const override {
        auto *edit=new QLineEdit(parent);edit->setMaxLength(8);edit->setValidator(new SolidIdValidator(edit));return edit;
    }
};
template<class T> T *control(QWidget *root,const char *name) { return root->findChild<T *>(name); }
void comboValues(QComboBox *combo,const QStringList &values) {
    combo->clear();combo->addItems(values);combo->setEditable(false);combo->setEnabled(!values.isEmpty());
}
void exclusive(QWidget *root,std::initializer_list<const char *> names) {
    auto *group=new QButtonGroup(root);
    for(const auto *name:names)group->addButton(control<QRadioButton>(root,name));
}
}
PropertyAssistant::PropertyAssistant(const QString &name,const QJsonObject &spec,ProjectDocument *project,std::function<void()> committed,QWidget *parent)
    :QDialog(parent),name_(name),project_(project),initial_(project->state()),committed_(std::move(committed)) {
    setAttribute(Qt::WA_DeleteOnClose);setWindowModality(Qt::ApplicationModal);
    setObjectName("wizard-"+name);setWindowTitle(spec.value("title").toString());resize(760,680);
    auto *column=new QVBoxLayout(this);steps_=new QStackedWidget(this);steps_->setObjectName("WizardSteps");column->addWidget(steps_,1);
    for(const auto &p:spec.value("pages").toArray()) {
        auto *page=new RecoveredWorkspace(steps_);page->setSessionEditable(true);page->showPage(page->idForName(p.toString()));
        control<QLabel>(page,"RecoveredTitle")->hide();control<QLabel>(page,"RecoveredNotice")->hide();steps_->addWidget(page);
    }
    notice_=new QLabel(this);notice_->setObjectName("WizardStatus");notice_->setWordWrap(true);column->addWidget(notice_);
    auto *row=new QHBoxLayout;row->addStretch();column->addLayout(row);
    cancel_=new QPushButton(QString::fromUtf8("取消"),this);cancel_->setObjectName("WizardCancel");
    back_=new QPushButton(QString::fromUtf8("< 后退"),this);back_->setObjectName("WizardBack");
    next_=new QPushButton(QString::fromUtf8("下一步 >"),this);next_->setObjectName("WizardNext");
    finish_=new QPushButton(QString::fromUtf8("完成"),this);finish_->setObjectName("WizardFinish");
    for(auto *b:{cancel_,back_,next_,finish_}){b->setAutoDefault(false);row->addWidget(b);}
    auto *picker=steps_->widget(name=="electrolyte"?1:0);
    available_=control<QListWidget>(picker,"lstAvailableComp");selected_=control<QListWidget>(picker,"lstSelectedComp");
    for(auto *list:{available_,selected_}){list->clear();list->setEnabled(true);list->setSelectionMode(QAbstractItemView::ExtendedSelection);}
    const auto all=name=="sfe"?ChemicalSystem::sfeComponents(initial_):ChemicalSystem::components(initial_);
    for(const auto &v:all) {
        const auto c=v.toObject();if(c.value("key").toString().startsWith("generated:"))continue;
        auto *item=new QListWidgetItem(c.value("id").toString(),available_);item->setData(Qt::UserRole,c);
        item->setToolTip(c.value("key").toString()+"\n"+c.value("dbName").toString()+" / "+c.value("alias").toString());
    }
    const auto move=[this](bool remove,bool all) {
        auto *from=remove?selected_:available_;auto *to=remove?available_:selected_;auto items=from->selectedItems();
        if(all){items.clear();for(int i=0;i<from->count();++i)items<<from->item(i);}
        if(name_=="electrolyte" && remove && !all && items.size()==1 && !options().symmetric && ChemicalSystem::isWater(items.first()->data(Qt::UserRole).toJsonObject())) {
            showError(QString::fromUtf8("非对称参考态需要水，不能单独移除水。"));return;
        }
        for(auto *item:items)to->addItem(from->takeItem(from->row(item)));
        if(name_=="electrolyte") {
            if(remove && all && !options().symmetric)for(int i=available_->count()-1;i>=0;--i)if(ChemicalSystem::isWater(available_->item(i)->data(Qt::UserRole).toJsonObject()))selected_->addItem(available_->takeItem(i));
            refreshCandidates();
        }
        updateButtons();
    };
    const QStringList commands{"btnMove","btnMoveAll","btnRemove","btnClearAll"};
    for(int i=0;i<commands.size();++i) {
        auto *b=picker->findChild<QPushButton *>(commands[i]);b->setToolTip({});
        connect(b,&QPushButton::clicked,this,[move,i]{move(i>=2,i%2);});
    }
    connect(available_,&QListWidget::itemDoubleClicked,this,[move]{move(false,false);});
    connect(selected_,&QListWidget::itemDoubleClicked,this,[move]{move(true,false);});
    for(auto *list:{available_,selected_})connect(list,&QListWidget::itemSelectionChanged,this,[this]{updateButtons();});
    if(name=="electrolyte") {
        // The query catalog has no reaction-bank API. Never advertise a fabricated APV bank.
        auto *bank=control<QComboBox>(this,"cboDBSelect");comboValues(bank,{QString::fromUtf8("已核实案例：WATER 水离解")});bank->setEnabled(false);
        comboValues(control<QComboBox>(this,"cboRefStateSelect"),{QString::fromUtf8("非对称"),QString::fromUtf8("对称")});
        exclusive(this,{"radioHydroniumIon","radioHydrogenIon"});
        exclusive(this,{"radioGenSpecRxns","radioGenChemHenry"});
        exclusive(this,{"radioTrueComponent","radioApparentComponent"});
        for(const auto *id:{"radioHydroniumIon","radioGenSpecRxns","radioTrueComponent"})control<QRadioButton>(this,id)->setChecked(true);
        control<QCheckBox>(this,"chkSaltFormation")->setChecked(true);
        auto *generated=steps_->widget(2);
        for(const auto *id:{"lstAqueousSpecies","lstSalts","lstReactions"}) {
            auto *list=control<QListWidget>(generated,id);list->clear();list->setEnabled(true);list->setSelectionMode(QAbstractItemView::ExtendedSelection);
            connect(list,&QListWidget::itemSelectionChanged,this,[this,list,generated]{
                if(!list->selectedItems().isEmpty())for(const auto *other:{"lstAqueousSpecies","lstSalts","lstReactions"})if(control<QListWidget>(generated,other)!=list)control<QListWidget>(generated,other)->clearSelection();
                updateButtons();
            });
        }
        auto *remove=control<QPushButton>(generated,"btnRemove");remove->setToolTip({});
        connect(remove,&QPushButton::clicked,this,[this,generated]{
            bool selected=false;for(const auto *id:{"lstAqueousSpecies","lstSalts","lstReactions"})selected|=!control<QListWidget>(generated,id)->selectedItems().isEmpty();
            if(!selected)return;
            candidates_={};for(const auto *id:{"lstAqueousSpecies","lstSalts","lstReactions"})control<QListWidget>(generated,id)->clear();
            showError(QString::fromUtf8("水离解及其关联离子已排除。请返回基准组分页重新生成。"));updateButtons();
        });
        auto *setMethod=control<QRadioButton>(this,"radioGenSpecRxns");auto *generate=control<QCheckBox>(this,"chkGenHenryChem");
        connect(setMethod,&QRadioButton::toggled,this,[this,generate](bool checked){generate->setChecked(!checked);updateButtons();});
        connect(generate,&QCheckBox::toggled,this,[this]{updateButtons();});
        for(auto *edit:steps_->widget(3)->findChildren<QLineEdit *>())edit->setReadOnly(true);
        for(auto *edit:steps_->widget(4)->findChildren<QLineEdit *>())edit->setReadOnly(true);
        for(auto *check:picker->findChildren<QCheckBox *>())connect(check,&QCheckBox::toggled,this,[this]{refreshCandidates();});
        connect(control<QRadioButton>(this,"radioHydroniumIon"),&QRadioButton::toggled,this,[this]{refreshCandidates();});
        auto *review=control<QPushButton>(steps_->widget(4),"btnModifyAddRxns");review->setToolTip({});review->setText(QString::fromUtf8("查看已写入反应"));review->setEnabled(true);
        connect(review,&QPushButton::clicked,this,[this]{
            const auto record=ChemicalSystem::chemistry(project_->state(),chemistryId_);
            auto *d=new QDialog(this);d->setAttribute(Qt::WA_DeleteOnClose);d->setObjectName("ChemistryReview");d->setWindowTitle(record.value("name").toString());d->resize(720,420);
            auto *layout=new QVBoxLayout(d);layout->addWidget(makeChemicalSystemView(record,project_->state(),d));
            auto *buttons=new QDialogButtonBox(QDialogButtonBox::Close,d);layout->addWidget(buttons);connect(buttons,&QDialogButtonBox::rejected,d,&QDialog::reject);d->open();
        });
        auto *henry=control<QPushButton>(steps_->widget(4),"btnReviewHenryList");henry->setEnabled(false);henry->setToolTip(QString::fromUtf8("当前纯水案例没有 Henry 候选或记录。"));
        for(auto *label:steps_->widget(4)->findChildren<QLabel *>())if(label->text().contains("ASPENPCD") || label->text().contains(QString::fromUtf8("生成的组分")))label->setText(QString::fromUtf8("生成的离子和反应已写入当前项目，物性常数和计算尚未接入。"));
        control<QLabel>(steps_->widget(4),"lblFinishElec")->setText(QString::fromUtf8("项目已更新。单击完成关闭向导；撤销请使用项目撤销。"));
    } else {
        exclusive(this,{"radioNewChemistry","radioExistChemistry"});control<QRadioButton>(this,"radioNewChemistry")->setChecked(true);
        auto *existing=control<QRadioButton>(this,"radioExistChemistry");
        connect(existing,&QRadioButton::toggled,this,[this](bool enabled){if(enabled)control<QLineEdit>(this,"txtChemName")->clear();updateButtons();});
        connect(control<QComboBox>(this,"cmbexistingChemistry"),&QComboBox::currentIndexChanged,this,[this]{updateButtons();});
        auto *table=control<QTableWidget>(this,"grdSolidComponent");table->setEnabled(true);table->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::AnyKeyPressed);
        table->setItemDelegateForColumn(1,new SolidIdDelegate(table));
        connect(table,&QTableWidget::itemChanged,this,[this,table](QTableWidgetItem *item){
            if(item->column()!=1)return;const auto id=ChemicalSystem::normalizedId(item->text());
            if(!ChemicalSystem::validSolidId(id)){showError(QString::fromUtf8("固体 ID：1–8 字符，首位为字母或数字；不允许空格或下划线。"));return;}
            for(int r=0;r<table->rowCount();++r)if(r!=item->row() && table->item(r,1) && ChemicalSystem::normalizedId(table->item(r,1)->text())==id) {
                const QSignalBlocker blocker(table);item->setText({});showError(QString::fromUtf8("固体 ID 重复，已清空本次输入。"));return;
            }
            showError(QString::fromUtf8("完成后写入项目固体组分及盐式系数；返回后再次进入会重建固体默认名。"));
        });
    }
    connect(next_,&QPushButton::clicked,this,[this]{forward();});connect(back_,&QPushButton::clicked,this,[this]{backward();});
    connect(finish_,&QPushButton::clicked,this,[this]{finish();});connect(cancel_,&QPushButton::clicked,this,&QDialog::reject);
    enterPage(0);
}
QStringList PropertyAssistant::selectedKeys() const {
    QStringList keys;for(int i=0;i<selected_->count();++i)keys<<selected_->item(i)->data(Qt::UserRole).toJsonObject().value("key").toString();return keys;
}
ChemicalSystem::ElectrolyteOptions PropertyAssistant::options() const {
    ChemicalSystem::ElectrolyteOptions o;
    o.symmetric=control<QComboBox>(const_cast<PropertyAssistant *>(this),"cboRefStateSelect")->currentIndex()==1;
    o.hydronium=control<QRadioButton>(const_cast<PropertyAssistant *>(this),"radioHydroniumIon")->isChecked();
    o.waterDissociation=control<QCheckBox>(const_cast<PropertyAssistant *>(this),"chkWaterDissociation")->isChecked();
    o.ice=control<QCheckBox>(const_cast<PropertyAssistant *>(this),"chkIceFormation")->isChecked();
    o.setMethod=control<QRadioButton>(const_cast<PropertyAssistant *>(this),"radioGenSpecRxns")->isChecked();
    o.componentsOnly=!o.setMethod && !control<QCheckBox>(const_cast<PropertyAssistant *>(this),"chkGenHenryChem")->isChecked();
    o.trueComponents=control<QRadioButton>(const_cast<PropertyAssistant *>(this),"radioTrueComponent")->isChecked();
    o.method=control<QComboBox>(const_cast<PropertyAssistant *>(this),"cboOptSet")->currentText();o.chemistryId=chemistryId_;o.replaceChemistry=replaceChemistry_;return o;
}
void PropertyAssistant::showError(const QString &message) {notice_->setText(message);}
void PropertyAssistant::updateButtons() {
    const int index=steps_->currentIndex();const bool elec=name_=="electrolyte";
    back_->setEnabled(index>0 && !hasCommitted_);next_->setEnabled(index<steps_->count()-1 && !hasCommitted_);finish_->setEnabled(hasCommitted_ || (!elec && index==1));
    cancel_->setEnabled(!hasCommitted_);cancel_->setText(hasCommitted_?QString::fromUtf8("已提交"):QString::fromUtf8("取消"));
    const auto picker=steps_->widget(elec?1:0);
    control<QPushButton>(picker,"btnMove")->setEnabled(!available_->selectedItems().isEmpty());
    control<QPushButton>(picker,"btnMoveAll")->setEnabled(available_->count()>0);
    control<QPushButton>(picker,"btnRemove")->setEnabled(!selected_->selectedItems().isEmpty());
    control<QPushButton>(picker,"btnClearAll")->setEnabled(selected_->count()>0);
    if(elec) {
        const auto o=options();const bool any=!candidates_.species.isEmpty() || !candidates_.reactions.isEmpty();
        control<QComboBox>(this,"cboOptSet")->setEnabled(o.setMethod && any);
        control<QCheckBox>(this,"chkGenHenryChem")->setEnabled(!o.setMethod && any);
        for(const auto *id:{"radioGenSpecRxns","radioGenChemHenry"})control<QRadioButton>(this,id)->setEnabled(any);
        if(index==2){next_->setEnabled(any && !o.componentsOnly);finish_->setEnabled(any && o.componentsOnly);}
        auto *generated=steps_->widget(2);bool chosen=false;
        for(const auto *id:{"lstAqueousSpecies","lstSalts","lstReactions"})chosen|=!control<QListWidget>(generated,id)->selectedItems().isEmpty();
        control<QPushButton>(generated,"btnRemove")->setEnabled(any && chosen);
    } else {
        const bool existing=control<QRadioButton>(this,"radioExistChemistry")->isChecked();
        auto *combo=control<QComboBox>(this,"cmbexistingChemistry");combo->setEnabled(existing && combo->count()>0);
        control<QLineEdit>(this,"txtChemName")->setEnabled(!existing);
        control<QCheckBox>(this,"globalChecked")->setEnabled(!existing || combo->currentText()!=ChemicalSystem::globalChemistryId(initial_));
        next_->setVisible(index==0);finish_->setVisible(index==1);
    }
}
void PropertyAssistant::refreshCandidates() {
    candidates_=ChemicalSystem::electrolyteCandidates(initial_,selectedKeys(),options());
    showError(candidates_.error.isEmpty()?QString::fromUtf8("已生成纯水离解候选；尚未写入项目。没有 Henry 候选，未接入计算。"):candidates_.error);
    updateButtons();
}
void PropertyAssistant::enterPage(int index) {
    steps_->setCurrentIndex(index);
    if(name_=="electrolyte") {
        if(index==0)showError(QString::fromUtf8("当前支持已核实的纯水水合氢离子离解案例；通用反应库、H+ 和成冰规则仍待接入。"));
        if(index==1) {
            if(!options().symmetric)for(int i=available_->count()-1;i>=0;--i)if(ChemicalSystem::isWater(available_->item(i)->data(Qt::UserRole).toJsonObject()))selected_->addItem(available_->takeItem(i));
            refreshCandidates();
        }
        if(index==2) {
            control<QRadioButton>(this,"radioGenSpecRxns")->setChecked(true);
            auto *method=control<QComboBox>(this,"cboOptSet");const auto previous=method->currentText();
            comboValues(method,options().symmetric?QStringList{"ENRTL-SR"}:QStringList{"ELECNRTL","ENRTL-RK"});
            if(method->findText(previous)>=0)method->setCurrentText(previous);
            for(const auto *id:{"lstAqueousSpecies","lstSalts","lstReactions"})control<QListWidget>(steps_->widget(2),id)->clear();
            for(const auto &v:candidates_.species)control<QListWidget>(steps_->widget(2),"lstAqueousSpecies")->addItem(v.toObject().value("id").toString());
            for(const auto &v:candidates_.reactions)control<QListWidget>(steps_->widget(2),"lstReactions")->addItem(v.toObject().value("equation").toString());
        }
        if(index==3) {
            if(options().setMethod)control<QRadioButton>(this,"radioTrueComponent")->setChecked(true);
            for(const auto *id:{"radioTrueComponent","radioApparentComponent"})control<QRadioButton>(this,id)->setEnabled(options().setMethod);
            control<QLineEdit>(steps_->widget(3),"txtChemID")->setText(chemistryId_);control<QLineEdit>(steps_->widget(3),"txtHenryID")->clear();
            showError(QString::fromUtf8("下一步将写入组分和 Chemistry；关闭完成页不会撤销。保存文件请使用项目保存。"));
        }
        if(index==4) {
            auto *summary=steps_->widget(4);const auto o=options();
            control<QLineEdit>(summary,"txtChemID")->setText(chemistryId_);control<QLineEdit>(summary,"txtHenryID")->clear();
            control<QLineEdit>(summary,"txtBaseOption")->setText(o.setMethod?o.method:QString::fromUtf8("不设置"));
            control<QLineEdit>(summary,"txtSimApproach")->setText(o.setMethod && o.trueComponents?QString::fromUtf8("真实组分"):QString::fromUtf8("表观组分"));
            showError(QString::fromUtf8("已写入项目组分、反应及所选全局设置。计算常数与求解器尚未接入。"));
        }
    } else if(index==0)showError(QString::fromUtf8("仅列出项目类别为 CONV、PSEUDO、OLIGOMER 的组分；数据库组分可在组分表中指定类别。"));
    else {
        if(!sfeLoaded_) {
            QStringList ids;for(const auto &v:initial_.value("objects").toArray())if(v.toObject().value("kind")=="chemistry")ids<<v.toObject().value("name").toString();
            comboValues(control<QComboBox>(this,"cmbexistingChemistry"),ids);control<QRadioButton>(this,"radioExistChemistry")->setEnabled(!ids.isEmpty());
            control<QLineEdit>(this,"txtChemName")->setText(ChemicalSystem::defaultChemistryId(initial_));
            control<QCheckBox>(this,"globalChecked")->setChecked(ChemicalSystem::globalChemistryId(initial_).isEmpty());sfeLoaded_=true;
        }
        auto *table=control<QTableWidget>(this,"grdSolidComponent");const QSignalBlocker blocker(table);
        table->setRowCount(selected_->count());
        for(int r=0;r<selected_->count();++r) {
            const auto c=selected_->item(r)->data(Qt::UserRole).toJsonObject();auto *cell=new QTableWidgetItem(c.value("id").toString());
            cell->setData(Qt::UserRole,c.value("key").toString());cell->setFlags(cell->flags()&~Qt::ItemIsEditable);table->setItem(r,0,cell);
            table->setItem(r,1,new QTableWidgetItem(ChemicalSystem::defaultSolidId(c)));
        }
        showError(QString::fromUtf8("完成后写入项目固体组分及盐式系数；返回后再次进入会重建固体默认名。"));
    }
    updateButtons();
}
bool PropertyAssistant::chooseChemistry() {
    auto name=options().setMethod?QString("GLOBAL"):QString();replaceChemistry_=false;
    for(;;) {
        if(name.isEmpty()) {
            bool ok=false;name=ChemicalSystem::normalizedId(QInputDialog::getText(this,QString::fromUtf8("Chemistry ID"),QString::fromUtf8("输入 Chemistry ID（1–8 位字母、数字、_ 或 -）"),QLineEdit::Normal,{},&ok));
            if(!ok)return false;if(!ChemicalSystem::validChemistryId(name)){showError(QString::fromUtf8("Chemistry ID 无效。"));name.clear();continue;}
        }
        if(ChemicalSystem::chemistry(initial_,name).isEmpty()){chemistryId_=name;return true;}
        const auto choice=QMessageBox::question(this,QString::fromUtf8("Chemistry 已存在"),QString::fromUtf8("替换 %1 的化学输入？选择“否”可输入另一个 ID。").arg(name),QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Cancel);
        if(choice==QMessageBox::Cancel)return false;
        if(choice==QMessageBox::Yes){chemistryId_=name;replaceChemistry_=true;return true;}
        name.clear();
    }
}
void PropertyAssistant::forward() {
    const int index=steps_->currentIndex();
    if(name_=="sfe") {
        if(selected_->count()==0){showError(QString::fromUtf8("请选择至少一个流体组分。"));return;}enterPage(1);return;
    }
    if(index==0 && !options().symmetric) {
        bool water=false;for(const auto &v:ChemicalSystem::components(initial_))water|=ChemicalSystem::isWater(v.toObject());
        if(!water){showError(QString::fromUtf8("非对称参考态需要 WATER；请先从物性库添加水。"));return;}
    }
    if(index==1){refreshCandidates();if(!candidates_.error.isEmpty() || candidates_.reactions.isEmpty())return;}
    if(index==2 && !chooseChemistry())return;
    if(index==3 && !commit(ChemicalSystem::applyElectrolyte(initial_,selectedKeys(),options(),candidates_)))return;
    enterPage(index+1);
}
void PropertyAssistant::backward() {
    if(hasCommitted_)return;
    const int index=steps_->currentIndex();if(index==2)candidates_={};if(index>0)enterPage(index-1);
}
bool PropertyAssistant::commit(const ChemicalSystem::Result &result) {
    if(project_->state()!=initial_){showError(QString::fromUtf8("项目在向导打开后发生变化，请关闭并重新打开向导。"));return false;}
    if(!result){showError(result.error);return false;}
    const auto validation=ProjectDocument::validate(result.state);if(!validation.isEmpty()){showError(validation);return false;}
    project_->edit(result.state);hasCommitted_=true;committed_();return true;
}
void PropertyAssistant::finish() {
    if(hasCommitted_){accept();return;}
    if(auto *editor=QApplication::focusWidget();editor && isAncestorOf(editor))editor->clearFocus();
    if(name_=="electrolyte") {
        if(steps_->currentIndex()==2 && options().componentsOnly && commit(ChemicalSystem::applyElectrolyte(initial_,selectedKeys(),options(),candidates_)))accept();
        return;
    }
    auto *table=control<QTableWidget>(this,"grdSolidComponent");QJsonArray rows;
    for(int r=0;r<table->rowCount();++r)rows.append(QJsonObject{{"fluid",table->item(r,0)->data(Qt::UserRole).toString()},{"solidId",table->item(r,1)?table->item(r,1)->text():QString()}});
    const bool existing=control<QRadioButton>(this,"radioExistChemistry")->isChecked();
    const auto id=existing?control<QComboBox>(this,"cmbexistingChemistry")->currentText():control<QLineEdit>(this,"txtChemName")->text();
    if(commit(ChemicalSystem::applySfe(initial_,rows,id,existing,control<QCheckBox>(this,"globalChecked")->isChecked())))accept();
}
