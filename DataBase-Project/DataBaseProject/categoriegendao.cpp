#include "categoriegendao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include "sportiv.h"
#include "mainwindow.h"
CategorieGenDao::CategorieGenDao()
{

}
void CategorieGenDao::existTable()
{
}

void CategorieGenDao::AddCategorieGen(CategorieGen& categorieGen)
{

    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
        query.prepare("INSERT INTO categorie_gen values(:id, :gen");
            query.bindValue(":id", categorieGen.getId());
            query.bindValue(":gen", categorieGen.getGen());
            int ok = query.exec();
            if(ok == 0)
            {
               //QMessageBox::warning(this, tr("Eroare"), tr("id, varsta, greutate, id_club trebuie sa fie de tip int"));
            }
}


void CategorieGenDao::RemoveCategorieGen(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM categorie_gen WHERE Id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

std::vector<CategorieGen> CategorieGenDao::getCategoriiGen()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_gen");
    query.exec();

    std::vector<CategorieGen> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        QString gen = query.value("gen").toString();
        CategorieGen cg(id, gen);
         list.push_back(cg);
    }

    return list;
}
