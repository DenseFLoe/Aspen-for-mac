#include "ComponentWorkspace.h"
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
            button->setEnabled(item.value("enabled").toBool(true));
            button->setObjectName(item.value("id").toString());
            const auto action = item.value("action").toString();
            if (!action.isEmpty()) connect(button, &QPushButton::clicked, this, [this, action] { dispatch(action); });
            else button->setToolTip(QString::fromUtf8("界面预览：此命令尚未连接业务处理"));
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
                button->setEnabled(false); // No database mutation in this UI shell.
                arrows->addWidget(button);
            }
            arrows->addStretch();
            row->addLayout(arrows);
        }
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
    else showPage(action);
}

void ComponentWorkspace::showFindDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle(QString::fromUtf8("查找化合物"));
    dialog.setObjectName("FindCompoundDialog");
    dialog.resize(720, 580);
    auto *layout = new QVBoxLayout(&dialog);
    auto *tabs = new QTabWidget(&dialog);
    auto *compound = new QWidget(tabs);
    auto *column = new QVBoxLayout(compound);
    auto *criteria = new QGroupBox(QString::fromUtf8("搜索准则"), compound);
    auto *form = new QFormLayout(criteria);
    auto *modes = new QWidget(criteria);
    auto *modeRow = new QHBoxLayout(modes);
    for (const auto &text : {QString::fromUtf8("开头为"), QString::fromUtf8("包含"), QString::fromUtf8("等于")}) {
        auto *radio = new QRadioButton(text, modes);
        radio->setChecked(text == QString::fromUtf8("包含"));
        modeRow->addWidget(radio);
    }
    form->addRow(modes);
    auto *query = new QLineEdit(criteria);
    query->setObjectName("compound-query");
    form->addRow(QString::fromUtf8("名称、别名或 CASRN："), query);
    auto *category = new QComboBox(criteria);
    category->addItem(QString::fromUtf8("全部"));
    form->addRow(QString::fromUtf8("化合物类："), category);
    for (const auto &label : {QString::fromUtf8("分子量："), QString::fromUtf8("沸点：")}) {
        auto *range = new QWidget(criteria);
        auto *row = new QHBoxLayout(range);
        row->setContentsMargins(0, 0, 0, 0);
        row->addWidget(new QLabel(QString::fromUtf8("从")));
        row->addWidget(new QLineEdit(range));
        row->addWidget(new QLabel(QString::fromUtf8("与")));
        row->addWidget(new QLineEdit(range));
        form->addRow(label, range);
    }
    column->addWidget(criteria);
    auto *search = formButton(QString::fromUtf8("立即查找"), compound);
    column->addWidget(search, 0, Qt::AlignLeft);
    auto *results = new QTableWidget(0, 8, compound);
    results->setHorizontalHeaderLabels({QString::fromUtf8("化合物名称"), QString::fromUtf8("别名"), QString::fromUtf8("数据库"), QString::fromUtf8("替换名称"), "MW", "BP <C>", QString::fromUtf8("CAS 编号"), QString::fromUtf8("化合物类")});
    column->addWidget(results, 1);
    auto *status = new QLabel(QString::fromUtf8("界面预览：未连接化合物数据库"), compound);
    column->addWidget(status);
    connect(search, &QPushButton::clicked, status, [status] {
        status->setText(QString::fromUtf8("未执行检索：当前版本仅实现界面，无化合物数据库连接。"));
    });
    tabs->addTab(compound, QString::fromUtf8("化合物"));
    for (const auto &text : {QString::fromUtf8("数据库"), QString("PubChem")}) {
        const int index = tabs->addTab(new QWidget(tabs), text);
        tabs->setTabEnabled(index, false); // Contents not observed in this capture.
        tabs->setTabToolTip(index, QString::fromUtf8("此弹窗标签尚未采集"));
    }
    layout->addWidget(tabs, 1);
    auto *close = formButton(QString::fromUtf8("关闭"), &dialog);
    layout->addWidget(close, 0, Qt::AlignRight);
    connect(close, &QPushButton::clicked, &dialog, &QDialog::accept);
    dialog.exec();
}
