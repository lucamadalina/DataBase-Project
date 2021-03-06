#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AddCompetitie.h"
#include "clasament.h"

#include "administrarecompetitiepage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlField>
#include <QSqlRecord>
#include <QSettings>
#include <QActionGroup>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QDebug>
#include <QPixmap>
#include <QActionGroup>

static QSqlDatabase m_db;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    QPixmap pix(":/p7.jpg");
    ui->picture->setPixmap(pix.scaled(421, 91));

    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    readSettings(hostName, databaseName, userName, password);
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(hostName);
    m_db.setDatabaseName(databaseName);
    m_db.setUserName(userName);
    m_db.setPassword(password);
    bool ok = m_db.open();
    if(!ok)
    {
       ui->statusBar->showMessage(tr("Database not connected!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Database connected!"));
    }
   }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password)
{
    qDebug() << "App dir path " << qApp->applicationDirPath();
    QSettings s(qApp->applicationDirPath() + "/DataBase.conf", QSettings::IniFormat);
    hostName = s.value("HOSTNAME").toString();
    databaseName = s.value("DATABASENAME").toString();
    userName = s.value("USERNAME").toString();
    password = s.value("PASSWORD").toString();
    qDebug() << "Settings file name " << s.fileName();
}


void MainWindow::on_p_AdCompetitie_clicked()
{
    AdministrareCompetitiePage pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}

void MainWindow::on_p_Clasament_clicked()
{
    Clasament pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}

void MainWindow::on_p_AdCampionat_clicked()
{
    AddCompetitie pag;
    this->hide();
    pag.setModal(true);
    pag.exec();
}
 QSqlDatabase MainWindow::getDataBase()
 {
     return m_db;
  }


void MainWindow::on_b_close_clicked()
{
    close();
}
