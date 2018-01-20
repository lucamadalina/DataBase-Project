#ifndef ADMINISTRARECOMPETITIEPAGE_H
#define ADMINISTRARECOMPETITIEPAGE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class AdministrareCompetitiePage;
}

class AdministrareCompetitiePage : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrareCompetitiePage(QWidget *parent = 0);
    ~AdministrareCompetitiePage();

private slots:
    void on_b_back_clicked();

    void on_b_adCatGreutate_clicked();

    void on_b_adCatVarsta_clicked();

    void on_b_adClubSportiv_clicked();

    void on_b_adSportiv_clicked();

private:
    Ui::AdministrareCompetitiePage *ui;
    MainWindow *mn;
    AdministrareCompetitiePage * adPage;

};

#endif // ADMINISTRARECOMPETITIEPAGE_H
