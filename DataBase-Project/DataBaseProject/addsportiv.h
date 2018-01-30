#ifndef ADDSPORTIV_H
#define ADDSPORTIV_H

#include <QDialog>
#include<sportiv.h>
#include<sportivdao.h>
#include"administrarecompetitiepage.h"
#include "clubsportivdao.h"
namespace Ui {
class addSportiv;
}

class addSportiv : public QDialog
{
    Q_OBJECT

public:
    explicit addSportiv(QWidget *parent = 0);
    ~addSportiv();

private slots:
    void on_b_adSportiv_clicked();

    void on_b_back_clicked();

private:
    Ui::addSportiv *ui;
    SportivDao sportivDao;
    Sportiv *sportiv;
    AdministrareCompetitiePage * adComPage;
    ClubSportivDao cs;
};

#endif // ADDSPORTIV_H
