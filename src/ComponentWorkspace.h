#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QWidget>

class QStackedWidget;
class QTabWidget;
class QLabel;
class QMenu;
class QTableWidget;

class ComponentWorkspace final : public QWidget
{
    Q_OBJECT
public:
    explicit ComponentWorkspace(const QJsonObject &catalog, QWidget *parent = nullptr);
    bool showPage(const QString &id);
    QString currentPage() const;
    QTabWidget *currentTabs() const;
    QStringList pageIds() const;
    QJsonObject sessionState() const;
    void restoreSessionState(const QJsonObject &state);
    void setDatabaseComponents(const QJsonArray &components) { databaseComponents_=components; }
    void setGeneratedComponents(const QJsonArray &components) { generatedComponents_=components; }
    void setComponentOrder(const QJsonArray &order) { componentOrder_=order; }
    QString selectedComponentKey() const;
    void setUserComponents(const QJsonArray &objects);
    void setChemicalSummary(const QString &text);

signals:
    void inputsChanged();
    void pageChanged(const QString &id);
    void actionRequested(const QString &action);
    void componentTypeChanged(const QString &database,const QString &compoundId,const QString &type);

protected:
    bool eventFilter(QObject *watched,QEvent *event) override;

private:
    QJsonObject catalog_, defaults_;
    QJsonArray databaseComponents_,generatedComponents_,componentOrder_;
    QTableWidget *componentTable_=nullptr;
    QStackedWidget *stack_ = nullptr;
    QLabel *title_ = nullptr;
    QLabel *chemicalSummary_ = nullptr;
    QMap<QString, QWidget *> pages_;
    QMap<QString, QTabWidget *> tabs_;
    QMenu *pageMenu_ = nullptr;
    QWidget *makeContent(const QJsonObject &spec);
    QWidget *makeElement(const QJsonObject &spec);
    void dispatch(const QString &action);
    void showFindDialog();
};
