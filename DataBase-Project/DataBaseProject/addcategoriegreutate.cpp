#include "addcategoriegreutate.h"
#include "ui_addcategoriegreutate.h"
#include "categoriegreutatedao.h"
#include "categoriegen.h"
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

void addcategoriegreutate::on_pushButton_clicked()
{
    bool ok = true;
    int id=ui->id->toPlainText().toInt(&ok);
    int prag_min=ui->prag_min->toPlainText().toInt(&ok);
    int prag_max=ui->prag_max->toPlainText().toInt(&ok);
    CategorieGreutate cg(id, prag_min, prag_max);
    if(!ok)
    {
        //QMessageBox::warning(this, tr("Error"), tr("id, varsta, greutate, id_club trebuie sa fie numere"));

    } else {
       categorieGreutateDao.AddCategorieGreutate(cg);
    }
}

void addcategoriegreutate::on_b_adCategorie_clicked()
{
    bool ok = true;
    int id=ui->id->toPlainText().toInt(&ok);
    int prag_min=ui->prag_min->toPlainText().toInt(&ok);
    int prag_max=ui->prag_max->toPlainText().toInt(&ok);
    CategorieGreutate cg(id, prag_min, prag_max);
    if(!ok)
    {
        //QMessageBox::warning(this, tr("Error"), tr("id, varsta, greutate, id_club trebuie sa fie numere"));

    } else {
       categorieGreutateDao.AddCategorieGreutate(cg);
    }

}

void addcategoriegreutate::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();
}
