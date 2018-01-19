#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#include <QDialog>
#include <mainwindow.h>
#include <addsportiv.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
namespace Ui {
class Campionat;
}

class Campionat : public QDialog
{
    Q_OBJECT

public:
    explicit Campionat(QWidget *parent = 0);
    ~Campionat();


public slots:
    void on_b_back_clicked();

private slots:
    //void on_ad_Sportiv_clicked();

private:
    Ui::Campionat *ui;
    MainWindow *mn;
    addSportiv *adSportiv;
};

#endif // CAMPIONAT_H
