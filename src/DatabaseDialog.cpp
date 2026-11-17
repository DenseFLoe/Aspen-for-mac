#include "ChemicalSystem.h"
#include "DatabaseDialog.h"
#include <QMouseEvent>
#include "PropertyDatabase.h"
#include "ProjectDocument.h"
#include <QBoxLayout>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QJsonDocument>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMap>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSettings>
#include <QSignalBlocker>
#include <QTableWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <algorithm>
#include <QLocale>
#include <cmath>

namespace {
QTableWidget *table(const QString &name,const QStringList &headers,QWidget *parent) {
    auto *t=new QTableWidget(0,headers.size(),parent);t->setObjectName(name);t->setHorizontalHeaderLabels(headers);
    t->setEditTriggers(QAbstractItemView::NoEditTriggers);t->setSelectionBehavior(QAbstractItemView::SelectRows);t->setSelectionMode(QAbstractItemView::SingleSelection);
    t->verticalHeader()->hide();t->verticalHeader()->setDefaultSectionSize(22);t->horizontalHeader()->setStretchLastSection(true);return t;
}
void row(QTableWidget *t,const QStringList &cells) {
    const int r=t->rowCount();t->insertRow(r);for(int c=0;c<cells.size();++c)t->setItem(r,c,new QTableWidgetItem(cells[c]));
}
QPushButton *button(const QString &text,const QString &name,QWidget *parent) {
    auto *b=new QPushButton(text,parent);b->setObjectName(name);b->setProperty("formButton",true);b->setAutoDefault(false);return b;
}
bool sameCompound(const QJsonObject &a,const QJsonObject &b) {
    return a.value("database")==b.value("database") && a.value("compoundId")==b.value("compoundId") && a.value("datasetId")==b.value("datasetId");
}
double toKelvin(double value,const QString &unit) {
    if(unit=="C")return value+273.15;
    if(unit=="F")return (value-32)*5/9+273.15;
    return unit=="R"?value*5/9:value;
}
double fromKelvin(double value,const QString &unit) {
    if(unit=="C")return value-273.15;
    if(unit=="F")return (value-273.15)*9/5+32;
    return unit=="R"?value*9/5:value;
}
class SearchResultItem final : public QTableWidgetItem {
public:
    SearchResultItem(const QString &text,bool numeric):QTableWidgetItem(text),numeric_(numeric){}
    bool operator<(const QTableWidgetItem &other) const override {
        if(!numeric_)return QTableWidgetItem::operator<(other);
        if(text().isEmpty() || other.text().isEmpty())return !text().isEmpty() && other.text().isEmpty();
        return text().toDouble()<other.text().toDouble();
    }
private:
    bool numeric_;
};
}

DatabaseDialog::DatabaseDialog(PropertyDatabase *database,ProjectDocument *project,QWidget *parent)
    :QDialog(parent),database_(database),project_(project) {
    setObjectName("FindCompoundDialog");setWindowTitle(QString::fromUtf8("查找化合物"));resize(717,594);setMinimumSize(640,480);
    auto *layout=new QVBoxLayout(this);layout->setContentsMargins(10,10,10,10);layout->setSpacing(12);
    auto *tabs=new QTabWidget(this);tabs->setObjectName("FindCompoundTabs");layout->addWidget(tabs,1);
    auto *compounds=new QWidget(tabs);tabs->addTab(compounds,QString::fromUtf8("化合物"));
    auto *column=new QVBoxLayout(compounds);column->setContentsMargins(16,16,16,16);column->setSpacing(12);
    auto *top=new QHBoxLayout;top->setSpacing(8);column->addLayout(top);
    auto *criteria=new QGroupBox(QString::fromUtf8("搜索准则"),compounds);criteria->setObjectName("CompoundSearchCriteria");
    auto *grid=new QGridLayout(criteria);grid->setHorizontalSpacing(8);grid->setVerticalSpacing(5);
    auto *label=new QLabel(QString::fromUtf8("名称、别名或 CASRN："),criteria);grid->addWidget(label,0,0,3,1);
    matchMode_=new QButtonGroup(this);
    const QStringList modes{QString::fromUtf8("开头为"),QString::fromUtf8("包含"),QString::fromUtf8("等于")};
    const QStringList modeNames{"MatchStartsWith","MatchContains","MatchEquals"};
    for(int i=0;i<modes.size();++i) {auto *radio=new QRadioButton(modes[i],criteria);radio->setObjectName(modeNames[i]);matchMode_->addButton(radio,i);grid->addWidget(radio,i,1);if(i==1)radio->setChecked(true);}
    query_=new QLineEdit(criteria);query_->setObjectName("compound-query");query_->setAccessibleName(label->text());query_->setMinimumWidth(150);label->setBuddy(query_);grid->addWidget(query_,1,2,1,4);
    classes_=new QComboBox(criteria);classes_->setObjectName("CompoundClassFilter");classes_->addItem(QString::fromUtf8("全部"));
    grid->addWidget(new QLabel(QString::fromUtf8("化合物类："),criteria),3,0);grid->addWidget(classes_,3,1,1,4);
    for(int r=4;r<6;++r) {
        // The range rows have their own columns: they start to the left of the
        // name-matching radio buttons, as in the original search dialog.
        auto *range=new QWidget(criteria);auto *rangeLayout=new QHBoxLayout(range);rangeLayout->setContentsMargins(0,0,0,0);rangeLayout->setSpacing(7);
        auto *caption=new QLabel(r==4?QString::fromUtf8("分子量："):QString::fromUtf8("沸点："),range);caption->setFixedWidth(100);rangeLayout->addWidget(caption);
        rangeLayout->addWidget(new QLabel(QString::fromUtf8("从"),range));
        auto *from=new QLineEdit(criteria);auto *to=new QLineEdit(criteria);for(auto *field:{from,to})field->setFixedWidth(64);
        from->setAccessibleName(caption->text()+QString::fromUtf8("下限"));to->setAccessibleName(caption->text()+QString::fromUtf8("上限"));
        if(r==4){mwMin_=from;mwMax_=to;from->setObjectName("MolecularWeightMin");to->setObjectName("MolecularWeightMax");}
        else {bpMin_=from;bpMax_=to;from->setObjectName("BoilingPointMin");to->setObjectName("BoilingPointMax");}
        rangeLayout->addWidget(from);rangeLayout->addWidget(new QLabel(QString::fromUtf8("与"),range));rangeLayout->addWidget(to);
        if(r==5) {bpUnit_=new QComboBox(range);bpUnit_->setObjectName("BoilingPointUnit");bpUnit_->setAccessibleName(QString::fromUtf8("沸点单位"));bpUnit_->addItems({"F","K","C","R"});const auto units=project_->state().value("units").toString();bpUnit_->setCurrentText(units=="SI"?"K":units=="ENG"?"F":"C");bpUnit_->setFixedWidth(50);rangeLayout->addWidget(bpUnit_);}
        rangeLayout->addStretch();grid->addWidget(range,r,0,1,6);
    }
    top->addWidget(criteria);auto *commands=new QVBoxLayout;commands->setSpacing(7);commands->addSpacing(38);
    auto *find=button(QString::fromUtf8("立即查找"),"SearchDatabase",compounds);find->setDefault(true);commands->addWidget(find);
    auto *reset=button(QString::fromUtf8("新搜索"),"NewDatabaseSearch",compounds);commands->addWidget(reset);
    auto *help=button(QString::fromUtf8("帮助"),"DatabaseSearchHelp",compounds);commands->addWidget(help);commands->addStretch();top->addLayout(commands);top->addStretch();
    auto *found=new QGroupBox(QString::fromUtf8("找到与指定条件匹配的化合物"),compounds);auto *foundLayout=new QVBoxLayout(found);foundLayout->setContentsMargins(8,12,8,8);
    results_=table("DatabaseResults",{QString::fromUtf8("化合物名称"),QString::fromUtf8("别名"),QString::fromUtf8("数据库"),QString::fromUtf8("替换名称"),"MW","BP <C>",QString::fromUtf8("CAS 编号"),QString::fromUtf8("化合物类")},found);
    results_->setSelectionMode(QAbstractItemView::ExtendedSelection);results_->installEventFilter(this);results_->viewport()->installEventFilter(this);
    const QList<int> widths{125,80,78,85,44,58,90,82};for(int i=0;i<widths.size();++i)results_->setColumnWidth(i,widths[i]);
    foundLayout->addWidget(results_,1);auto *resultActions=new QHBoxLayout;
    add_=button(QString::fromUtf8("添加所选化合物"),"AddDatabaseComponent",found);resultActions->addWidget(add_);resultActions->addStretch();
    detailsButton_=button(QString::fromUtf8("物性数据…"),"ShowDatabaseParameters",found);resultActions->addWidget(detailsButton_);
    auto *manage=button(QString::fromUtf8("已选组分…"),"ManageDatabaseComponents",found);resultActions->addWidget(manage);foundLayout->addLayout(resultActions);column->addWidget(found,1);
    status_=new QLabel(compounds);status_->setObjectName("DatabaseQueryStatus");status_->setWordWrap(true);status_->setMinimumHeight(22);column->addWidget(status_);

    auto *banks=new QWidget(tabs);tabs->addTab(banks,QString::fromUtf8("数据库"));auto *banksLayout=new QVBoxLayout(banks);banksLayout->setContentsMargins(16,16,16,16);
    auto *bankGroup=new QGroupBox(QString::fromUtf8("纯组分数据库和搜索顺序"),banks);auto *bankGrid=new QGridLayout(bankGroup);
    bankGrid->addWidget(new QLabel(QString::fromUtf8("可用数据库："),bankGroup),0,0);bankGrid->addWidget(new QLabel(QString::fromUtf8("所选数据库："),bankGroup),0,2);
    availableBanks_=new QListWidget(bankGroup);availableBanks_->setObjectName("FindAvailableDatabanks");selectedBanks_=new QListWidget(bankGroup);selectedBanks_->setObjectName("FindSelectedDatabanks");
    for(auto *list:{availableBanks_,selectedBanks_}) {list->setMinimumSize(170,200);list->setSelectionMode(QAbstractItemView::ExtendedSelection);}
    bankGrid->addWidget(availableBanks_,1,0);bankGrid->addWidget(selectedBanks_,1,2);auto *moves=new QVBoxLayout;auto *order=new QVBoxLayout;moves->addStretch();order->addStretch();
    QList<QPushButton *> bankButtons;
    const QStringList bankLabels{">",">>","<","<<",QString::fromUtf8("▲"),QString::fromUtf8("▼")};
    const QStringList bankNames{"FindAddDatabank","FindAddAllDatabanks","FindRemoveDatabank","FindRemoveAllDatabanks","FindDatabankUp","FindDatabankDown"};
    for(int i=0;i<6;++i) {auto *b=button(bankLabels[i],bankNames[i],bankGroup);b->setFixedWidth(36);bankButtons<<b;(i<4?moves:order)->addWidget(b);}
    moves->addStretch();order->addStretch();bankGrid->addLayout(moves,1,1);bankGrid->addLayout(order,1,3);banksLayout->addWidget(bankGroup);
    auto *bankHint=new QLabel(QString::fromUtf8("仅在所选子库中检索；顺序用于排列检索结果。物性计算尚未接入。"),banks);bankHint->setWordWrap(true);banksLayout->addWidget(bankHint);
    path_=new QLabel(banks);path_->setObjectName("RuntimeDatabasePath");path_->setWordWrap(true);path_->setTextInteractionFlags(Qt::TextSelectableByMouse);banksLayout->addWidget(path_);
    auto *choose=button(QString::fromUtf8("选择本地数据库…"),"ChooseDatabase",banks);banksLayout->addWidget(choose,0,Qt::AlignLeft);banksLayout->addStretch();
    auto *pubchem=new QWidget(tabs);tabs->addTab(pubchem,"PubChem");tabs->setTabEnabled(2,false);tabs->setTabToolTip(2,QString::fromUtf8("尚未接入 PubChem 在线检索。"));
    // QTabWidget normally reserves the widest page, including hidden pages.
    // Ignore only inactive pages horizontally so the databank picker can use
    // the original compact width without clipping a page at larger font sizes.
    banks->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Preferred);pubchem->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Preferred);
    connect(tabs,&QTabWidget::currentChanged,this,[this,tabs,layout,previous=0,widths=QMap<int,int>{{0,717},{1,563},{2,717}}](int index) mutable {
        widths[previous]=width();previous=index;
        for(int i=0;i<tabs->count();++i){auto *page=tabs->widget(i);page->setSizePolicy(i==index?QSizePolicy::Preferred:QSizePolicy::Ignored,QSizePolicy::Preferred);page->updateGeometry();}
        setMinimumWidth(index==1?520:640);tabs->updateGeometry();layout->invalidate();layout->activate();
        resize(qMax(widths.value(index,717),minimumSizeHint().width()),height());
    });
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Close,this);buttons->button(QDialogButtonBox::Close)->setText(QString::fromUtf8("关闭"));buttons->button(QDialogButtonBox::Close)->setAutoDefault(false);layout->addWidget(buttons);connect(buttons,&QDialogButtonBox::rejected,this,&QDialog::reject);

    details_=new QDialog(this);details_->setObjectName("DatabaseParameterDialog");details_->setWindowTitle(QString::fromUtf8("纯组分物性数据"));details_->resize(1000,600);
    auto *detailLayout=new QVBoxLayout(details_);auto *notice=new QLabel(QString::fromUtf8("显示该组分全部来源的参数。原始值仅供查询，尚未验证计算适用性；缺失值不补零。"),details_);notice->setWordWrap(true);detailLayout->addWidget(notice);
    parameters_=table("DatabaseParameters",{QString::fromUtf8("物性"),"cp_id",QString::fromUtf8("元素索引"),QString::fromUtf8("原始十进制值"),QString::fromUtf8("单位元数据"),QString::fromUtf8("子库"),"dbc_id"},details_);
    parameters_->setColumnWidth(3,240);parameters_->setColumnWidth(4,170);detailLayout->addWidget(parameters_,2);
    auto *paging=new QHBoxLayout;previous_=button(QString::fromUtf8("上一页参数"),"PreviousDatabaseParameters",details_);next_=button(QString::fromUtf8("下一页参数"),"NextDatabaseParameters",details_);paging->addWidget(previous_);paging->addWidget(next_);paging->addStretch();detailLayout->addLayout(paging);
    source_=new QTextEdit(details_);source_->setObjectName("ParameterProvenance");source_->setReadOnly(true);source_->setPlaceholderText(QString::fromUtf8("选中参数查看文献、注释、单位和原始文件哈希。"));detailLayout->addWidget(source_,1);
    auto *detailClose=new QDialogButtonBox(QDialogButtonBox::Close,details_);detailLayout->addWidget(detailClose);connect(detailClose,&QDialogButtonBox::rejected,details_,&QDialog::reject);

    selectionDialog_=new QDialog(this);selectionDialog_->setObjectName("DatabaseSelectionDialog");selectionDialog_->setWindowTitle(QString::fromUtf8("已选组分"));selectionDialog_->resize(500,340);auto *selectionLayout=new QVBoxLayout(selectionDialog_);
    selected_=new QListWidget(selectionDialog_);selected_->setObjectName("SelectedDatabaseComponents");selected_->installEventFilter(this);selectionLayout->addWidget(selected_,1);
    remove_=button(QString::fromUtf8("移除选中组分"),"RemoveDatabaseComponent",selectionDialog_);selectionLayout->addWidget(remove_,0,Qt::AlignLeft);
    auto *selectionClose=new QDialogButtonBox(QDialogButtonBox::Close,selectionDialog_);selectionLayout->addWidget(selectionClose);connect(selectionClose,&QDialogButtonBox::rejected,selectionDialog_,&QDialog::reject);

    connect(find,&QPushButton::clicked,this,&DatabaseDialog::search);
    connect(query_,&QLineEdit::textChanged,this,&DatabaseDialog::clearResults);
    connect(matchMode_,&QButtonGroup::idClicked,this,&DatabaseDialog::clearResults);
    for(auto *field:{mwMin_,mwMax_,bpMin_,bpMax_})connect(field,&QLineEdit::textChanged,this,&DatabaseDialog::clearResults);
    connect(classes_,&QComboBox::currentIndexChanged,this,&DatabaseDialog::clearResults);
    connect(bpUnit_,&QComboBox::currentTextChanged,this,&DatabaseDialog::clearResults);
    connect(reset,&QPushButton::clicked,this,[this]{query_->clear();classes_->setCurrentIndex(0);for(auto *field:{mwMin_,mwMax_,bpMin_,bpMax_})field->clear();clearResults();query_->setFocus();});
    connect(help,&QPushButton::clicked,this,[this]{QMessageBox::information(this,QString::fromUtf8("查找化合物"),QString::fromUtf8("输入名称、别名或 CAS 号，或指定分子量、沸点范围与分类后查找。范围包含端点，允许只填一侧；缺少已核实数值的记录不匹配范围。\n双击选中结果或按 Enter 可添加当前多选组分；Ctrl / Shift 可多选。点击列标题可排序结果。\n数据库标签可选择检索子库，数值按所选子库顺序取首条有效参数。\n“物性数据”显示原始参数和来源，“已选组分”可移除项目中的组分。"));});
    connect(results_,&QTableWidget::itemSelectionChanged,this,&DatabaseDialog::updateActions);
    connect(results_,&QTableWidget::itemDoubleClicked,this,[this]{addSelection();});connect(add_,&QPushButton::clicked,this,&DatabaseDialog::addSelection);
    connect(results_->horizontalHeader(),&QHeaderView::sectionClicked,this,[this](int column){auto *header=results_->horizontalHeader();sortOrder_=sortColumn_==column && sortOrder_==Qt::AscendingOrder?Qt::DescendingOrder:Qt::AscendingOrder;sortColumn_=column;results_->sortItems(column,sortOrder_);header->setSortIndicator(column,sortOrder_);header->setSortIndicatorShown(true);});
    connect(detailsButton_,&QPushButton::clicked,this,&DatabaseDialog::openDetails);connect(manage,&QPushButton::clicked,selectionDialog_,&QDialog::open);
    connect(parameters_,&QTableWidget::itemSelectionChanged,this,&DatabaseDialog::showSource);
    connect(previous_,&QPushButton::clicked,this,[this]{offset_=qMax(0,offset_-200);showParameters();});connect(next_,&QPushButton::clicked,this,[this]{offset_+=200;showParameters();});
    connect(selected_,&QListWidget::currentRowChanged,this,&DatabaseDialog::updateActions);
    connect(remove_,&QPushButton::clicked,this,[this]{const int r=selected_->currentRow();auto state=project_->state();auto c=state.value("components").toArray();if(r<0 || r>=c.size())return;if(ChemicalSystem::componentReferenced(state,ChemicalSystem::databaseKey(c[r].toObject()))){status_->setText(QString::fromUtf8("该组分被化学系统引用，不能移除。"));return;}c.removeAt(r);state["components"]=c;if(c.isEmpty()){auto d=state.value("dependencies").toObject();d.remove("propertyDatabase");state["dependencies"]=d;}project_->edit(state);if(selected_->count())selected_->setCurrentRow(qMin(r,selected_->count()-1));});
    connect(project_,&ProjectDocument::changed,this,&DatabaseDialog::refreshSelection);
    connect(project_,&ProjectDocument::changed,this,&DatabaseDialog::syncDatabankSelection);
    auto updateBanks=[this,bankButtons]{bankButtons[0]->setEnabled(!availableBanks_->selectedItems().isEmpty());bankButtons[1]->setEnabled(availableBanks_->count()>0);bankButtons[2]->setEnabled(!selectedBanks_->selectedItems().isEmpty());bankButtons[3]->setEnabled(selectedBanks_->count()>0);bankButtons[4]->setEnabled(selectedBanks_->selectedItems().size()==1 && selectedBanks_->currentRow()>0);bankButtons[5]->setEnabled(selectedBanks_->selectedItems().size()==1 && selectedBanks_->currentRow()>=0 && selectedBanks_->currentRow()+1<selectedBanks_->count());};
    for(int i=0;i<4;++i)connect(bankButtons[i],&QPushButton::clicked,this,[this,i,updateBanks]{auto *from=i<2?availableBanks_:selectedBanks_;auto *to=i<2?selectedBanks_:availableBanks_;auto items=from->selectedItems();if(i%2){items.clear();for(int r=0;r<from->count();++r)items<<from->item(r);}for(auto *item:items)to->addItem(from->takeItem(from->row(item)));saveDatabankSelection();clearResults();updateBanks();});
    for(int i=4;i<6;++i)connect(bankButtons[i],&QPushButton::clicked,this,[this,i,updateBanks]{const int r=selectedBanks_->currentRow(),target=r+(i==4?-1:1);if(r<0 || target<0 || target>=selectedBanks_->count())return;auto *item=selectedBanks_->takeItem(r);selectedBanks_->insertItem(target,item);selectedBanks_->setCurrentRow(target);saveDatabankSelection();clearResults();updateBanks();});
    connect(availableBanks_,&QListWidget::itemSelectionChanged,this,updateBanks);connect(selectedBanks_,&QListWidget::itemSelectionChanged,this,updateBanks);
    connect(choose,&QPushButton::clicked,this,[this,updateBanks]{const auto path=QFileDialog::getOpenFileName(this,QString::fromUtf8("选择本地数据库"),database_->path(),"SQLite (*.sqlite)");if(path.isEmpty())return;QString error;PropertyDatabase probe;if(!probe.open(path,&error)){QMessageBox::warning(this,QString::fromUtf8("无法打开数据库"),error);return;}if(!database_->open(path,&error)){QMessageBox::warning(this,QString::fromUtf8("无法打开数据库"),error);return;}QSettings("AspenForMac","UIShell").setValue("databasePath",path);refreshDatabanks();clearResults();updateBanks();emit databaseChanged();});
    refreshDatabanks();refreshSelection();clearResults();updateBanks();query_->setFocus();
}

void DatabaseDialog::refreshDatabanks() {
    availableBanks_->clear();selectedBanks_->clear();QString error;allBanks_=database_->databanks(&error);
    const QStringList defaults{"APV150 PURE41","APV150 AQUEOUS","APV150 SOLIDS","APV150 INORGANIC","APESV150 AP-EOS","NISTV150 NIST-TRC"};
    QMap<QString,QJsonObject> defaultBanks;
    for(const auto &v:allBanks_){const auto b=v.toObject();const auto label=b.value("database").toString()+" "+b.value("name").toString();if(defaults.contains(label))defaultBanks[label]=b;}
    auto appendBank=[](QListWidget *list,const QJsonObject &b){auto *item=new QListWidgetItem(b.value("database").toString()+" "+b.value("name").toString(),list);item->setData(Qt::UserRole,b);};
    for(const auto &label:defaults)if(defaultBanks.contains(label))appendBank(selectedBanks_,defaultBanks[label]);
    for(const auto &v:allBanks_){const auto b=v.toObject();const auto label=b.value("database").toString()+" "+b.value("name").toString();if(defaultBanks.contains(label))continue;appendBank(defaultBanks.isEmpty()?selectedBanks_:availableBanks_,b);}
    defaultBanks_=bankSelection();syncDatabankSelection();
    path_->setText(database_->isOpen()?QString::fromUtf8("本地数据库：%1").arg(database_->path()):QString::fromUtf8("尚未选择本地数据库。"));
    if(!error.isEmpty())path_->setToolTip(error);
    const QSignalBlocker blocked(classes_);classes_->clear();classes_->addItem(QString::fromUtf8("全部"));classes_->addItems(database_->compoundClasses(&error));
    const bool filters=database_->supportsCompoundFilters();classes_->setEnabled(filters && classes_->count()>1);
    const auto hint=filters?QString():QString::fromUtf8("此运行库缺少范围和分类索引，请用更新后的构建工具在新目录生成运行库。");
    classes_->setToolTip(error.isEmpty()?hint:error);
    for(auto *field:{mwMin_,mwMax_,bpMin_,bpMax_}){field->clear();field->setEnabled(filters);field->setToolTip(hint);}
    bpUnit_->setEnabled(filters);
}
QJsonArray DatabaseDialog::bankSelection() const {
    QJsonArray result;for(int i=0;i<selectedBanks_->count();++i){const auto bank=selectedBanks_->item(i)->data(Qt::UserRole).toJsonObject();result.append(QJsonObject{{"database",bank.value("database")},{"bankId",bank.value("bankId")}});}return result;
}
void DatabaseDialog::saveDatabankSelection() {
    if(!database_->isOpen())return;
    auto state=project_->state();state["compoundSearch"]=QJsonObject{{"datasetId",database_->datasetId()},{"databanks",bankSelection()}};project_->edit(state);
}
void DatabaseDialog::syncDatabankSelection() {
    if(!database_->isOpen())return;
    const auto preferences=project_->state().value("compoundSearch").toObject();
    if(!preferences.isEmpty() && preferences.value("datasetId")!=database_->datasetId())return;
    const auto desired=preferences.isEmpty()?defaultBanks_:preferences.value("databanks").toArray();
    if(desired==bankSelection())return;
    availableBanks_->clear();selectedBanks_->clear();
    QJsonArray used;
    auto append=[](QListWidget *list,const QJsonObject &bank){auto *item=new QListWidgetItem(bank.value("database").toString()+" "+bank.value("name").toString(),list);item->setData(Qt::UserRole,bank);};
    for(const auto &v:desired)for(const auto &candidate:allBanks_){const auto bank=candidate.toObject(),id=v.toObject();if(bank.value("database")==id.value("database") && bank.value("bankId")==id.value("bankId")){append(selectedBanks_,bank);used.append(candidate);break;}}
    for(const auto &bank:allBanks_)if(!used.contains(bank))append(availableBanks_,bank.toObject());
    clearResults();
}
QJsonObject DatabaseDialog::resultAt(int row) const {
    const auto *item=results_->item(row,0);return item?item->data(Qt::UserRole).toJsonObject():QJsonObject{};
}
void DatabaseDialog::clearResults() {
    clearDetails();
    const QSignalBlocker blocked(results_);results_->setRowCount(0);matches_={};
    status_->setText(database_->isOpen()?QString::fromUtf8("输入搜索准则，然后单击“立即查找”。"):QString::fromUtf8("尚未连接本地数据库，请在“数据库”标签中选择。"));updateActions();
}
void DatabaseDialog::search() {
    clearDetails();
    const QSignalBlocker blocked(results_);results_->setRowCount(0);PropertyDatabase::SearchOptions options;
    options.mode=matchMode_->checkedId()==0?PropertyDatabase::MatchMode::StartsWith:matchMode_->checkedId()==2?PropertyDatabase::MatchMode::Equals:PropertyDatabase::MatchMode::Contains;
    options.restrictDatabanks=!allBanks_.isEmpty();
    for(int i=0;i<selectedBanks_->count();++i)options.databanks.append(selectedBanks_->item(i)->data(Qt::UserRole).toJsonObject());
    QString error;matches_={};
    const QList<QPair<QLineEdit *,std::optional<double> *>> fields{{mwMin_,&options.molecularWeightMin},{mwMax_,&options.molecularWeightMax},{bpMin_,&options.boilingPointMinK},{bpMax_,&options.boilingPointMaxK}};
    for(const auto &field:fields)if(field.first->isEnabled() && !field.first->text().trimmed().isEmpty()) {
        bool ok=false;auto value=QLocale().toDouble(field.first->text().trimmed(),&ok);
        if(!ok || !std::isfinite(value)){status_->setText(field.first->accessibleName()+QString::fromUtf8("必须为有效数值。"));field.first->setFocus();updateActions();return;}
        if(field.first==bpMin_ || field.first==bpMax_)value=toKelvin(value,bpUnit_->currentText());
        *field.second=value;
    }
    if(classes_->isEnabled() && classes_->currentIndex()>0)options.compoundClass=classes_->currentText();
    matches_=database_->search(query_->text(),&error,options);const bool more=matches_.size()>100;if(more)matches_.removeLast();
    results_->horizontalHeaderItem(5)->setText("BP <"+bpUnit_->currentText()+">");sortColumn_=-1;results_->horizontalHeader()->setSortIndicatorShown(false);results_->horizontalHeader()->setSortIndicator(-1,Qt::AscendingOrder);
    for(const auto &v:matches_){const auto c=v.toObject();const auto bp=c.value("boilingPointK");const QStringList cells{c.value("name").toString(),c.value("alias").toString(),c.value("database").toString(),{},c.value("molecularWeight").toString(),bp.isString()?QString::number(fromKelvin(bp.toString().toDouble(),bpUnit_->currentText()),'g',12):QString(),c.value("cas").toString(),c.value("compoundClass").toString()};const int r=results_->rowCount();results_->insertRow(r);for(int col=0;col<cells.size();++col)results_->setItem(r,col,new SearchResultItem(cells[col],col==4 || col==5));results_->item(r,0)->setData(Qt::UserRole,c);results_->item(r,0)->setToolTip(c.value("database").toString()+":"+c.value("compoundId").toString());}
    const bool criteria=!query_->text().trimmed().isEmpty() || options.molecularWeightMin || options.molecularWeightMax || options.boilingPointMinK || options.boilingPointMaxK || !options.compoundClass.isEmpty();
    status_->setText(!error.isEmpty()?error:!criteria?QString::fromUtf8("请输入检索条件。"):selectedBanks_->count()==0 && !allBanks_.isEmpty()?QString::fromUtf8("请在“数据库”标签中选择至少一个子库。"):QString::fromUtf8("找到 %1 条%2").arg(matches_.size()).arg(more?QString::fromUtf8("以上，显示前 100 条；请缩小搜索范围。"):QString::fromUtf8("。")));
    if(!matches_.isEmpty())results_->selectRow(0);updateActions();
}
void DatabaseDialog::clearDetails() {
    details_->reject();const QSignalBlocker blocked(parameters_);parameters_->setRowCount(0);source_->clear();parameterRows_={};detailCompound_={};offset_=0;previous_->setEnabled(false);next_->setEnabled(false);
}
void DatabaseDialog::updateActions() {
    bool canAdd=false;const auto components=project_->state().value("components").toArray();
    const auto dependency=project_->state().value("dependencies").toObject().value("propertyDatabase").toString();
    const bool compatible=dependency.isEmpty() || dependency==database_->datasetId();
    for(const auto &index:results_->selectionModel()->selectedRows()){const auto c=resultAt(index.row());if(c.isEmpty())continue;bool exists=false;for(const auto &v:components)if(sameCompound(c,v.toObject())){exists=true;break;}canAdd|=!exists;}
    add_->setEnabled(database_->isOpen() && compatible && canAdd);add_->setToolTip(!compatible?QString::fromUtf8("项目引用另一数据版本，请连接项目原版本后添加。"):QString());
    detailsButton_->setEnabled(database_->isOpen() && results_->currentRow()>=0 && results_->currentRow()<matches_.size());remove_->setEnabled(selected_->currentRow()>=0);
}
void DatabaseDialog::addSelection() {
    // Validate against the document, not a possibly stale button state during
    // native double-click delivery (notably the Cocoa item-view path).
    updateActions();
    if(!add_->isEnabled())return;auto state=project_->state();auto components=state.value("components").toArray();int added=0;
    auto indexes=results_->selectionModel()->selectedRows();std::sort(indexes.begin(),indexes.end(),[](const auto &a,const auto &b){return a.row()<b.row();});
    for(const auto &index:indexes){auto c=resultAt(index.row());if(c.isEmpty())continue;bool exists=false;for(const auto &v:components)if(sameCompound(c,v.toObject())){exists=true;break;}if(!exists){c.remove("molecularWeight");c.remove("boilingPointK");c.remove("compoundClass");components.append(c);++added;}}
    if(!added)return;state["components"]=components;auto dependencies=state.value("dependencies").toObject();dependencies["propertyDatabase"]=database_->datasetId();state["dependencies"]=dependencies;project_->edit(state);status_->setText(QString::fromUtf8("已添加 %1 个组分。").arg(added));
}
void DatabaseDialog::refreshSelection() {
    const int old=selected_->currentRow();const QSignalBlocker blocked(selected_);selected_->clear();for(const auto &v:project_->state().value("components").toArray()){const auto c=v.toObject();auto *item=new QListWidgetItem(c.value("name").toString()+"  ["+c.value("database").toString()+"]",selected_);item->setToolTip(c.value("database").toString()+":"+c.value("compoundId").toString());}if(old>=0 && selected_->count())selected_->setCurrentRow(qMin(old,selected_->count()-1));updateActions();
}
void DatabaseDialog::openDetails() {
    detailCompound_=resultAt(results_->currentRow());if(detailCompound_.isEmpty())return;offset_=0;details_->setWindowTitle(detailCompound_.value("name").toString()+QString::fromUtf8(" — 纯组分物性数据"));showParameters();details_->open();
}
void DatabaseDialog::showParameters() {
    const QSignalBlocker blocked(parameters_);parameters_->setRowCount(0);source_->clear();parameterRows_={};previous_->setEnabled(offset_>0);next_->setEnabled(false);
    QString error;parameterRows_=database_->parameters(detailCompound_.value("database").toString(),detailCompound_.value("compoundId").toString(),offset_,&error);
    if(!error.isEmpty()){source_->setPlainText(error);return;}next_->setEnabled(parameterRows_.size()>200);if(parameterRows_.size()>200)parameterRows_.removeLast();
    for(const auto &v:parameterRows_){const auto p=v.toObject();QStringList units;for(const auto &u:p.value("units").toArray()){const auto o=u.toObject();units<<o.value("type").toString()+": "+o.value("default_unit").toString();}row(parameters_,{p.value("property").toString(),QString::number(p.value("cpId").toInt()),p.value("elementIndex").isNull()?QString():QString::number(p.value("elementIndex").toInt()),p.value("valueText").isNull()?QString::fromUtf8("无原始数值"):p.value("valueText").toString(),units.isEmpty()?QString::fromUtf8("未提供单位"):units.join("; "),p.value("databank").toString(),p.value("referenceId").isNull()?QString():QString::number(p.value("referenceId").toInt())});}
}
void DatabaseDialog::showSource() {
    const int r=parameters_->currentRow();if(r<0 || r>=parameterRows_.size()){source_->clear();return;}const auto parameter=parameterRows_[r].toObject();QString error;auto provenance=database_->provenance(detailCompound_.value("database").toString(),parameter.value("referenceId").toInt(-1),&error);provenance["parameter"]=parameter;provenance["compound"]=detailCompound_;source_->setPlainText(error.isEmpty()?QString::fromUtf8(QJsonDocument(provenance).toJson()):error);
}
bool DatabaseDialog::eventFilter(QObject *watched,QEvent *event) {
    if(watched==results_->viewport() && event->type()==QEvent::MouseButtonDblClick) {
        auto *mouse=static_cast<QMouseEvent *>(event);
        if(mouse->button()==Qt::LeftButton) {
            const auto index=results_->indexAt(mouse->position().toPoint());
            if(index.isValid()) {if(!results_->selectionModel()->isRowSelected(index.row(),{}))results_->selectRow(index.row());addSelection();return true;}
        }
    }
    if(watched==selected_ && event->type()==QEvent::KeyPress && static_cast<QKeyEvent *>(event)->key()==Qt::Key_Delete){remove_->click();return true;}
    if(watched==results_ && event->type()==QEvent::KeyPress){auto *key=static_cast<QKeyEvent *>(event);if(key->key()==Qt::Key_Return || key->key()==Qt::Key_Enter){addSelection();return true;}}
    return QDialog::eventFilter(watched,event);
}
