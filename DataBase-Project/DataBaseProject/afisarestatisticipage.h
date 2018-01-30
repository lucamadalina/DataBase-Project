#ifndef AFISARESTATISTICIPAGE_H
#define AFISARESTATISTICIPAGE_H

#include <QDialog>
#include "clasamentorganizatii.h"
#include<mainwindow.h>
#include<QSqlDatabase>
namespace Ui {
class AfisareStatisticiPage;
}

class AfisareStatisticiPage : public QDialog
{
    Q_OBJECT

public:
    explicit AfisareStatisticiPage(QWidget *parent = 0);
    ~AfisareStatisticiPage();
    std::vector<ClasamentOrganizatii> getClasamentForChart();
    QString getNumeOrganizatieForChart(int id);
    QVector<QColor> rndColors(int count);
private slots:
   void on_b_backToClasament_clicked();

private:
    Ui::AfisareStatisticiPage *ui;
    MainWindow* mw;
    QSqlDatabase m_db;
    std::vector<ClasamentOrganizatii> list;
};

#endif // AFISARESTATISTICIPAGE_H
