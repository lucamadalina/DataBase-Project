#include "viewclasamentsportivi.h"
#include "ui_viewclasamentsportivi.h"
#include "clasament.h"
#include <QTableWidget>
ViewClasamentSportivi::ViewClasamentSportivi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewClasamentSportivi)
{
    ui->setupUi(this);
    finalList = AfisareClasament();
    ui->tableWidget_1->setRowCount(finalList.size());
    ui->tableWidget_1->setColumnCount(2);
    ui->tableWidget_1->setHorizontalHeaderLabels(QString("Nume;Punctaj;").split(";"));
    ui->tableWidget_1->resize(600,600);
    int i;
    QTableWidgetItem *newItem;
    for(i=0; i<finalList.size(); i++){
            newItem = new QTableWidgetItem(finalList[i].getNumeSportiv());
            ui->tableWidget_1->setItem(i, 0, newItem);
            newItem = new QTableWidgetItem(QString::number(finalList[i].getNumarPuncte()));
            ui->tableWidget_1->setItem(i, 1, newItem);

    }

}

ViewClasamentSportivi::~ViewClasamentSportivi()
{
    delete ui;
}

void ViewClasamentSportivi::on_b_backToClasament_clicked()
{
    Clasament c;
    this->hide();
    c.setModal(true);
    c.exec();

}

std::vector<ClasamentSportivi> ViewClasamentSportivi::AfisareClasament()
{
    Clasament clasament;
    std::vector<QString> lista_categoriilor;
    lista_categoriilor = clasament.getListaCategorii();
    QString interval_varsta = lista_categoriilor.at(0);
    QString interval_greutate = lista_categoriilor.at(1);
    QString interval_gen = lista_categoriilor.at(2);

    QStringList split_list_varsta = interval_varsta.split(".");
    QString id_varsta = split_list_varsta.at(0);

    QStringList split_list_greutate = interval_greutate.split(".");
    QString id_greutate = split_list_greutate.at(0);

    QStringList split_list_gen = interval_gen.split(".");
    QString id_gen = split_list_gen.at(0);

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);

   int id_categoriiSelectate = 0;
    QString text = "select varsta_greutate_gen.id from varsta_greutate_gen inner join clasament_sportiv \
             on  varsta_greutate_gen.id = clasament_sportiv.id_varsta_greutate_gen and \
               varsta_greutate_gen.varsta_id = "+id_varsta +
             " and varsta_greutate_gen.greutate_id = "+id_greutate+" and varsta_greutate_gen.gen_id="+id_gen;


    query.prepare("select varsta_greutate_gen.id from varsta_greutate_gen inner join clasament_sportiv \
                  on  varsta_greutate_gen.id = clasament_sportiv.id_varsta_greutate_gen and \
                    varsta_greutate_gen.varsta_id = (:id_varsta) \
                  and varsta_greutate_gen.greutate_id = (:id_greutate) and varsta_greutate_gen.gen_id=(:id_gen)");
    query.exec(text);
    if (query.next()){
        id_categoriiSelectate = query.value(0).toInt();
    }
    std::vector<ClasamentSportivi> listaFinala;
    query.prepare("select * from clasament_sportiv where id_varsta_greutate_gen=(:id_categorii)");
    query.bindValue(":id_categorii", id_categoriiSelectate);
    query.exec();
    while(query.next()){
        int id_sportiv = query.value("id_sportiv").toInt();
        int numar_puncte = query.value("numar_puncte").toInt();
        Sportiv sportiv = getSportiv(id_sportiv);
        ClasamentSportivi cs(sportiv, numar_puncte);
        listaFinala.push_back(cs);
    }
    listaFinala = setOrdaring(listaFinala);
    return listaFinala;
    }

Sportiv ViewClasamentSportivi::getSportiv(int id){
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM sportiv where id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    QString nume;
    QString prenume;
    int varsta, greutate;
    if (query.next()) {
         nume = query.value("nume").toString();
         prenume = query.value("prenume").toString();
         varsta = query.value("varsta").toInt();
         greutate = query.value("greutate").toInt();

       }
     Sportiv sp(nume, prenume, varsta, greutate);
    return sp;
}

std::vector<ClasamentSportivi> ViewClasamentSportivi::setOrdaring(std::vector<ClasamentSportivi> list){
    int i;
    int j;
    ClasamentSportivi aux;
    for(i=0; i<list.size();i++){
        for(j=i+1; j<list.size();j++){
            if(list[i].getNumarPuncte() < list[j].getNumarPuncte()){
                aux = list[i];
                list[i] = list[j];
                 list[j] = aux;
            }
            if(list[i].getNumarPuncte() == list[j].getNumarPuncte()){
                if(list[i].getSportiv().getGreutate() > list[j].getSportiv().getGreutate()){
                    aux = list[i];
                    list[i] = list[j];
                     list[j] = aux;
                }
            }

        }
    }
    return list;
}

