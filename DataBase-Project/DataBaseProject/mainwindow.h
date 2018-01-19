#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase getDb();


private slots:

    void readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password);

    void on_p_AdCompetitie_clicked();

    void on_p_Clasament_clicked();

    void on_p_AdCampionat_clicked();


private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
};

#endif // MAINWINDOW_H

