#ifndef VIEWCLASAMENT_H
#define VIEWCLASAMENT_H

#include <QDialog>
#include<mainwindow.h>
#include<QSqlDatabase>
#include "clasamentorganizatii.h"
#include "qtablewidget.h"
#include <QtCharts/qpieseries.h>
namespace Ui {
class ViewClasament;
}

class ViewClasament : public QDialog
{
    Q_OBJECT

public:
    explicit ViewClasament(QWidget *parent = 0);
    ~ViewClasament();
    std::vector<ClasamentOrganizatii> getClasament();
    QString getNumeOrganizatie(int id);
    std::vector<ClasamentOrganizatii> setOrdaring(std::vector<ClasamentOrganizatii> list);

private slots:
    void on_b_backToClasament_clicked();

private:
    Ui::ViewClasament *ui;
    MainWindow* mw;
    QSqlDatabase m_db;
    QTableWidget *table;
    std::vector<ClasamentOrganizatii> finalList;
};

#endif // VIEWCLASAMENT_H
