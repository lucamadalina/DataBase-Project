#include "addcategoriegreutate.h"
#include "ui_addcategoriegreutate.h"
#include "categoriegreutatedao.h"
#include "categoriegen.h"
#include <QMessageBox>
addcategoriegreutate::addcategoriegreutate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcategoriegreutate)
{
    ui->setupUi(this);
}

addcategoriegreutate::~addcategoriegreutate()
{
    delete ui;
}

void addcategoriegreutate::on_b_adCategorie_clicked()
{
    bool ok = true;
    int prag_min=ui->prag_min->toPlainText().toInt(&ok);
    int prag_max=ui->prag_max->toPlainText().toInt(&ok);
    CategorieGreutate cg( prag_min, prag_max);
    if((!ok) || prag_min < 1 || prag_max > 150)
    {
        QMessageBox::warning(this, tr("WARNING"), tr("pragul minim si pragul maxim trebuie sa fie numere intregi si cuprinse in intervalul 1-150"));
        ui->prag_min->clear();
        ui->prag_max->clear();

    } else {
        QMessageBox::information(this, tr("INFORMATION"), tr("Adaugare cu succes a categoriei de greutate"));
        categorieGreutateDao.AddCategorieGreutate(cg);
        on_b_back_clicked();
    }

}

void addcategoriegreutate::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();
}

void addcategoriegreutate::on_home_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();

}
