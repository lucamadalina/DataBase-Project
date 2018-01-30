#include "addcategorievarsta.h"
#include "ui_addcategorievarsta.h"
#include "categorievarstadao.h"
#include "administrarecompetitiepage.h"
#include <QMessageBox>
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
    int prag_min=ui->prag_min->toPlainText().toInt(&ok);
    int prag_max=ui->prag_max->toPlainText().toInt(&ok);
    CategorieVarsta cv( prag_min, prag_max);
    if(!ok || prag_min < 5 || prag_max > 100)
    {
        QMessageBox::warning(this, tr("WARNING"), tr("pragul minim si pragul maxim trebuie sa fie numere intregi si cuprinse in intervalul 5-100"));
        ui->prag_min->clear();
        ui->prag_max->clear();
    } else {
        QMessageBox::information(this, tr("INFORMATION"), tr("Adaugare cu succes a categoriei de varsta"));
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
