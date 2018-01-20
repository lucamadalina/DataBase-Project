#include "clubsportivdao.h"
#include<vector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "sportiv.h"
#include "mainwindow.h"
ClubSportivDao::ClubSportivDao()
{

}
void ClubSportivDao::existTable()
{
}

void ClubSportivDao::AddClubSportiv(ClubSportiv& clubSportiv)
{

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO club_sportiv values(:id, :denumire, :tara, :adresa");
    int id = clubSportiv.getId();
    QString denumire = clubSportiv.getDenumire();
    QString tara = clubSportiv.getTara();
    QString adresa = clubSportiv.getAdresa();
    QString values = "INSERT INTO club_sportiv values("+QString::number(id)+", '"+denumire+"', '"+tara+"', '"+adresa+"')";
    int ok = query.exec(values);
    if(ok == 0)
    {
       //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
    }



}


void ClubSportivDao::RemoveClubSportiv(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM club_sportiv WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<ClubSportiv> ClubSportivDao::getCluburiSportive()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM club_sportiv");
    query.exec();

    std::vector<ClubSportiv> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        QString denumire = query.value("denumire").toString();
        QString tara = query.value("tara").toString();
        QString adresa = query.value("adresa").toString();
        ClubSportiv cs(id, denumire, tara, adresa);
         list.push_back(cs);
    }

    return list;
}
