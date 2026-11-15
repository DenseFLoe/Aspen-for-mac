#include "DatabaseDialog.h"
#include "PropertyDatabase.h"
#include "ProjectDocument.h"
#include <QBoxLayout>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QHeaderView>
#include <QJsonDocument>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QSettings>
#include <QSignalBlocker>
#include <QSplitter>
#include <QTableWidget>
#include <QTextEdit>

namespace {
QTableWidget *table(const QString &name,const QStringList &headers,QWidget *parent) {
    auto *t=new QTableWidget(0,headers.size(),parent); t->setObjectName(name);t->setHorizontalHeaderLabels(headers);
    t->setEditTriggers(QAbstractItemView::NoEditTriggers);t->setSelectionBehavior(QAbstractItemView::SelectRows);t->setSelectionMode(QAbstractItemView::SingleSelection);
    t->verticalHeader()->hide();t->horizontalHeader()->setStretchLastSection(true);return t;
}
void row(QTableWidget *t,const QStringList &cells) {
    const int r=t->rowCount();t->insertRow(r);for(int c=0;c<cells.size();++c) t->setItem(r,c,new QTableWidgetItem(cells[c]));
}
}
DatabaseDialog::DatabaseDialog(PropertyDatabase *database,ProjectDocument *project,QWidget *parent)
    :QDialog(parent),database_(database),project_(project) {
    setObjectName("FindCompoundDialog");setWindowTitle(QString::fromUtf8("真实组分与物性数据库"));resize(1080,760);
    auto *layout=new QVBoxLayout(this);auto *location=new QHBoxLayout;
    path_=new QLabel(database_->isOpen()?database_->path():QString::fromUtf8("尚未选择运行数据库"),this);path_->setWordWrap(true);location->addWidget(path_,1);
    auto *choose=new QPushButton(QString::fromUtf8("选择数据库…"),this);choose->setObjectName("ChooseDatabase");location->addWidget(choose);layout->addLayout(location);
    auto *criteria=new QHBoxLayout;query_=new QLineEdit(this);query_->setObjectName("compound-query");query_->setPlaceholderText(QString::fromUtf8("名称、CAS、别名或同义词，例如 WATER / 7732-18-5"));criteria->addWidget(query_,1);
    auto *find=new QPushButton(QString::fromUtf8("查找"),this);find->setObjectName("SearchDatabase");criteria->addWidget(find);layout->addLayout(criteria);
    status_=new QLabel(this);status_->setObjectName("DatabaseQueryStatus");status_->setWordWrap(true);layout->addWidget(status_);
    auto *split=new QSplitter(Qt::Horizontal,this);auto *left=new QWidget(split);auto *leftLayout=new QVBoxLayout(left);leftLayout->setContentsMargins(0,0,0,0);
    results_=table("DatabaseResults",{QString::fromUtf8("名称"),QString::fromUtf8("别名"),"CAS",QString::fromUtf8("主库"),QString::fromUtf8("实体 ID")},left);leftLayout->addWidget(results_,1);
    add_=new QPushButton(QString::fromUtf8("将选中组分加入项目"),left);add_->setObjectName("AddDatabaseComponent");add_->setEnabled(false);leftLayout->addWidget(add_);
    auto *right=new QWidget(split);auto *rightLayout=new QVBoxLayout(right);rightLayout->setContentsMargins(0,0,0,0);rightLayout->addWidget(new QLabel(QString::fromUtf8("项目已选组分"),right));
    selected_=new QListWidget(right);selected_->setObjectName("SelectedDatabaseComponents");rightLayout->addWidget(selected_,1);
    auto *remove=new QPushButton(QString::fromUtf8("移除选中组分"),right);remove->setObjectName("RemoveDatabaseComponent");rightLayout->addWidget(remove);split->setStretchFactor(0,3);split->setStretchFactor(1,1);layout->addWidget(split,2);
    layout->addWidget(new QLabel(QString::fromUtf8("参数原始值（仅供查询，尚未验证计算适用性；无原始存值的条目不补零）"),this));
    parameters_=table("DatabaseParameters",{QString::fromUtf8("物性"),"cp_id",QString::fromUtf8("元素索引"),QString::fromUtf8("原始十进制值"),QString::fromUtf8("单位元数据"),QString::fromUtf8("子库"),"dbc_id"},this);
    parameters_->setColumnWidth(3,240);parameters_->setColumnWidth(4,170);
    results_->setColumnWidth(0,220);results_->setColumnWidth(2,120);layout->addWidget(parameters_,2);
    auto *paging=new QHBoxLayout;previous_=new QPushButton(QString::fromUtf8("上一页参数"),this);next_=new QPushButton(QString::fromUtf8("下一页参数"),this);previous_->setObjectName("PreviousDatabaseParameters");next_->setObjectName("NextDatabaseParameters");paging->addWidget(previous_);paging->addWidget(next_);paging->addStretch();layout->addLayout(paging);
    source_=new QTextEdit(this);source_->setObjectName("ParameterProvenance");source_->setReadOnly(true);source_->setMaximumHeight(150);source_->setPlaceholderText(QString::fromUtf8("选中参数查看文献、注释、单位和原始文件哈希。"));layout->addWidget(source_,1);
    auto *buttons=new QDialogButtonBox(QDialogButtonBox::Close,this);layout->addWidget(buttons);connect(buttons,&QDialogButtonBox::rejected,this,&QDialog::reject);
    connect(choose,&QPushButton::clicked,this,[this] {
        const auto path=QFileDialog::getOpenFileName(this,QString::fromUtf8("选择运行数据库"),database_->path(),"SQLite (*.sqlite)");if(path.isEmpty()) return;
        QString error;if(database_->open(path,&error)) {QSettings("AspenForMac","UIShell").setValue("databasePath",path);path_->setText(path);}
        else path_->setText(error);
        emit databaseChanged();search();
    });
    connect(find,&QPushButton::clicked,this,&DatabaseDialog::search);connect(query_,&QLineEdit::returnPressed,this,&DatabaseDialog::search);
    connect(results_,&QTableWidget::itemSelectionChanged,this,[this]{offset_=0;showParameters();});
    connect(parameters_,&QTableWidget::itemSelectionChanged,this,&DatabaseDialog::showSource);
    connect(previous_,&QPushButton::clicked,this,[this]{offset_=qMax(0,offset_-200);showParameters();});
    connect(next_,&QPushButton::clicked,this,[this]{offset_+=200;showParameters();});
    connect(add_,&QPushButton::clicked,this,[this] {
        const int r=results_->currentRow();if(r<0 || r>=matches_.size()) return;const auto c=matches_[r].toObject();
        auto state=project_->state();auto components=state.value("components").toArray();
        for(const auto &v:components) {const auto existing=v.toObject();if(existing.value("datasetId")!=c.value("datasetId")) {status_->setText(QString::fromUtf8("项目引用另一数据版本；请连接项目原版本后添加。"));return;}
            if(existing.value("database")==c.value("database") && existing.value("compoundId")==c.value("compoundId")) {status_->setText(QString::fromUtf8("该组分已在项目中。"));return;}}
        components.append(c);state["components"]=components;auto dependencies=state.value("dependencies").toObject();dependencies["propertyDatabase"]=database_->datasetId();state["dependencies"]=dependencies;project_->edit(state);status_->setText(QString::fromUtf8("已加入项目；可保存或撤销。"));
    });
    connect(remove,&QPushButton::clicked,this,[this] {const int r=selected_->currentRow();auto state=project_->state();auto c=state.value("components").toArray();if(r<0 || r>=c.size()) return;c.removeAt(r);state["components"]=c;if(c.isEmpty()) {auto d=state.value("dependencies").toObject();d.remove("propertyDatabase");state["dependencies"]=d;}project_->edit(state);});
    connect(project_,&ProjectDocument::changed,this,&DatabaseDialog::refreshSelection);
    refreshSelection();search();
}
void DatabaseDialog::refreshSelection() {
    selected_->clear();for(const auto &v:project_->state().value("components").toArray()) {const auto c=v.toObject();selected_->addItem(c.value("name").toString()+" ["+c.value("database").toString()+":"+c.value("compoundId").toString()+"]");}
}
void DatabaseDialog::search() {
    const QSignalBlocker blocker(results_); results_->setRowCount(0); QString error;matches_=database_->search(query_->text(),&error);
    const bool more=matches_.size()>100;if(more) matches_.removeLast();
    for(const auto &v:matches_) {const auto c=v.toObject();row(results_,{c.value("name").toString(),c.value("alias").toString(),c.value("cas").toString(),c.value("database").toString(),c.value("compoundId").toString()});}
    status_->setText(!error.isEmpty()?error:query_->text().trimmed().isEmpty()?QString::fromUtf8("请输入检索条件。数据库以只读方式打开。"):QString::fromUtf8("找到 %1 条%2。不同主库的同名记录保留独立身份。").arg(matches_.size()).arg(more?QString::fromUtf8("以上，显示前 100 条，请缩小条件"):QString()));
    offset_=0;if(!matches_.isEmpty()) results_->selectRow(0);showParameters();
}
void DatabaseDialog::showParameters() {
    const QSignalBlocker blocker(parameters_);parameters_->setRowCount(0);source_->clear();parameterRows_={};previous_->setEnabled(offset_>0);next_->setEnabled(false);
    const int r=results_->currentRow();add_->setEnabled(r>=0 && r<matches_.size() && database_->isOpen());if(!add_->isEnabled()) return;
    const auto c=matches_[r].toObject();QString error;parameterRows_=database_->parameters(c.value("database").toString(),c.value("compoundId").toString(),offset_,&error);
    if(!error.isEmpty()) {status_->setText(error);return;} next_->setEnabled(parameterRows_.size()>200);if(parameterRows_.size()>200) parameterRows_.removeLast();
    for(const auto &v:parameterRows_) {const auto p=v.toObject();QStringList units;
        for(const auto &u:p.value("units").toArray()) {const auto o=u.toObject();units<<o.value("type").toString()+": "+o.value("default_unit").toString();}
        row(parameters_,{p.value("property").toString(),QString::number(p.value("cpId").toInt()),p.value("elementIndex").isNull()?QString():QString::number(p.value("elementIndex").toInt()),p.value("valueText").isNull()?QString::fromUtf8("无原始数值"):p.value("valueText").toString(),units.isEmpty()?QString::fromUtf8("未提供单位"):units.join("; "),p.value("databank").toString(),p.value("referenceId").isNull()?QString():QString::number(p.value("referenceId").toInt())});}
}
void DatabaseDialog::showSource() {
    const int r=parameters_->currentRow(),c=results_->currentRow();if(r<0 || r>=parameterRows_.size() || c<0 || c>=matches_.size()) return;
    const auto parameter=parameterRows_[r].toObject();QString error;auto provenance=database_->provenance(matches_[c].toObject().value("database").toString(),parameter.value("referenceId").toInt(-1),&error);
    provenance["parameter"]=parameter;provenance["compound"]=matches_[c];source_->setPlainText(error.isEmpty()?QString::fromUtf8(QJsonDocument(provenance).toJson()):error);
}
