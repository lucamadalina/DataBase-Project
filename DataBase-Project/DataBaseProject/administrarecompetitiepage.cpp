#include "administrarecompetitiepage.h"
#include "ui_administrarecompetitiepage.h"
#include "mainwindow.h"
#include "addsportiv.h"
#include "addcategoriegreutate.h"
#include "addcategorievarsta.h"
#include "addclubsportiv.h"
#include "simularelupte.h"

AdministrareCompetitiePage::AdministrareCompetitiePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministrareCompetitiePage)
{
    ui->setupUi(this);
}

AdministrareCompetitiePage::~AdministrareCompetitiePage()
{
    delete ui;
}

void AdministrareCompetitiePage::on_b_back_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();
}


void AdministrareCompetitiePage::on_b_adCatGreutate_clicked()
{
    addcategoriegreutate pag;
    this->hide();
    pag.setModal(true);
    pag.exec();

}

void AdministrareCompetitiePage::on_b_adCatVarsta_clicked()
{
    addCategorieVarsta pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}

void AdministrareCompetitiePage::on_b_adClubSportiv_clicked()
{
    addClubSportiv pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}

void AdministrareCompetitiePage::on_b_adSportiv_clicked()
{
    addSportiv pag;
    this->hide();
    pag.setModal(true);
    pag.exec();

}

void AdministrareCompetitiePage::on_b_simulareLupte_clicked()
{
    simularelupte sl;
    this->hide();
    sl.setModal(true);
    sl.exec();
}
