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


void SportivDao::existTable()
{
}

int SportivDao::AddSportiv(Sportiv& sportiv)
{
    int idCatGen = calculateIdCategorieGen(sportiv.getGen());
    int idCatGreutate = calculateIdCategorieGreutate(sportiv.getGreutate());
    int idCatVarsta = calculateIdCategorieVarsta(sportiv.getVarsta());
    int id_varsta_greutate_gen = getIdVarstaGreutateGen(idCatGen, idCatGreutate, idCatVarsta);
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);

//    QString text1 = "INSERT INTO sportiv(nume, prenume,cnp, varsta, greutate, tara, gen,";
//        QString text2 = "id_varsta_greutate_gen,id_club) values('" ;
//        QString text3 = sportiv.getNume()+"','"+sportiv.getPrenume()+"', "+QString::number(sportiv.getCNP())+", "+QString::number(sportiv.getVarsta());
//        QString text4= ", "+QString::number(sportiv.getGreutate())+",'" + sportiv.getTara()+"', '"+sportiv.getGen();
//        QString text5="', "+ QString::number(sportiv.getIdClubSportiv()) +", "+ QString::number(id_varsta_greutate_gen)+")";
    //QString total = text1+text2+text3+text4+text5;

        QString text = "INSERT INTO sportiv(nume, prenume, cnp, varsta, greutate, tara, gen,\
        id_varsta_greutate_gen,id_club) values('" +sportiv.getNume()+"','"+sportiv.getPrenume()+"',"+QString::number(sportiv.getCNP())
        +", "+QString::number(sportiv.getVarsta()) + ", "+QString::number(sportiv.getGreutate())+",'"
        + sportiv.getTara()+"', '"+sportiv.getGen()+"', "+ QString::number(id_varsta_greutate_gen)
        +", "+ QString::number(sportiv.getIdClubSportiv())+")";
        query.prepare("INSERT INTO sportiv(nume, prenume, cnp, varsta, greutate, tara, gen, id_club,\
        id_varsta_greutate_gen) values( :nume, :prenume, :cnp, :varsta, \
        :greutate, :tara, :gen, :id_club, :id_varsta_greutate_gen)");
            int ok = query.exec(text);
            if(ok == 0)
            {
                return 0;
            } else {
                int id;
                query.prepare("select id from sportiv where cnp = (:cnp)");
                query.bindValue(":cnp", sportiv.getCNP());
                ok = query.exec();
                if(query.next()){
                    id = query.value(0).toInt();
                }
                int nr = 0;
                QString values = "INSERT INTO clasament_sportiv(id_sportiv, numar_puncte, id_varsta_greutate_gen)\
                            values("+QString::number(id)+", "+QString::number(nr)+", "+QString::number(id_varsta_greutate_gen)+")";
                query.prepare("INSERT INTO clasament_sportiv(id_sportiv, numar_puncte, \
                                           id_varsta_greutate_gen) values(:id_sportiv,:numar_puncte,:id_varsta_greutate_gen");
                query.exec(values);
            }
       return 1;

 }
int SportivDao::calculateIdCategorieGen(QString gen){
     m_db = mw->getDataBase();
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

int SportivDao::getIdVarstaGreutateGen(int gen, int greutate, int varsta)
{
   int id = 0;
   m_db = mw->getDataBase();
   QSqlQuery query(m_db);
   query.prepare("select * from varsta_greutate_gen where greutate_id= (:id_greutate)\
                 and varsta_id = (:id_varsta) and gen_id = (:id_gen)");
   query.bindValue(":id_greutate", greutate);
   query.bindValue(":id_varsta", varsta);
   query.bindValue(":id_gen", gen);
   query.exec();
   if(query.next()) {
      id = query.value("id").toInt();
   }
   return id;

}

int SportivDao::calculateIdCategorieGreutate(int greutate){
     m_db = mw->getDataBase();
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
     m_db = mw->getDataBase();
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
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Sportiv WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

QList<Sportiv> SportivDao::getSportivi()
{
     m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM sportiv");
    query.exec();

   QList<Sportiv> list;
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

QList<Sportiv> SportivDao::getSportiviSimulare(int id)
{
    m_db = mw->getDataBase();
   QSqlQuery query(m_db);
   query.prepare("SELECT * FROM sportiv where id_varsta_greutate_gen = (:id)");
   query.bindValue(":id", id);
   query.exec();

   QList<Sportiv> list;
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
   if(list.empty() == true){
       Sportiv sportiv(id, "nume","prenume", 1,
                     1, "tara", "gen", 1);
       list.push_back(sportiv);
   }
   return list;
}

