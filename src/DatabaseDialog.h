#pragma once
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
class PropertyDatabase;
class ProjectDocument;
class QLineEdit;
class QLabel;
class QTableWidget;
class QTextEdit;
class QPushButton;
class QListWidget;
class QButtonGroup;
class QEvent;

class DatabaseDialog final : public QDialog {
    Q_OBJECT
public:
    DatabaseDialog(PropertyDatabase *database,ProjectDocument *project,QWidget *parent=nullptr);
signals:
    void databaseChanged();
private:
    PropertyDatabase *database_;
    ProjectDocument *project_;
    QLineEdit *query_;
    QLabel *status_, *path_;
    QTableWidget *results_, *parameters_;
    QTextEdit *source_;
    QListWidget *selected_, *availableBanks_, *selectedBanks_;
    QButtonGroup *matchMode_;
    QDialog *details_, *selectionDialog_;
    QPushButton *add_, *detailsButton_, *remove_, *previous_, *next_;
    QJsonArray matches_, parameterRows_, allBanks_;
    QJsonObject detailCompound_;
    int offset_=0;
    void search();
    void clearResults();
    void clearDetails();
    void addSelection();
    void updateActions();
    void refreshDatabanks();
    void openDetails();
    bool eventFilter(QObject *watched,QEvent *event) override;
    void showParameters();
    void refreshSelection();
    void showSource();
};
