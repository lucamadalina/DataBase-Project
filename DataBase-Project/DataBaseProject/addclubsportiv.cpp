#include "addclubsportiv.h"
#include "ui_addclubsportiv.h"
#include "administrarecompetitiepage.h"
#include "clubsportiv.h"
#include <QMessageBox>
addClubSportiv::addClubSportiv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClubSportiv)
{
    ui->setupUi(this);
    QPixmap pix(":/p6.jpg");
    ui->picture->setPixmap(pix.scaled(131, 131));

}

addClubSportiv::~addClubSportiv()
{
    delete ui;
}

void addClubSportiv::on_b_back_clicked()
{
    adComPage = new AdministrareCompetitiePage();
    this->hide();
    adComPage->show();


}

void addClubSportiv::on_b_addClubSportiv_clicked()
{
    QString denumire = ui->denumire->toPlainText();
    QString tara = ui->tara->toPlainText();
    QString adresa = ui->adresa->toPlainText();
    if (!denumire[0].isLetter() || !tara[0].isLetter() || !adresa[0].isLetter())
    {
        QMessageBox::warning(this, tr("WARNING"), tr("Denumirea si tara trebuie sa inceapa cu litera"));
        ui->denumire->clear();
        ui->tara->clear();
        ui->adresa->clear();
    }
    else
    {
        QMessageBox::information(this, tr("INFORMATION"), tr("Adaugare club sportiv reusita"));
    ClubSportiv cs(denumire, tara, adresa);
    clubSportivDao.AddClubSportiv(cs);
    on_b_back_clicked();
}
}
