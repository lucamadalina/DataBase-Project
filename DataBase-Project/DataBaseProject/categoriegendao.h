#ifndef CATEGORIEGENDAO_H
#define CATEGORIEGENDAO_H
#include"categoriegen.h"
#include<vector>
#include<mainwindow.h>
#include<QSqlDatabase>

class CategorieGenDao
{
public:
    CategorieGenDao();
    void existTable();
    void AddCategorieGen(CategorieGen& categorieGen);
    void RemoveCategorieGen(int id);
    std::vector<CategorieGen> getCategoriiGen();

private:
    bool ExistCategorieGen(int id);
    MainWindow* mw;
    QSqlDatabase m_db;
};

#endif // CATEGORIEGENDAO_H
