#include "campionat.h"
#include "ui_campionat.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "addsportiv.h"

Campionat::Campionat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Campionat)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Cristian/Desktop/DataBase/DataBase-Project/DataBaseProject/p1.jpg");
    ui->picture->setPixmap(pix);
}


Campionat::~Campionat()
{
    delete ui;
}

void Campionat::on_b_back_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();
}

void Campionat::on_ad_Sportiv_clicked()
{
    adSportiv = new addSportiv();
    this->hide();
    adSportiv->show();
}
