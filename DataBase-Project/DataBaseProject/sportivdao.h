#ifndef SPORTIVDAO_H
#define SPORTIVDAO_H
#include<QString>
#include<QSqlDatabase>
#include<vector>
#include "mainwindow.h"

class Sportiv;

class SportivDao
{
public:
    SportivDao();
   // SportivDao(QSqlDatabase &m_db);
    void existTable();
    void AddSportiv(Sportiv& sportiv);
    void RemoveSportiv(int id);
    int calculateIdCategorieGreutate(int greutate);
    int calculateIdCategorieVarsta(int varsta);
    int calculateIdCategorieGen(QString gen);
    std::vector<Sportiv> getSportivi();

private:
    bool SportivExist(int id);
    MainWindow* mw;
    const QSqlDatabase& m_db = mw->getDb();

};

#endif // SPORTIVDAO_H
