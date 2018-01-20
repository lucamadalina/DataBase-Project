#ifndef CATEGORIEVARSTADAO_H
#define CATEGORIEVARSTADAO_H
#include<categorievarsta.h>
#include<vector>
#include<mainwindow.h>
#include<QSqlDatabase>

class CategorieVarstaDao
{
public:
    CategorieVarstaDao();
    void existTable();
    void AddCategorieVarsta(CategorieVarsta& categorieVarsta);
    void RemoveCategorieVarsta(int id);
    std::vector<CategorieVarsta> getCategoriiVarsta();
    // bool ExistCategorieVarsta(int id);

private:
    MainWindow* mw;
    QSqlDatabase m_db;
};


#endif // CATEGORIEVARSTADAO_H
