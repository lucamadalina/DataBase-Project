#include "addcategorievarsta.h"
#include "ui_addcategorievarsta.h"
#include "categorievarstadao.h"
#include "administrarecompetitiepage.h"
addCategorieVarsta::addCategorieVarsta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCategorieVarsta)
{
    ui->setupUi(this);
}

addCategorieVarsta::~addCategorieVarsta()
{
    delete ui;
}

void addCategorieVarsta::on_b_addCatVarsta_clicked()
{
    bool ok = true;
    int id=ui->id->toPlainText().toInt(&ok);
    int prag_min=ui->prag_min->toPlainText().toInt(&ok);
    int prag_max=ui->prag_max->toPlainText().toInt(&ok);
    CategorieVarsta cv(id, prag_min, prag_max);
    if(!ok)
    {
        //QMessageBox::warning(this, tr("Error"), tr("id, varsta, greutate, id_club trebuie sa fie numere"));

    } else {
       categorieVarstaDao.AddCategorieVarsta(cv);
       on_b_back_clicked();
    }
}

void addCategorieVarsta::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();
}
