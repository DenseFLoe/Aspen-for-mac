#pragma once
#include <QJsonObject>
#include <QObject>
#include <QVector>

// The persistent document has no dependency on widgets or the Aspen runtime.
// Unverified resource inputs remain explicitly separate from typed inputs.
class ProjectDocument final : public QObject {
    Q_OBJECT
public:
    explicit ProjectDocument(QObject *parent=nullptr);
    static QJsonObject emptyState();
    static QString validate(const QJsonObject &state);
    const QJsonObject &state() const { return state_; }
    QString fileName() const { return fileName_; }
    bool isModified() const { return state_ != saved_; }
    bool canUndo() const { return index_ > 0; }
    bool canRedo() const { return index_+1 < history_.size(); }
    void edit(const QJsonObject &state);
    void reset();
    void undo();
    void redo();
    bool save(const QString &path, QString *error);
    bool load(const QString &path, QString *error);
signals:
    void changed();
    void restored();
private:
    QJsonObject state_, saved_;
    QString fileName_;
    QVector<QJsonObject> history_;
    int index_=0;
    void initialize(const QJsonObject &state);
};
