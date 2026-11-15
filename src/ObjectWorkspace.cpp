#include "ObjectWorkspace.h"
#include "RecoveredWorkspace.h"
#include "IconCatalog.h"
#include <QAction>
#include <QBoxLayout>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>
#include <QFormLayout>
#include <QGraphicsPathItem>
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
#include <QPainterPath>
#include <QPushButton>
#include <QRegularExpression>
#include <QSignalBlocker>
#include <QTableWidget>
#include <QTabBar>
#include <QTabWidget>
#include <QToolButton>
#include <QUuid>
#include <functional>

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
    std::function<void(QString)> open, remove;
    std::function<void()> cancel;
    std::function<void(QString,QPointF)> moved;
    QString keyAt(const QPoint &position) const {
        auto *item=itemAt(position);
        while(item && item->data(0).toString().isEmpty()) item=item->parentItem();
        return item?item->data(0).toString():QString();
    }
protected:
    void mousePressEvent(QMouseEvent *event) override {
        if(placing && event->button()==Qt::LeftButton) {
            const auto key=keyAt(event->position().toPoint());
            place(mapToScene(event->position().toPoint()),key); event->accept(); return;
        }
        QGraphicsView::mousePressEvent(event);
    }
    void mouseDoubleClickEvent(QMouseEvent *event) override {
        const auto key=keyAt(event->position().toPoint());
        if(!placing && !key.isEmpty()) { open(key); event->accept(); return; }
        QGraphicsView::mouseDoubleClickEvent(event);
    }
    void mouseReleaseEvent(QMouseEvent *event) override {
        QGraphicsView::mouseReleaseEvent(event);
        QList<QPair<QString,QPointF>> positions;
        for(auto *item:scene()->selectedItems())
            if(item->data(1).toString()=="block") positions.append({item->data(0).toString(),item->pos()});
        for(const auto &p:positions) moved(p.first,p.second);
    }
    void keyPressEvent(QKeyEvent *event) override {
        if(event->key()==Qt::Key_Escape) { cancel(); return; }
        if(event->key()==Qt::Key_Delete && !scene()->selectedItems().isEmpty()) {
            remove(scene()->selectedItems().first()->data(0).toString()); return;
        }
        QGraphicsView::keyPressEvent(event);
    }
};

ObjectWorkspace::ObjectWorkspace(QWidget *parent) : QWidget(parent)
{
    setObjectName("ObjectWorkspace");
    QFile catalog(":/ui/object-types.json"); catalog.open(QIODevice::ReadOnly);
    definitions_=QJsonDocument::fromJson(catalog.readAll()).object().value("collections").toArray();
    auto *layout=new QVBoxLayout(this); layout->setContentsMargins(3,0,3,3);
    documents_=new QTabWidget(this); documents_->setObjectName("ObjectDocuments");
    documents_->setDocumentMode(true); documents_->setTabsClosable(true); documents_->setMovable(true);
    documents_->setUsesScrollButtons(true); layout->addWidget(documents_);
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
    connect(table_,&QTableWidget::cellDoubleClicked,this,[this](int,int){openObject(selectedKey());});
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
    placementNotice_=new QLabel(QString::fromUtf8("选择模型后单击画布放置；双击对象编辑输入。"),flowsheet_); flowLayout->addWidget(placementNotice_);
    auto *palette=new QHBoxLayout;
    auto *select=new QPushButton(QString::fromUtf8("选择"),flowsheet_); select->setObjectName("FlowSelect"); palette->addWidget(select);
    connect(select,&QPushButton::clicked,this,[this]{beginPlacement({},{});});
    for(const auto &kind:{QString("streams"),QString("blocks")}) {
        auto *types=new QComboBox(flowsheet_); types->setObjectName("Palette-"+kind);
        for(const auto &type:definition(kind).value("types").toArray()) {
            const auto t=type.toObject(); types->addItem(t.value("label").toString(t.value("id").toString()),t.value("id").toString());
        }
        auto *add=new QPushButton(kind=="blocks"?QString::fromUtf8("放置模块"):QString::fromUtf8("连接流股"),flowsheet_);
        add->setObjectName("Place-"+kind); palette->addWidget(types); palette->addWidget(add);
        connect(add,&QPushButton::clicked,this,[this,kind,types]{beginPlacement(kind,types->currentData().toString());});
    }
    palette->addStretch(); flowLayout->addLayout(palette);
    documents_->addTab(flowsheet_,QString::fromUtf8("主工艺流程"));
    documents_->tabBar()->setTabButton(1,QTabBar::RightSide,nullptr);
    canvas_->place=[this](QPointF p,const QString &key){placeAt(p,key);};
    canvas_->open=[this](const QString &key){openObject(key);};
    canvas_->remove=[this](const QString &key){requestDelete(key);};
    canvas_->moved=[this](const QString &key,QPointF p){moveBlock(key,p);};
    canvas_->cancel=[this]{beginPlacement({},{});};
    connect(documents_,&QTabWidget::tabCloseRequested,this,[this](int index){
        auto *view=documents_->widget(index); if(view==manager_ || view==flowsheet_) return;
        closeObject(view->property("objectKey").toString());
    });
    connect(documents_,&QTabWidget::currentChanged,this,[this](int){
        const auto key=currentObject();
        if(entries_.contains(key) && entries_[key].view)
            emit objectActivated(key,entries_[key].view->currentPage());
    });
    showCollection("property-sets");
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
    kind_=kind; parent_=parent; refreshManager(); documents_->setCurrentWidget(manager_); emit collectionActivated(kind,parent);
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
    if(clipboard_.isEmpty() || clipboard_.value("kind")!=kind_) return;
    const auto source=clipboard_;const auto values=clipboardValues_;const auto children=clipboardChildren_;const auto childValues=clipboardChildValues_;
    const auto kind=kind_,parent=parent_;
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
    connect(confirm,&QPushButton::clicked,dialog,[this,dialog,kind,parent,source,values,children,childValues]{
        const auto created=createObject(kind,dialog->property("resolvedName").toString(),source.value("type").toString(),parent);if(created.isEmpty()) return;
        for(const auto &field:{"startX","startY","endX","endY","from","to"}) if(source.contains(field)) entries_[created].data[field]=source.value(field);
        if(kind=="blocks") {entries_[created].data["x"]=source.value("x").toDouble()+30;entries_[created].data["y"]=source.value("y").toDouble()+30;}
        refreshCanvas();
        setObjectState(created,values);QMap<QString,QString> mapping{{source.value("key").toString(),created}};
        for(const auto &v:children) {
            const auto d=v.toObject();const auto child=createObject(d.value("kind").toString(),d.value("name").toString(),d.value("type").toString(),mapping.value(d.value("parent").toString()));
            if(!child.isEmpty()) {mapping[d.value("key").toString()]=child;setObjectState(child,childValues.value(d.value("key").toString()));}
        }
        dialog->accept();openObject(created);
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
    if(!entries_.contains(key)) return;
    auto *dialog=new QDialog(this); dialog->setAttribute(Qt::WA_DeleteOnClose); dialog->setObjectName("ObjectDeleteDialog"); dialog->setWindowTitle(QString::fromUtf8("删除对象"));
    auto *layout=new QVBoxLayout(dialog); layout->addWidget(new QLabel(QString::fromUtf8("删除 %1 及其子对象？").arg(object(key).value("name").toString()),dialog));
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Yes|QDialogButtonBox::Cancel,dialog); layout->addWidget(buttons);
    buttons->button(QDialogButtonBox::Yes)->setText(QString::fromUtf8("删除")); buttons->button(QDialogButtonBox::Cancel)->setText(QString::fromUtf8("取消"));
    buttons->button(QDialogButtonBox::Cancel)->setDefault(true);
    connect(buttons,&QDialogButtonBox::accepted,dialog,[this,key,dialog]{removeObject(key);dialog->accept();});
    connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::reject); dialog->open();
}
void ObjectWorkspace::showFlowsheet() {documents_->setCurrentWidget(flowsheet_);refreshCanvas();}
void ObjectWorkspace::beginPlacement(const QString &kind,const QString &type) {
    placementKind_=kind;placementType_=type;streamPending_=false;canvas_->placing=!kind.isEmpty();
    canvas_->setCursor(kind.isEmpty()?Qt::ArrowCursor:Qt::CrossCursor);
    placementNotice_->setText(kind=="streams"?QString::fromUtf8("依次单击起点和终点；单击模块可连接，Esc 取消。"):
        kind=="blocks"?QString::fromUtf8("单击画布放置 %1；Esc 退出放置。").arg(type):QString::fromUtf8("拖动模块调整位置；双击对象编辑输入。"));
}
void ObjectWorkspace::placeAt(const QPointF &point,const QString &attachment) {
    if(placementKind_.isEmpty()) return;
    const QPointF position(qMax(40.0,point.x()),qMax(30.0,point.y()));
    if(placementKind_=="streams" && !streamPending_) {
        streamStart_=position;streamStartKey_=object(attachment).value("kind")=="blocks"?attachment:QString();streamPending_=true;
        placementNotice_->setText(QString::fromUtf8("选择流股终点；Esc 取消。")); return;
    }
    const auto key=createObject(placementKind_,suggestedName(placementKind_),placementType_);
    if(key.isEmpty()) return;
    auto &d=entries_[key].data; d["x"]=position.x();d["y"]=position.y();
    if(placementKind_=="streams") {
        d["startX"]=streamStart_.x();d["startY"]=streamStart_.y();d["endX"]=position.x();d["endY"]=position.y();
        d["from"]=streamStartKey_;d["to"]=object(attachment).value("kind")=="blocks"?attachment:QString();streamPending_=false;
    }
    refreshCanvas();emit objectsChanged();
}
void ObjectWorkspace::moveBlock(const QString &key,const QPointF &position) {
    if(!entries_.contains(key) || object(key).value("kind")!="blocks") return;
    entries_[key].data["x"]=qMax(40.0,position.x());entries_[key].data["y"]=qMax(30.0,position.y());refreshCanvas();
}
void ObjectWorkspace::refreshCanvas() {
    canvas_->scene()->clear();
    for(const auto &key:order_) {
        const auto d=entries_[key].data;
        if(d.value("kind")=="blocks") {
            auto *box=canvas_->scene()->addRect(-40,-24,80,48,QPen(QColor("#476580")),QBrush(QColor("#e5f0fa")));
            box->setPos(d.value("x").toDouble(),d.value("y").toDouble());box->setData(0,key);box->setData(1,"block");
            box->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
            auto *label=new QGraphicsSimpleTextItem(d.value("name").toString()+"\n"+d.value("type").toString(),box);label->setPos(-34,-19);
        } else if(d.value("kind")=="streams" && d.contains("startX")) {
            QPointF from(d.value("startX").toDouble(),d.value("startY").toDouble()),to(d.value("endX").toDouble(),d.value("endY").toDouble());
            const auto start=object(d.value("from").toString()),end=object(d.value("to").toString());
            if(!start.isEmpty()) from={start.value("x").toDouble()+40,start.value("y").toDouble()};
            if(!end.isEmpty()) to={end.value("x").toDouble()-40,end.value("y").toDouble()};
            QPainterPath path(from);const qreal middle=(from.x()+to.x())/2;path.lineTo(middle,from.y());path.lineTo(middle,to.y());path.lineTo(to);
            auto *line=canvas_->scene()->addPath(path,QPen(QColor("#32618a"),2));line->setData(0,key);line->setFlag(QGraphicsItem::ItemIsSelectable);line->setZValue(-1);
            auto *label=new QGraphicsSimpleTextItem(d.value("name").toString(),line);label->setPos(middle+3,(from.y()+to.y())/2-18);
            const qreal direction=to.x()>=middle?1:-1;
            QPainterPath arrow;arrow.moveTo(to+QPointF(-7*direction,-4));arrow.lineTo(to);arrow.lineTo(to+QPointF(-7*direction,4));
            auto *head=new QGraphicsPathItem(arrow,line);head->setPen(QPen(QColor("#32618a"),2));
        }
    }
}
