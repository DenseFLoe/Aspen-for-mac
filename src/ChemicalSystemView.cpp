#include "ChemicalSystemView.h"
#include "ChemicalSystem.h"
#include <QBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMap>
#include <QTableWidget>

QWidget *makeChemicalSystemView(const QJsonObject &record,const QJsonObject &state,QWidget *parent) {
    auto *view=new QWidget(parent);view->setObjectName("ChemicalSystemView");view->setProperty("projectDerived",true);
    auto *column=new QVBoxLayout(view);const auto data=record.value("chemistryData").toObject();
    auto *heading=new QLabel(QString::fromUtf8("Chemistry — ")+record.value("name").toString(),view);column->addWidget(heading);
    auto *notice=new QLabel(QString::fromUtf8("以下为项目中的实际反应及盐式系数。尚未接入平衡常数、求解器和完整反应编辑校验。"),view);notice->setWordWrap(true);column->addWidget(notice);
    QStringList metadata;
    if(data.contains("referenceState"))metadata<<QString::fromUtf8("参考态：")+data.value("referenceState").toString();
    if(data.contains("approach"))metadata<<QString::fromUtf8("模拟方式：")+data.value("approach").toString();
    if(data.contains("gammaBasis"))metadata<<"GAMMA_BASIS: (unset)";
    column->addWidget(new QLabel(metadata.join("  ·  "),view));
    QMap<QString,QString> names;
    for(const auto &v:ChemicalSystem::components(state))names[v.toObject().value("key").toString()]=v.toObject().value("id").toString();
    auto *table=new QTableWidget(view);table->setObjectName("ChemistryRecords");table->setProperty("projectDerived",true);
    table->setColumnCount(4);table->setHorizontalHeaderLabels({QString::fromUtf8("记录"),QString::fromUtf8("组分"),QString::fromUtf8("系数"),QString::fromUtf8("选项／证据")});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);table->horizontalHeader()->setStretchLastSection(true);
    const auto append=[&](const QString &title,const QJsonObject &coeff,const QString &option) {
        for(auto it=coeff.begin();it!=coeff.end();++it) {
            const int row=table->rowCount();table->insertRow(row);const QStringList cells{title,names.value(it.key(),it.key()),it.value().toString(),option};
            for(int c=0;c<cells.size();++c)table->setItem(row,c,new QTableWidgetItem(cells[c]));table->item(row,1)->setToolTip(it.key());
        }
    };
    for(const auto &v:data.value("reactions").toArray()) {const auto r=v.toObject();append(r.value("equation").toString(r.value("id").toString()),r.value("coefficients").toObject(),r.value("evidence").toString());}
    for(const auto &v:data.value("saltCoefficients").toArray()) {const auto r=v.toObject();append(names.value(r.value("solid").toString()),r.value("coefficients").toObject(),"SALT_OPTION="+r.value("option").toString());}
    column->addWidget(table,1);return view;
}
