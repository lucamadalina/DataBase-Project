#ifndef SPORTIVDAO_H
#define SPORTIVDAO_H
#include<QString>
#include<QSqlDatabase>
#include<vector>
#include "mainwindow.h"
#include "clubsportiv.h"

using namespace std;
class Sportiv;

class SportivDao
{
public:
    SportivDao();
    //SportivDao(QSqlDatabase &m_db);
    void existTable();
    void AddSportiv(Sportiv& sportiv);
    void RemoveSportiv(int id);
    int calculateIdCategorieGreutate(int greutate);
    int calculateIdCategorieVarsta(int varsta);
    int calculateIdCategorieGen(QString gen);
    int getIdVarstaGreutateGen(int gen, int greutate, int varsta);
    QList<Sportiv> getSportivi();
    QList<Sportiv> getSportiviSimulare(int id);

private:
    bool SportivExist(int id);
    MainWindow* mw;
    QSqlDatabase m_db;

};

#endif // SPORTIVDAO_H
