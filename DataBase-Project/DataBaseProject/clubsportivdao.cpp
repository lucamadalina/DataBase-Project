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
    query.prepare("INSERT INTO club_sportiv values(:denumire, :tara, :adresa");
    QString denumire = clubSportiv.getDenumire();
    QString tara = clubSportiv.getTara();
    QString adresa = clubSportiv.getAdresa();
    QString values = "INSERT INTO club_sportiv(denumire,tara, adresa) values('"+denumire+"', '"+tara+"', '"+adresa+"')";
    int ok = query.exec(values);
    if(ok == 0)
    {
       //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
    } else {
        query.prepare("select id from club_sportiv where denumire = (:denumire)");
        query.bindValue(":denumire", denumire);
        query.exec();
        int id_club;
        if(query.next()){
            id_club = query.value(0).toInt();
        }
        query.prepare("insert into clasament_organizatii(id_organizatie, numar_puncte) values (:id, :numar_puncte)");
        values = "INSERT INTO clasament_organizatii(id_organizatie, numar_puncte) values("+
                QString::number(id_club)+","+QString::number(0) +")";
        ok = query.exec(values);
        if(ok == 0){

        }
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
