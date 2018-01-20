#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#include <QDialog>
#include <mainwindow.h>
#include <campionatdao.h>
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
class AddCompetitie;
}

class AddCompetitie : public QDialog
{
    Q_OBJECT

public:
    explicit AddCompetitie(QWidget *parent = 0);
    ~AddCompetitie();


public slots:
    void on_b_back_clicked();

private slots:
    void on_Add_competitie_clicked();

private:
    Ui::AddCompetitie *ui;
    MainWindow *mn;
    CampionatDao campionatDao;
};

#endif // CAMPIONAT_H
