#include "simularelupte.h"
#include "ui_simularelupte.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QTimer>
#include <campionat.h>

simularelupte::simularelupte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simularelupte)
{
    ui->setupUi(this);
    setComboBox();
}

simularelupte::~simularelupte()
{
    delete ui;
}

std::vector<QString> simularelupte::getCompetitii()
{
   m_db = mw->getDataBase();
   QSqlQuery query(m_db);
   query.prepare("SELECT * FROM competitie");
   query.exec();

   std::vector<QString> list;
   while(query.next()) {
       QString denumire = query.value("denumire").toString();
       int id = query.value("id").toInt();
       QString locatie = query.value("locatie").toString();
       int puncteParticipare = query.value("puncte_participare").toInt();
       int puncteRunda1 = query.value("puncte_runda1").toInt();
       int puncteSemiFinala = query.value("puncte_semifinala").toInt();
       int puncteFinala = query.value("puncte_finala").toInt();
       Campionat campionat(id, denumire, puncteParticipare, locatie, puncteRunda1,
                           puncteSemiFinala, puncteFinala);
       list.push_back(denumire);
   }

   return list;
}

void simularelupte::setComboBox()
{
    std::vector<QString> listacompetitii = getCompetitii();
    QStringList list;
    for(QString const competitie : listacompetitii){
         list = list + (QStringList()<<competitie);
    }
    ui->comboBox->addItems(list);
}

void simularelupte::on_b_simulare_clicked()
{
    QString competitie = ui->comboBox->currentText();
    ui->textEdit->setText("Se va simula competitia " + competitie);
    ui->textEdit_2->setText(" ");
    ui->textEdit->setReadOnly(true);
    execute(competitie);
}
void simularelupte::execute(QString competitie){
    ui->textEdit_2->setReadOnly(true);
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("select varsta_greutate_gen.id, categorie_gen.gen, categorie_varsta.prag_min, categorie_varsta.prag_max,\
                        categorie_greutate.prag_min, categorie_greutate.prag_max\
                      from categorie_varsta inner join varsta_greutate_gen on categorie_varsta.id = varsta_greutate_gen.varsta_id\
                      inner join categorie_greutate on categorie_greutate.id = varsta_greutate_gen.greutate_id\
                      inner join categorie_gen on categorie_gen.id = varsta_greutate_gen.gen_id");
        query.exec();
        QString text;
        while(query.next()) {
            int j=0;
            int id = query.value(j++).toInt();
            QString gen = query.value(j++).toString();
            int varsta_prag_min = query.value(j++).toInt();
            int varsta_prag_max = query.value(j++).toInt();;
            int greutate_prag_min = query.value(j++).toInt();
            int greutate_prag_max = query.value(j++).toInt();
            text = text +"Se simuleaza categoria " + QString::number(varsta_prag_min) + "-"+
                    QString::number(varsta_prag_max) + " ani, "+QString::number(greutate_prag_min) + "- "+
                    QString::number(greutate_prag_max) + " kilograme, "+gen+ "\n";
            ui->textEdit_2->setText(text);
            listaSportivi = sportivDao.getSportiviSimulare(id);
            if(listaSportivi.empty() == true ){
                text = text  + "Competitia la aceasta categorie nu se poate desfasura!" + "\n"
                          +"Nu exista niciun sportiv inscris la aceasta categorie"+ "\n";
                ui->textEdit_2->setText(text);
            } else if(listaSportivi.size() < 8 ){
                text = text + "Competitia la aceasta categorie nu se poate desfasura!"
                +"Concurentii inscrisi nu sunt suficienti" + "\n";
                ui->textEdit_2->setText(text);
            } else {
                text = text + "Competitia la aceasta categorie s-a desfasurat" +"\n";
                ui->textEdit_2->setText(text);

                setPuncte(listaSportivi, competitie);

            }
        }
}

void simularelupte::setPuncte(QList<Sportiv> lista, QString competitie)
{
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("select * from competitie where denumire = (:denumire)");
    query.bindValue(":denumire", competitie);
    query.exec();
    QString denumire, locatie;
    int id, pp, pr1, ps, pf;
    if(query.next()) {
                denumire = query.value("denumire").toString();
               id = query.value("id").toInt();
                locatie = query.value("locatie").toString();
               pp = query.value("puncte_participare").toInt();
               pr1 = query.value("puncte_runda1").toInt();
               ps= query.value("puncte_semifinala").toInt();
               pf = query.value("puncte_finala").toInt();
    }
    Campionat campionat(id, denumire, pp, locatie, pr1,
                         ps, pf);
    QString text;

    text = text + "Sportivi care au pierdut in runda 1" +"\n";
    for(int k=0; k<8; k++){
        query.prepare("UPDATE clasament_sportiv\
                      SET numar_puncte = numar_puncte + (:numar)\
                      WHERE id_sportiv = (:id)");
         query.bindValue(":numar", campionat.getPuncteParticipare());
         query.bindValue(":id", lista[k].getId());
         query.exec();
         setPuncteOrganizatie(campionat.getPuncteParticipare(), lista[k].getIdClubSportiv());
         text = text + lista[k].getNume() + " " + lista[k].getPrenume() + "\n";
         ui->textEdit_3->setText(text);
         ui->textEdit_3->setReadOnly(true);
    }
     text = text + "Sportivi care au pierdut in runda 2" +"\n";
    for(int k=8; k<12; k++){
        query.prepare("UPDATE clasament_sportiv\
                      SET numar_puncte = numar_puncte + (:numar)\
                      WHERE id_sportiv = (:id)");
         query.bindValue(":numar", campionat.getPuncteRunda1());
         query.bindValue(":id", lista[k].getId());
         query.exec();
         setPuncteOrganizatie(campionat.getPuncteRunda1(), lista[k].getIdClubSportiv());
         text = text + lista[k].getNume() + " " + lista[k].getPrenume() + "\n";
         ui->textEdit_3->setText(text);
         ui->textEdit_3->setReadOnly(true);
    }
     text = text + "Sportivi care au pierdut in semifinala" +"\n";
    for(int k=12; k<14; k++){
        query.prepare("UPDATE clasament_sportiv\
                      SET numar_puncte = numar_puncte +(:numar)\
                      WHERE id_sportiv = (:id)");
         query.bindValue(":numar", campionat.getPuncteSemiFinala());
         query.bindValue(":id", lista[k].getId());
         query.exec();
         setPuncteOrganizatie(campionat.getPuncteSemiFinala(), lista[k].getIdClubSportiv());
         text = text + lista[k].getNume() + " " + lista[k].getPrenume() + "\n";
         ui->textEdit_3->setText(text);
         ui->textEdit_3->setReadOnly(true);
    }
     text = text + "Sportivi care au pierdut in finala" +"\n";
    for(int k=14; k<16; k++){
        query.prepare("UPDATE clasament_sportiv\
                      SET numar_puncte = numar_puncte + (:numar)\
                      WHERE id_sportiv = (:id)");
         query.bindValue(":numar", campionat.getPuncteFinala());
         query.bindValue(":id", lista[k].getId());
         query.exec();
         setPuncteOrganizatie(campionat.getPuncteFinala(), lista[k].getIdClubSportiv());
         text = text + lista[k].getNume() + " " + lista[k].getPrenume() + "\n";
         ui->textEdit_3->setText(text);
         ui->textEdit_3->setReadOnly(true);
    }

}

void simularelupte::setPuncteOrganizatie(int puncte, int idOrganizatie)
{
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("UPDATE clasament_organizatii\
                  SET numar_puncte = numar_puncte + (:numar)\
                  WHERE id_organizatie = (:id)");
    query.bindValue(":numar", puncte);
    query.bindValue(":id", idOrganizatie);
    int ok = query.exec();
    if(ok == 0){

     }
}


