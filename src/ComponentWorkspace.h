#pragma once
#include <QJsonObject>
#include <QMap>
#include <QWidget>

class QStackedWidget;
class QTabWidget;
class QLabel;
class QMenu;

class ComponentWorkspace final : public QWidget
{
    Q_OBJECT
public:
    explicit ComponentWorkspace(const QJsonObject &catalog, QWidget *parent = nullptr);
    bool showPage(const QString &id);
    QString currentPage() const;
    QTabWidget *currentTabs() const;
    QStringList pageIds() const;
    void setUserComponents(const QJsonArray &objects);

signals:
    void pageChanged(const QString &id);
    void actionRequested(const QString &action);

private:
    QJsonObject catalog_;
    QStackedWidget *stack_ = nullptr;
    QLabel *title_ = nullptr;
    QMap<QString, QWidget *> pages_;
    QMap<QString, QTabWidget *> tabs_;
    QMenu *pageMenu_ = nullptr;
    QWidget *makeContent(const QJsonObject &spec);
    QWidget *makeElement(const QJsonObject &spec);
    void dispatch(const QString &action);
    void showFindDialog();
};
