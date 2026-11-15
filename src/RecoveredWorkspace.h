#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QWidget>
#include <QVariantMap>

class QLabel;
class QScrollArea;

// Portable projections of static resources. Never loads or calls Aspen binaries.
class RecoveredWorkspace final : public QWidget
{
    Q_OBJECT
public:
    explicit RecoveredWorkspace(QWidget *parent = nullptr);
    const QJsonObject &catalog() const { return catalog_; }
    bool showPage(const QString &id);
    QString currentPage() const { return current_; }
    QString idForType(const QString &type) const;
    QString idForName(const QString &name) const;
    void setGlobalUnits(const QString &units);
    QJsonArray nativeDialogs() const { return dialogs_; }
    QJsonArray menuCatalog() const { return menus_; }
signals:
    void actionRequested(const QString &action);
    void pageChanged(const QString &id);
    void globalUnitsChanged(const QString &units);
    void closeRequested();
private:
    QJsonObject catalog_;
    QJsonArray dialogs_, menus_;
    QMap<QString, QJsonObject> specs_;
    QMap<QString, QJsonObject> metadata_;
    QLabel *title_ = nullptr;
    QLabel *notice_ = nullptr;
    QScrollArea *scroll_ = nullptr;
    QString current_;
    QString renderScope_, renderingId_, globalUnits_ = "METCBAR";
    QJsonObject interactions_;
    QMap<QString, QVariantMap> state_;
    void saveState();
    void restoreState(QWidget *view);
    QJsonObject pageSpec(const QString &id);
    QWidget *renderPage(const QJsonObject &spec, int depth = 0);
    QWidget *renderNodes(const QJsonArray &nodes, int index, int depth, int pageDepth);
    QWidget *renderDialog(const QJsonObject &spec);
    QWidget *renderMenu(const QJsonObject &spec);
};
