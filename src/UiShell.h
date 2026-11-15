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
class ObjectWorkspace;
class ProjectDocument;
class QCloseEvent;

// UI-only shell: navigation works; simulation commands have no backend.
class UiShell final : public QMainWindow
{
public:
    explicit UiShell(const QJsonObject &catalog, QWidget *parent = nullptr);
    void dispatch(const QString &action);
    ProjectDocument *project() const { return project_; }
    bool saveProject(const QString &path, QString *error);
    bool loadProject(const QString &path, QString *error);
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    ProjectDocument *project_=nullptr;
    bool restoringProject_=false;
    void initializeProject();
    void captureProject();
    void restoreProject();
    bool projectAction(const QString &action);
    bool saveProjectDialog(bool saveAs);
    bool confirmProjectReplacement();
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
    ObjectWorkspace *objects_ = nullptr;
    void syncObjectNavigation();
    bool dispatchObjectAction(const QString &action);
    void setWorkspaceMode(bool simulation);
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
