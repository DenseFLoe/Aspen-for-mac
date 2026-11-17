#include "ProcessInputWidget.h"
#include "ProcessInput.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QSignalBlocker>
#include <QPushButton>

ProcessInputWidget::ProcessInputWidget(const QJsonObject &object,const QJsonArray &components,QWidget *parent)
    :QWidget(parent),object_(object),input_(object.value("processInput").toObject()) {
    setObjectName("ProcessInputEditor");input_["version"]=1;
    auto *layout=new QVBoxLayout(this);
    if(object.value("kind")=="streams" && !object.value("from").toString().isEmpty()) {
        layout->addWidget(new QLabel(QString::fromUtf8("产品／中间流股由上游设备计算；尚无计算结果。"),this));return;
    }
    layout->addWidget(new QLabel(object.value("kind")=="blocks"?QString::fromUtf8("Flash2 · 温度和压力规定"):QString::fromUtf8("进料 · 摩尔分率与总摩尔流量"),this));
    auto *form=new QFormLayout;layout->addLayout(form);
    for(const auto &f:ProcessInput::fields(object)) {
        auto *edit=new QLineEdit(input_.value(f).toObject().value("text").toString(),this);
        edit->setObjectName("Process_"+f);edit->setAccessibleName(ProcessInput::label(f));edits_[f]=edit;
        form->addRow(ProcessInput::label(f)+" ("+ProcessInput::defaultUnit(f)+")",edit);
        connect(edit,&QLineEdit::editingFinished,this,[this,f,edit]{input_[f]=ProcessInput::quantity(edit->text(),ProcessInput::defaultUnit(f));publish();});
    }
    if(object.value("kind")=="streams") {
        layout->addWidget(new QLabel(QString::fromUtf8("组成基准：摩尔分率（无量纲）；总流量单独指定。"),this));
        fractions_=new QTableWidget(this);fractions_->setObjectName("ProcessFractions");fractions_->setColumnCount(2);
        fractions_->setHorizontalHeaderLabels({QString::fromUtf8("组分"),QString::fromUtf8("摩尔分率")});fractions_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);layout->addWidget(fractions_);
        connect(fractions_,&QTableWidget::cellChanged,this,[this](int row,int col){
            if(col!=1)return;auto values=input_.value("fractions").toObject();
            values[fractions_->item(row,0)->data(Qt::UserRole).toString()]=fractions_->item(row,1)->text();input_["fractions"]=values;publish();
        });
        auto *remove=new QPushButton(QString::fromUtf8("移除已失效的组成项"),this);layout->addWidget(remove);
        connect(remove,&QPushButton::clicked,this,[this]{QJsonObject values;const auto old=input_.value("fractions").toObject();for(const auto &v:components_){const auto key=ProcessInput::componentKey(v.toObject());if(old.contains(key))values[key]=old[key];}input_["fractions"]=values;publish();});
    }
    status_=new QLabel(this);status_->setWordWrap(true);status_->setObjectName("ProcessInputStatus");layout->addWidget(status_);layout->addStretch();setComponents(components);updateStatus();
}
void ProcessInputWidget::setComponents(const QJsonArray &components) {
    if(components_==components)return;components_=components;
    if(fractions_) {const QSignalBlocker block(fractions_);fractions_->setRowCount(components.size());int row=0;
        for(const auto &v:components){const auto c=v.toObject();const auto key=ProcessInput::componentKey(c);auto *name=new QTableWidgetItem(c.value("name").toString());name->setFlags(name->flags()&~Qt::ItemIsEditable);name->setData(Qt::UserRole,key);fractions_->setItem(row,0,name);fractions_->setItem(row++,1,new QTableWidgetItem(input_.value("fractions").toObject().value(key).toString()));}}
    updateStatus();
}
void ProcessInputWidget::publish() {object_["processInput"]=input_;updateStatus();emit inputChanged(input_);}
void ProcessInputWidget::updateStatus() {if(!status_)return;object_["processInput"]=input_;const auto problems=ProcessInput::issues(object_,components_);status_->setText(problems.isEmpty()?QString::fromUtf8("本页输入完整；尚未接入计算。"):problems.first().message);}
void ProcessInputWidget::focusField(const QString &field) {
    if(edits_.contains(field)){edits_[field]->setFocus();edits_[field]->selectAll();}
    else if(fractions_){int row=0;for(int i=0;i<fractions_->rowCount();++i)if(field=="fraction:"+fractions_->item(i,0)->data(Qt::UserRole).toString())row=i;fractions_->setFocus();if(fractions_->rowCount())fractions_->setCurrentCell(row,1);}
}
