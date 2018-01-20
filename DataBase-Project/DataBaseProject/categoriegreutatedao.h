#ifndef CATEGORIEGREUTATEDAO_H
#define CATEGORIEGREUTATEDAO_H
#include "categoriegreutate.h"
#include<vector>
#include<mainwindow.h>
#include<QSqlDatabase>
class CategorieGreutateDao
{
public:
    CategorieGreutateDao();
    void existTable();
    void AddCategorieGreutate(CategorieGreutate& categorieGreutate);
    void RemoveCategorieGreutate(int id);
    std::vector<CategorieGreutate> getCategoriiGreutate();
    bool ExistCategorieGreutate(int id);
private:
    MainWindow* mw;
    QSqlDatabase m_db;
};

#endif // CATEGORIEGREUTATEDAO_H
