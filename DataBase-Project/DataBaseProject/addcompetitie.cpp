#include "AddCompetitie.h"
#include "ui_AddCompetitie.h"
#include "campionat.h"
#include<QDir>

class CampionatDao;

AddCompetitie::AddCompetitie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCompetitie)
{
    ui->setupUi(this);
    QPixmap pix(":/p1.jpg");
    ui->picture->setPixmap(pix.scaled(161, 111));
}

AddCompetitie::~AddCompetitie()
{
    delete ui;
}
void AddCompetitie::on_b_back_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();
}
void AddCompetitie::on_Add_competitie_clicked()
{
    bool ok = true;
    QString denumire = ui->denumire->toPlainText();
    QString locatie = ui->locatie->toPlainText();
    int puncteParticipare = ui->puncte_participare->toPlainText().toInt(&ok);
    int puncteRunda1 = ui->puncte_runda1->toPlainText().toInt(&ok);
    int puncteSemiFinala = ui->puncte_semifinala->toPlainText().toInt(&ok);
    int puncteFinala = ui->puncte_finala->toPlainText().toInt(&ok);

    Campionat competitie(denumire, puncteParticipare, locatie, puncteRunda1, puncteSemiFinala, puncteFinala);

    if(ok){
      campionatDao.AddCampionat(competitie);
    }else{

    }
}
