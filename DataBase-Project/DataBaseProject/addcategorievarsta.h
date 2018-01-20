#ifndef ADDCATEGORIEVARSTA_H
#define ADDCATEGORIEVARSTA_H
#include<categorievarstadao.h>
#include <QDialog>
#include "administrarecompetitiepage.h"
namespace Ui {
class addCategorieVarsta;
}

class addCategorieVarsta : public QDialog
{
    Q_OBJECT

public:
    explicit addCategorieVarsta(QWidget *parent = 0);
    ~addCategorieVarsta();

private slots:
    void on_b_addCatVarsta_clicked();

    void on_b_back_clicked();

private:
    Ui::addCategorieVarsta *ui;
     CategorieVarstaDao categorieVarstaDao;
     AdministrareCompetitiePage * adComPage;
};

#endif // ADDCATEGORIEVARSTA_H
