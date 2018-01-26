#include "viewclasamentsportivi.h"
#include "ui_viewclasamentsportivi.h"
#include "clasament.h"
ViewClasamentSportivi::ViewClasamentSportivi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewClasamentSportivi)
{
    ui->setupUi(this);
}

ViewClasamentSportivi::~ViewClasamentSportivi()
{
    delete ui;
}

void ViewClasamentSportivi::on_b_backToClasament_clicked()
{
    Clasament c;
    this->hide();
    c.setModal(true);
    c.exec();

}
