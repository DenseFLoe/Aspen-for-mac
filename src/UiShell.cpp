#include "UiShell.h"
#include "IconCatalog.h"
#include <QAction>
#include <QBoxLayout>
#include <QFrame>
#include <QGridLayout>
#include <QHeaderView>
#include <QIcon>
#include <QKeySequence>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPainter>
#include <QPixmap>
#include <QPolygonF>
#include <QScrollArea>
#include <QShortcut>
#include <QSizePolicy>
#include <QSlider>
#include <QSplitter>
#include <QStackedWidget>
#include <QStatusBar>
#include <QStyle>
#include <QTableWidget>
#include <QTabBar>
#include <QTabWidget>
#include <QToolButton>
#include <QTreeWidget>

namespace {
QJsonObject buttonSpec(const QString &label)
{
    return {{"label", label}};
}


}

UiShell::UiShell(const QJsonObject &catalog, QWidget *parent)
    : QMainWindow(parent), catalog_(catalog)
{
    setWindowTitle(QString::fromUtf8("Simulation 2 — Aspen Plus 界面研究"));
    resize(1180, 730);
    setMinimumSize(800, 540);
    pages_ = new QStackedWidget(this);
    pages_->addWidget(makeWorkspace());
    pages_->addWidget(makeFilePage());
    setCentralWidget(pages_);

    auto *incomplete = new QLabel(QString::fromUtf8("所需输入不完整"), this);
    incomplete->setObjectName("Incomplete");
    statusBar()->addWidget(incomplete);
    statusBar()->addWidget(makeButton(buttonSpec(QString::fromUtf8("检查状态")), this));
    statusBar()->addPermanentWidget(makeButton(buttonSpec("100%"), this));
    statusBar()->addPermanentWidget(makeButton(buttonSpec("−"), this));
    auto *zoom = new QSlider(Qt::Horizontal, this);
    zoom->setRange(0, 100);
    zoom->setValue(50);
    zoom->setFixedWidth(100);
    zoom->setEnabled(false); // Display only; viewport transformations are out of scope.
    statusBar()->addPermanentWidget(zoom);
    statusBar()->addPermanentWidget(makeButton(buttonSpec("+"), this));

    auto *escape = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(escape, &QShortcut::activated, this, [this] { pages_->setCurrentIndex(0); });
}

QMenu *UiShell::makeMenu(const QJsonArray &entries, QWidget *parent)
{
    auto *menu = new QMenu(parent);
    for (const auto &value : entries) {
        const auto entry = value.toObject();
        if (entry.value("separator").toBool()) {
            menu->addSeparator();
            continue;
        }
        QString label = entry.value("label").toString();
        if (entry.value("checked").toBool()) label.prepend(QString::fromUtf8("✓  "));
        QAction *action = nullptr;
        const auto children = entry.value("items").toArray();
        if (!children.isEmpty()) {
            auto *submenu = makeMenu(children, menu);
            submenu->setTitle(label);
            action = menu->addMenu(submenu);
        } else {
            action = menu->addAction(label);
            // No triggered handler: selecting a leaf only dismisses the menu.
        }
        action->setEnabled(entry.value("enabled").toBool(true));
        action->setObjectName(entry.value("id").toString());
    }
    return menu;
}

QToolButton *UiShell::makeButton(const QJsonObject &spec, QWidget *parent, bool iconOnly)
{
    auto *button = new QToolButton(parent);
    const auto label = spec.value("label").toString();
    button->setText(label);
    button->setAccessibleName(label);
    button->setToolTip(label);
    button->setObjectName(spec.value("id").toString());
    button->setProperty("controlId", spec.value("id").toString());
    button->setAutoRaise(true);
    button->setEnabled(spec.value("enabled").toBool(true));
    const bool large = spec.value("large").toBool();
    auto icon = aspenIcon(spec.value("id").toString());
    if (icon.isNull()) icon = aspenIcon(spec.value("icon").toString());
    button->setIcon(icon);
    button->setIconSize(large ? QSize(32, 32) : QSize(16, 16));
    button->setToolButtonStyle(iconOnly ? Qt::ToolButtonIconOnly
        : large ? Qt::ToolButtonTextUnderIcon : Qt::ToolButtonTextBesideIcon);
    if (large) button->setMinimumHeight(65);
    auto items = spec.value("items").toArray();
    const auto menuRef = spec.value("menu").toString();
    if (!menuRef.isEmpty()) items = catalog_.value("menus").toObject().value(menuRef).toArray();
    if (!items.isEmpty()) {
        button->setMenu(makeMenu(items, button));
        button->setPopupMode(QToolButton::InstantPopup);
    }
    if (spec.value("selected").toBool()) {
        button->setCheckable(true);
        button->setChecked(true);
        // Keep observed state: buttons do not change the original model's run mode.
        connect(button, &QToolButton::clicked, button, [button] { button->setChecked(true); });
    }
    return button;
}

QWidget *UiShell::makeRibbon(const QJsonObject &ribbon)
{
    auto *content = new QWidget;
    content->setObjectName("RibbonContent");
    auto *row = new QHBoxLayout(content);
    row->setContentsMargins(4, 2, 4, 0);
    row->setSpacing(3);
    for (const auto &value : ribbon.value("groups").toArray()) {
        const auto group = value.toObject();
        auto *frame = new QFrame(content);
        frame->setObjectName("RibbonGroup");
        auto *vertical = new QVBoxLayout(frame);
        vertical->setContentsMargins(3, 0, 5, 0);
        vertical->setSpacing(0);
        auto *grid = new QGridLayout;
        grid->setSpacing(0);
        int column = 0;
        int line = 0;
        for (const auto &item : group.value("controls").toArray()) {
            const auto spec = item.toObject();
            auto *button = makeButton(spec, frame);
            if (spec.value("large").toBool()) {
                if (line != 0) { ++column; line = 0; }
                grid->addWidget(button, 0, column++, 3, 1);
            } else {
                grid->addWidget(button, line++, column);
                if (line == 3) { line = 0; ++column; }
            }
        }
        vertical->addLayout(grid, 1);
        auto *title = new QLabel(group.value("label").toString(), frame);
        title->setObjectName("GroupTitle");
        title->setAlignment(Qt::AlignCenter);
        vertical->addWidget(title);
        row->addWidget(frame);
    }
    row->addStretch();
    auto *scroll = new QScrollArea;
    scroll->setWidget(content);
    scroll->setWidgetResizable(true);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    return scroll;
}

QWidget *UiShell::makeWorkspace()
{
    auto *workspace = new QWidget;
    auto *column = new QVBoxLayout(workspace);
    column->setContentsMargins(0, 0, 0, 0);
    column->setSpacing(2);
    auto *quick = new QWidget(workspace);
    quick->setObjectName("QuickBar");
    auto *quickRow = new QHBoxLayout(quick);
    quickRow->setContentsMargins(5, 0, 5, 0);
    quickRow->setSpacing(0);
    for (const auto &item : catalog_.value("quickAccess").toArray())
        quickRow->addWidget(makeButton(item.toObject(), quick, true));
    quickRow->addStretch();
    auto *search = new QLineEdit(quick);
    search->setPlaceholderText(QString::fromUtf8("Aspen Knowledge中搜索"));
    search->setAccessibleName(QString::fromUtf8("Aspen Knowledge中搜索"));
    search->setReadOnly(true);
    search->setMaximumWidth(240);
    quickRow->addWidget(search);
    quickRow->addWidget(makeButton(buttonSpec(QString::fromUtf8("搜索")), quick, true));
    quickRow->addWidget(makeButton(buttonSpec(QString::fromUtf8("最小化功能区")), quick, true));
    quickRow->addWidget(makeButton({{"label", QString::fromUtf8("帮助")}, {"icon", "help"}}, quick, true));
    column->addWidget(quick);

    auto *ribbon = new QTabWidget(workspace);
    ribbon->setObjectName("Ribbon");
    ribbon->setFixedHeight(133);
    auto *file = makeButton(buttonSpec(QString::fromUtf8("文件")), ribbon);
    file->setToolButtonStyle(Qt::ToolButtonTextOnly);
    file->setObjectName("FileButton");
    ribbon->setCornerWidget(file, Qt::TopLeftCorner);
    connect(file, &QToolButton::clicked, this, [this] { pages_->setCurrentIndex(1); });
    for (const auto &value : catalog_.value("ribbons").toArray()) {
        const auto spec = value.toObject();
        ribbon->addTab(makeRibbon(spec), spec.value("label").toString());
    }
    column->addWidget(ribbon);

    auto *splitter = new QSplitter(Qt::Horizontal, workspace);
    splitter->setChildrenCollapsible(false);
    splitter->addWidget(makeNavigator());
    splitter->addWidget(makeComponentPage());
    splitter->setSizes({205, 955});
    splitter->setStretchFactor(1, 1);
    column->addWidget(splitter, 1);
    return workspace;
}

QWidget *UiShell::makeNavigator()
{
    auto *panel = new QWidget;
    panel->setMinimumWidth(160);
    auto *layout = new QVBoxLayout(panel);
    layout->setContentsMargins(3, 2, 2, 2);
    layout->setSpacing(3);
    auto *heading = new QHBoxLayout;
    heading->addWidget(new QLabel(QString::fromUtf8("物性"), panel), 1);
    heading->addWidget(makeButton({{"label", QString::fromUtf8("收起导航")}, {"icon", "back"}}, panel, true));
    layout->addLayout(heading);
    auto *filter = makeButton({{"label", QString::fromUtf8("所有项")}, {"menu", "navigation-filter"}}, panel);
    filter->setToolButtonStyle(Qt::ToolButtonTextOnly);
    filter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(filter);
    auto *tree = new QTreeWidget(panel);
    tree->setHeaderHidden(true);
    tree->setIndentation(16);
    for (const auto &value : catalog_.value("navigation").toArray()) {
        const auto node = value.toObject();
        auto *item = new QTreeWidgetItem(tree, {node.value("label").toString()});
        item->setIcon(0, aspenIcon("folder"));
        for (const auto &child : node.value("children").toArray()) {
            auto *childItem = new QTreeWidgetItem(item, {child.toString()});
            childItem->setIcon(0, aspenIcon("form-complete"));
            if (child.toString() == QString::fromUtf8("规定")) tree->setCurrentItem(childItem);
        }
        item->setExpanded(node.value("expanded").toBool());
    }
    layout->addWidget(tree, 1);
    for (const auto &value : catalog_.value("modes").toArray()) {
        auto *mode = makeButton(buttonSpec(value.toString()), panel);
        mode->setObjectName(value.toString() == QString::fromUtf8("物性") ? "ActiveMode" : "NavigationMode");
        mode->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        layout->addWidget(mode);
    }
    layout->addWidget(makeButton(buttonSpec(QString::fromUtf8("导航选项")), panel, true));
    return panel;
}

QWidget *UiShell::makeComponentPage()
{
    auto *page = new QWidget;
    page->setObjectName("ComponentPage");
    auto *column = new QVBoxLayout(page);
    column->setContentsMargins(6, 2, 6, 6);
    auto *titleRow = new QHBoxLayout;
    titleRow->addWidget(new QLabel(QString::fromUtf8("组分 - 规定"), page));
    titleRow->addWidget(makeButton(buttonSpec("×"), page));
    titleRow->addWidget(makeButton(buttonSpec("+"), page));
    titleRow->addStretch();
    // The document tab overflow was visible but not expanded during observation.
    titleRow->addWidget(makeButton(buttonSpec(QString::fromUtf8("所有选项卡")), page));
    column->addLayout(titleRow);
    auto *tabs = new QTabBar(page);
    for (const auto &value : catalog_.value("componentTabs").toArray()) tabs->addTab(value.toString());
    tabs->setExpanding(false);
    // These are observed tabs, but their contents are outside this menu-only pass.
    for (int i = 1; i < tabs->count(); ++i) tabs->setTabEnabled(i, false);
    column->addWidget(tabs);
    column->addSpacing(12);
    column->addWidget(new QLabel(QString::fromUtf8("选择组分"), page));
    const auto headers = catalog_.value("componentColumns").toArray();
    auto *table = new QTableWidget(1, static_cast<int>(headers.size()), page);
    QStringList labels;
    for (const auto &label : headers) labels << label.toString();
    table->setHorizontalHeaderLabels(labels);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setVerticalHeaderLabels({"*"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->setFixedHeight(62);
    column->addWidget(table);
    auto *buttons = new QHBoxLayout;
    for (const auto &value : catalog_.value("componentButtons").toArray()) {
        auto *button = makeButton(value.toObject(), page);
        button->setObjectName("FormButton");
        button->setToolButtonStyle(Qt::ToolButtonTextOnly);
        buttons->addWidget(button);
    }
    buttons->addStretch();
    auto *controls = new QWidget(page);
    controls->setLayout(buttons);
    auto *scroll = new QScrollArea(page);
    scroll->setWidget(controls);
    scroll->setWidgetResizable(true);
    scroll->setFixedHeight(58);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    column->addWidget(scroll);
    column->addStretch();
    return page;
}

QWidget *UiShell::makeFilePanel(const QJsonObject &entry)
{
    auto *panel = new QWidget;
    auto *layout = new QVBoxLayout(panel);
    layout->setContentsMargins(22, 26, 22, 16);
    auto *heading = new QLabel(entry.value("label").toString(), panel);
    heading->setObjectName("PanelHeading");
    layout->addWidget(heading);
    auto *row = new QHBoxLayout;
    for (const auto &value : entry.value("items").toArray()) {
        auto *button = makeButton(value.toObject(), panel);
        button->setObjectName("FileCommand");
        button->setToolButtonStyle(Qt::ToolButtonTextOnly);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        row->addWidget(button);
    }
    layout->addLayout(row);
    if (entry.value("id").toString() == "file-new") {
        auto *title = new QLabel(QString::fromUtf8("Aspen Plus模板"), panel);
        title->setObjectName("PanelHeading");
        layout->addWidget(title);
        auto *templateRow = new QHBoxLayout;
        auto *categories = new QTreeWidget(panel);
        categories->setHeaderLabel(QString::fromUtf8("类别"));
        categories->setRootIsDecorated(false);
        for (const auto &value : catalog_.value("templateCategories").toArray())
            new QTreeWidgetItem(categories, {value.toString()});
        categories->setMaximumWidth(220);
        templateRow->addWidget(categories);
        auto *templates = new QTreeWidget(panel);
        templates->setHeaderLabel(QString::fromUtf8("模板（英制）"));
        templates->setRootIsDecorated(false);
        for (const auto &value : catalog_.value("visibleTemplates").toArray())
            new QTreeWidgetItem(templates, {value.toString()});
        templateRow->addWidget(templates, 1);
        layout->addLayout(templateRow, 1);
    } else {
        layout->addStretch();
    }
    return panel;
}

QWidget *UiShell::makeFilePage()
{
    auto *page = new QWidget;
    page->setObjectName("FilePage");
    auto *row = new QHBoxLayout(page);
    row->setContentsMargins(0, 0, 0, 0);
    auto *rail = new QWidget(page);
    rail->setObjectName("FileRail");
    rail->setFixedWidth(125);
    auto *railLayout = new QVBoxLayout(rail);
    railLayout->setContentsMargins(0, 8, 0, 8);
    railLayout->setSpacing(2);
    auto *back = makeButton({{"label", QString::fromUtf8("返回")}, {"icon", "back"}}, rail);
    railLayout->addWidget(back);
    connect(back, &QToolButton::clicked, this, [this] { pages_->setCurrentIndex(0); });
    auto *panels = new QStackedWidget(page);
    for (const auto &value : catalog_.value("fileMenu").toArray()) {
        const auto entry = value.toObject();
        auto railSpec = entry;
        railSpec.remove("items");
        auto *button = makeButton(railSpec, rail);
        // Backstage rows switch visible command panels, rather than launch commands.
        button->setObjectName("FileEntry");
        button->setToolButtonStyle(Qt::ToolButtonTextOnly);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        railLayout->addWidget(button);
        if (!entry.value("items").toArray().isEmpty()) {
            const int index = panels->addWidget(makeFilePanel(entry));
            button->setCheckable(true);
            button->setAutoExclusive(true);
            button->setChecked(index == 0);
            connect(button, &QToolButton::clicked, panels, [panels, index] { panels->setCurrentIndex(index); });
        }
    }
    railLayout->addStretch();
    row->addWidget(rail);
    row->addWidget(panels, 1);
    return page;
}
