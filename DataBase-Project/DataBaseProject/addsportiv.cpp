#include "addsportiv.h"
#include "ui_addsportiv.h"
#include "administrarecompetitiepage.h"
#include <QMessageBox>
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
       if(!ok || !nume[0].isLetter() || varsta < 5 || varsta > 100 || greutate < 1 || greutate > 150 || !prenume[0].isLetter())
       {
           QMessageBox::warning(this, tr("WARNING"), tr("Valorile caracteristicilor pentru un sportiv trebuie sa fie corecte si "
                                                        ""
                                                        "varsta trebuie sa fie cuprinsa in intervalul 5-100 si "
                                                        "greutatea trebuie sa fie cuprinsa in intervalul 1-150"));
           ui->nume->clear();
           ui->prenume->clear();
           ui->tara->clear();
           ui->gen->clear();
           ui->cnp->clear();
           ui->varsta->clear();
           ui->greutate->clear();
           ui->id_club->clear();

       } else {

           int ok = sportivDao.AddSportiv(sportiv);
            if(ok == 1){
                QMessageBox::information(this, tr("INFORMATION"), tr("Adaugare sportiv reusita !"));
                on_b_back_clicked();
            } else {
                QMessageBox::warning(this, tr("WARNING"), tr("Eroare inserare"));
                ui->nume->clear();
                ui->prenume->clear();
                ui->tara->clear();
                ui->gen->clear();
                ui->cnp->clear();
                ui->varsta->clear();
                ui->greutate->clear();
                ui->id_club->clear();
            }

       }
}

void addSportiv::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();
}
