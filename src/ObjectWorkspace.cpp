#include "ProcessInput.h"
#include "ProcessUnits.h"
#include "ProcessInputWidget.h"
#include "ObjectWorkspace.h"
#include "ChemicalSystem.h"
#include "ChemicalSystemView.h"
#include "RecoveredWorkspace.h"
#include "IconCatalog.h"
#include <QAction>
#include <QBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>
#include <QGridLayout>
#include <QContextMenuEvent>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>
#include <QFormLayout>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QHeaderView>
#include <QJsonDocument>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPainterPathStroker>
#include <QPushButton>
#include <QRegularExpression>
#include <QSignalBlocker>
#include <QShortcut>
#include <QStyleOptionGraphicsItem>
#include <QTableWidget>
#include <QTabBar>
#include <QTabWidget>
#include <QToolButton>
#include <QUuid>
#include <functional>

QIcon flowsheetModelIcon(const QString &type, bool threeDimensional);

class BlockGraphicsItem final : public QGraphicsRectItem
{
public:
    BlockGraphicsItem():QGraphicsRectItem(-40,-36,80,84) {setPen(Qt::NoPen);setBrush(Qt::NoBrush);}
    QRectF boundingRect() const override {return QGraphicsRectItem::boundingRect().adjusted(-3,-3,3,3);}
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override {
        auto appearance=*option;appearance.state&=~QStyle::State_Selected;
        QGraphicsRectItem::paint(painter,&appearance,widget);
        if(!isSelected())return;
        painter->save();painter->setPen(Qt::NoPen);painter->setBrush(Qt::black);
        const auto r=rect();const QList<QPointF> points{r.topLeft(),r.topRight(),r.bottomLeft(),r.bottomRight(),
            {r.center().x(),r.top()},{r.center().x(),r.bottom()},{r.left(),r.center().y()},{r.right(),r.center().y()}};
        for(const auto &p:points)painter->drawRect(QRectF(p-QPointF(2,2),QSizeF(4,4)));
        painter->restore();
    }
};

// Keep thin stream strokes easy to select without changing their visible width.
class StreamGraphicsItem final : public QGraphicsPathItem
{
public:
    explicit StreamGraphicsItem(const QPainterPath &path):QGraphicsPathItem(path) {}
    QPainterPath shape() const override {
        QPainterPathStroker stroke;stroke.setWidth(10);return stroke.createStroke(path());
    }
    QRectF boundingRect() const override {return shape().boundingRect();}
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override {
        auto appearance=*option;appearance.state&=~QStyle::State_Selected;
        QGraphicsPathItem::paint(painter,&appearance,widget);
        if(!isSelected())return;
        painter->save();painter->setPen(QPen(QColor("#368b3e"),1));painter->setBrush(Qt::white);
        const auto route=path();for(int i=0;i<route.elementCount();++i){const auto p=route.elementAt(i);painter->drawRect(QRectF(p.x-2.5,p.y-2.5,5,5));}
        painter->restore();
    }
};

class FlowsheetView final : public QGraphicsView
{
public:
    explicit FlowsheetView(QWidget *parent) : QGraphicsView(parent) {
        setScene(new QGraphicsScene(this)); setSceneRect(0,0,1200,800);
        setBackgroundBrush(Qt::white); setRenderHint(QPainter::Antialiasing);
        setDragMode(QGraphicsView::RubberBandDrag); setAlignment(Qt::AlignLeft|Qt::AlignTop);
        setObjectName("FlowsheetCanvas");
    }
    bool placing=false;
    std::function<void(QPointF,QString)> place;
    std::function<void(QString)> open, rename, copy, cut;
    std::function<void(QStringList)> remove;
    std::function<void()> cancel;
    std::function<void()> paste;
    std::function<void(QPoint)> menu;
    std::function<void(QMap<QString,QPointF>)> moved;
    bool locked=false;
    QStringList selectedKeys() const {
        QStringList keys;
        for(auto *item:scene()->selectedItems()) {
            const auto key=item->data(0).toString();
            if(!key.isEmpty() && !keys.contains(key)) keys.append(key);
        }
        return keys;
    }
    QString keyAt(const QPoint &position) const {
        auto *item=itemAt(position);
        while(item && item->data(0).toString().isEmpty()) item=item->parentItem();
        return item?item->data(0).toString():QString();
    }
protected:
    bool event(QEvent *event) override {
        if(event->type()==QEvent::ShortcutOverride && static_cast<QKeyEvent *>(event)->key()==Qt::Key_Escape) {event->accept();return true;}
        return QGraphicsView::event(event);
    }
    void mousePressEvent(QMouseEvent *event) override {
        suppressContextMenu_=false;
        if(placing && event->button()==Qt::RightButton) {
            cancel();suppressContextMenu_=true;event->accept();return;
        }
        if(placing && event->button()==Qt::LeftButton) {
            const auto key=keyAt(event->position().toPoint());
            place(mapToScene(event->position().toPoint()),key); event->accept(); return;
        }
        QGraphicsView::mousePressEvent(event);
        dragStart_.clear();
        if(event->button()==Qt::LeftButton && !locked)
            for(auto *item:scene()->selectedItems())
                if(item->data(1).toString()=="block")dragStart_[item->data(0).toString()]=item->pos();
    }
    void contextMenuEvent(QContextMenuEvent *event) override {
        if(suppressContextMenu_) {suppressContextMenu_=false;event->accept();return;}
        if(placing) {cancel();event->accept();return;}
        QPoint point=event->pos();
        if(event->reason()==QContextMenuEvent::Keyboard) {
            const auto selected=scene()->selectedItems();
            point=selected.isEmpty()?viewport()->rect().center():mapFromScene(selected.first()->sceneBoundingRect().center());
        }
        menu(point);event->accept();
    }
    void mouseDoubleClickEvent(QMouseEvent *event) override {
        const auto key=keyAt(event->position().toPoint());
        if(event->button()==Qt::LeftButton && !placing && !key.isEmpty()) { open(key); event->accept(); return; }
        QGraphicsView::mouseDoubleClickEvent(event);
    }
    void mouseReleaseEvent(QMouseEvent *event) override {
        QGraphicsView::mouseReleaseEvent(event);
        if(event->button()!=Qt::LeftButton || locked || placing) return;
        QMap<QString,QPointF> positions;
        for(auto *item:scene()->selectedItems())
            if(const auto key=item->data(0).toString();dragStart_.contains(key) && item->pos()!=dragStart_.value(key))positions[key]=item->pos();
        dragStart_.clear();
        if(!positions.isEmpty())moved(positions);
    }
    void keyPressEvent(QKeyEvent *event) override {
        const auto keys=selectedKeys();
        if(event->key()==Qt::Key_Escape) {if(placing)cancel();else scene()->clearSelection();event->accept();return;}
        if(event->key()==Qt::Key_Menu || (event->key()==Qt::Key_F10 && event->modifiers()==Qt::ShiftModifier)) {
            if(placing)cancel();else {
                const auto selected=scene()->selectedItems();
                menu(selected.isEmpty()?viewport()->rect().center():mapFromScene(selected.first()->sceneBoundingRect().center()));
            }
            event->accept();return;
        }
        if(placing) {QGraphicsView::keyPressEvent(event);return;}
        if(event->matches(QKeySequence::SelectAll)) {for(auto *item:scene()->items())if(item->flags().testFlag(QGraphicsItem::ItemIsSelectable))item->setSelected(true);event->accept();return;}
        if(event->matches(QKeySequence::Copy)) {if(keys.size()==1)copy(keys.first());event->accept();return;}
        if(event->matches(QKeySequence::Cut)) {if(!locked && keys.size()==1)cut(keys.first());event->accept();return;}
        if(event->matches(QKeySequence::Paste)) {if(!locked)paste();event->accept();return;}
        if(event->key()==Qt::Key_Delete || event->key()==Qt::Key_Backspace) {if(!locked && !keys.isEmpty())remove(keys);event->accept();return;}
        if(keys.size()==1 && (event->key()==Qt::Key_Return || event->key()==Qt::Key_Enter)) {open(keys.first());event->accept();return;}
        if(keys.size()==1 && event->key()==Qt::Key_F2) {if(!locked)rename(keys.first());event->accept();return;}
        QGraphicsView::keyPressEvent(event);
    }
private:
    QMap<QString,QPointF> dragStart_;
    bool suppressContextMenu_=false;
};

ObjectWorkspace::ObjectWorkspace(QWidget *parent) : QWidget(parent)
{
    setObjectName("ObjectWorkspace");
    QFile catalog(":/ui/object-types.json"); catalog.open(QIODevice::ReadOnly);
    definitions_=QJsonDocument::fromJson(catalog.readAll()).object().value("collections").toArray();
    auto *layout=new QVBoxLayout(this); layout->setContentsMargins(3,0,3,3);
    documents_=new QTabWidget(this); documents_->setObjectName("ObjectDocuments");
    documents_->setDocumentMode(true); documents_->setTabsClosable(true); documents_->setMovable(true);
    documents_->setUsesScrollButtons(true); metrics_=makeMetrics(); layout->addWidget(metrics_); layout->addWidget(documents_,1);
    manager_=new QWidget(documents_); manager_->setObjectName("ObjectManager");
    auto *managerLayout=new QVBoxLayout(manager_);
    heading_=new QLabel(manager_); managerLayout->addWidget(heading_);
    auto *toolbar=new QHBoxLayout;
    const QList<QPair<QString,QString>> actions{{"new",QString::fromUtf8("新建")},{"copy",QString::fromUtf8("复制")},
        {"paste",QString::fromUtf8("粘贴")},{"edit",QString::fromUtf8("编辑输入")},{"rename",QString::fromUtf8("重命名")},{"delete",QString::fromUtf8("删除")}};
    for(const auto &a:actions) {
        auto *button=new QPushButton(a.second,manager_); button->setObjectName("Object"+a.first);
        buttons_[a.first]=button; toolbar->addWidget(button);
    }
    toolbar->addStretch(); managerLayout->addLayout(toolbar);
    table_=new QTableWidget(0,4,manager_); table_->setObjectName("ObjectTable");
    table_->setHorizontalHeaderLabels({QString::fromUtf8("名称"),QString::fromUtf8("类型"),QString::fromUtf8("状态"),QString::fromUtf8("描述")});
    table_->setSelectionBehavior(QAbstractItemView::SelectRows); table_->setSelectionMode(QAbstractItemView::SingleSelection);
    table_->setEditTriggers(QAbstractItemView::NoEditTriggers); table_->horizontalHeader()->setStretchLastSection(true);
    table_->verticalHeader()->hide(); managerLayout->addWidget(table_,1);
    connect(buttons_["new"],&QPushButton::clicked,this,[this]{requestNew(kind_,parent_);});
    connect(buttons_["copy"],&QPushButton::clicked,this,[this]{copyObject(selectedKey());});
    connect(buttons_["paste"],&QPushButton::clicked,this,&ObjectWorkspace::requestPaste);
    connect(buttons_["edit"],&QPushButton::clicked,this,[this]{openObject(selectedKey());});
    connect(buttons_["rename"],&QPushButton::clicked,this,[this]{requestRename(selectedKey());});
    connect(buttons_["delete"],&QPushButton::clicked,this,[this]{requestDelete(selectedKey());});
    connect(table_,&QTableWidget::itemSelectionChanged,this,&ObjectWorkspace::refreshButtons);
    connect(table_,&QTableWidget::cellActivated,this,[this](int,int){openObject(selectedKey());});
    const QList<QPair<QKeySequence,QString>> tableKeys{{QKeySequence::Copy,"copy"},{QKeySequence::Paste,"paste"},{QKeySequence(Qt::Key_Delete),"delete"},{QKeySequence(Qt::Key_F2),"rename"}};
    for(const auto &binding:tableKeys) {
        auto *shortcut=new QShortcut(binding.first,table_);shortcut->setContext(Qt::WidgetShortcut);
        connect(shortcut,&QShortcut::activated,this,[this,binding]{buttons_[binding.second]->click();});
    }
    table_->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(table_,&QWidget::customContextMenuRequested,this,[this](const QPoint &point){
        if(auto *item=table_->itemAt(point)) table_->selectRow(item->row());
        QMenu menu(this);
        for(const auto &key:{"new","edit","rename","copy","paste","delete"}) {
            auto *a=menu.addAction(buttons_[key]->text()); a->setEnabled(buttons_[key]->isEnabled());
            connect(a,&QAction::triggered,buttons_[key],&QPushButton::click);
        }
        menu.exec(table_->viewport()->mapToGlobal(point));
    });
    documents_->addTab(manager_,QString::fromUtf8("对象"));
    documents_->tabBar()->setTabButton(0,QTabBar::RightSide,nullptr);

    flowsheet_=new QWidget(documents_); auto *flowLayout=new QVBoxLayout(flowsheet_);
    flowLayout->setContentsMargins(0,0,0,0); canvas_=new FlowsheetView(flowsheet_); flowLayout->addWidget(canvas_,1);
    placementNotice_=new QLabel(flowsheet_); placementNotice_->setObjectName("FlowPlacementNotice"); placementNotice_->hide(); flowLayout->addWidget(placementNotice_);
    modelPalette_=makeModelPalette(); layout->addWidget(modelPalette_);
    documents_->addTab(flowsheet_,QString::fromUtf8("主工艺流程"));
    documents_->tabBar()->setTabButton(1,QTabBar::RightSide,nullptr);
    canvas_->place=[this](QPointF p,const QString &key){placeAt(p,key);};
    canvas_->open=[this](const QString &key){openObject(key);};
    canvas_->remove=[this](const QStringList &keys){if(!flowsheetLocked_)requestDeleteObjects(keys);};
    canvas_->rename=[this](const QString &key){if(!flowsheetLocked_)requestRename(key);};
    canvas_->copy=[this](const QString &key){copyObject(key);};
    canvas_->cut=[this](const QString &key){if(!flowsheetLocked_){copyObject(key);removeObject(key);}};
    canvas_->paste=[this]{if(!flowsheetLocked_)requestPaste();};
    canvas_->menu=[this](QPoint p){showFlowsheetMenu(p);};
    canvas_->moved=[this](const QMap<QString,QPointF> &positions){moveBlocks(positions);};
    canvas_->cancel=[this]{beginPlacement({},{});};
    connect(canvas_->scene(),&QGraphicsScene::selectionChanged,this,&ObjectWorkspace::flowsheetSelectionChanged);
    connect(documents_,&QTabWidget::tabCloseRequested,this,[this](int index){
        auto *view=documents_->widget(index); if(view==manager_ || view==flowsheet_) return;
        closeObject(view->property("objectKey").toString());
    });
    connect(documents_,&QTabWidget::currentChanged,this,[this](int){
        const bool flow=documents_->currentWidget()==flowsheet_;
        metrics_->setVisible(flow); modelPalette_->setVisible(flow);
        emit flowsheetActivated(flow);
        const auto key=currentObject();
        if(entries_.contains(key) && entries_[key].view)
            emit objectActivated(key,entries_[key].view->currentPage());
    });
    metrics_->hide();modelPalette_->hide();
    showCollection("property-sets");
}

ObjectWorkspace::~ObjectWorkspace() {
    // QWidget tears down its children after the derived destructor has finished.
    // A selected scene emits selectionChanged while deleting its items, and tab
    // teardown can also emit signals. Stop callbacks while this type is still alive.
    for(auto *child:findChildren<QObject *>())QObject::disconnect(child,nullptr,this,nullptr);
}

QJsonArray ObjectWorkspace::objects() const {
    QJsonArray result; for(const auto &key:order_) if(entries_.contains(key)) result.append(entries_[key].data); return result;
}
QJsonObject ObjectWorkspace::object(const QString &key) const {return entries_.value(key).data;}
QJsonObject ObjectWorkspace::definition(const QString &kind) const {
    for(const auto &v:definitions_) if(v.toObject().value("id").toString()==kind) return v.toObject(); return {};
}
QJsonObject ObjectWorkspace::typeDefinition(const QString &kind,const QString &type) const {
    for(const auto &v:definition(kind).value("types").toArray()) if(v.toObject().value("id").toString()==type) return v.toObject(); return {};
}
QString ObjectWorkspace::suggestedName(const QString &kind,const QString &parent) const {
    const auto spec=definition(kind), owner=object(parent);
    const auto parents=spec.value("parentTypes").toArray();
    if(spec.isEmpty() || (parents.isEmpty() && !parent.isEmpty()) ||
        (!parents.isEmpty() && !parents.contains(owner.value("type")))) return {};
    const auto prefix=definition(kind).value("prefix").toString("OBJ-");
    for(int i=1;;++i) {const auto name=prefix+QString::number(i); if(nameError(kind,name,parent).isEmpty()) return name;}
}
QString ObjectWorkspace::nameError(const QString &kind,const QString &name,const QString &parent,const QString &except) const {
    if(definition(kind).isEmpty()) return QString::fromUtf8("未知对象类别");
    if(!parent.isEmpty() && !entries_.contains(parent)) return QString::fromUtf8("所属对象已不存在");
    const auto parentTypes=definition(kind).value("parentTypes").toArray();
    if(!parentTypes.isEmpty() && !parentTypes.contains(object(parent).value("type"))) return QString::fromUtf8("请选择有效的所属模块。");
    if(parentTypes.isEmpty() && !parent.isEmpty()) return QString::fromUtf8("此类别属于案例顶层。");
    if(!QRegularExpression("^[A-Za-z0-9][A-Za-z0-9_-]{0,7}$").match(name).hasMatch()) return QString::fromUtf8("请输入 1–8 位字母、数字、连字符或下划线组成的 ID。");
    if(kind=="user-components")for(const auto &v:ChemicalSystem::components(chemicalState_)) {
        const auto c=v.toObject();if(c.value("key")!="object:"+except && ChemicalSystem::normalizedId(c.value("id").toString())==ChemicalSystem::normalizedId(name))return QString::fromUtf8("项目已有此组分 ID。");
    }
    for(auto it=entries_.cbegin();it!=entries_.cend();++it) {
        const auto d=it->data;
        if(it.key()!=except && d.value("kind")==kind && d.value("parent")==parent && d.value("name").toString().compare(name,Qt::CaseInsensitive)==0)
            return QString::fromUtf8("此 ID 已存在，请输入不同的名称。");
    }
    return {};
}
QString ObjectWorkspace::createObject(const QString &kind,const QString &name,const QString &type,const QString &parent) {
    const auto normalized=name.trimmed().toUpper();
    if(!nameError(kind,normalized,parent).isEmpty() || typeDefinition(kind,type).isEmpty()) return {};
    const auto key=QUuid::createUuid().toString(QUuid::WithoutBraces);
    Entry entry; entry.data={{"key",key},{"kind",kind},{"name",normalized},{"type",type},{"parent",parent},
        {"x",100+(order_.size()%6)*130},{"y",100+(order_.size()/6)*100}};
    entries_.insert(key,entry); order_.append(key); refreshManager(); refreshCanvas(); emit objectsChanged(); return key;
}
bool ObjectWorkspace::renameObject(const QString &key,const QString &name) {
    if(!entries_.contains(key)) return false;
    auto &d=entries_[key].data; const auto normalized=name.trimmed().toUpper();
    if(!nameError(d.value("kind").toString(),normalized,d.value("parent").toString(),key).isEmpty()) return false;
    d["name"]=normalized; refreshTitles(); refreshManager(); refreshCanvas(); emit objectsChanged(); return true;
}
bool ObjectWorkspace::removeObject(const QString &key) {
    if(!entries_.contains(key)) return false;
    if(ChemicalSystem::componentReferenced(chemicalState_,"object:"+key)) return false;
    QStringList removed{key};
    for(int i=0;i<removed.size();++i) for(const auto &candidate:order_)
        if(entries_[candidate].data.value("parent").toString()==removed[i]) removed.append(candidate);
    for(const auto &id:removed) {closeObject(id); entries_.remove(id); order_.removeAll(id);}
    for(auto &entry:entries_) for(const auto &end:{"from","to"}) if(removed.contains(entry.data.value(end).toString())) entry.data[end]="";
    if(removed.contains(parent_)) {parent_.clear();kind_="blocks";}
    refreshManager(); refreshCanvas(); emit objectsRemoved(removed); emit objectsChanged(); return true;
}
QString ObjectWorkspace::selectedKey() const {
    return table_->currentRow()>=0 && table_->item(table_->currentRow(),0)?table_->item(table_->currentRow(),0)->data(Qt::UserRole).toString():QString();
}
QString ObjectWorkspace::currentObject() const {return documents_->currentWidget()?documents_->currentWidget()->property("objectKey").toString():QString();}
void ObjectWorkspace::refreshManager() {
    const auto selected=selectedKey(); const QSignalBlocker blocker(table_); table_->setRowCount(0);
    heading_->setText(definition(kind_).value("label").toString()+(parent_.isEmpty()?QString():" — "+object(parent_).value("name").toString()));
    documents_->setTabText(documents_->indexOf(manager_),heading_->text());
    for(const auto &key:order_) {
        const auto d=entries_[key].data;
        if(d.value("kind")!=kind_ || d.value("parent")!=parent_) continue;
        const int row=table_->rowCount(); table_->insertRow(row);
        const QStringList cells{d.value("name").toString(),typeDefinition(kind_,d.value("type").toString()).value("label").toString(d.value("type").toString()),QString::fromUtf8("输入未完成"),d.value("description").toString()};
        for(int col=0;col<cells.size();++col) table_->setItem(row,col,new QTableWidgetItem(cells[col]));
        table_->item(row,0)->setData(Qt::UserRole,key);
        if(key==selected) table_->selectRow(row);
    }
    refreshButtons();
}
void ObjectWorkspace::refreshButtons() {
    const bool selected=entries_.contains(selectedKey());
    for(const auto &name:{"edit","copy","rename","delete"}) buttons_[name]->setEnabled(selected);
    buttons_["new"]->setEnabled(!definition(kind_).isEmpty());
    buttons_["paste"]->setEnabled(!clipboard_.isEmpty() && clipboard_.value("kind")==kind_);
}
void ObjectWorkspace::showCollection(const QString &kind,const QString &parent) {
    if(definition(kind).isEmpty() || (!parent.isEmpty() && !entries_.contains(parent))) return;
    const auto parents=definition(kind).value("parentTypes").toArray();
    if((parents.isEmpty() && !parent.isEmpty()) || (!parents.isEmpty() && !parents.contains(object(parent).value("type")))) return;
    kind_=kind; parent_=parent; refreshManager(); documents_->setTabVisible(documents_->indexOf(manager_),true);documents_->setCurrentWidget(manager_); emit collectionActivated(kind,parent);
}
bool ObjectWorkspace::openObject(const QString &key,const QString &page) {
    if(!entries_.contains(key)) return false;
    auto &entry=entries_[key]; const auto kind=entry.data.value("kind").toString();
    const auto pages=typeDefinition(kind,entry.data.value("type").toString()).value("pages").toArray();
    if(pages.isEmpty()) return false;
    const bool newlyOpened=!entry.view;
    if(!entry.view) {
        auto *view=new RecoveredWorkspace(documents_); entry.view=view;
        view->setProperty("objectKey",key); view->setSessionEditable(true); view->setGlobalUnits(units_);
        view->setSessionState(entry.values);
        connect(view,&RecoveredWorkspace::actionRequested,this,[this,key](const QString &action){
            if(action.startsWith("collection:")) showCollection(action.mid(11),key); else emit actionRequested(action);
        });
        connect(view,&RecoveredWorkspace::inputsChanged,this,&ObjectWorkspace::inputsChanged);
        connect(view,&RecoveredWorkspace::pageChanged,this,[this,key](const QString &id){emit objectActivated(key,id);});
        connect(view,&RecoveredWorkspace::closeRequested,this,[this,key]{closeObject(key);});
        connect(view,&RecoveredWorkspace::globalUnitsChanged,this,[this](const QString &units){emit actionRequested("units:"+units);});
        documents_->addTab(view,entry.data.value("name").toString());
    }
    auto target=page;
    if(target.isEmpty()) target=entry.view->currentPage();
    if(target.isEmpty()) target=entry.lastPage;
    if(target.isEmpty()) target=pages.first().toObject().value("page").toString();
    if(!entry.view->idForName(target).isEmpty()) target=entry.view->idForName(target);
    bool allowed=false;
    for(const auto &p:pages) if(entry.view->idForName(p.toObject().value("page").toString())==target) allowed=true;
    if(!allowed) {if(newlyOpened) closeObject(key);return false;}
    if(entry.view->currentPage()!=target && !entry.view->showPage(target)) return false;
    if(ProcessInput::supported(entry.data)) {
        auto typed=entry.data.value("processInput").toObject();typed["version"]=1;
        for(const auto &field:ProcessInput::fields(entry.data)) if(!typed.contains(field))typed[field]=ProcessInput::quantity("",ProcessUnits::forSet(field,units_));
        auto display=entry.data;display["processInput"]=typed;
        auto *editor=new ProcessInputWidget(display,chemicalState_.value("components").toArray(),entry.view);
        connect(editor,&ProcessInputWidget::inputChanged,this,[this,key](const QJsonObject &input){
            if(!entries_.contains(key))return;entries_[key].data["processInput"]=input;emit inputsChanged();
        });
        entry.view->setBusinessContent(editor);
    }
    if(entry.data.contains("chemistryData"))entry.view->setBusinessContent(makeChemicalSystemView(entry.data,chemicalState_,entry.view));
    refreshTitles(); documents_->setCurrentWidget(entry.view); emit objectActivated(key,target); return true;
}
void ObjectWorkspace::closeObject(const QString &key) {
    if(!entries_.contains(key) || !entries_[key].view) return;
    auto &entry=entries_[key]; entry.values=entry.view->sessionState();entry.lastPage=entry.view->currentPage();
    auto *view=entry.view; entry.view=nullptr; documents_->removeTab(documents_->indexOf(view)); view->deleteLater();
}
void ObjectWorkspace::refreshTitles() {
    for(auto it=entries_.begin();it!=entries_.end();++it) if(it->view) {
        const auto d=it->data;
        const auto title=definition(d.value("kind").toString()).value("label").toString()+" — "+d.value("name").toString()+" ("+d.value("type").toString()+")";
        documents_->setTabText(documents_->indexOf(it->view),title);
        it->view->findChild<QLabel *>("RecoveredTitle")->setText(title);
        if(d.value("kind")=="user-components") {
            if(auto *id=it->view->findChild<QLineEdit *>("txtCompID")) {id->setText(d.value("name").toString());id->setReadOnly(true);}
            if(auto *type=it->view->findChild<QComboBox *>("cboType")) {
                type->setCurrentIndex(QStringList{"CONVENTIONAL","SOLID","NONCONVENTIONAL"}.indexOf(d.value("type").toString()));type->setEnabled(false);
            }
        }
    }
}
void ObjectWorkspace::setObjectState(const QString &key,const QMap<QString,QVariantMap> &values) {
    if(!entries_.contains(key)) return; entries_[key].values=values;
    if(entries_[key].view) entries_[key].view->setSessionState(values);
    emit inputsChanged();
}
void ObjectWorkspace::setGlobalUnits(const QString &units) {
    units_=units; for(auto &entry:entries_) if(entry.view) entry.view->setGlobalUnits(units);
}
void ObjectWorkspace::requestNew(const QString &kind,const QString &parent) {nameDialog(kind,parent,{});}
void ObjectWorkspace::requestRename(const QString &key) {
    if(entries_.contains(key)) nameDialog(object(key).value("kind").toString(),object(key).value("parent").toString(),key);
}
void ObjectWorkspace::copyObject(const QString &key) {
    if(!entries_.contains(key)) return;
    const auto &entry=entries_[key]; clipboard_=entry.data;
    if(clipboard_.value("kind")=="streams") {
        const auto from=object(clipboard_.value("from").toString()),to=object(clipboard_.value("to").toString());
        if(!from.isEmpty()){clipboard_["startX"]=from.value("x").toDouble()+40;clipboard_["startY"]=from.value("y");}
        if(!to.isEmpty()){clipboard_["endX"]=to.value("x").toDouble()-40;clipboard_["endY"]=to.value("y");}
    }
    clipboardValues_=entry.view?entry.view->sessionState():entry.values;
    clipboardChildren_={};clipboardChildValues_.clear();
    QStringList parents{key};
    for(int i=0;i<parents.size();++i) for(const auto &id:order_) {
        const auto &child=entries_[id];if(child.data.value("parent").toString()!=parents[i]) continue;
        clipboardChildren_.append(child.data);parents.append(id);
        clipboardChildValues_[id]=child.view?child.view->sessionState():child.values;
    }
    refreshButtons();
}
void ObjectWorkspace::requestPaste() {
    const bool onFlowsheet=documents_->currentWidget()==flowsheet_;
    if(clipboard_.isEmpty() || (onFlowsheet && (flowsheetLocked_ || !QStringList{"blocks","streams"}.contains(clipboard_.value("kind").toString()))) ||
       (!onFlowsheet && clipboard_.value("kind")!=kind_)) return;
    const auto source=clipboard_;const auto values=clipboardValues_;const auto children=clipboardChildren_;const auto childValues=clipboardChildValues_;
    const auto kind=onFlowsheet?source.value("kind").toString():kind_,parent=onFlowsheet?QString():parent_;
    auto *dialog=new QDialog(this);dialog->setAttribute(Qt::WA_DeleteOnClose);dialog->setObjectName("ObjectPasteDialog");
    dialog->setWindowTitle(QString::fromUtf8("解决 ID 冲突"));dialog->resize(500,280);
    auto *layout=new QHBoxLayout(dialog);auto *list=new QTableWidget(1,2,dialog);list->setObjectName("PasteConflictTable");
    list->setHorizontalHeaderLabels({QString::fromUtf8("对象"),QString::fromUtf8("状态")});list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    list->setSelectionBehavior(QAbstractItemView::SelectRows);list->horizontalHeader()->setStretchLastSection(true);list->verticalHeader()->hide();
    list->setItem(0,0,new QTableWidgetItem(source.value("name").toString()));list->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("需要新 ID")));list->selectRow(0);layout->addWidget(list,1);
    auto *actions=new QVBoxLayout;layout->addLayout(actions);
    auto *edit=new QPushButton(QString::fromUtf8("编辑 ID"),dialog);edit->setObjectName("PasteEditId");actions->addWidget(edit);actions->addStretch();
    auto *confirm=new QPushButton(QString::fromUtf8("确定"),dialog);confirm->setObjectName("PasteConfirm");confirm->setEnabled(false);actions->addWidget(confirm);
    auto *cancel=new QPushButton(QString::fromUtf8("取消"),dialog);actions->addWidget(cancel);
    if(nameError(kind,source.value("name").toString(),parent).isEmpty()) {
        dialog->setProperty("resolvedName",source.value("name").toString());list->item(0,1)->setText(QString::fromUtf8("可粘贴"));confirm->setEnabled(true);
    }
    connect(edit,&QPushButton::clicked,dialog,[this,dialog,list,confirm,kind,parent,source]{
        auto *editor=new QDialog(dialog);editor->setAttribute(Qt::WA_DeleteOnClose);editor->setObjectName("PasteIdDialog");editor->setWindowTitle(QString::fromUtf8("对象名称"));
        auto *form=new QVBoxLayout(editor);form->addWidget(new QLabel(QString::fromUtf8("请输入 ID："),editor));
        auto *name=new QLineEdit(dialog->property("resolvedName").toString().isEmpty()?source.value("name").toString():dialog->property("resolvedName").toString(),editor);
        name->setObjectName("ObjectId");name->setMaxLength(8);form->addWidget(name);
        auto *error=new QLabel(editor);form->addWidget(error);auto *buttons=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,editor);form->addWidget(buttons);
        const auto update=[this,name,error,buttons,kind,parent]{const auto problem=nameError(kind,name->text().trimmed(),parent);error->setText(problem);buttons->button(QDialogButtonBox::Ok)->setEnabled(problem.isEmpty());};
        connect(name,&QLineEdit::textChanged,editor,update);
        connect(buttons,&QDialogButtonBox::accepted,editor,[dialog,editor,name,list,confirm]{dialog->setProperty("resolvedName",name->text().trimmed().toUpper());list->item(0,1)->setText(QString::fromUtf8("新 ID：")+name->text().trimmed().toUpper());confirm->setEnabled(true);editor->accept();});
        connect(buttons,&QDialogButtonBox::rejected,editor,&QDialog::reject);update();editor->open();name->selectAll();name->setFocus();
    });
    connect(confirm,&QPushButton::clicked,dialog,[this,dialog,kind,parent,source,values,children,childValues,onFlowsheet]{
        if(onFlowsheet && flowsheetLocked_)return;
        QSignalBlocker transaction(this);
        const auto created=createObject(kind,dialog->property("resolvedName").toString(),source.value("type").toString(),parent);if(created.isEmpty()) return;
        for(const auto &field:{"startX","startY","endX","endY","from","to","iconRotation","iconFlipHorizontal","iconFlipVertical"}) if(source.contains(field)) entries_[created].data[field]=source.value(field);
        // A copied stream gets its own free endpoints; it must not silently duplicate connections.
        if(kind=="streams") {
            entries_[created].data["from"]="";entries_[created].data["to"]="";
            for(const auto &field:{"startX","startY","endX","endY"})if(source.contains(field))entries_[created].data[field]=source.value(field).toDouble()+30;
        }
        if(kind=="blocks") {entries_[created].data["x"]=source.value("x").toDouble()+30;entries_[created].data["y"]=source.value("y").toDouble()+30;}
        refreshCanvas();
        setObjectState(created,values);QMap<QString,QString> mapping{{source.value("key").toString(),created}};
        for(const auto &v:children) {
            const auto d=v.toObject();const auto child=createObject(d.value("kind").toString(),d.value("name").toString(),d.value("type").toString(),mapping.value(d.value("parent").toString()));
            if(!child.isEmpty()) {mapping[d.value("key").toString()]=child;setObjectState(child,childValues.value(d.value("key").toString()));}
        }
        transaction.unblock(); emit objectsChanged();
        dialog->accept();
        if(onFlowsheet){showFlowsheet();selectFlowsheetObject(created);canvas_->setFocus();}else openObject(created);
    });
    connect(cancel,&QPushButton::clicked,dialog,&QDialog::reject);dialog->open();
}
void ObjectWorkspace::nameDialog(const QString &kind,const QString &parent,const QString &key) {
    const auto spec=definition(kind); if(spec.isEmpty()) return;
    auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("ObjectNameDialog");
    dialog->setWindowTitle(key.isEmpty()?QString::fromUtf8("创建新ID"):QString::fromUtf8("重命名"));
    auto *layout=new QVBoxLayout(dialog); auto *form=new QFormLayout;
    auto *name=new QLineEdit(key.isEmpty()?suggestedName(kind,parent):object(key).value("name").toString(),dialog);
    name->setObjectName("ObjectId"); name->setMaxLength(8); form->addRow(QString::fromUtf8("输入ID："),name);
    auto *type=new QComboBox(dialog); type->setObjectName("ObjectType");
    for(const auto &v:spec.value("types").toArray()) {const auto t=v.toObject();type->addItem(t.value("label").toString(t.value("id").toString()),t.value("id").toString());}
    if(type->count()>1 && key.isEmpty()) type->setCurrentIndex(-1);
    if(!key.isEmpty()) {type->setCurrentIndex(type->findData(object(key).value("type").toString()));type->setEnabled(false);}
    if(type->count()>1) form->addRow(QString::fromUtf8("选择类型："),type); else type->hide();
    layout->addLayout(form); auto *error=new QLabel(dialog); error->setObjectName("ObjectNameError"); error->setWordWrap(true); layout->addWidget(error);
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,dialog); layout->addWidget(buttons);
    buttons->button(QDialogButtonBox::Ok)->setText(QString::fromUtf8("确定")); buttons->button(QDialogButtonBox::Cancel)->setText(QString::fromUtf8("取消"));
    const auto update=[this,name,type,error,buttons,kind,parent,key]{
        auto problem=nameError(kind,name->text().trimmed(),parent,key);
        if(problem.isEmpty() && type->currentIndex()<0) problem=QString::fromUtf8("请选择类型。");
        error->setText(problem); buttons->button(QDialogButtonBox::Ok)->setEnabled(problem.isEmpty());
    };
    connect(name,&QLineEdit::textChanged,dialog,update); connect(type,&QComboBox::currentIndexChanged,dialog,update);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[this,dialog,name,type,kind,parent,key]{
        if(!key.isEmpty()) {if(renameObject(key,name->text())) dialog->accept();return;}
        const auto created=createObject(kind,name->text(),type->currentData().toString(),parent);
        if(created.isEmpty()) return;
        dialog->accept();openObject(created);
    });
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject);
    update(); dialog->resize(340,160); dialog->open(); name->selectAll(); name->setFocus();
}
void ObjectWorkspace::requestDelete(const QString &key) {
    requestDeleteObjects({key});
}
void ObjectWorkspace::requestDeleteObjects(const QStringList &keys) {
    QStringList existing,names;for(const auto &key:keys)if(entries_.contains(key)){existing.append(key);names.append(object(key).value("name").toString());}
    if(existing.isEmpty())return;
    const bool onFlowsheet=documents_->currentWidget()==flowsheet_;
    if(onFlowsheet && flowsheetLocked_)return;
    auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("ObjectDeleteDialog"); dialog->setWindowTitle(QString::fromUtf8("删除对象"));
    auto *layout=new QVBoxLayout(dialog); layout->addWidget(new QLabel(QString::fromUtf8("删除 %1 及其子对象？").arg(names.join(", ")),dialog));
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Yes|QDialogButtonBox::Cancel,dialog); layout->addWidget(buttons);
    for(const auto &key:existing)if(ChemicalSystem::componentReferenced(chemicalState_,"object:"+key)) {
        layout->insertWidget(1,new QLabel(QString::fromUtf8("该组分被化学系统引用，不能删除。请先撤销相关向导生成。"),dialog));
        buttons->button(QDialogButtonBox::Yes)->setEnabled(false);break;
    }
    buttons->button(QDialogButtonBox::Yes)->setText(QString::fromUtf8("删除")); buttons->button(QDialogButtonBox::Cancel)->setText(QString::fromUtf8("取消"));
    buttons->button(QDialogButtonBox::Cancel)->setDefault(true);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[this,existing,dialog,onFlowsheet]{
        if(onFlowsheet && flowsheetLocked_)return;
        QStringList removed;
        for(const auto &v:objects()) {
            auto key=v.toObject().value("key").toString(),ancestor=key;
            while(!ancestor.isEmpty()){if(existing.contains(ancestor)){removed.append(key);break;}ancestor=object(ancestor).value("parent").toString();}
        }
        QSignalBlocker transaction(this);for(const auto &key:existing)removeObject(key);transaction.unblock();
        emit objectsRemoved(removed);emit objectsChanged();dialog->accept();
    });
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject); dialog->open();
}
void ObjectWorkspace::showFlowsheet() {
    documents_->setTabVisible(documents_->indexOf(manager_),false);
    documents_->setCurrentWidget(flowsheet_);metrics_->show();modelPalette_->show();refreshCanvas();
    emit flowsheetActivated(true);
}
void ObjectWorkspace::setFlowsheetZoom(int percent) {
    percent=qBound(25,percent,200);canvas_->resetTransform();canvas_->scale(percent/100.0,percent/100.0);emit flowsheetZoomChanged(percent);
}
void ObjectWorkspace::setThreeDimensionalIcons(bool enabled) {threeDimensionalIcons_=enabled;refreshCanvas();}
void ObjectWorkspace::setFlowsheetLocked(bool locked) {flowsheetLocked_=locked;canvas_->locked=locked;modelPalette_->setEnabled(!locked);beginPlacement({},{});refreshCanvas();}

QString ObjectWorkspace::selectedFlowsheetObject() const {
    const auto keys=canvas_->selectedKeys();return keys.size()==1?keys.first():QString();
}
void ObjectWorkspace::selectFlowsheetObject(const QString &key) {
    canvas_->scene()->clearSelection();
    for(auto *item:canvas_->scene()->items())if(item->data(0).toString()==key){item->setSelected(true);break;}
}
void ObjectWorkspace::transformSelectedBlock(const QString &operation) {
    const auto key=selectedFlowsheetObject();
    if(flowsheetLocked_ || object(key).value("kind")!="blocks")return;
    auto &d=entries_[key].data;
    if(operation=="rotate")d["iconRotation"]=(d.value("iconRotation").toInt()+90)%360;
    else if(operation=="flip-horizontal")d["iconFlipHorizontal"]=!d.value("iconFlipHorizontal").toBool();
    else if(operation=="flip-vertical")d["iconFlipVertical"]=!d.value("iconFlipVertical").toBool();
    else return;
    refreshCanvas();emit objectsChanged();
}
void ObjectWorkspace::fitFlowsheet() {
    const auto bounds=canvas_->scene()->itemsBoundingRect().adjusted(-35,-35,35,35);
    if(canvas_->scene()->items().isEmpty())return;
    setFlowsheetZoom(qRound(100*qMin(canvas_->viewport()->width()/bounds.width(),canvas_->viewport()->height()/bounds.height())));
    canvas_->centerOn(bounds.center());
}
void ObjectWorkspace::showFlowsheetMenu(const QPoint &position) {
    const auto key=canvas_->keyAt(position);
    if(!key.isEmpty() && !canvas_->selectedKeys().contains(key))selectFlowsheetObject(key);
    else if(key.isEmpty())canvas_->scene()->clearSelection();
    canvas_->setFocus();
    auto *menu=new QMenu(this);menu->setObjectName("FlowsheetContextMenu");menu->setAttribute(Qt::WA_DeleteOnClose);
    connect(menu,&QMenu::aboutToHide,menu,&QObject::deleteLater);
    const auto keys=canvas_->selectedKeys();const bool single=keys.size()==1,editable=!flowsheetLocked_;
    auto add=[this,menu](const QString &id,const QString &label,bool enabled,const std::function<void()> &callback={}) {
        auto *action=menu->addAction(label);action->setObjectName(id);action->setEnabled(enabled);
        if(callback)connect(action,&QAction::triggered,this,callback);
        return action;
    };
    auto unavailable=[&](const QString &label){auto *a=add({},label,false);a->setToolTip(QString::fromUtf8("此操作尚未接入。"));};
    auto disabledSubmenu=[&](const QString &label){auto *sub=menu->addMenu(label);sub->setEnabled(false);sub->setToolTip(QString::fromUtf8("此操作尚未接入。"));};
    if(key.isEmpty()) {
        const int zoom=qRound(canvas_->transform().m11()*100);
        add("FlowZoomIn",QString::fromUtf8("放大"),zoom<200,[this,zoom]{setFlowsheetZoom(zoom+10);});
        add("FlowZoomOut",QString::fromUtf8("缩小"),zoom>25,[this,zoom]{setFlowsheetZoom(zoom-10);});
        add("FlowZoomFit",QString::fromUtf8("缩放到适当大小"),!canvas_->scene()->items().isEmpty(),[this]{fitFlowsheet();});
        menu->addSeparator();
        auto *labels=add("FlowHideLabels",QString::fromUtf8("隐藏标签"),true,[this]{labelsHidden_=!labelsHidden_;refreshCanvas();});labels->setCheckable(true);labels->setChecked(labelsHidden_);
        add("FlowCenter",QString::fromUtf8("中心视图"),true,[this]{canvas_->centerOn(canvas_->scene()->items().isEmpty()?canvas_->sceneRect().center():canvas_->scene()->itemsBoundingRect().center());});
        unavailable(QString::fromUtf8("平移"));unavailable(QString::fromUtf8("流程视图"));menu->addSeparator();
        add("FlowRedraw",QString::fromUtf8("重画"),true,[this]{refreshCanvas();});
        add("FlowSelectAll",QString::fromUtf8("全选"),!canvas_->scene()->items().isEmpty(),[this]{for(auto *item:canvas_->scene()->items())if(item->flags().testFlag(QGraphicsItem::ItemIsSelectable))item->setSelected(true);});
        menu->addSeparator();unavailable(QString::fromUtf8("分页预览"));unavailable(QString::fromUtf8("重置分页符"));menu->addSeparator();
        unavailable(QString::fromUtf8("查找对象…"));
        const bool canPaste=editable && QStringList{"blocks","streams"}.contains(clipboard_.value("kind").toString());
        add("FlowPaste",QString::fromUtf8("粘贴"),canPaste,[this]{requestPaste();});unavailable(QString::fromUtf8("打印预览"));
    } else {
        const bool block=object(key).value("kind")=="blocks";
        add("FlowInput",QString::fromUtf8("输入…"),single,[this,key]{openObject(key);});
        unavailable(QString::fromUtf8("结果…"));if(block)unavailable(QString::fromUtf8("流股结果…"));unavailable(QString::fromUtf8("调和…"));
        if(block){menu->addSeparator();unavailable(QString::fromUtf8("更改工段…"));unavailable(QString::fromUtf8("移动选择…"));menu->addSeparator();}
        else {disabledSubmenu(QString::fromUtf8("分析…"));unavailable(QString::fromUtf8("更改流股类型…"));}
        unavailable(QString::fromUtf8("禁用"));
        if(block){menu->addSeparator();unavailable(QString::fromUtf8("转换成…"));unavailable(QString::fromUtf8("成本"));}
        else {unavailable(QString::fromUtf8("打断流股"));unavailable(QString::fromUtf8("插入模块"));}
        menu->addSeparator();
        add("FlowCut",QString::fromUtf8("剪切"),editable && single,[this,key]{if(!flowsheetLocked_){copyObject(key);removeObject(key);}})->setShortcut(QKeySequence::Cut);
        add("FlowCopy",QString::fromUtf8("复制"),single,[this,key]{copyObject(key);})->setShortcut(QKeySequence::Copy);
        add("FlowRename",block?QString::fromUtf8("重命名模块"):QString::fromUtf8("重命名流股"),editable && single,[this,key]{if(!flowsheetLocked_)requestRename(key);});
        if(block) {
            menu->addSeparator();auto *rotate=menu->addMenu(QString::fromUtf8("旋转图标"));rotate->setEnabled(editable && single);
            const QList<QPair<QString,QString>> transforms{{"rotate",QString::fromUtf8("旋转 90°")},{"flip-horizontal",QString::fromUtf8("水平翻转")},{"flip-vertical",QString::fromUtf8("垂直翻转")}};
            for(const auto &t:transforms){auto *a=rotate->addAction(t.second);a->setObjectName("FlowTransform-"+t.first);connect(a,&QAction::triggered,this,[this,t]{transformSelectedBlock(t.first);});}
            unavailable(QString::fromUtf8("交换图标"));
        } else {
            auto *reconnect=menu->addMenu(QString::fromUtf8("重新连接"));reconnect->setEnabled(editable && single);
            for(const auto &end:QStringList{"from","to"}){auto *a=reconnect->addAction(end=="from"?QString::fromUtf8("重新连接源"):QString::fromUtf8("重新连接目标"));a->setObjectName("FlowReconnect-"+end);connect(a,&QAction::triggered,this,[=]{beginReconnection(key,end);});}
            unavailable(QString::fromUtf8("对齐模块"));
            unavailable(QString::fromUtf8("重排流股"));
        }
        disabledSubmenu(QString::fromUtf8("隐藏"));
        if(!block)add("FlowStreamAppearance",QString::fromUtf8("流股颜色和样式"),editable && single,[this,key]{showStreamAppearance(key);});
        // Delete is also available from the keyboard and keeps the existing confirmation/undo path.
        menu->addSeparator();add("FlowDelete",QString::fromUtf8("删除"),editable,[this,keys]{if(!flowsheetLocked_)requestDeleteObjects(keys);})->setShortcut(QKeySequence::Delete);
    }
    menu->popup(canvas_->viewport()->mapToGlobal(position));
}

void ObjectWorkspace::beginPlacement(const QString &kind,const QString &type) {
    if(flowsheetLocked_ && !kind.isEmpty()) return;
    for(auto *button:findChildren<QToolButton *>()) if(button->property("modelTile").toBool()) button->setChecked(kind=="blocks" && button->property("paletteType").toString()==type);
    reconnectKey_.clear();reconnectEnd_.clear();placementKind_=kind;placementType_=type;streamPending_=false;canvas_->placing=!kind.isEmpty();
    if(auto *select=findChild<QPushButton *>("FlowSelect")){select->setCheckable(true);select->setChecked(kind.isEmpty());}
    if(auto *stream=findChild<QToolButton *>("StreamPaletteButton")){stream->setCheckable(true);stream->setChecked(kind=="streams");}
    if(documents_->currentWidget()==flowsheet_)canvas_->setFocus(Qt::OtherFocusReason);
    canvas_->setCursor(kind.isEmpty()?Qt::ArrowCursor:Qt::CrossCursor);
    placementNotice_->setVisible(!kind.isEmpty());
    if(kind.isEmpty()) canvas_->setToolTip({});
    placementNotice_->setText(kind=="streams"?QString::fromUtf8("依次单击起点和终点；单击模块可连接，Esc 取消。"):
        kind=="blocks"?QString::fromUtf8("单击画布放置 %1；Esc 退出放置。").arg(type):QString::fromUtf8("拖动模块调整位置；双击对象编辑输入。"));
}
void ObjectWorkspace::placeAt(const QPointF &point,const QString &attachment) {
    if(!reconnectKey_.isEmpty() && !flowsheetLocked_) {
        const auto key=reconnectKey_,end=reconnectEnd_;
        if(!entries_.contains(key)){beginPlacement({},{});return;}
        // Reconnection targets a block or a free endpoint; clicking another
        // stream must not silently disconnect the current one.
        if(!attachment.isEmpty() && object(attachment).value("kind")!="blocks")return;
        auto &data=entries_[key].data;data[end]=attachment;
        data[end=="from"?"startX":"endX"]=qMax(40.0,point.x());data[end=="from"?"startY":"endY"]=qMax(30.0,point.y());
        beginPlacement({},{});refreshCanvas();emit objectsChanged();return;
    }
    if(flowsheetLocked_ || placementKind_.isEmpty()) return;
    const QPointF position(qMax(40.0,point.x()),qMax(30.0,point.y()));
    if(placementKind_=="streams" && !streamPending_) {
        streamStart_=position;streamStartKey_=object(attachment).value("kind")=="blocks"?attachment:QString();streamPending_=true;
        placementNotice_->setText(QString::fromUtf8("选择流股终点；Esc 取消。")); return;
    }
    QSignalBlocker transaction(this);
    const auto key=createObject(placementKind_,suggestedName(placementKind_),placementType_);
    if(key.isEmpty()) return;
    auto &d=entries_[key].data; d["x"]=position.x();d["y"]=position.y();
    if(placementKind_=="streams") {
        d["startX"]=streamStart_.x();d["startY"]=streamStart_.y();d["endX"]=position.x();d["endY"]=position.y();
        d["from"]=streamStartKey_;d["to"]=object(attachment).value("kind")=="blocks"?attachment:QString();streamPending_=false;
        placementNotice_->setText(QString::fromUtf8("依次单击起点和终点；单击模块可连接，Esc 取消。"));
    }
    refreshCanvas();transaction.unblock();emit objectsChanged();
}
void ObjectWorkspace::beginReconnection(const QString &key,const QString &end) {
    if(flowsheetLocked_ || object(key).value("kind")!="streams" || !QStringList{"from","to"}.contains(end))return;
    beginPlacement({},{});reconnectKey_=key;reconnectEnd_=end;canvas_->placing=true;canvas_->setCursor(Qt::CrossCursor);
    placementNotice_->setText(end=="from"?QString::fromUtf8("单击新的源模块或空白位置；Esc 取消。"):QString::fromUtf8("单击新的目标模块或空白位置；Esc 取消。"));placementNotice_->show();canvas_->setFocus();
}
void ObjectWorkspace::setStreamAppearance(const QString &key,const QString &property,const QJsonValue &value) {
    if(flowsheetLocked_ || object(key).value("kind")!="streams")return;
    if(property=="lineColor"){if(!QColor(value.toString()).isValid())return;}
    else if(property=="lineWidth" || property=="lineStyle"){if(value.toInt()<1 || value.toInt()>5)return;}
    else return;
    entries_[key].data[property]=value;refreshCanvas();emit objectsChanged();
}
void ObjectWorkspace::showStreamAppearance(const QString &key) {
    if(flowsheetLocked_ || object(key).value("kind")!="streams")return;
    const auto initial=object(key);
    auto *dialog=new QDialog(this);dialog->setAttribute(Qt::WA_DeleteOnClose);dialog->setObjectName("StreamAppearanceDialog");dialog->setWindowTitle(QString::fromUtf8("颜色和样式"));
    auto *column=new QVBoxLayout(dialog);column->addWidget(new QLabel(QString::fromUtf8("轮廓颜色"),dialog));
    auto *colors=new QGridLayout;column->addLayout(colors);
    const QStringList palette{"#000000","#808080","#ff0000","#808000","#008000","#008080","#000080","#800080","#e0e0e0","#c0c0c0","#800000","#ffff00","#00ff00","#00ffff","#0080ff","#ff00ff"};
    auto *colorGroup=new QButtonGroup(dialog);auto *widthGroup=new QButtonGroup(dialog);auto *styleGroup=new QButtonGroup(dialog);
    dialog->setProperty("lineColor",initial.value("lineColor").toString("#32618a"));
    for(int i=0;i<palette.size();++i){auto *b=new QToolButton(dialog);b->setObjectName("StreamColor-"+QString::number(i));b->setCheckable(true);b->setFixedSize(22,22);b->setStyleSheet("background:"+palette[i]+"; border:1px solid #888;");b->setAccessibleName(palette[i]);colorGroup->addButton(b,i);colors->addWidget(b,i/8,i%8);if(palette[i]==dialog->property("lineColor").toString())b->setChecked(true);}
    auto *samples=new QGridLayout;column->addLayout(samples);samples->addWidget(new QLabel(QString::fromUtf8("线宽")),0,0);samples->addWidget(new QLabel(QString::fromUtf8("样式")),0,1);
    for(int i=1;i<=5;++i)for(int c=0;c<2;++c){QPixmap pix(90,18);pix.fill(Qt::white);QPainter painter(&pix);painter.setPen(QPen(Qt::black,c?2:i,c?Qt::PenStyle(i):Qt::SolidLine));painter.drawLine(4,9,86,9);painter.end();auto *b=new QToolButton(dialog);b->setIcon(QIcon(pix));b->setIconSize(pix.size());b->setCheckable(true);b->setObjectName((c?"StreamStyle-":"StreamWidth-")+QString::number(i));b->setAccessibleName((c?QString::fromUtf8("样式 "):QString::fromUtf8("线宽 "))+QString::number(i));(c?styleGroup:widthGroup)->addButton(b,i);b->setChecked(initial.value(c?"lineStyle":"lineWidth").toInt(c?1:2)==i);samples->addWidget(b,i,c);}
    column->addWidget(new QLabel(QString::fromUtf8("预览")));auto *preview=new QLabel(dialog);preview->setObjectName("StreamAppearancePreview");column->addWidget(preview);
    auto *defaults=new QCheckBox(QString::fromUtf8("使用默认颜色和样式"),dialog);defaults->setObjectName("UseDefaultCheckBox");defaults->setChecked(!initial.contains("lineColor") && !initial.contains("lineWidth") && !initial.contains("lineStyle"));column->addWidget(defaults);
    const auto update=[=]{QPixmap pix(220,32);pix.fill(Qt::white);QPainter painter(&pix);painter.setPen(QPen(QColor(defaults->isChecked()?"#32618a":dialog->property("lineColor").toString()),defaults->isChecked()?2:widthGroup->checkedId(),defaults->isChecked()?Qt::SolidLine:Qt::PenStyle(styleGroup->checkedId())));painter.drawLine(5,16,215,16);painter.end();preview->setPixmap(pix);};
    connect(colorGroup,&QButtonGroup::idClicked,dialog,[=](int id){dialog->setProperty("lineColor",palette[id]);defaults->setChecked(false);update();});
    for(auto *group:{widthGroup,styleGroup})connect(group,&QButtonGroup::idClicked,dialog,[=]{defaults->setChecked(false);update();});
    connect(defaults,&QCheckBox::toggled,dialog,update);update();
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,dialog);column->addWidget(buttons);connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[=]{if(flowsheetLocked_ || !entries_.contains(key)){dialog->reject();return;}auto &data=entries_[key].data;if(defaults->isChecked()){data.remove("lineColor");data.remove("lineWidth");data.remove("lineStyle");}else{data["lineColor"]=dialog->property("lineColor").toString();data["lineWidth"]=widthGroup->checkedId();data["lineStyle"]=styleGroup->checkedId();}refreshCanvas();emit objectsChanged();dialog->accept();});dialog->open();
}
void ObjectWorkspace::moveBlock(const QString &key,const QPointF &position) {
    moveBlocks({{key,position}});
}
void ObjectWorkspace::moveBlocks(const QMap<QString,QPointF> &positions) {
    if(flowsheetLocked_)return;
    bool changed=false,clamped=false;
    for(auto it=positions.cbegin();it!=positions.cend();++it) {
        if(!entries_.contains(it.key()) || object(it.key()).value("kind")!="blocks")continue;
        auto &d=entries_[it.key()].data;const QPointF p(qMax(40.0,it.value().x()),qMax(30.0,it.value().y()));
        clamped=clamped || p!=it.value();
        if(QPointF(d.value("x").toDouble(),d.value("y").toDouble())==p)continue;
        d["x"]=p.x();d["y"]=p.y();changed=true;
    }
    if(changed || clamped)refreshCanvas();
    if(changed)emit objectsChanged();
}
void ObjectWorkspace::refreshCanvas() {
    const auto selection=canvas_->selectedKeys();
    const QSignalBlocker blocker(canvas_->scene());
    canvas_->scene()->clear();
    for(const auto &key:order_) {
        const auto d=entries_[key].data;
        if(d.value("kind")=="blocks") {
            auto *box=new BlockGraphicsItem;canvas_->scene()->addItem(box);
            box->setPos(d.value("x").toDouble(),d.value("y").toDouble());box->setData(0,key);box->setData(1,"block");
            box->setFlag(QGraphicsItem::ItemIsSelectable);box->setFlag(QGraphicsItem::ItemIsMovable,!flowsheetLocked_);
            auto *symbol=new QGraphicsPixmapItem(flowsheetModelIcon(d.value("type").toString(),threeDimensionalIcons_).pixmap(64,56),box);symbol->setPos(-32,-28);
            symbol->setTransformOriginPoint(32,28);symbol->setRotation(d.value("iconRotation").toInt()%360);
            QTransform reflection;reflection.translate(32,28);reflection.scale(d.value("iconFlipHorizontal").toBool()?-1:1,d.value("iconFlipVertical").toBool()?-1:1);reflection.translate(-32,-28);symbol->setTransform(reflection);
            symbol->setAcceptedMouseButtons(Qt::NoButton);
            auto *label=new QGraphicsSimpleTextItem(d.value("name").toString(),box);label->setPos(-label->boundingRect().width()/2,34);label->setAcceptedMouseButtons(Qt::NoButton);label->setVisible(!labelsHidden_);
            box->setSelected(selection.contains(key));box->setToolTip(d.value("name").toString()+" ("+d.value("type").toString()+")");
        } else if(d.value("kind")=="streams" && d.contains("startX")) {
            QPointF from(d.value("startX").toDouble(),d.value("startY").toDouble()),to(d.value("endX").toDouble(),d.value("endY").toDouble());
            const auto start=object(d.value("from").toString()),end=object(d.value("to").toString());
            if(!start.isEmpty()) from={start.value("x").toDouble()+40,start.value("y").toDouble()};
            if(!end.isEmpty()) to={end.value("x").toDouble()-40,end.value("y").toDouble()};
            QPainterPath path(from);const qreal middle=(from.x()+to.x())/2;path.lineTo(middle,from.y());path.lineTo(middle,to.y());path.lineTo(to);
            const QPen pen(QColor(d.value("lineColor").toString("#32618a")),qBound(1,d.value("lineWidth").toInt(2),5),Qt::PenStyle(qBound(1,d.value("lineStyle").toInt(1),5)));
            auto *line=new StreamGraphicsItem(path);canvas_->scene()->addItem(line);line->setPen(pen);line->setData(0,key);line->setFlag(QGraphicsItem::ItemIsSelectable);line->setZValue(-1);
            auto *label=new QGraphicsSimpleTextItem(d.value("name").toString(),line);label->setPos(middle+3,(from.y()+to.y())/2-18);label->setAcceptedMouseButtons(Qt::NoButton);label->setVisible(!labelsHidden_);
            const qreal direction=to.x()>=middle?1:-1;
            QPainterPath arrow;arrow.moveTo(to+QPointF(-7*direction,-4));arrow.lineTo(to);arrow.lineTo(to+QPointF(-7*direction,4));
            auto *head=new QGraphicsPathItem(arrow,line);head->setPen(QPen(pen.color(),pen.widthF()));
            head->setAcceptedMouseButtons(Qt::NoButton);line->setSelected(selection.contains(key));line->setToolTip(d.value("name").toString()+" ("+d.value("type").toString()+")");
        }
    }
    emit flowsheetSelectionChanged();
}

QJsonArray ObjectWorkspace::projectObjects() {
    QJsonArray result;
    for(const auto &key:order_) {
        auto &entry=entries_[key];
        if(entry.view) entry.values=entry.view->sessionState();
        QJsonObject inputs;
        for(auto it=entry.values.cbegin();it!=entry.values.cend();++it) inputs[it.key()]=QJsonObject::fromVariantMap(it.value());
        auto data=entry.data; data["inputs"]=inputs; result.append(data);
    }
    return result;
}
void ObjectWorkspace::restoreProjectObjects(const QJsonArray &objects) {
    const auto selected=currentObject();
    const auto page=entries_.contains(selected) && entries_[selected].view?entries_[selected].view->currentPage():QString();
    QSignalBlocker blocked(this);
    for(const auto &key:order_) closeObject(key);
    entries_.clear(); order_.clear(); clipboard_={}; clipboardValues_.clear(); clipboardChildren_={}; clipboardChildValues_.clear();
    beginPlacement({},{});
    for(const auto &v:objects) {
        Entry entry; entry.data=v.toObject(); const auto key=entry.data.value("key").toString();
        const auto inputs=entry.data.take("inputs").toObject();
        for(auto it=inputs.begin();it!=inputs.end();++it) entry.values[it.key()]=it.value().toObject().toVariantMap();
        entries_[key]=entry; order_.append(key);
    }
    if(!parent_.isEmpty() && !entries_.contains(parent_)) {parent_.clear();kind_="blocks";}
    refreshManager(); refreshCanvas();
    if(entries_.contains(selected)) openObject(selected,page);
    blocked.unblock();emit flowsheetSelectionChanged();
}

void ObjectWorkspace::setChemicalSystemState(const QJsonObject &state) {
    chemicalState_=state;
    for(auto &entry:entries_) if(entry.view)
        if(auto *editor=entry.view->findChild<ProcessInputWidget *>()) editor->setComponents(state.value("components").toArray());
}

bool ObjectWorkspace::convertProcessUnits(const QString &units,QString *error) {
    QMap<QString,QJsonObject> converted;
    for(const auto &key:order_) {
        const auto &data=entries_[key].data;if(!ProcessInput::supported(data))continue;
        auto input=data.value("processInput").toObject();input["version"]=1;
        for(const auto &field:ProcessInput::fields(data)) {
            const auto q=input.value(field).toObject(ProcessInput::quantity("",ProcessInput::defaultUnit(field)));QJsonObject result;
            if(!ProcessUnits::convert(field,q,ProcessUnits::forSet(field,units),&result)) {
                *error=QString::fromUtf8("%1：%2无效，请修正后切换单位。").arg(data.value("name").toString(),ProcessInput::label(field));return false;
            }
            input[field]=result;
        }
        converted[key]=input;
    }
    for(auto it=converted.begin();it!=converted.end();++it) {
        auto &entry=entries_[it.key()];entry.data["processInput"]=it.value();
        if(entry.view)if(auto *editor=entry.view->findChild<ProcessInputWidget *>())editor->setInput(it.value());
    }
    return true;
}
