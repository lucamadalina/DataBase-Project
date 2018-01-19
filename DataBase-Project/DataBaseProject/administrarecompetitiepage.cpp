#include "administrarecompetitiepage.h"
#include "ui_administrarecompetitiepage.h"
#include "mainwindow.h"
#include "addsportiv.h"
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

void AdministrareCompetitiePage::on_pushButton_5_clicked()
{
    addSportiv pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}
