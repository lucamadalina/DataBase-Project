#include "addsportiv.h"
#include "ui_addsportiv.h"
#include "administrarecompetitiepage.h"
class SportivDao;

addSportiv::addSportiv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSportiv)
{
    ui->setupUi(this);

}

addSportiv::~addSportiv()
{
    delete ui;
}

void addSportiv::on_b_adSportiv_clicked()
{

       QString nume=ui->nume->toPlainText();
       QString prenume=ui->prenume->toPlainText();
       QString tara=ui->tara->toPlainText();
       QString gen=ui->gen->toPlainText();
       bool ok = true;
       int id = ui->id->toPlainText().toInt(&ok);
       int varsta = ui->varsta->toPlainText().toInt(&ok);
       int greutate = ui->greutate->toPlainText().toInt(&ok);
       int id_club = ui->id_club->toPlainText().toInt(&ok);
       Sportiv sportiv(id, nume, prenume,varsta, greutate,tara, gen, id_club);
       if(!ok)
       {
           //QMessageBox::warning(this, tr("Error"), tr("id, varsta, greutate, id_club trebuie sa fie numere"));

       } else {
           sportivDao.AddSportiv(sportiv);
           on_b_back_clicked();
       }
}

void addSportiv::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();
}
