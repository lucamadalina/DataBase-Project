#include "clasament.h"
#include "ui_clasament.h"

Clasament::Clasament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clasament)
{
    ui->setupUi(this);
}

Clasament::~Clasament()
{
    delete ui;
}

void Clasament::on_b_back_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();
}