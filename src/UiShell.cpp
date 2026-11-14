#include "UiShell.h"
#include "IconCatalog.h"
#include "ComponentWorkspace.h"
#include "RecoveredWorkspace.h"
#include <QFile>
#include <QJsonDocument>
#include <QSignalBlocker>
#include <functional>
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
#include <QPixmap>
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
#include <QTreeWidgetItemIterator>

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
    resize(1101, 650);
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

bool UiShell::openRecovered(const QString &name)
{
    if (!recovered_) return false;
    for (const auto &value:recovered_->catalog().value("pages").toArray()) {
        const auto page=value.toObject();
        if (page.value("name").toString()!=name) continue;
        if (!recovered_->showPage(page.value("id").toString())) return false;
        documents_->setCurrentIndex(1); return true;
    }
    return false;
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
    if (iconOnly) {
        button->setFixedSize(23, 23);
        if (icon.isNull()) { button->setText({}); button->setArrowType(Qt::DownArrow); }
    }
    if (large) { button->setMinimumHeight(65); button->setProperty("largeRibbon", true); }
    else button->setMaximumHeight(24);
    const auto id = spec.value("id").toString();
    const QMap<QString,QString> staticTargets{{"setup","MMSetup_Setup"},{"methods","MMProp_Spec_Input"},{"property-sets","MMPropSets_Input"}};
    if (staticTargets.contains(id)) connect(button,&QToolButton::clicked,this,[this,target=staticTargets[id]] { openRecovered(target); });
    if (id == "components") connect(button, &QToolButton::clicked, this, [this] {
        if (components_) { documents_->setCurrentIndex(0); components_->showPage("specifications"); }
    });
    if (id == "draw-structure") connect(button, &QToolButton::clicked, this, [this] {
        if (components_) { documents_->setCurrentIndex(0); components_->showPage("molecular-structure"); }
    });
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
        QToolButton *corner = nullptr;
        for (const auto &item : group.value("controls").toArray()) {
            const auto spec = item.toObject();
            auto *button = makeButton(spec, frame);
            QFont ribbonFont = button->font();
            ribbonFont.setPixelSize(11);
            button->setFont(ribbonFont);
            if (spec.value("id").toString() == "run-settings") {
                corner = button;
                corner->setText("↘");
                corner->setToolButtonStyle(Qt::ToolButtonTextOnly);
                corner->setFixedSize(13, 13);
                continue;
            }
            int textWidth = 0;
            for (const auto &lineText : button->text().split('\n'))
                textWidth = qMax(textWidth, button->fontMetrics().horizontalAdvance(lineText));
            const int iconWidth = button->icon().isNull() ? 0 : button->iconSize().width();
            const int width = spec.value("large").toBool() ? qMax(iconWidth, textWidth) + 10
                : textWidth + iconWidth + (iconWidth ? 5 : 0) + 8;
            button->setFixedWidth(width + (button->menu() ? 10 : 0));
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
        auto *caption = new QHBoxLayout;
        caption->setContentsMargins(0, 0, 0, 0);
        caption->addWidget(title, 1);
        if (corner) caption->addWidget(corner);
        vertical->addLayout(caption);
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
    column->setSpacing(0);
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
    quickRow->addWidget(makeButton({{"label", QString::fromUtf8("搜索")}, {"icon", "search"}}, quick, true));
    quickRow->addWidget(makeButton(buttonSpec(QString::fromUtf8("最小化功能区")), quick, true));
    quickRow->addWidget(makeButton({{"label", QString::fromUtf8("帮助")}, {"icon", "quick-help"}}, quick, true));
    column->addWidget(quick);

    auto *ribbon = new QTabWidget(workspace);
    ribbon->setObjectName("Ribbon");
    ribbon->setFixedHeight(122);
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
    auto *componentPage = makeComponentPage();
    splitter->addWidget(makeNavigator());
    splitter->addWidget(componentPage);
    splitter->setSizes({198, 900});
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
    navigation_ = new QTreeWidget(panel);
    navigation_->setObjectName("PropertiesNavigation");
    navigation_->setHeaderHidden(true);
    navigation_->setIndentation(16);
    navigation_->setIconSize(QSize(16, 16));
    QFile file(":/ui/components.json");
    file.open(QIODevice::ReadOnly);
    const auto componentCatalog = QJsonDocument::fromJson(file.readAll()).object();
    QTreeWidgetItem *initial = nullptr;
    std::function<void(const QJsonArray &, QTreeWidgetItem *)> addNodes;
    addNodes = [this, &addNodes, &initial](const QJsonArray &nodes, QTreeWidgetItem *parent) {
        for (const auto &value : nodes) {
            const auto node = value.toObject();
            auto *item = new QTreeWidgetItem(parent, {node.value("label").toString()});
            item->setIcon(0, aspenIcon(node.value("icon").toString("folder")));
            item->setData(0, Qt::UserRole, node.value("page").toString());
            if (node.value("page").toString() == "specifications") initial = item;
            addNodes(node.value("children").toArray(), item);
        }
    };
    for (const auto &value : catalog_.value("navigation").toArray()) {
        const auto node = value.toObject();
        auto *item = new QTreeWidgetItem(navigation_, {node.value("label").toString()});
        const bool components = node.value("label").toString() == QString::fromUtf8("组分");
        item->setIcon(0, aspenIcon(components ? "folder-incomplete" : "folder"));
        if (components) {
            item->setData(0, Qt::UserRole, "specifications");
            addNodes(componentCatalog.value("navigation").toArray(), item);
            item->setExpanded(true);
        } else {
            item->setToolTip(0, QString::fromUtf8("更多静态页面见“全部资源”"));
            const QMap<QString,QString> targets{{QString::fromUtf8("设置"),"MMSetup_Setup"},{QString::fromUtf8("方法"),"MMProp_Spec_Input"},{QString::fromUtf8("物性组"),"MMPropSets_Input"}};
            item->setData(0,Qt::UserRole+2,targets.value(node.value("label").toString()));
        }
    }
    navigation_->setCurrentItem(initial);
    connect(navigation_, &QTreeWidget::currentItemChanged, this, [this](QTreeWidgetItem *item) {
        if (!item || !components_) return;
        const auto id = item->data(0, Qt::UserRole).toString();
        if (!item->data(0,Qt::UserRole+2).toString().isEmpty()) openRecovered(item->data(0,Qt::UserRole+2).toString());
        if (!id.isEmpty()) { documents_->setCurrentIndex(0); components_->showPage(id); }
    });
    connect(navigation_, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item) {
        if (!item->data(0,Qt::UserRole+2).toString().isEmpty()) openRecovered(item->data(0,Qt::UserRole+2).toString());
        if (components_ && !item->data(0, Qt::UserRole).toString().isEmpty()) {
            documents_->setCurrentIndex(0); components_->showPage(item->data(0, Qt::UserRole).toString());
        }
    });
    connect(components_, &ComponentWorkspace::pageChanged, this, [this](const QString &id) {
        const QSignalBlocker blocker(navigation_);
        for (QTreeWidgetItemIterator it(navigation_); *it; ++it) {
            if ((*it)->parent() && (*it)->data(0, Qt::UserRole).toString() == id) {
                navigation_->setCurrentItem(*it);
                navigation_->scrollToItem(*it);
                break;
            }
        }
    });
    auto *navTabs = new QTabWidget(panel);
    navTabs->setObjectName("NavigationTabs");
    navTabs->addTab(navigation_, QString::fromUtf8("已核对"));
    auto *recoveryPanel = new QWidget(navTabs);
    auto *recoveryLayout = new QVBoxLayout(recoveryPanel);
    recoveryLayout->setContentsMargins(0,0,0,0);
    auto *query = new QLineEdit(recoveryPanel);
    query->setObjectName("RecoverySearch");
    query->setPlaceholderText(QString::fromUtf8("搜索页面、按钮、菜单"));
    recoveryLayout->addWidget(query);
    auto *tree = new QTreeWidget(recoveryPanel);
    tree->setObjectName("RecoveredNavigation"); tree->setHeaderHidden(true); tree->setIndentation(12);
    QMap<QString,QTreeWidgetItem *> modules;
    for (const auto &v : recovered_->catalog().value("modules").toArray()) {
        const auto m=v.toObject();
        auto *item = new QTreeWidgetItem(tree,{m.value("label").toString()});
        item->setToolTip(0,m.value("id").toString()); modules[m.value("id").toString()]=item;
    }
    for (const auto &v : recovered_->catalog().value("pages").toArray()) {
        const auto p=v.toObject(); auto *parent=modules.value(p.value("module").toString());
        if (!parent) continue;
        auto *item=new QTreeWidgetItem(parent,{p.value("title").toString()});
        item->setData(0,Qt::UserRole,p.value("id").toString());
        item->setData(0,Qt::UserRole+1,p.value("search").toString()+" "+p.value("name").toString());
        item->setToolTip(0,p.value("name").toString()+"\n"+p.value("source").toObject().value("resource").toString());
    }
    for (const auto &pair : {qMakePair(QString("dialog:"),recovered_->nativeDialogs()),qMakePair(QString("menu:"),recovered_->menuCatalog())}) {
        auto *group = new QTreeWidgetItem(tree,{pair.first=="dialog:"?QString::fromUtf8("传统对话框"):QString::fromUtf8("菜单")});
        QMap<QString,QTreeWidgetItem *> files;
        for (int i=0;i<pair.second.size();++i) {
            const auto p=pair.second[i].toObject(); const auto source=p.value("file").toString().section('/',-1);
            if (!files.contains(source)) files[source]=new QTreeWidgetItem(group,{source});
            auto title=p.value("title").toString();
            if (title.isEmpty()) title=p.value("resource").toString();
            auto *item=new QTreeWidgetItem(files[source],{title+" ["+QString::number(p.value("language").toInt())+"]"});
            item->setData(0,Qt::UserRole,pair.first+QString::number(i));
            item->setData(0,Qt::UserRole+1,QString::fromUtf8(QJsonDocument(p).toJson(QJsonDocument::Compact)));
        }
    }
    auto openRecovered = [this](QTreeWidgetItem *item) {
        if (item && recovered_->showPage(item->data(0,Qt::UserRole).toString())) documents_->setCurrentIndex(1);
    };
    connect(tree,&QTreeWidget::currentItemChanged,this,[openRecovered](QTreeWidgetItem *item) { openRecovered(item); });
    connect(tree,&QTreeWidget::itemClicked,this,openRecovered);
    connect(query,&QLineEdit::textChanged,tree,[tree](const QString &text) {
        std::function<bool(QTreeWidgetItem *)> filter;
        filter=[&](QTreeWidgetItem *item) {
            bool found=item->text(0).contains(text,Qt::CaseInsensitive)||item->data(0,Qt::UserRole+1).toString().contains(text,Qt::CaseInsensitive);
            for (int i=0;i<item->childCount();++i) found=filter(item->child(i))||found;
            item->setHidden(!found); if (item->childCount()) item->setExpanded(!text.isEmpty()&&found); return found;
        };
        for (int i=0;i<tree->topLevelItemCount();++i) filter(tree->topLevelItem(i));
    });
    recoveryLayout->addWidget(tree,1);
    navTabs->addTab(recoveryPanel,QString::fromUtf8("全部资源"));
    layout->addWidget(navTabs, 1);
    for (const auto &value : catalog_.value("modes").toArray()) {
        auto *mode = makeButton(buttonSpec(value.toString()), panel);
        mode->setObjectName(value.toString() == QString::fromUtf8("物性") ? "ActiveMode" : "NavigationMode");
        mode->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        const QStringList modeIcons{"mode-properties", "mode-simulation", "mode-safety", "mode-energy"};
        const QStringList modeLabels{QString::fromUtf8("物性"), QString::fromUtf8("模拟"), QString::fromUtf8("安全分析"), QString::fromUtf8("能量分析")};
        const int modeIndex = modeLabels.indexOf(value.toString());
        mode->setIcon(aspenIcon(modeIcons.value(modeIndex)));
        mode->setIconSize(QSize(24, 24));
        mode->setMinimumHeight(34);
        mode->setMaximumHeight(34);
        layout->addWidget(mode);
    }
    layout->addWidget(makeButton(buttonSpec(QString::fromUtf8("导航选项")), panel, true));
    return panel;
}

QWidget *UiShell::makeComponentPage()
{
    QFile file(":/ui/components.json");
    file.open(QIODevice::ReadOnly);
    components_ = new ComponentWorkspace(QJsonDocument::fromJson(file.readAll()).object());
    documents_=new QStackedWidget;
    documents_->addWidget(components_);
    recovered_=new RecoveredWorkspace;
    documents_->addWidget(recovered_);
    return documents_;
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
