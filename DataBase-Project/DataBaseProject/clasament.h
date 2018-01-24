#ifndef CLASAMENT_H
#define CLASAMENT_H

#include <QDialog>
#include "mainwindow.h"
#include "viewclasament.h"
namespace Ui {
class Clasament;
}

class Clasament : public QDialog
{
    Q_OBJECT

public:
    explicit Clasament(QWidget *parent = 0);
    ~Clasament();

private slots:
    void on_b_back_clicked();

    void on_pushButton_clicked();

    void on_b_viewclasament_clicked();

private:
    Ui::Clasament *ui;
    MainWindow *mn;
    ViewClasament *vc;
};

#endif // CLASAMENT_H
