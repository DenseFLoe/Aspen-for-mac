#include "RecoveredWorkspace.h"
#include "IconCatalog.h"
#include "WidgetState.h"
#include <QAbstractButton>
#include <QButtonGroup>
#include <QScopedValueRollback>
#include <QScrollBar>
#include <QSignalBlocker>
#include <QBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QFile>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QJsonDocument>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QPushButton>
#include <QPalette>
#include <QRadioButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QTabWidget>
#include <QTableWidget>
#include <QTextEdit>
#include <QToolButton>
#include <QResizeEvent>
#include <QSet>
#include <functional>

namespace {
QJsonObject readObject(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return {};
    return QJsonDocument::fromJson(file.readAll()).object();
}
QJsonArray readArray(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return {};
    return QJsonDocument::fromJson(file.readAll()).array();
}
QString caption(const QJsonObject &p)
{
    for (const auto &key : {"Content", "Text", "Header", "Title", "Label", "Caption"})
        if (p.value(key).isString()) return p.value(key).toString();
    for (const auto &key : {"Content", "Text", "Header", "Title"})
        if (p.value(key).isObject()) return QString::fromUtf8("未解析文字");
    return {};
}
int number(const QJsonObject &p, const QString &key, int fallback)
{
    bool ok = false;
    const auto v = p.value(key);
    const auto n = v.isDouble() ? v.toDouble() : v.toString().toDouble(&ok);
    return v.isDouble() || ok ? qBound(0, qRound(n), 4000) : fallback;
}
bool isData(const QString &t)
{
    return (t.contains("Grid") && t != "Grid") || t.contains("Plot") || t.contains("Chart");
}

// WPF MMTabPage children are usually positioned using Margin/Alignment. Keep
// those coordinates in a scrollable canvas, without compressing to window size.
class ResourceCanvas : public QWidget
{
public:
    struct Item { QWidget *widget; QJsonObject p; };
    QList<Item> items;
    explicit ResourceCanvas(QWidget *parent = nullptr) : QWidget(parent) {}
    QSize sizeHint() const override
    {
        if (items.isEmpty() && layout()) return QWidget::sizeHint();
        QSize extent(20,22);
        for (const auto &item:items) {
            const auto m=item.p.value("Margin").toString().split(',');
            const int horizontal=m.size()==4?m[0].toInt()+m[2].toInt():2*m.value(0).toInt();
            const int vertical=m.size()==4?m[1].toInt()+m[3].toInt():2*m.value(m.size()==1?0:1).toInt();
            const auto hint=item.widget->sizeHint().expandedTo(item.widget->minimumSizeHint()).expandedTo(item.widget->minimumSize());
            extent.setWidth(qMax(extent.width(),number(item.p,"Width",qMax(number(item.p,"MinWidth",20),hint.width()))+horizontal));
            extent.setHeight(qMax(extent.height(),number(item.p,"Height",qMax(number(item.p,"MinHeight",22),hint.height()))+vertical));
        }
        return extent;
    }
    QSize minimumSizeHint() const override { return sizeHint(); }
    void place()
    {
        for (const auto &item : items) {
            auto *w = item.widget; const auto &p = item.p;
            const auto margins = p.value("Margin").toString().split(',');
            auto part = [&margins](int i) { return margins.value(i).toDouble(); };
            int left = part(0), top = margins.size() == 1 ? left : part(1);
            int right = margins.size() == 1 ? left : margins.size() == 2 ? left : part(2);
            int bottom = margins.size() == 1 ? left : margins.size() == 2 ? top : part(3);
            const auto h = p.value("HorizontalAlignment").toString("Stretch");
            const auto v = p.value("VerticalAlignment").toString("Stretch");
            const int minW = number(p,"MinWidth",h=="Stretch"?qMax(20,w->minimumWidth()):qMax(20,w->sizeHint().width()));
            const int minH = number(p,"MinHeight",v=="Stretch"?qMax(22,w->minimumHeight()):qMax(22,w->sizeHint().height()));
            int width = number(p,"Width",h == "Stretch" ? qMax(minW,this->width()-left-right) : minW);
            int height = number(p,"Height",v == "Stretch" ? qMax(minH,this->height()-top-bottom) : minH);
            int x = h == "Right" ? this->width()-right-width : h == "Center" ? (this->width()-width+left-right)/2 : left;
            int y = v == "Bottom" ? this->height()-bottom-height : v == "Center" ? (this->height()-height+top-bottom)/2 : top;
            w->setGeometry(qMax(0,x),qMax(0,y),width,height);
        }
    }
protected:
    void resizeEvent(QResizeEvent *event) override { QWidget::resizeEvent(event); place(); }
};
}

RecoveredWorkspace::RecoveredWorkspace(QWidget *parent) : QWidget(parent)
{
    setObjectName("RecoveredWorkspace");
    catalog_ = readObject(":/ui/recovered/index.json");
    interactions_ = readObject(":/ui/interactions.json");
    dialogs_ = readArray(":/ui/recovered/native-dialogs.json");
    menus_ = readArray(":/ui/recovered/menus.json");
    for (const auto &value : catalog_.value("pages").toArray()) {
        const auto page = value.toObject(); metadata_[page.value("id").toString()] = page;
    }
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(6,2,6,4);
    title_ = new QLabel(this); title_->setObjectName("RecoveredTitle");
    title_->setTextInteractionFlags(Qt::TextSelectableByMouse);
    layout->addWidget(title_);
    notice_ = new QLabel(QString::fromUtf8("输入可随项目保存 · 字段语义尚未全部验证；未连接计算引擎"),this);
    notice_->setWordWrap(true); layout->addWidget(notice_);
    scroll_ = new QScrollArea(this); scroll_->setWidgetResizable(true);
    scroll_->setObjectName("RecoveredScroll"); layout->addWidget(scroll_,1);
    auto colors=palette(); colors.setColor(QPalette::Window,QColor("#f4f4f8")); setPalette(colors); setAutoFillBackground(true);
}

QString RecoveredWorkspace::idForType(const QString &type) const
{
    const auto exact = catalog_.value("types").toObject().value(type).toString();
    // Legacy COM ProgIDs also name forms present in the portable WPF catalog.
    return exact.isEmpty() ? idForName(type.section('.', -1)) : exact;
}

QString RecoveredWorkspace::idForName(const QString &name) const
{
    for (const auto &value : catalog_.value("pages").toArray()) {
        const auto p = value.toObject();
        if (p.value("name").toString() == name) return p.value("id").toString();
    }
    return {};
}

void RecoveredWorkspace::setGlobalUnits(const QString &units)
{
    globalUnits_ = units;
    for (auto *combo : findChildren<QComboBox *>()) {
        if (!combo->property("globalUnits").toBool()) continue;
        const QSignalBlocker blocker(combo);
        combo->setCurrentText(units);
    }
}

void RecoveredWorkspace::saveState()
{
    if (current_.isEmpty() || !scroll_->widget()) return;
    QVariantMap values;
    const auto widgets = scroll_->widget()->findChildren<QWidget *>();
    for (auto *w : widgets) {
        const auto key = w->property("stateKey").toString();
        if (key.isEmpty()) continue;
        if (auto *t = qobject_cast<QTabWidget *>(w)) values[key] = t->currentIndex();
        else if (auto *c = qobject_cast<QComboBox *>(w)) values[key] = QVariantMap{{"index",c->currentIndex()},{"text",c->currentText()}};
        else if (auto *e = qobject_cast<QLineEdit *>(w)) values[key] = e->text();
        else if (auto *e = qobject_cast<QTextEdit *>(w)) values[key] = e->toPlainText();
        else if (auto *b = qobject_cast<QAbstractButton *>(w); b && b->isCheckable()) values[key] = b->isChecked();
        else if (auto *s = qobject_cast<QSpinBox *>(w)) values[key] = s->value();
        else if (auto *t = qobject_cast<QTableWidget *>(w)) {
            QVariantList rows;
            for (int r=0;r<t->rowCount();++r) {
                QStringList cells;
                for (int c=0;c<t->columnCount();++c) cells << (t->item(r,c)?t->item(r,c)->text():QString());
                rows << QVariant(cells);
            }
            values[key] = rows;
        }
    }
    state_[current_] = values;
}

void RecoveredWorkspace::restoreState(QWidget *view)
{
    const auto values = state_.value(current_);
    for (auto *w : view->findChildren<QWidget *>()) {
        const auto key = w->property("stateKey").toString();
        if (!values.contains(key) || w->property("globalUnits").toBool()) continue;
        const auto value = values.value(key);
        if (auto *t = qobject_cast<QTabWidget *>(w)) t->setCurrentIndex(value.toInt());
        else if (auto *c = qobject_cast<QComboBox *>(w)) {
            const auto selection=value.toMap();
            c->setCurrentIndex(selection.value("index",-1).toInt());
            if (c->isEditable()) c->setEditText(selection.value("text").toString());
        }
        else if (auto *e = qobject_cast<QLineEdit *>(w)) e->setText(value.toString());
        else if (auto *e = qobject_cast<QTextEdit *>(w)) e->setPlainText(value.toString());
        else if (auto *b = qobject_cast<QAbstractButton *>(w); b && b->isCheckable()) b->setChecked(value.toBool());
        else if (auto *s = qobject_cast<QSpinBox *>(w)) s->setValue(value.toInt());
        else if (auto *t = qobject_cast<QTableWidget *>(w)) {
            const QSignalBlocker blocker(t);
            const auto rows=value.toList(); t->setRowCount(rows.size());
            for (int r=0;r<rows.size();++r) {
                const auto cells=rows[r].toStringList();
                for(int c=0;c<t->columnCount();++c) t->setItem(r,c,new QTableWidgetItem(cells.value(c)));
            }
        }
    }
}

QMap<QString, QVariantMap> RecoveredWorkspace::sessionState()
{
    saveState();
    return state_;
}

void RecoveredWorkspace::setSessionState(const QMap<QString, QVariantMap> &state)
{
    const QSignalBlocker blocked(this);
    const auto page=current_;
    current_.clear(); state_=state;
    if(!page.isEmpty()) showPage(page);
}

QJsonObject RecoveredWorkspace::pageSpec(const QString &id)
{
    if (specs_.contains(id)) return specs_[id];
    const auto module = metadata_.value(id).value("module").toString();
    for (const auto &value : catalog_.value("modules").toArray()) {
        const auto m = value.toObject();
        if (m.value("id").toString() != module) continue;
        const auto data = readObject(":/ui/recovered/"+m.value("file").toString());
        for (const auto &p : data.value("pages").toArray()) {
            auto page = p.toObject(); specs_[page.value("id").toString()] = page;
        }
        break;
    }
    return specs_.value(id);
}

bool RecoveredWorkspace::showPage(const QString &id)
{
    saveState();
    QWidget *view = nullptr;
    QJsonObject spec;
    if (id.startsWith("dialog:")) {
        bool ok; const auto i = id.mid(7).toInt(&ok);
        if (!ok || i < 0 || i >= dialogs_.size()) return false;
        spec = dialogs_[i].toObject(); view = renderDialog(spec);
    } else if (id.startsWith("menu:")) {
        bool ok; const auto i = id.mid(5).toInt(&ok);
        if (!ok || i < 0 || i >= menus_.size()) return false;
        spec = menus_[i].toObject(); view = renderMenu(spec);
    } else {
        spec = pageSpec(id); if (spec.isEmpty()) return false;
        view = renderPage(spec);
    }
    current_ = id;
    title_->setText(spec.value("title").toString(spec.value("resource").toString())+"  "+spec.value("name").toString());
    const auto source = spec.value("source").toObject();
    title_->setToolTip(source.isEmpty() ? spec.value("file").toString() : source.value("file").toString()+"\n"+source.value("resource").toString());
    scroll_->setWidget(view); // Deletes previous canvas; thousands of pages stay lazy.
    restoreState(view);
    setGlobalUnits(globalUnits_);
    WidgetState::observe(view,this,[this] { saveState(); emit inputsChanged(); });
    emit pageChanged(id);
    return true;
}

QWidget *RecoveredWorkspace::renderPage(const QJsonObject &spec, int depth)
{
    if (depth > 8) return new QLabel(QString::fromUtf8("页面引用超过预览深度"));
    QScopedValueRollback<QString> context(renderScope_, renderScope_ + "/" + spec.value("id").toString());
    QScopedValueRollback<QString> identity(renderingId_, spec.value("id").toString());
    const auto pageName=spec.value("name").toString();
    QScopedValueRollback<bool> editable(sessionEditable_,sessionEditable_ &&
        !pageName.contains("_Out",Qt::CaseInsensitive) && !pageName.contains("_Result",Qt::CaseInsensitive));
    auto nodes = spec.value("nodes").toArray();
    const auto overrides = interactions_.value("forms").toObject().value(spec.value("name").toString()).toObject();
    for (int i=0; i<nodes.size(); ++i) {
        auto n = nodes[i].toObject(); auto p = n.value("p").toObject();
        const auto config = overrides.value(p.value("Name").toString()).toObject();
        for (auto it=config.begin(); it!=config.end(); ++it) p[it.key()] = it.value();
        n["p"] = p; nodes[i] = n;
    }
    auto *view=nodes.isEmpty() ? new QWidget : renderNodes(nodes,0,0,depth);
    // Radio buttons in different WPF panels can share one named group.
    QMap<QString,QButtonGroup *> groups;
    for (auto *radio:view->findChildren<QRadioButton *>()) {
        const auto name=radio->property("radioGroup").toString();
        if (name.isEmpty()) continue;
        if (!groups.contains(name)) groups[name]=new QButtonGroup(view);
        groups[name]->addButton(radio);
    }
    if (spec.value("name").toString()=="MMProp_Spec_Input_Global") {
        auto *filter=view->findChild<QComboBox *>("cboGPProcessType");
        auto *base=view->findChild<QComboBox *>("MMComboBox4");
        if (filter && base) {
            QStringList common;
            for(int i=0;i<base->count();++i) common.append(base->itemText(i));
            connect(filter,&QComboBox::currentTextChanged,base,[base,common](const QString &value) {
                base->clear();
                if (value=="COMMON") { base->addItems(common); base->setCurrentIndex(-1); }
                base->setEnabled(value=="COMMON");
                base->setToolTip(value=="COMMON"?QString():QString::fromUtf8("此过滤器的方法集合尚待原版核对"));
            });
        }
    }
    return view;
}

QWidget *RecoveredWorkspace::renderNodes(const QJsonArray &nodes, int index, int depth, int pageDepth)
{
    if (depth>128) return new QLabel(QString::fromUtf8("控件嵌套超过预览深度"));
    const auto node = nodes[index].toObject(); const auto p = node.value("p").toObject();
    const auto type = node.value("type").toString();
    QList<int> children;
    for (int i = index+1; i < nodes.size(); ++i) {
        const auto n = nodes[i].toObject();
        if (n.value("parent").toInt(-1) != index) continue;
        const auto slot = n.value("slot").toString();
        const auto childType = n.value("type").toString();
        const auto cp=n.value("p").toObject();
        const auto visibility=cp.value("Visibility").toString(cp.value("DefaultVisibility").toString());
        if (visibility=="Collapsed" || visibility=="Hidden") continue;
        const QStringList nonVisual{"Binding","MultiBinding","RelativeSource","Setter","Style","Trigger","DataTrigger","Condition","ResourceDictionary","NullExtension","RowDefinition","ColumnDefinition","GradientStop","CommandBinding"};
        if (nonVisual.contains(childType) || childType.endsWith("Converter") || childType.endsWith("Brush") || childType.endsWith("Transform")) continue;
        if (slot.contains("Resources") || slot.contains("Style") || slot.contains("Template") || slot.contains("Trigger")) continue;
        children.append(i);
    }
    QWidget *widget = nullptr;
    if (type.contains("TabStrip") || type == "TabControl") {
        auto *tabs = new QTabWidget; tabs->setUsesScrollButtons(true);
        for (int child : children) {
            const auto item = nodes[child].toObject(); const auto props = item.value("p").toObject();
            auto reference = props.value("ContentType").toObject().value("type").toString();
            if (reference.isEmpty()) reference = props.value("ContentProgId").toString();
            if (reference.isEmpty()) reference = props.value("ContentPage").toString();
            const auto ref = idForType(reference);
            QWidget *body = nullptr;
            if (!ref.isEmpty()) body = renderPage(pageSpec(ref),pageDepth+1);
            else if (!reference.isEmpty() || !props.value("ContentProgId").toString().isEmpty()) body = new QLabel(QString::fromUtf8("此页未找到独立静态布局，需运行时组件提供内容"));
            else body = renderNodes(nodes,child,depth+1,pageDepth);
            auto *scroller = new QScrollArea; scroller->setWidgetResizable(true); scroller->setWidget(body);
            const auto tabIndex = tabs->addTab(scroller,caption(props).isEmpty()?QString::fromUtf8("未命名页签"):caption(props));
            tabs->setTabEnabled(tabIndex, props.value("IsEnabled").toBool(true));
        }
        widget = tabs;
    } else if (type.contains("ListPicker")) {
        widget = new QWidget; auto *row = new QHBoxLayout(widget);
        for (const auto &key : {"OptionsHeader","SelectionHeader"}) {
            auto *column = new QVBoxLayout; column->addWidget(new QLabel(p.value(key).toString()));
            auto *list = new QListWidget; list->setMinimumWidth(60); list->setEnabled(false); column->addWidget(list); row->addLayout(column,1);
            if (QString(key)=="OptionsHeader") {
                auto *arrows = new QVBoxLayout;
                for (const auto &label : {">", ">>", "<", "<<"}) { auto *b=new QPushButton(label); b->setEnabled(false); arrows->addWidget(b); }
                row->addLayout(arrows);
            }
        }
    } else if (type.contains("RadioButton") || type=="MMOptionButton") {
        auto *radio = new QRadioButton(caption(p)); radio->setChecked(p.value("IsChecked").toBool()); radio->setProperty("radioGroup",p.value("GroupName").toString()); widget = radio;
    } else if (type.contains("CheckBox") && !type.contains("GroupBox") && (index>0 || children.isEmpty())) {
        auto *check = new QCheckBox(caption(p)); check->setChecked(p.value("IsChecked").toBool()); widget = check;
    } else if (type.contains("Button")) {
        auto *button = new QPushButton(caption(p)); button->setAutoDefault(false); widget=button;
        for (const auto &property:{"SmallImage","LargeImage","ImageSource","Source"}) {
            const auto icon=aspenIcon(renderingId_+":"+QString::number(index)+":"+property);
            if (!icon.isNull()) { button->setIcon(icon); break; }
        }
        for (int child:children) {
            if (nodes[child].toObject().value("type").toString()=="Image")
                button->setIcon(aspenIcon(renderingId_+":"+QString::number(child)+":Source"));
        }
        const auto action = p.value("Action").toString();
        if (!action.isEmpty()) connect(button,&QPushButton::clicked,this,[this,action] { emit actionRequested(action); });
        else if (p.value("IsCancel").toBool() || QStringList{"btnClose","buttonCancel","CancelButton"}.contains(p.value("Name").toString()))
            connect(button,&QPushButton::clicked,this,&RecoveredWorkspace::closeRequested);
        else { button->setEnabled(false); button->setToolTip(QString::fromUtf8("此界面动作尚未接入")); }
    } else if (type.contains("Combo") || type.contains("DropDown")) {
        auto *combo=new QComboBox;
        for (const auto &value : p.value("Options").toArray()) combo->addItem(value.toString());
        for (int child : children) {
            const auto item=nodes[child].toObject();
            if (item.value("type").toString()=="ComboBoxItem" || item.value("type").toString()=="ComboBoxDataItem") {
                const auto cp=item.value("p").toObject();
                combo->addItem(cp.value("DisplayText").toString(caption(cp)),cp.value("Value").toVariant());
            }
        }
        combo->setEditable(sessionEditable_ && combo->count()==0);
        combo->setEnabled(combo->count()>0 || combo->isEditable());
        combo->setCurrentIndex(p.value("SelectedIndex").toInt(-1));
        if (p.contains("SelectedText")) combo->setCurrentText(p.value("SelectedText").toString());
        if (p.value("GlobalUnits").toBool()) {
            combo->setProperty("globalUnits",true); combo->setCurrentText(globalUnits_);
            connect(combo,&QComboBox::currentTextChanged,this,[this](const QString &value) { globalUnits_=value; emit globalUnitsChanged(value); });
        }
        widget=combo;
    } else if (type=="MMVariableEdit") {
        widget=new QWidget; auto *row=new QHBoxLayout(widget); row->setContentsMargins(0,0,0,0); row->setSpacing(2);
        auto *edit=new QLineEdit(p.value("Text").toString()); edit->setReadOnly(!p.value("Editable").toBool(sessionEditable_));
        edit->setMaxLength(number(p,"MaxLength",32767));
        edit->setProperty("stateKey",renderScope_+":"+QString::number(index)+":value"); row->addWidget(edit,1);
        if (p.value("UnitsVisibility").toString()!="Collapsed" && p.contains("UnitsWidth")) {
            auto *units=new QComboBox;
            for(const auto &unit:p.value("Units").toArray()) units->addItem(unit.toString());
            units->setEnabled(units->count()>1); units->setMinimumWidth(45); row->addWidget(units,1);
            units->setProperty("stateKey",renderScope_+":"+QString::number(index)+":units");
        }
    } else if (type.contains("SpinBox")) {
        auto *spin=new QSpinBox; spin->setRange(number(p,"Minimum",0),number(p,"Maximum",9999)); spin->setValue(p.value("Value").toInt()); widget=spin;
    } else if (type=="MMDescription" || type=="RichTextBox" || (type=="TextBox" && p.value("AcceptsReturn").toBool())) {
        auto *edit=new QTextEdit(p.value("Text").toString()); edit->setAcceptRichText(false); edit->setMinimumHeight(80); widget=edit;
    } else if (type.contains("TextBox") || type.contains("EditBox") || type.contains("Numeric") || type.endsWith("Edit")) {
        auto *edit=new QLineEdit(p.value("Text").toString()); edit->setReadOnly(!p.value("Editable").toBool(sessionEditable_ || !p.contains("VariablePath"))); edit->setMaxLength(number(p,"MaxLength",32767)); widget=edit;
    } else if (type=="Image" || type=="AutoDisabledImage") {
        auto *label=new QLabel; const auto icon=aspenIcon(renderingId_+":"+QString::number(index)+":Source");
        if (!icon.isNull()) label->setPixmap(icon.pixmap(QSize(number(p,"Width",512),number(p,"Height",256))));
        else label->setText(QString::fromUtf8("图像尚未恢复"));
        widget=label;
    } else if ((type.contains("Label") || type.contains("TextBlock") || type == "AccessText") && (index>0 || children.isEmpty())) {
        auto *label = new QLabel(caption(p)); label->setWordWrap(true); widget=label;
    } else if (type.startsWith("MMScrollArea") && !type.endsWith("Field")) {
        QStringList labels; QList<int> widths;
        for (int i=index+1;i<nodes.size();++i) {
            auto child=nodes[i].toObject(); int parent=child.value("parent").toInt(-1);
            while (parent>index) parent=nodes[parent].toObject().value("parent").toInt(-1);
            if (parent!=index || !child.value("type").toString().endsWith("Field")) continue;
            const auto cp=child.value("p").toObject();
            if (!cp.value("Label").isString()) continue;
            labels<<cp.value("Label").toString(); widths<<number(cp,"Width",120);
        }
        auto *table=new QTableWidget(0,labels.size()); table->setHorizontalHeaderLabels(labels);
        for (int i=0;i<widths.size();++i) table->setColumnWidth(i,widths[i]);
        table->horizontalHeader()->setStretchLastSection(true); table->setMinimumSize(100,60);
        table->setEditTriggers(sessionEditable_?QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::AnyKeyPressed:QAbstractItemView::NoEditTriggers);
        if (sessionEditable_ && !labels.isEmpty()) {
            table->setRowCount(1);
            connect(table,&QTableWidget::cellChanged,table,[table](int row,int) {
                if (row!=table->rowCount()-1) return;
                for(int col=0;col<table->columnCount();++col)
                    if(table->item(row,col) && !table->item(row,col)->text().isEmpty()) { table->insertRow(table->rowCount()); break; }
            });
            table->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(table,&QWidget::customContextMenuRequested,table,[this,table](const QPoint &point){
                const auto index=table->indexAt(point); if(!index.isValid()) return;
                QMenu menu(table); auto *remove=menu.addAction(QString::fromUtf8("删除此行"));
                connect(remove,&QAction::triggered,table,[this,table,index]{
                    QSignalBlocker transaction(this);
                    table->removeRow(index.row());
                    if(table->rowCount()==0) table->insertRow(0);
                    saveState();transaction.unblock();emit inputsChanged();
                });
                menu.exec(table->viewport()->mapToGlobal(point));
            });
        }
        widget=table;
    } else if (isData(type) && children.isEmpty()) {
        auto *table=new QTableWidget(0,0); table->setMinimumSize(120,60); table->setEnabled(false); widget=table;
    } else if (type.contains("ListBox")) {
        widget=new QListWidget; widget->setEnabled(false);
    } else if (type.contains("GroupBox")) {
        auto *group=new QGroupBox(caption(p)); auto *layout=new QVBoxLayout(group);
        auto *canvas=new ResourceCanvas;
        for (int child : children) {
            auto *w=renderNodes(nodes,child,depth+1,pageDepth);
            if (nodes[child].toObject().value("slot").toString()=="Header") { layout->addWidget(w); continue; }
            w->setParent(canvas); canvas->items.append({w,nodes[child].toObject().value("p").toObject()});
        }
        layout->addWidget(canvas); widget=group;
    } else if (type == "StackPanel" || type == "WrapPanel" || type == "DockPanel" || type == "MMOptionGroup") {
        widget=new QWidget;
        QBoxLayout *layout = p.value("Orientation").toString()=="Horizontal" ? static_cast<QBoxLayout *>(new QHBoxLayout(widget)) : new QVBoxLayout(widget);
        layout->setContentsMargins(0,0,0,0);
        for (int child : children) layout->addWidget(renderNodes(nodes,child,depth+1,pageDepth));
        if (type=="MMOptionGroup") {
            auto *group=new QButtonGroup(widget);
            for (auto *radio:widget->findChildren<QRadioButton *>()) group->addButton(radio);
        }
    } else if (type == "Grid" && !children.isEmpty()) {
        widget=new QWidget; auto *layout=new QGridLayout(widget); layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(3); layout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
        int rowNumber=0,columnNumber=0;
        for (int i=index+1;i<nodes.size();++i) {
            const auto def=nodes[i].toObject(); if (def.value("parent").toInt(-1)!=index) continue;
            const auto dt=def.value("type").toString(); if (dt!="RowDefinition"&&dt!="ColumnDefinition") continue;
            const auto dp=def.value("p").toObject(); const bool row=dt=="RowDefinition";
            const auto text=dp.value(row?"Height":"Width").toString(); bool ok=false; const double fixed=text.toDouble(&ok);
            const int n=row?rowNumber++:columnNumber++;
            if (ok) { if(row) layout->setRowMinimumHeight(n,qBound(0,qRound(fixed),4000)); else layout->setColumnMinimumWidth(n,qBound(0,qRound(fixed),4000)); }
            if (text.endsWith('*')) { const auto weight=qMax(1,text.chopped(1).toInt()); if(row) layout->setRowStretch(n,weight); else layout->setColumnStretch(n,weight); }
        }
        QMap<QString,QList<int>> cells;
        for (int child:children) {
            const auto cp=nodes[child].toObject().value("p").toObject();
            const auto key=QString("%1:%2:%3:%4").arg(number(cp,"Row",0)).arg(number(cp,"Column",0)).arg(number(cp,"RowSpan",1)).arg(number(cp,"ColumnSpan",1));
            cells[key].append(child);
        }
        QSet<int> handled;
        for (int child : children) {
            if (handled.contains(child)) continue;
            const auto props=nodes[child].toObject().value("p").toObject();
            const auto key=QString("%1:%2:%3:%4").arg(number(props,"Row",0)).arg(number(props,"Column",0)).arg(number(props,"RowSpan",1)).arg(number(props,"ColumnSpan",1));
            const auto alternatives=cells.value(key);
            bool conditional=false;
            for (int i=index+1;i<nodes.size();++i) {
                const auto n=nodes[i].toObject();
                if (alternatives.contains(n.value("parent").toInt(-1)) && n.value("slot").toString()=="Visibility") conditional=true;
            }
            QWidget *control=nullptr;
            if (conditional && alternatives.size()>1) {
                auto *choices=new QTabWidget; choices->setObjectName("ConditionalAlternatives");
                choices->setToolTip(QString::fromUtf8("同一位置的条件内容；切换查看，实际显示条件待原程序核对"));
                int best=0,largest=-1;
                for (int alternative:alternatives) {
                    const auto ap=nodes[alternative].toObject().value("p").toObject();
                    auto label=caption(ap); if (label.isEmpty()) label=ap.value("Name").toString();
                    choices->addTab(renderNodes(nodes,alternative,depth+1,pageDepth),label);
                    int descendants=0;
                    for (int i=alternative+1;i<nodes.size();++i) {
                        int parent=nodes[i].toObject().value("parent").toInt(-1);
                        while(parent>alternative) parent=nodes[parent].toObject().value("parent").toInt(-1);
                        if(parent==alternative) ++descendants;
                    }
                    if (descendants>largest) { largest=descendants; best=choices->count()-1; }
                    handled.insert(alternative);
                }
                choices->setCurrentIndex(best); control=choices;
            } else control=renderNodes(nodes,child,depth+1,pageDepth);
            const auto margin=props.value("Margin").toString().split(',');
            if (margin.size()==4) {
                auto *wrapper=new QWidget; auto *box=new QVBoxLayout(wrapper);
                box->setContentsMargins(qMax(0,margin[0].toInt()),qMax(0,margin[1].toInt()),qMax(0,margin[2].toInt()),qMax(0,margin[3].toInt())); box->addWidget(control); control=wrapper;
            }
            layout->addWidget(control,number(props,"Row",0),number(props,"Column",0),qMax(1,number(props,"RowSpan",1)),qMax(1,number(props,"ColumnSpan",1)));
        }
    } else {
        const auto reference=idForName(type);
        if (index>0 && !reference.isEmpty() && reference!=renderingId_ && children.isEmpty()) {
            widget=renderPage(pageSpec(reference),pageDepth+1);
        } else {
        auto *canvas=new ResourceCanvas;
        for (int child : children) {
            auto *w=renderNodes(nodes,child,depth+1,pageDepth); w->setParent(canvas);
            canvas->items.append({w,nodes[child].toObject().value("p").toObject()});
        }
        widget=canvas;
        if (children.isEmpty()) {
            auto *l=new QVBoxLayout(canvas); auto *label=new QLabel(QString::fromUtf8("运行时控件：")+type); label->setWordWrap(true); l->addWidget(label);
        }
        }
    }
    widget->setObjectName(p.value("Name").toString());
    widget->setProperty("stateKey",renderScope_+":"+QString::number(index));
    if (p.contains("IsEnabled")) widget->setEnabled(p.value("IsEnabled").toBool());
    widget->setProperty("resourceType",type);
    widget->setProperty("sourceNode",index);
    if (widget->toolTip().isEmpty()) widget->setToolTip(type+(p.contains("VariablePath")?"\n"+p.value("VariablePath").toString():QString()));
    widget->setMinimumSize(number(p,"MinWidth",index==0?600:0),number(p,"MinHeight",index==0?400:0));
    if (p.contains("Width") && number(p,"Width",0)>0) widget->setFixedWidth(number(p,"Width",0));
    if (p.contains("Height") && number(p,"Height",0)>0) widget->setFixedHeight(number(p,"Height",0));
    if (!children.isEmpty()) widget->setMinimumSize(widget->minimumSize().expandedTo(widget->minimumSizeHint()));
    return widget;
}

QWidget *RecoveredWorkspace::renderDialog(const QJsonObject &spec)
{
    auto *canvas = new QWidget;
    const auto box = spec.value("rect").toArray();
    // Win32 dialog units use average character width / 4 and font height / 8.
    const double sx=fontMetrics().averageCharWidth()/4.0, sy=fontMetrics().height()/8.0;
    canvas->setMinimumSize(qRound(box.at(2).toInt()*sx)+20,qRound(box.at(3).toInt()*sy)+20);
    for (const auto &value : spec.value("controls").toArray()) {
        const auto c=value.toObject(); const auto t=c.value("type").toString(); const auto text=c.value("text").toString();
        QWidget *w=nullptr;
        const auto style=quint32(c.value("style").toDouble());
        if (t=="Button") {
            const auto kind=style & 15;
            if (kind==7) w=new QGroupBox(text,canvas);
            else if (kind==2 || kind==3 || kind==5 || kind==6) w=new QCheckBox(text,canvas);
            else if (kind==4 || kind==9) w=new QRadioButton(text,canvas);
            else w=new QPushButton(text,canvas);
        } else if (t=="Static") { auto *l=new QLabel(text,canvas); l->setWordWrap(true); w=l; }
        else if (t=="Edit") w=new QLineEdit(text,canvas);
        else if (t=="ComboBox") w=new QComboBox(canvas);
        else if (t=="ListBox") w=new QListWidget(canvas);
        else { w=new QLabel(t,canvas); w->setStyleSheet("border: 1px solid #a9bacd;"); }
        const auto rect=c.value("rect").toArray();
        w->setGeometry(qRound(rect.at(0).toInt()*sx),qRound(rect.at(1).toInt()*sy),qMax(1,qRound(rect.at(2).toInt()*sx)),qMax(1,qRound(rect.at(3).toInt()*sy)));
        if (t!="Static") w->setEnabled(false);
        w->setObjectName("native-"+QString::number(c.value("id").toDouble(),'f',0));
    }
    return canvas;
}

QWidget *RecoveredWorkspace::renderMenu(const QJsonObject &spec)
{
    auto *view=new QWidget; auto *layout=new QVBoxLayout(view);
    auto *bar=new QHBoxLayout;
    std::function<void(QMenu *,const QJsonArray &)> add;
    add=[this,&add](QMenu *menu,const QJsonArray &items) {
        for (const auto &v:items) {
            const auto e=v.toObject(); const auto label=e.value("text").toString();
            if (label.isEmpty()) { menu->addSeparator(); continue; }
            QAction *action;
            if (e.contains("items")) { auto *sub=menu->addMenu(label); add(sub,e.value("items").toArray()); action=sub->menuAction(); }
            else {
                action=menu->addAction(label);
                auto clean=label.section('\t',0,0); clean.remove('&');
                const auto command=interactions_.value("menuCommands").toObject().value(clean).toString();
                if (!command.isEmpty()) connect(action,&QAction::triggered,this,[this,command] { emit actionRequested(command); });
                else connect(action,&QAction::triggered,this,[this,clean] { emit actionRequested("unavailable:"+clean); });
            }
            action->setEnabled(!(e.value("state").toInt()&3));
            if (e.value("state").toInt()&8) { action->setCheckable(true); action->setChecked(true); }
        }
    };
    for (const auto &v:spec.value("items").toArray()) {
        const auto e=v.toObject(); auto *button=new QToolButton(view); button->setText(e.value("text").toString());
        if (e.contains("items")) { auto *menu=new QMenu(button); add(menu,e.value("items").toArray()); button->setMenu(menu); button->setPopupMode(QToolButton::InstantPopup); }
        else button->setEnabled(false);
        bar->addWidget(button);
    }
    bar->addStretch(); layout->addLayout(bar); layout->addStretch(); return view;
}
