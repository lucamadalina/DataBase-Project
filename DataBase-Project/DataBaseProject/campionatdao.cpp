#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "mainwindow.h"
#include<iostream>
#include "campionat.h"
#include "campionatdao.h"
CampionatDao::CampionatDao()
{

}
void CampionatDao::existTable()
{

}

void CampionatDao::AddCampionat(Campionat& campionat)
{

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    int id = campionat.getId();
    QString denumire = campionat.getDenumire();
    QString locatie = campionat.getLocatie();
    int pp = campionat.getPuncteParticipare();
    int p1 = campionat.getPuncteRunda1();
    int ps = campionat.getPuncteSemiFinala();
    int pf = campionat.getPuncteFinala();
    QString values = "INSERT INTO competitie values("+QString::number(id)+", '"+denumire+"', "+QString::number(pp)+", '"+locatie+"', "+QString::number(p1)+", "+QString::number(ps)+", "+QString::number(pf)+")";

    query.prepare("INSERT INTO competitie values(:id, :denumire, :puncte_participare, :locatie, :puncte_runda1, :puncte_semifinala, :puncte_finala");
    query.exec(values);
}


void CampionatDao::RemoveCampionat(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM competitie WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<Campionat> CampionatDao::getCampionate()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM competitie");
    query.exec();

    std::vector<Campionat> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        QString denumire = query.value("denumire").toString();
        QString locatie = query.value("locatie").toString();
        int puncteParticipare = query.value("puncte_participare").toInt();;
        int puncteRunda1 = query.value("puncte_runda1").toInt();
        int puncteSemiFinala = query.value("puncte_semifinala").toInt();
        int puncteFinala = query.value("puncte_finala").toInt();;
        Campionat campionat(id, denumire, puncteParticipare, locatie,
                      puncteRunda1, puncteSemiFinala, puncteFinala);
         list.push_back(campionat);
    }

    return list;
}
