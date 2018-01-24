#include "viewclasament.h"
#include "ui_viewclasament.h"
#include "clasamentorganizatii.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

ViewClasament::ViewClasament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewClasament)
{
    ui->setupUi(this);
    finalList = getClasament();
    ui->tableWidget->setRowCount(finalList.size());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Denumire;Punctaj;").split(";"));
    ui->tableWidget->resize(600,600);
    int i;
    int j;
    QTableWidgetItem *newItem;
    for(i=0; i<finalList.size(); i++){
            newItem = new QTableWidgetItem(getNumeOrganizatie(finalList[i].getIdOrganizatie()));
            ui->tableWidget->setItem(i, 0, newItem);
            newItem = new QTableWidgetItem(QString::number(finalList[i].getNrPuncte()));
            ui->tableWidget->setItem(i, 1, newItem);

    }
}

ViewClasament::~ViewClasament()
{
    delete ui;
}

std::vector<ClasamentOrganizatii> ViewClasament::getClasament(){

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM clasament_organizatii");
    query.exec();

    std::vector<ClasamentOrganizatii> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        int id_organizatie = query.value("id_organizatie").toInt();
        int nr_puncte = query.value("numar_puncte").toInt();
        ClasamentOrganizatii co(id, id_organizatie, nr_puncte);
        list.push_back(co);
    }
    list = setOrdaring(list);;
    return list;
}
QString ViewClasament::getNumeOrganizatie(int id){
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM club_sportiv where id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    QString name;

    if (query.next()) {
         name = query.value("denumire").toString();
       }
    return name;

}

std::vector<ClasamentOrganizatii> ViewClasament::setOrdaring(std::vector<ClasamentOrganizatii> list){
    int i;
    int j;
    ClasamentOrganizatii aux;
    for(i=0; i<list.size();i++){
        for(j=i+1; j<list.size();j++){
            if(list[i].getNrPuncte() < list[j].getNrPuncte()){
                aux = list[i];
                list[i] = list[j];
                 list[j] = aux;
            }
        }
    }
    return list;
}
