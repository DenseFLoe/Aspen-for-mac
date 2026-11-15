#pragma once
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QPointF>
#include <QVariantMap>
#include <QWidget>

class QLabel;
class QTableWidget;
class QTabWidget;
class QPushButton;
class RecoveredWorkspace;
class FlowsheetView;

// Object editing adapter; persistent snapshots belong to ProjectDocument.
class ObjectWorkspace final : public QWidget
{
    Q_OBJECT
public:
    explicit ObjectWorkspace(QWidget *parent=nullptr);
    QJsonArray definitions() const { return definitions_; }
    QJsonArray objects() const;
    QJsonArray projectObjects();
    void restoreProjectObjects(const QJsonArray &objects);
    QJsonObject object(const QString &key) const;
    QJsonObject definition(const QString &kind) const;
    QJsonObject typeDefinition(const QString &kind, const QString &type) const;
    QString suggestedName(const QString &kind, const QString &parent={}) const;
    QString nameError(const QString &kind, const QString &name, const QString &parent={}, const QString &except={}) const;
    QString createObject(const QString &kind, const QString &name, const QString &type, const QString &parent={});
    bool renameObject(const QString &key, const QString &name);
    bool removeObject(const QString &key);
    void showCollection(const QString &kind, const QString &parent={});
    bool openObject(const QString &key, const QString &page={});
    void closeObject(const QString &key);
    void showFlowsheet();
    void setGlobalUnits(const QString &units);
    void requestNew(const QString &kind, const QString &parent={});
    void requestRename(const QString &key);
    void requestDelete(const QString &key);
    void copyObject(const QString &key);
    void requestPaste();
    void setObjectState(const QString &key, const QMap<QString,QVariantMap> &values);
    QString currentObject() const;
    void beginPlacement(const QString &kind, const QString &type);
    void placeAt(const QPointF &position, const QString &attachment={});
    void moveBlock(const QString &key, const QPointF &position);
signals:
    void objectsChanged();
    void inputsChanged();
    void objectsRemoved(const QStringList &keys);
    void objectActivated(const QString &key, const QString &page);
    void collectionActivated(const QString &kind, const QString &parent);
    void actionRequested(const QString &action);
private:
    struct Entry {
        QJsonObject data;
        QMap<QString,QVariantMap> values;
        RecoveredWorkspace *view=nullptr;
        QString lastPage;
    };
    QJsonArray definitions_;
    QMap<QString,Entry> entries_;
    QStringList order_;
    QString kind_, parent_, units_="METCBAR";
    QTabWidget *documents_=nullptr;
    QWidget *manager_=nullptr, *flowsheet_=nullptr;
    QTableWidget *table_=nullptr;
    QLabel *heading_=nullptr, *placementNotice_=nullptr;
    QMap<QString,QPushButton *> buttons_;
    FlowsheetView *canvas_=nullptr;
    QJsonObject clipboard_;
    QMap<QString,QVariantMap> clipboardValues_;
    QJsonArray clipboardChildren_;
    QMap<QString,QMap<QString,QVariantMap>> clipboardChildValues_;
    QString placementKind_, placementType_, streamStartKey_;
    QPointF streamStart_;
    bool streamPending_=false;
    QString selectedKey() const;
    void refreshManager();
    void refreshButtons();
    void refreshCanvas();
    void refreshTitles();
    void nameDialog(const QString &kind, const QString &parent, const QString &key);
};
