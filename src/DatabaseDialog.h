#pragma once
#include <QDialog>
#include <QJsonArray>
class PropertyDatabase;
class ProjectDocument;
class QLineEdit;
class QLabel;
class QTableWidget;
class QTextEdit;
class QPushButton;
class QListWidget;

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
    QListWidget *selected_;
    QPushButton *add_, *previous_, *next_;
    QJsonArray matches_, parameterRows_;
    int offset_=0;
    void search();
    void showParameters();
    void refreshSelection();
    void showSource();
};
