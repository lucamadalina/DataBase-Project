#include "sportivdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "sportiv.h"
#include "mainwindow.h"
#include<iostream>

SportivDao::SportivDao(){

}
//SportivDao::SportivDao(QSqlDatabase& m_db): m_db(m_db) {

//}

void SportivDao::existTable()
{
}

void SportivDao::AddSportiv(Sportiv& sportiv)
{
   //aici m_db este null
    //mw->getDataBase(*m_db);
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
        query.prepare("INSERT INTO sportiv values(:id, :nume, :prenume, :varsta, :greutate, :tara, :gen, :id_club, :id_categorie_greutate,"
                      ":id_categorie_varsta, :id_categorie_gen)");
            query.bindValue(":id", sportiv.getId());
            query.bindValue(":nume", sportiv.getNume());
            query.bindValue(":prenume", sportiv.getPrenume());
            query.bindValue(":tara", sportiv.getTara());
            query.bindValue(":varsta", sportiv.getVarsta());
            query.bindValue(":greutate", sportiv.getGreutate());
            query.bindValue(":gen", sportiv.getGen());
            query.bindValue(":id_club", sportiv.getIdClubSportiv());
            int idCatGen = calculateIdCategorieGen(sportiv.getGen());
            int idCatGreutate = calculateIdCategorieGreutate(sportiv.getGreutate());
            int idCatVarsta = calculateIdCategorieVarsta(sportiv.getVarsta());
            query.bindValue(":id_categorie_greutate", idCatGreutate);
            query.bindValue(":id_categorie_varsta", idCatVarsta);
            query.bindValue(":id_categorie_gen", idCatGen);
            int ok = query.exec();
            if(ok == 0)
            {
               //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
            }
}
int SportivDao::calculateIdCategorieGen(QString gen){
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_gen");
    query.exec();
    while(query.next()) {

        int id = query.value("id").toInt();
        QString genCategorie = query.value("gen").toString();
        if(gen == genCategorie ){
            return id;
        }
    }
    return 0;
}

int SportivDao::calculateIdCategorieGreutate(int greutate){
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_greutate");
    query.exec();
    while(query.next()) {

        int id = query.value("id").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        if(greutate <= prag_max && greutate > prag_min ){
            return id;
        }
    }
    return 0;
}

int SportivDao::calculateIdCategorieVarsta(int varsta){
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_varsta");
    query.exec();
    while(query.next()) {

        int id = query.value("id").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        if(varsta <= prag_max && varsta > prag_min ){
            return id;
        }
    }
    return 0;
}

void SportivDao::RemoveSportiv(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Sportiv WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<Sportiv> SportivDao::getSportivi()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM sportiv");
    query.exec();

    std::vector<Sportiv> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        QString nume = query.value("nume").toString();
        QString prenume = query.value("prenume").toString();
        QString tara = query.value("tara").toString();
        QString gen = query.value("gen").toString();
        int varsta = query.value("varsta").toInt();
        int greutate = query.value("greutate").toInt();
        int id_club = query.value("id_club").toInt();
        Sportiv sportiv(id, nume, prenume, varsta,
                      greutate, tara, gen, id_club);
         list.push_back(sportiv);
    }

    return list;
}

