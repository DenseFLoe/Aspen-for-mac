#pragma once
#include "ChemicalSystem.h"
#include <QDialog>
#include <functional>

class ProjectDocument;
class QStackedWidget;
class QLabel;
class QPushButton;
class QListWidget;
class PropertyAssistant final : public QDialog {
public:
    PropertyAssistant(const QString &name,const QJsonObject &spec,ProjectDocument *project,std::function<void()> committed,QWidget *parent);
private:
    QString name_,chemistryId_;
    ProjectDocument *project_;
    QJsonObject initial_;
    std::function<void()> committed_;
    QStackedWidget *steps_;
    QLabel *notice_;
    QPushButton *next_,*back_,*finish_,*cancel_;
    QListWidget *available_,*selected_;
    ChemicalSystem::Candidates candidates_;
    bool hasCommitted_=false,sfeLoaded_=false,replaceChemistry_=false;
    QStringList selectedKeys() const;
    ChemicalSystem::ElectrolyteOptions options() const;
    void updateButtons();
    void showError(const QString &message);
    void enterPage(int index);
    void forward();
    void backward();
    void finish();
    bool commit(const ChemicalSystem::Result &result);
    void refreshCandidates();
    bool chooseChemistry();
};
