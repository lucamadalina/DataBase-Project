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
    int j;
    QTableWidgetItem *newItem;
    for(i=0; i<finalList.size(); i++){
            newItem = new QTableWidgetItem(getNumeLuptator(finalList[i].getId()));
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
    lista_categoriilor = clasament.GetMemberForAfisareClasament();
    QString interval_varsta = lista_categoriilor.at(0);
    QString interval_greutate = lista_categoriilor.at(1);
    QString interval_gen = lista_categoriilor.at(2);

    QStringList split_list_varsta = interval_varsta.split(",");
    QString id_varsta = split_list_varsta.at(0);

    QStringList split_list_greutate = interval_greutate.split(",");
    QString id_greutate = split_list_greutate.at(0);

    QStringList split_list_gen = interval_gen.split(",");
    QString id_gen = split_list_gen.at(0);

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM clasament_sportivi WHERE id_categorie_greutate = (:id_greutate) AND id_categorie_varsta = (:id_varsta) AND id_categorie_gen = (:id_gen)");
    query.bindValue(":id_gen", id_gen);
    query.bindValue(":id_varsta", id_greutate);
    query.bindValue(":id_varsta", id_varsta);
    query.exec();

    std::vector<ClasamentSportivi> list;
    while (query.next())
    {
        int id = query.value("id").toInt();
        int nr_puncte = query.value("numar_puncte").toInt();
        int id_categorie_greutate = query.value("id_categorie_greutate").toInt();
        int id_categorie_varsta = query.value("id_categorie_varsta").toInt();
        int id_categorie_gen = query.value("id_categorie_gen").toInt();
        ClasamentSportivi co(id, id_categorie_greutate, id_categorie_varsta, id_categorie_gen, nr_puncte);
        list.push_back(co);
    }
    list = setOrdaring(list);;
    return list;
    }

QString ViewClasamentSportivi::getNumeLuptator(int id){
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM sportiv where id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    QString name;

    if (query.next()) {
         name = query.value("nume").toString();
       }
    return name;

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
        }
    }
    return list;
}

