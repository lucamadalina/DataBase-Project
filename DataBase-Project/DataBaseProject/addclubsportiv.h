#ifndef ADDCLUBSPORTIV_H
#define ADDCLUBSPORTIV_H
#include "clubsportivdao.h"
#include "administrarecompetitiepage.h"
#include <QDialog>

namespace Ui {
class addClubSportiv;
}

class addClubSportiv : public QDialog
{
    Q_OBJECT

public:
    explicit addClubSportiv(QWidget *parent = 0);
    ~addClubSportiv();

private slots:
    void on_b_back_clicked();

    void on_b_addClubSportiv_clicked();

private:
    Ui::addClubSportiv *ui;
    AdministrareCompetitiePage * adComPage;
    ClubSportivDao clubSportivDao;
};

#endif // ADDCLUBSPORTIV_H
