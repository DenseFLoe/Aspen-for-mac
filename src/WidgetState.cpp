#include "WidgetState.h"
#include <QAbstractButton>
#include <QApplication>
#include <QComboBox>
#include <QJsonArray>
#include <QLineEdit>
#include <QListWidget>
#include <QSignalBlocker>
#include <QSpinBox>
#include <QTableWidget>
#include <QTextEdit>

namespace {
QString key(QWidget *w,QWidget *root) {
    if(!w->property("stateKey").toString().isEmpty()) return w->property("stateKey").toString();
    QStringList path;
    for(auto *p=w;p && p!=root;p=p->parentWidget()) {
        int ordinal=0;
        if(auto *parent=p->parentWidget()) for(auto *s:parent->findChildren<QWidget *>(QString(),Qt::FindDirectChildrenOnly)) {
            if(s==p) break;
            if(s->metaObject()==p->metaObject() && s->objectName()==p->objectName()) ++ordinal;
        }
        path.prepend(QString::fromLatin1(p->metaObject()->className())+":"+p->objectName()+":"+QString::number(ordinal));
    }
    // QStackedWidget raises pages and changes QObject child order. Freeze the
    // adapter key during the initial default capture, before any navigation.
    const auto result=path.join('/');w->setProperty("stateKey",result);return result;
}
bool internal(QWidget *w,QWidget *root) {
    if(w->property("projectDerived").toBool()) return true;
    for(auto *p=w->parentWidget();p && p!=root;p=p->parentWidget())
        if(qobject_cast<QComboBox *>(p) || qobject_cast<QSpinBox *>(p) || qobject_cast<QAbstractItemView *>(p)) return true;
    return false;
}
}
void WidgetState::commit(QWidget *root) {
    if(auto *editor=QApplication::focusWidget();editor && (editor==root || root->isAncestorOf(editor)))editor->clearFocus();
}
QJsonObject WidgetState::capture(QWidget *root) {
    QJsonObject result;
    for(auto *w:root->findChildren<QWidget *>()) {
        if(internal(w,root)) continue;
        QJsonValue v;
        if(auto *c=qobject_cast<QComboBox *>(w)) v=QJsonObject{{"index",c->currentIndex()},{"text",c->currentText()}};
        else if(auto *e=qobject_cast<QLineEdit *>(w)) v=e->text();
        else if(auto *e=qobject_cast<QTextEdit *>(w)) v=e->toPlainText();
        else if(auto *b=qobject_cast<QAbstractButton *>(w);b && b->isCheckable()) v=b->isChecked();
        else if(auto *s=qobject_cast<QSpinBox *>(w)) v=s->value();
        else if(auto *t=qobject_cast<QTableWidget *>(w)) {
            QJsonArray rows; for(int r=0;r<t->rowCount();++r) {QJsonArray cells;
                for(int c=0;c<t->columnCount();++c) cells.append(t->item(r,c)?QJsonValue(t->item(r,c)->text()):QJsonValue()); rows.append(cells);}
            v=rows;
        } else if(auto *l=qobject_cast<QListWidget *>(w)) {QJsonArray rows; for(int r=0;r<l->count();++r) rows.append(l->item(r)->text());v=rows;}
        else continue;
        result[key(w,root)]=v;
    }
    return result;
}
void WidgetState::restore(QWidget *root,const QJsonObject &state) {
    for(auto *w:root->findChildren<QWidget *>()) {
        if(internal(w,root) || !state.contains(key(w,root))) continue;
        const QSignalBlocker blocked(w); const auto v=state.value(key(w,root));
        if(auto *c=qobject_cast<QComboBox *>(w)) {c->setCurrentIndex(v.toObject().value("index").toInt(-1)); if(c->isEditable()) c->setEditText(v.toObject().value("text").toString());}
        else if(auto *e=qobject_cast<QLineEdit *>(w)) e->setText(v.toString());
        else if(auto *e=qobject_cast<QTextEdit *>(w)) e->setPlainText(v.toString());
        else if(auto *b=qobject_cast<QAbstractButton *>(w);b && b->isCheckable()) b->setChecked(v.toBool());
        else if(auto *s=qobject_cast<QSpinBox *>(w)) s->setValue(v.toInt());
        else if(auto *t=qobject_cast<QTableWidget *>(w)) {const auto rows=v.toArray();t->setRowCount(rows.size());
            for(int r=0;r<rows.size();++r) for(int c=0;c<t->columnCount();++c) {const auto cells=rows[r].toArray();
                const auto value=c<cells.size()?cells[c]:QJsonValue(); delete t->takeItem(r,c); if(!value.isNull()) t->setItem(r,c,new QTableWidgetItem(value.toString()));}}
        else if(auto *l=qobject_cast<QListWidget *>(w)) {l->clear();for(const auto &row:v.toArray()) l->addItem(row.toString());}
    }
}
void WidgetState::observe(QWidget *root,QObject *receiver,const std::function<void()> &changed) {
    for(auto *w:root->findChildren<QWidget *>()) {
        if(internal(w,root)) continue;
        if(auto *c=qobject_cast<QComboBox *>(w)) QObject::connect(c,&QComboBox::currentTextChanged,receiver,changed);
        else if(auto *e=qobject_cast<QLineEdit *>(w)) QObject::connect(e,&QLineEdit::textChanged,receiver,changed);
        else if(auto *e=qobject_cast<QTextEdit *>(w)) QObject::connect(e,&QTextEdit::textChanged,receiver,changed);
        else if(auto *b=qobject_cast<QAbstractButton *>(w);b && b->isCheckable()) QObject::connect(b,&QAbstractButton::toggled,receiver,changed);
        else if(auto *s=qobject_cast<QSpinBox *>(w)) QObject::connect(s,&QSpinBox::valueChanged,receiver,changed);
        else if(auto *t=qobject_cast<QTableWidget *>(w)) {
            QObject::connect(t,&QTableWidget::itemChanged,receiver,changed);
            QObject::connect(t->model(),&QAbstractItemModel::rowsRemoved,receiver,changed);
            QObject::connect(t->model(),&QAbstractItemModel::rowsInserted,receiver,changed);
        } else if(auto *l=qobject_cast<QListWidget *>(w)) {
            QObject::connect(l->model(),&QAbstractItemModel::rowsInserted,receiver,changed);
            QObject::connect(l->model(),&QAbstractItemModel::rowsRemoved,receiver,changed);
            QObject::connect(l->model(),&QAbstractItemModel::rowsMoved,receiver,changed);
        }
    }
}
