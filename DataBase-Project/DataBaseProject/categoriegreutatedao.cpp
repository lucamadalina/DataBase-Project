#include "categoriegreutatedao.h"
#include "categoriegreutate.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "sportiv.h"
#include "mainwindow.h"
CategorieGreutateDao::CategorieGreutateDao()
{

}
void CategorieGreutateDao::existTable()
{
}

void CategorieGreutateDao::AddCategorieGreutate(CategorieGreutate& categorieGreutate)
{

    m_db = mw->getDataBase();
    int id = categorieGreutate.getId();
    int prag_min = categorieGreutate.getPragMin();
    int prag_max = categorieGreutate.getPragMax();
    QString values = "INSERT INTO categorie_greutate values("+QString::number(id)+", "+QString::number(prag_min)+", "+QString::number(prag_max)+")";
    QSqlQuery query(m_db);
        query.prepare("INSERT INTO categorie_greutate values(:id, :prag_min, prag_max");

            int ok = query.exec(values);
            if(ok == 0)
            {
               //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
            }
}


void CategorieGreutateDao::RemoveCategorieGreutate(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM categorie_greutate WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<CategorieGreutate> CategorieGreutateDao::getCategoriiGreutate()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_greutate");
    query.exec();

    std::vector<CategorieGreutate> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        CategorieGreutate cg(id, prag_min, prag_max);
         list.push_back(cg);
    }

    return list;
}
