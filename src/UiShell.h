#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QMainWindow>

class QMenu;
class QStackedWidget;
class QToolButton;

// UI-only shell: leaf actions intentionally have no application callbacks.
class UiShell final : public QMainWindow
{
public:
    explicit UiShell(const QJsonObject &catalog, QWidget *parent = nullptr);

private:
    QJsonObject catalog_;
    QStackedWidget *pages_ = nullptr;
    QToolButton *makeButton(const QJsonObject &spec, QWidget *parent, bool iconOnly = false);
    QMenu *makeMenu(const QJsonArray &entries, QWidget *parent);
    QWidget *makeWorkspace();
    QWidget *makeRibbon(const QJsonObject &ribbon);
    QWidget *makeNavigator();
    QWidget *makeComponentPage();
    QWidget *makeFilePage();
    QWidget *makeFilePanel(const QJsonObject &entry);
};
