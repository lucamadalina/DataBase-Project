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

void CampionatDao::AddCampionat(Campionat &campionat)
{

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
        query.prepare("INSERT INTO competitie values(:id, :denumire, :puncte_participare, :locatie, :puncte_runda1, :puncte_semifinala, :puncte_finala");
            query.bindValue(":id", campionat.getId());
            query.bindValue(":denumire", campionat.getDenumire());
            query.bindValue(":puncte_participare", campionat.getPuncteParticipare());
            query.bindValue(":locatie", campionat.getLocatie());
            query.bindValue(":puncte_runda1", campionat.getPuncteRunda1());
            query.bindValue(":puncte_semifinala", campionat.getPuncteSemiFinala());
            query.bindValue(":puncte_finala", campionat.getPuncteFinala());
            int ok = query.exec();
            if(ok == 0)
            {
               //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
            }
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
