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
    ~ObjectWorkspace() override;
    QJsonArray definitions() const { return definitions_; }
    QJsonArray objects() const;
    QJsonArray projectObjects();
    void restoreProjectObjects(const QJsonArray &objects);
    void setChemicalSystemState(const QJsonObject &state);
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
    void setFlowsheetZoom(int percent);
    void setFlowsheetLocked(bool locked);
    bool flowsheetLocked() const { return flowsheetLocked_; }
    void setModelPaletteVisible(bool visible);
    void setThreeDimensionalIcons(bool enabled);
    QString selectedFlowsheetObject() const;
    void transformSelectedBlock(const QString &operation);
    void beginReconnection(const QString &key,const QString &end);
    void setStreamAppearance(const QString &key,const QString &property,const QJsonValue &value);
    void showStreamAppearance(const QString &key);
signals:
    void objectsChanged();
    void inputsChanged();
    void objectsRemoved(const QStringList &keys);
    void objectActivated(const QString &key, const QString &page);
    void collectionActivated(const QString &kind, const QString &parent);
    void actionRequested(const QString &action);
    void flowsheetActivated(bool active);
    void flowsheetSelectionChanged();
    void flowsheetZoomChanged(int percent);
private:
    struct Entry {
        QJsonObject data;
        QMap<QString,QVariantMap> values;
        RecoveredWorkspace *view=nullptr;
        QString lastPage;
    };
    QJsonArray definitions_;
    QJsonObject chemicalState_;
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
    QString reconnectKey_,reconnectEnd_;
    QPointF streamStart_;
    bool streamPending_=false;
    bool flowsheetLocked_=false, threeDimensionalIcons_=true;
    bool labelsHidden_=false;
    QWidget *modelPalette_=nullptr, *metrics_=nullptr;
    QWidget *makeModelPalette();
    QWidget *makeMetrics();
    QString selectedKey() const;
    void refreshManager();
    void refreshButtons();
    void refreshCanvas();
    void refreshTitles();
    void nameDialog(const QString &kind, const QString &parent, const QString &key);
    void showFlowsheetMenu(const QPoint &position);
    void requestDeleteObjects(const QStringList &keys);
    void moveBlocks(const QMap<QString,QPointF> &positions);
    void selectFlowsheetObject(const QString &key);
    void fitFlowsheet();
};
