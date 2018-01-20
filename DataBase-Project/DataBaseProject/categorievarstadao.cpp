#include "categorievarstadao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "sportiv.h"
#include "mainwindow.h"
CategorieVarstaDao::CategorieVarstaDao()
{

}


void CategorieVarstaDao::AddCategorieVarsta(CategorieVarsta& categorieVarsta)
{

    m_db = mw->getDataBase();
    int id = categorieVarsta.getId();
    int prag_min = categorieVarsta.getPragMin();
    int prag_max = categorieVarsta.getPragMax();
    QString values = "INSERT INTO categorie_varsta values("+QString::number(id)+", "+QString::number(prag_min)+", "+QString::number(prag_max)+")";
    QSqlQuery query(m_db);
        query.prepare("INSERT INTO categorie_varsta values(:id, :prag_min, prag_max");

            int ok = query.exec(values);
            if(ok == 0)
            {
               //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
            }
}


void CategorieVarstaDao::RemoveCategorieVarsta(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM categorie_varsta WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<CategorieVarsta> CategorieVarstaDao::getCategoriiVarsta()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_varsta");
    query.exec();

    std::vector<CategorieVarsta> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        CategorieVarsta cv(id, prag_min, prag_max);
         list.push_back(cv);
    }

    return list;
}
