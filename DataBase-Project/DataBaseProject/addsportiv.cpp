#include "addsportiv.h"
#include "ui_addsportiv.h"
#include "administrarecompetitiepage.h"
class SportivDao;

addSportiv::addSportiv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSportiv)
{
    ui->setupUi(this);
    QList<QString> list1;
    list1 << "feminin" << "masculin";
    ui->gen->addItems(list1);
    vector<ClubSportiv> listaCluburiSportive = cs.getCluburiSportive();
    QList<QString> list2;
    for(ClubSportiv club : listaCluburiSportive){
         list2 = list2 + (QStringList()<<QString::number(club.getId())+". "+club.getDenumire());
    }
    ui->id_club->addItems(list2);
}

addSportiv::~addSportiv()
{
    delete ui;
}

void addSportiv::on_b_adSportiv_clicked()
{
        bool ok = true;
       QString nume=ui->nume->toPlainText();
       QString prenume=ui->prenume->toPlainText();
       QString tara=ui->tara->toPlainText();
       QString gen=ui->gen->currentText();
       long cnp = ui->cnp->toPlainText().toLong(&ok);
       int varsta = ui->varsta->toPlainText().toInt(&ok);
       int greutate = ui->greutate->toPlainText().toInt(&ok);
       int id_club = ui->id_club->currentText().split(".").value(0).toInt(&ok);
       Sportiv sportiv(nume, prenume, cnp, varsta, greutate,tara, gen, id_club);
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
