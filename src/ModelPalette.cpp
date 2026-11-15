#include "ObjectWorkspace.h"
#include <QBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QTabWidget>
#include <QToolButton>

QIcon flowsheetModelIcon(const QString &type, bool threeDimensional)
{
    QPixmap image(64, 56); image.fill(Qt::transparent);
    QPainter p(&image); p.setRenderHint(QPainter::Antialiasing);
    QLinearGradient metal(8, 0, 54, 0);
    metal.setColorAt(0, QColor("#55574d")); metal.setColorAt(.42, QColor("#f5f5df")); metal.setColorAt(1, QColor("#77796a"));
    p.setPen(QPen(QColor("#45483e"), 1.2)); p.setBrush(threeDimensional?QBrush(metal):QBrush(QColor("#e0e8ef")));
    if(type=="Mixer" || type=="Fsplit") {
        QPolygonF shape; shape << QPointF(14,4) << QPointF(49,28) << QPointF(14,52);
        if(type=="Fsplit") {p.translate(64,0);p.scale(-1,1);}
        p.drawPolygon(shape);
    } else if(type=="MATERIAL" || type=="HEAT" || type=="WORK" || type=="POWER") {
        p.setPen(QPen(QColor("#526579"),1.4)); p.drawLine(5,28,59,28);
        p.drawLine(54,23,59,28);p.drawLine(54,33,59,28);
        p.setBrush(QColor("#dce7f3"));p.drawRect(24,20,16,16);
    } else if(type=="Ssplit") {
        p.drawRect(4,11,14,9);p.drawRect(28,2,9,9);
        QPainterPath body;body.moveTo(16,9);body.lineTo(51,9);body.lineTo(51,36);body.lineTo(37,49);body.lineTo(37,54);body.lineTo(29,54);body.lineTo(29,49);body.lineTo(16,36);body.closeSubpath();p.drawPath(body);
    } else if(type.contains("frac",Qt::CaseInsensitive) || type=="Distl" || type=="Dstwu") {
        p.drawRoundedRect(23,2,22,52,8,8);for(int y=14;y<49;y+=9)p.drawLine(24,y,44,y);
    } else if(type=="Pump" || type.contains("Compr")) {
        p.drawEllipse(12,9,37,37);p.drawPolygon(QPolygonF{QPointF(13,52),QPointF(25,41),QPointF(40,41),QPointF(50,52)});
    } else {
        p.drawRoundedRect(17,6,32,44,7,7);p.drawLine(4,20,17,20);p.drawLine(49,36,61,36);
    }
    return QIcon(image);
}

QWidget *ObjectWorkspace::makeMetrics()
{
    auto *strip=new QWidget(this);strip->setObjectName("FlowsheetMetrics");strip->setFixedHeight(34);
    auto *row=new QHBoxLayout(strip);row->setContentsMargins(0,0,0,0);row->setSpacing(2);
    const QStringList labels{QString::fromUtf8("资本:  ___ USD   公用工程:  ___ USD/Year"),
        QString::fromUtf8("节能:  ___ MW  (___ %)"),QString::fromUtf8("换热器 - 未知:  0   正常:  0   风险:  0"),QString::fromUtf8("CO2e 范围1  ___")};
    const QStringList colors{"#c2e3b5","#bbe0fa","#e4cfaa","#626464"};
    const QStringList borders{"#42991b","#477aff","#a78b50","#999999"};
    for(int i=0;i<labels.size();++i) {
        auto *card=new QWidget(strip);auto *cardRow=new QHBoxLayout(card);cardRow->setContentsMargins(7,2,7,2);cardRow->setSpacing(8);
        card->setObjectName("MetricCard"+QString::number(i));
        card->setStyleSheet(QString("QWidget#%1 {background:%2; border:2px solid %3;} QLabel {color:%4;}").arg(card->objectName(),colors[i],borders[i],i==3?"#dddddd":"#182018"));
        auto *label=new QLabel(labels[i],card);cardRow->addWidget(label,1);
        if(i<2) {
            QPixmap switchImage(52,20);switchImage.fill(Qt::transparent);QPainter painter(&switchImage);painter.setRenderHint(QPainter::Antialiasing);painter.setPen(QPen(QColor("#1a231b"),2));painter.drawEllipse(1,2,15,15);painter.drawLine(4,5,13,14);
            QLinearGradient gradient(0,0,0,20);gradient.setColorAt(0,QColor("#666666"));gradient.setColorAt(1,QColor("#101010"));painter.setBrush(gradient);painter.setPen(Qt::NoPen);painter.drawRoundedRect(20,2,31,16,8,8);painter.setBrush(QColor("#dddddd"));painter.drawEllipse(22,3,14,14);painter.end();
            auto *toggle=new QLabel(card);toggle->setPixmap(switchImage);cardRow->addWidget(toggle);
        }
        card->setToolTip(QString::fromUtf8("尚未接入分析计算；空白值表示暂无结果。"));row->addWidget(card,i==0?4:i==3?1:3);
    }
    auto *scroll=new QScrollArea(this);scroll->setObjectName("MetricsScroll");scroll->setWidget(strip);scroll->setWidgetResizable(true);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);scroll->setFixedHeight(36);
    return scroll;
}

QWidget *ObjectWorkspace::makeModelPalette()
{
    auto *panel=new QWidget(this);panel->setObjectName("ModelPalette");panel->setFixedHeight(130);
    auto *column=new QVBoxLayout(panel);column->setContentsMargins(3,0,3,3);column->setSpacing(1);
    auto *header=new QHBoxLayout;auto *title=new QLabel(QString::fromUtf8("模型选项板"),panel);title->setObjectName("PaletteTitle");header->addWidget(title,1);
    auto *collapse=new QToolButton(panel);collapse->setArrowType(Qt::DownArrow);collapse->setToolTip(QString::fromUtf8("折叠/展开模型选项板"));header->addWidget(collapse);
    auto *close=new QToolButton(panel);close->setText("×");close->setToolTip(QString::fromUtf8("关闭模型选项板（在查看选项卡重新打开）"));header->addWidget(close);column->addLayout(header);
    auto *body=new QWidget(panel);auto *row=new QHBoxLayout(body);row->setContentsMargins(0,0,0,0);row->setSpacing(8);
    auto *streams=new QWidget(body);auto *streamColumn=new QVBoxLayout(streams);streamColumn->setContentsMargins(0,0,0,0);streamColumn->setSpacing(3);
    auto *select=new QPushButton(QString::fromUtf8("↖"),streams);select->setObjectName("FlowSelect");select->setToolTip(QString::fromUtf8("选择对象 / 退出放置"));select->setFixedSize(21,21);streamColumn->addWidget(select);
    connect(select,&QPushButton::clicked,this,[this]{beginPlacement({},{});});
    auto *stream=new QToolButton(streams);stream->setObjectName("StreamPaletteButton");stream->setText(QString::fromUtf8("物料"));stream->setIcon(flowsheetModelIcon("MATERIAL",true));stream->setIconSize(QSize(58,46));
    stream->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);stream->setFixedSize(80,70);stream->setPopupMode(QToolButton::MenuButtonPopup);stream->setProperty("paletteType","MATERIAL");
    auto *menu=new QMenu(stream);const QStringList streamTypes{"MATERIAL","HEAT","WORK","POWER"},streamLabels{QString::fromUtf8("物料"),QString::fromUtf8("热量"),QString::fromUtf8("功"),QString::fromUtf8("电能")};
    for(int i=0;i<streamTypes.size();++i) {
        auto *action=menu->addAction(streamLabels[i]);connect(action,&QAction::triggered,this,[this,stream,streamTypes,streamLabels,i]{stream->setText(streamLabels[i]);stream->setProperty("paletteType",streamTypes[i]);beginPlacement("streams",streamTypes[i]);});
    }
    stream->setMenu(menu);connect(stream,&QToolButton::clicked,this,[this,stream]{beginPlacement("streams",stream->property("paletteType").toString());});streamColumn->addWidget(stream);row->addWidget(streams);
    auto *tabs=new QTabWidget(body);tabs->setObjectName("ModelCategories");tabs->setUsesScrollButtons(true);tabs->setDocumentMode(true);
    const QList<QPair<QString,QStringList>> groups{
        {QString::fromUtf8("混合器/分流器"),{"Mixer","Fsplit","Ssplit"}},
        {QString::fromUtf8("分离器"),{"Flash2","Flash3","Decanter","Sep","Sep2"}},
        {QString::fromUtf8("换热器"),{"Heater","HeatX","MHeatx","HXFlux"}},
        {QString::fromUtf8("塔"),{"RadFrac","Dstwu","Distl","Extract","Multifrac","Petrofrac","Scfrac"}},
        {QString::fromUtf8("反应器"),{"RStoic","RYield","REquil","RGibbs","RCSTR","RPlug","RBatch","Electrolyzer"}},
        {QString::fromUtf8("压力变送设备"),{"Pump","Compr","MCompr","Valve","Pipeline"}},
        {QString::fromUtf8("操纵器"),{"Dupl","Clchng","Feedbl","Makeup","Mult","QTVec","Selector","Strvar","Chargebal"}},
        {QString::fromUtf8("固体"),{"Crusher","Crystallizer","BatchCrystal","Dryer","Flubed","Granulator"}},
        {QString::fromUtf8("固体分离器"),{"Ccd","CfFilter","Cfuge","Classifier","Cyclone","Esp","Fabfl","Filter","Hycyc","Screen","Swash","Vscrub"}},
        {QString::fromUtf8("间歇模型"),{"BatchOp","BatchSep","ConSep"}},
        {QString::fromUtf8("用户模型"),{"Hierarchy","Solvay","User","User2","User3"}}
    };
    for(const auto &group:groups) {
        auto *page=new QWidget;auto *models=new QHBoxLayout(page);models->setContentsMargins(3,3,3,0);models->setSpacing(7);
        for(const auto &requested:group.second) {
            QString type;for(const auto &v:definition("blocks").value("types").toArray()) if(v.toObject().value("id").toString().compare(requested,Qt::CaseInsensitive)==0)type=v.toObject().value("id").toString();
            if(type.isEmpty()) continue;
            auto *button=new QToolButton(page);button->setObjectName("Model-"+type);button->setProperty("paletteType",type);button->setProperty("modelTile",true);
            button->setText(type=="Fsplit"?"FSplit":type=="Ssplit"?"SSplit":type);button->setCheckable(true);button->setIcon(flowsheetModelIcon(type,true));button->setIconSize(QSize(64,52));button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);button->setFixedSize(70,72);
            button->setToolTip(QString::fromUtf8("选择 %1，然后单击流程图放置").arg(type));
            connect(button,&QToolButton::clicked,this,[this,type]{beginPlacement("blocks",type);});models->addWidget(button);
        }
        models->addStretch();auto *scroll=new QScrollArea;scroll->setWidget(page);scroll->setWidgetResizable(true);scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);tabs->addTab(scroll,group.first);
    }
    row->addWidget(tabs,1);column->addWidget(body,1);
    connect(collapse,&QToolButton::clicked,panel,[panel,body]{const bool hidden=!body->isHidden();body->setVisible(!hidden);panel->setFixedHeight(hidden?24:130);});
    connect(close,&QToolButton::clicked,this,[this]{setModelPaletteVisible(false);});
    return panel;
}

void ObjectWorkspace::setModelPaletteVisible(bool visible) {modelPalette_->setVisible(visible);}
