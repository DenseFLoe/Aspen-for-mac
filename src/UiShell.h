#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QMainWindow>

class QMenu;
class QStackedWidget;
class QToolButton;
class ComponentWorkspace;
class QTreeWidget;
class RecoveredWorkspace;
class QDialog;

// UI-only shell: navigation works; simulation commands have no backend.
class UiShell final : public QMainWindow
{
public:
    explicit UiShell(const QJsonObject &catalog, QWidget *parent = nullptr);
    void dispatch(const QString &action);

private:
    QJsonObject catalog_;
    QJsonObject interactions_;
    QStringList locations_;
    int locationIndex_ = -1;
    bool traversing_ = false;
    QString globalUnits_ = "METCBAR";
    void remember(const QString &location);
    void openDialog(const QString &name);
    void openWizard(const QString &name);
    void setUnits(const QString &units);
    void notifyUnavailable(const QString &label);
    QStackedWidget *pages_ = nullptr;
    ComponentWorkspace *components_ = nullptr;
    QTreeWidget *navigation_ = nullptr;
    RecoveredWorkspace *recovered_ = nullptr;
    QStackedWidget *documents_ = nullptr;
    bool openRecovered(const QString &name);
    QToolButton *makeButton(const QJsonObject &spec, QWidget *parent, bool iconOnly = false);
    QMenu *makeMenu(const QJsonArray &entries, QWidget *parent);
    QWidget *makeWorkspace();
    QWidget *makeRibbon(const QJsonObject &ribbon);
    QWidget *makeNavigator();
    QWidget *makeComponentPage();
    QWidget *makeFilePage();
    QWidget *makeFilePanel(const QJsonObject &entry);
};
