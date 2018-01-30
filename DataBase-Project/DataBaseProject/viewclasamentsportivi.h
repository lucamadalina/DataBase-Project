#ifndef VIEWCLASAMENTSPORTIVI_H
#define VIEWCLASAMENTSPORTIVI_H

#include <QDialog>
#include <QSqlDatabase>
#include "mainwindow.h"
#include <QTableWidget>
#include "clasamentsportivi.h"
namespace Ui {
class ViewClasamentSportivi;
}

class ViewClasamentSportivi : public QDialog
{
    Q_OBJECT

public:
    explicit ViewClasamentSportivi(QWidget *parent = 0);
    ~ViewClasamentSportivi();
    std::vector<ClasamentSportivi> AfisareClasament();
    Sportiv getSportiv(int id);
    std::vector<ClasamentSportivi> setOrdaring(std::vector<ClasamentSportivi> list);

private slots:
    void on_b_backToClasament_clicked();

private:
    Ui::ViewClasamentSportivi *ui;
    MainWindow* mw;
    QSqlDatabase m_db;
    QTableWidget *table;
    std::vector<ClasamentSportivi> finalList;

};

#endif // VIEWCLASAMENTSPORTIVI_H
