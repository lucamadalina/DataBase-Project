#ifndef SIMULARELUPTE_H
#define SIMULARELUPTE_H

#include <QDialog>
#include<QSqlDatabase>
#include<vector>
#include "mainwindow.h"
#include "sportivdao.h"
#include "sportiv.h"
#include "administrarecompetitiepage.h"

namespace Ui {
class simularelupte;
}

class simularelupte : public QDialog
{
    Q_OBJECT

public:
    explicit simularelupte(QWidget *parent = 0);
    ~simularelupte();
    vector<QString> getCompetitii();
    void setComboBox();

private slots:
    void on_b_simulare_clicked();
    void execute(QString myString);
    void setPuncte(QList<Sportiv> list, QString denumire);
    void setPuncteOrganizatie(int puncte, int idOrganizatie);

    void on_b_back_clicked();

private:
    Ui::simularelupte *ui;
    MainWindow* mw;
    QSqlDatabase m_db;
//    int greutate_prag_min;
//    int greutate_prag_max;
//    int varsta_prag_min;
//    int varsta_prag_max;
//    QString gen;
    SportivDao sportivDao;
    QList<Sportiv> listaSportivi;
    AdministrareCompetitiePage pag;
};

#endif // SIMULARELUPTE_H
