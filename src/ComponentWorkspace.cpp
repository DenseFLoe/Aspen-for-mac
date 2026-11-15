#include "ComponentWorkspace.h"
#include "WidgetState.h"
#include <QSignalBlocker>
#include "IconCatalog.h"
#include <QBoxLayout>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QFormLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QJsonArray>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QStackedWidget>
#include <QTabBar>
#include <QTabWidget>
#include <QTableWidget>
#include <QTextEdit>
#include <QToolButton>

namespace {
QStringList strings(const QJsonArray &values)
{
    QStringList result;
    for (const auto &value : values) result << value.toString();
    return result;
}

QPushButton *formButton(const QString &text, QWidget *parent)
{
    auto *button = new QPushButton(text, parent);
    button->setProperty("formButton", true);
    button->setMinimumWidth(70);
    button->setAutoDefault(false);
    return button;
}
}

ComponentWorkspace::ComponentWorkspace(const QJsonObject &catalog, QWidget *parent)
    : QWidget(parent), catalog_(catalog)
{
    setObjectName("ComponentWorkspace");
    auto *column = new QVBoxLayout(this);
    column->setContentsMargins(3, 0, 3, 3);
    column->setSpacing(2);
    auto *documentBar = new QWidget(this);
    documentBar->setObjectName("DocumentBar");
    auto *row = new QHBoxLayout(documentBar);
    row->setContentsMargins(8, 0, 2, 0);
    row->setSpacing(4);
    title_ = new QLabel(documentBar);
    title_->setObjectName("DocumentTitle");
    row->addWidget(title_);
    auto *close = new QToolButton(documentBar);
    close->setText("×");
    close->setAccessibleName(QString::fromUtf8("关闭选项卡"));
    row->addWidget(close);
    auto *add = new QToolButton(documentBar);
    add->setText("+");
    add->setAccessibleName(QString::fromUtf8("打开组分页面"));
    row->addWidget(add);
    row->addStretch();
    auto *all = new QToolButton(documentBar);
    all->setText("▾");
    all->setAccessibleName(QString::fromUtf8("所有选项卡"));
    row->addWidget(all);
    pageMenu_ = new QMenu(this);
    for (auto *button : {add, all}) {
        button->setMenu(pageMenu_);
        button->setPopupMode(QToolButton::InstantPopup);
    }
    column->addWidget(documentBar);
    stack_ = new QStackedWidget(this);
    stack_->setObjectName("ComponentPages");
    stack_->addWidget(new QWidget(stack_));
    column->addWidget(stack_, 1);
    connect(close, &QToolButton::clicked, this, [this] {
        stack_->setCurrentIndex(0);
        title_->clear();
    });
    for (const auto &value : catalog_.value("pages").toArray()) {
        const auto spec = value.toObject();
        const auto id = spec.value("id").toString();
        auto *page = new QWidget(stack_);
        page->setObjectName("page-" + id);
        page->setProperty("pageId", id);
        page->setProperty("pageTitle", spec.value("title").toString());
        auto *layout = new QVBoxLayout(page);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        const auto tabSpecs = spec.value("tabs").toArray();
        if (tabSpecs.isEmpty()) {
            layout->addWidget(makeContent(spec));
        } else {
            auto *tabs = new QTabWidget(page);
            tabs->setObjectName("tabs-" + id);
            tabs->setDocumentMode(true);
            // The stylesheet supplies the pane border; avoid a second native baseline.
            tabs->tabBar()->setDrawBase(false);
            tabs->setUsesScrollButtons(true);
            auto *info = new QLabel(tabs);
            info->setPixmap(aspenIcon("info").pixmap(16, 16));
            info->setContentsMargins(0, 2, 5, 0);
            tabs->setCornerWidget(info);
            for (const auto &tabValue : tabSpecs) {
                const auto tab = tabValue.toObject();
                const int index = tabs->addTab(makeContent(tab), tab.value("label").toString());
                tabs->setTabEnabled(index, tab.value("enabled").toBool(true));
                if (!tab.value("icon").toString().isEmpty())
                    tabs->setTabIcon(index, aspenIcon(tab.value("icon").toString()));
            }
            tabs_[id] = tabs;
            layout->addWidget(tabs);
        }
        pages_[id] = page;
        stack_->addWidget(page);
        auto *action = pageMenu_->addAction(spec.value("title").toString());
        connect(action, &QAction::triggered, this, [this, id] { showPage(id); });
    }
    showPage("specifications");
    if(auto *table=pages_.value("specifications")->findChild<QTableWidget *>()) table->setProperty("projectDerived",true);
    defaults_=WidgetState::capture(this);
    WidgetState::observe(this,this,[this] { emit inputsChanged(); });
}

bool ComponentWorkspace::showPage(const QString &id)
{
    auto *page = pages_.value(id, nullptr);
    if (!page) return false;
    stack_->setCurrentWidget(page);
    title_->setText(page->property("pageTitle").toString());
    emit pageChanged(id);
    return true;
}

QString ComponentWorkspace::currentPage() const
{
    return stack_->currentWidget()->property("pageId").toString();
}

QTabWidget *ComponentWorkspace::currentTabs() const { return tabs_.value(currentPage(), nullptr); }
QStringList ComponentWorkspace::pageIds() const { return pages_.keys(); }

QWidget *ComponentWorkspace::makeContent(const QJsonObject &spec)
{
    auto *content = new QWidget;
    content->setObjectName("FormCanvas");
    auto *layout = new QVBoxLayout(content);
    layout->setContentsMargins(12, 16, 12, 12);
    layout->setSpacing(12);
    for (const auto &value : spec.value("elements").toArray()) {
        const auto element = value.toObject();
        auto *widget = makeElement(element);
        layout->addWidget(widget, element.value("stretch").toInt(0));
    }
    if (!spec.value("fill").toBool()) layout->addStretch();
    auto *scroll = new QScrollArea;
    scroll->setObjectName("FormScroll");
    scroll->setWidgetResizable(true);
    scroll->setWidget(content);
    return scroll;
}

void ComponentWorkspace::setUserComponents(const QJsonArray &objects)
{
    auto *page=pages_.value("specifications"); if(!page) return;
    auto *table=page->findChild<QTableWidget *>(); if(!table) return;
    const QSignalBlocker blocked(table);
    for(int row=table->rowCount()-1;row>=0;--row)
        if(table->item(row,0) && table->item(row,0)->data(Qt::UserRole+5).toBool()) table->removeRow(row);
    for(const auto &value:objects) {
        const auto d=value.toObject(); if(d.value("kind").toString()!="user-components") continue;
        const int row=qMax(0,table->rowCount()-1); table->insertRow(row);
        for(int col=0;col<table->columnCount();++col) table->setItem(row,col,new QTableWidgetItem);
        table->item(row,0)->setText(d.value("name").toString());table->item(row,0)->setData(Qt::UserRole+5,true);
        if(table->columnCount()>1) table->item(row,1)->setText(d.value("type").toString());
    }
    for(const auto &value:databaseComponents_) {
        const auto c=value.toObject();const int r=qMax(0,table->rowCount()-1);table->insertRow(r);
        const auto displayId=c.value("alias").toString().isEmpty()?c.value("name").toString():c.value("alias").toString();
        const QStringList cells{displayId,QString(),c.value("name").toString(),c.value("alias").toString(),c.value("cas").toString()};
        for(int col=0;col<table->columnCount();++col) table->setItem(r,col,new QTableWidgetItem(cells.value(col)));
        table->item(r,0)->setData(Qt::UserRole+5,true);table->item(r,0)->setToolTip(c.value("database").toString()+":"+c.value("compoundId").toString()+"\n"+c.value("datasetId").toString());
        if(table->columnCount()>1)table->item(r,1)->setToolTip(QString::fromUtf8("组分类别尚未接入。"));
    }
    table->setFixedHeight(qMin(240,32+24*table->rowCount()));
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

QWidget *ComponentWorkspace::makeElement(const QJsonObject &spec)
{
    const auto type = spec.value("type").toString();
    const auto label = spec.value("label").toString();
    QWidget *widget = nullptr;
    if (type == "table") {
        const auto headers = strings(spec.value("columns").toArray());
        auto *table = new QTableWidget(spec.value("rows").toInt(0), headers.size());
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setMinimumSectionSize(50);
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setFixedWidth(20);
        table->verticalHeader()->setDefaultSectionSize(24);
        if (table->rowCount() == 1) table->setVerticalHeaderLabels({"*"});
        table->horizontalHeader()->setFixedHeight(spec.value("headerHeight").toInt(28));
        const auto widths = spec.value("columnWidths").toArray();
        for (int i = 0; i < headers.size(); ++i) {
            table->setColumnWidth(i, i < widths.size() ? widths[i].toInt() : 125);
            for (int row = 0; row < table->rowCount(); ++row)
                table->setItem(row, i, new QTableWidgetItem);
        }
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionBehavior(QAbstractItemView::SelectItems);
        table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setFixedHeight(spec.value("height").toInt(table->rowCount() > 0 ? 56 : 38));
        widget = table;
    } else if (type == "group" || type == "row") {
        widget = type == "group" ? static_cast<QWidget *>(new QGroupBox(label)) : new QWidget;
        QBoxLayout *layout = type == "row" ? static_cast<QBoxLayout *>(new QHBoxLayout(widget))
                                            : static_cast<QBoxLayout *>(new QVBoxLayout(widget));
        layout->setContentsMargins(type == "group" ? 8 : 0, type == "group" ? 6 : 0, 8, 5);
        layout->setSpacing(3);
        for (const auto &value : spec.value("elements").toArray()) layout->addWidget(makeElement(value.toObject()));
        if (!spec.value("fill").toBool()) layout->addStretch();
        if (type == "group" && !spec.contains("minHeight"))
            widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    } else if (type == "buttons") {
        widget = new QWidget;
        auto *row = new QHBoxLayout(widget);
        row->setContentsMargins(0, 0, 0, 0);
        row->setSpacing(spec.value("joined").toBool() ? 0 : 8);
        for (const auto &value : spec.value("items").toArray()) {
            const auto item = value.isString() ? QJsonObject{{"label", value.toString()}} : value.toObject();
            auto *button = formButton(item.value("label").toString(), widget);
            button->setIcon(aspenIcon(item.value("id").toString()));
            button->setEnabled(item.value("enabled").toBool(true));
            button->setObjectName(item.value("id").toString());
            const auto action = item.value("action").toString();
            if (!action.isEmpty()) connect(button, &QPushButton::clicked, this, [this, action] { dispatch(action); });
            else {
                const auto id=item.value("id").toString();
                if (!id.isEmpty()) connect(button,&QPushButton::clicked,this,[this,id] { emit actionRequested(id); });
                else button->setEnabled(false);
            }
            row->addWidget(button);
        }
        row->addStretch();
    } else if (type == "field") {
        widget = new QWidget;
        auto *row = new QHBoxLayout(widget);
        row->setContentsMargins(0, 0, 0, 0);
        auto *caption = new QLabel(label, widget);
        caption->setFixedWidth(spec.value("labelWidth").toInt(165));
        row->addWidget(caption);
        QWidget *input = nullptr;
        if (spec.contains("options")) {
            auto *combo = new QComboBox(widget);
            combo->addItems(strings(spec.value("options").toArray()));
            combo->setMinimumContentsLength(10);
            input = combo;
        } else if (spec.value("spin").toBool()) {
            auto *spin = new QSpinBox(widget);
            spin->setRange(0, 999);
            input = spin;
        } else {
            auto *edit = new QLineEdit(spec.value("value").toString(), widget);
            edit->setReadOnly(true);
            input = edit;
        }
        input->setObjectName(spec.value("id").toString());
        input->setAccessibleName(label);
        caption->setBuddy(input);
        input->setFixedWidth(spec.value("inputWidth").toInt(235));
        row->addWidget(input);
        row->addStretch();
    } else if (type == "check") {
        auto *check = new QCheckBox(label);
        check->setChecked(spec.value("checked").toBool());
        widget = check;
    } else if (type == "radios") {
        widget = new QWidget;
        auto *row = new QHBoxLayout(widget);
        row->setContentsMargins(0, 0, 0, 0);
        auto *group = new QButtonGroup(widget);
        int i = 0;
        for (const auto &value : spec.value("items").toArray()) {
            auto *radio = new QRadioButton(value.toString(), widget);
            group->addButton(radio);
            radio->setChecked(i++ == 0);
            row->addWidget(radio);
        }
        row->addStretch();
    } else if (type == "comments") {
        widget = new QWidget;
        auto *layout = new QVBoxLayout(widget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(new QLabel(label.isEmpty() ? QString::fromUtf8("注释") : label));
        auto *edit = new QTextEdit(widget);
        edit->setObjectName("comments-editor");
        edit->setAccessibleName(label.isEmpty() ? QString::fromUtf8("注释") : label);
        edit->setAcceptRichText(false);
        edit->setMinimumHeight(220);
        layout->addWidget(edit, 1);
    } else if (type == "databanks") {
        widget = new QGroupBox(QString::fromUtf8("纯组分数据库和搜索顺序"));
        auto *row = new QHBoxLayout(widget);
        QList<QPushButton *> commands;
        for (const auto &key : {QString("available"), QString("selected")}) {
            auto *column = new QVBoxLayout;
            column->addWidget(new QLabel(key == "available" ? QString::fromUtf8("可用数据库") : QString::fromUtf8("所选数据库")));
            auto *list = new QListWidget(widget);
            list->setObjectName(key + "-databanks");
            list->addItems(strings(catalog_.value(key + "Databanks").toArray()));
            list->setFixedSize(176, 164);
            column->addWidget(list);
            row->addLayout(column);
            auto *arrows = new QVBoxLayout;
            arrows->addStretch();
            const QStringList labels = key == "available" ? QStringList{">", ">>", "<", "<<"} : QStringList{"▲", "▼"};
            for (const auto &text : labels) {
                auto *button = formButton(text, widget);
                button->setMinimumWidth(40);
                button->setMaximumWidth(42);
                commands.append(button);
                arrows->addWidget(button);
            }
            arrows->addStretch();
            row->addLayout(arrows);
        }
        auto *available=widget->findChild<QListWidget *>("available-databanks");
        auto *selected=widget->findChild<QListWidget *>("selected-databanks");
        const auto update=[available,selected,commands] {
            commands[0]->setEnabled(available->currentRow()>=0); commands[1]->setEnabled(available->count()>0);
            commands[2]->setEnabled(selected->currentRow()>=0); commands[3]->setEnabled(selected->count()>0);
            commands[4]->setEnabled(selected->currentRow()>0); commands[5]->setEnabled(selected->currentRow()>=0 && selected->currentRow()+1<selected->count());
        };
        for(int i=0;i<4;++i) connect(commands[i],&QPushButton::clicked,widget,[this,available,selected,i,update] {
            QSignalBlocker transaction(this);
            auto *from=i<2?available:selected; auto *to=i<2?selected:available;
            if (i%2) { while(from->count()) to->addItem(from->takeItem(0)); }
            else if (from->currentRow()>=0) to->addItem(from->takeItem(from->currentRow()));
            update();transaction.unblock();emit inputsChanged();
        });
        for(int i=4;i<6;++i) connect(commands[i],&QPushButton::clicked,widget,[this,selected,i,update] {
            QSignalBlocker transaction(this);
            const int current=selected->currentRow(), target=current+(i==4?-1:1);
            if (current>=0 && target>=0 && target<selected->count()) { auto *item=selected->takeItem(current); selected->insertItem(target,item); selected->setCurrentRow(target); }
            update();transaction.unblock();emit inputsChanged();
        });
        connect(available,&QListWidget::currentRowChanged,widget,update); connect(selected,&QListWidget::currentRowChanged,widget,update); update();
        row->addStretch();
    } else {
        widget = new QLabel(label);
    }
    if (spec.contains("width")) widget->setMaximumWidth(spec.value("width").toInt());
    if (spec.contains("minHeight")) widget->setMinimumHeight(spec.value("minHeight").toInt());
    widget->setEnabled(spec.value("enabled").toBool(true));
    return widget;
}

void ComponentWorkspace::dispatch(const QString &action)
{
    if (action == "find-compound") showFindDialog();
    else if (!showPage(action)) emit actionRequested(action);
}

void ComponentWorkspace::showFindDialog() { emit actionRequested("database-search"); }

QJsonObject ComponentWorkspace::sessionState() const { return WidgetState::capture(const_cast<ComponentWorkspace *>(this)); }
void ComponentWorkspace::restoreSessionState(const QJsonObject &state) {
    const QSignalBlocker blocked(this);
    WidgetState::restore(this,defaults_); WidgetState::restore(this,state);
}
