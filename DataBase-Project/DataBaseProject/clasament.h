#ifndef CLASAMENT_H
#define CLASAMENT_H

#include <QDialog>
#include "mainwindow.h"
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

    void on_pushButton_2_clicked();

private:
    Ui::Clasament *ui;
    MainWindow *mn;
};

#endif // CLASAMENT_H
