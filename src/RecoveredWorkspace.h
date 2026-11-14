#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QWidget>

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
    QJsonArray nativeDialogs() const { return dialogs_; }
    QJsonArray menuCatalog() const { return menus_; }
private:
    QJsonObject catalog_;
    QJsonArray dialogs_, menus_;
    QMap<QString, QJsonObject> specs_;
    QMap<QString, QJsonObject> metadata_;
    QLabel *title_ = nullptr;
    QLabel *notice_ = nullptr;
    QScrollArea *scroll_ = nullptr;
    QString current_;
    QJsonObject pageSpec(const QString &id);
    QWidget *renderPage(const QJsonObject &spec, int depth = 0);
    QWidget *renderNodes(const QJsonArray &nodes, int index, int depth, int pageDepth);
    QWidget *renderDialog(const QJsonObject &spec);
    QWidget *renderMenu(const QJsonObject &spec);
};
