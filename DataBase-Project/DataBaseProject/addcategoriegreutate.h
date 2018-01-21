#ifndef ADDCATEGORIEGREUTATE_H
#define ADDCATEGORIEGREUTATE_H
#include<categoriegreutatedao.h>
#include <QDialog>
#include "administrarecompetitiepage.h"
#include "addcategorievarsta.h"
namespace Ui {
class addcategoriegreutate;
}

class addcategoriegreutate : public QDialog
{
    Q_OBJECT

public:
    explicit addcategoriegreutate(QWidget *parent = 0);
    ~addcategoriegreutate();

private slots:
    void on_pushButton_clicked();

    void on_b_adCategorie_clicked();

    void on_b_back_clicked();

    void on_home_clicked();

private:
    Ui::addcategoriegreutate *ui;
    CategorieGreutateDao categorieGreutateDao;
    AdministrareCompetitiePage * adComPage;
    MainWindow* mn;
    addCategorieVarsta* addCatVarsta;
};

#endif // ADDCATEGORIEGREUTATE_H
