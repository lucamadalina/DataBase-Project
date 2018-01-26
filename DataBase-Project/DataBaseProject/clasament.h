#ifndef CLASAMENT_H
#define CLASAMENT_H

#include <QDialog>
#include "mainwindow.h"
#include "viewclasament.h"
#include <QDialog>
#include "mainwindow.h"
#include "viewclasament.h"
#include <QtGui>
#include <QtCore>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include <QtAlgorithms>
#include "viewclasamentsportivi.h"
namespace Ui {
class Clasament;
}

class Clasament : public QDialog
{
    Q_OBJECT

public:
    explicit Clasament(QWidget *parent = 0);
    ~Clasament();
    std::vector<QString> GetMemberForAfisareClasament();

private slots:
    void on_b_back_clicked();

    void on_b_viewclasament_clicked();

    void on_b_afisaticlasamentul_clicked();

private:
    Ui::Clasament *ui;
    MainWindow *mn;
    ViewClasament *vc;
    ViewClasamentSportivi *vcs;
    QSqlDatabase m_db;
    void GetCategoriiVarsta();
    void GetCategoriiGreutate();
    void GetCategoriiGen();
};

#endif // CLASAMENT_H
