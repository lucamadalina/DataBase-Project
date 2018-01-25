#include "clasament.h"
#include "ui_clasament.h"
Clasament::Clasament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clasament)
{
    ui->setupUi(this);
    GetCategoriiVarsta();
    GetCategoriiGreutate();
    GetCategoriiGen();
}

Clasament::~Clasament()
{
    delete ui;
}

void Clasament::on_b_back_clicked()
{
    mn = new MainWindow();
    this->hide();
    mn->show();
}

void Clasament::on_pushButton_clicked()
{
    //select
}

void Clasament::on_b_viewclasament_clicked()
{
    vc = new ViewClasament();
    this->hide();
    vc->show();
}

void Clasament::GetCategoriiVarsta()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_varsta");
    query.exec();
    std::vector<QString> list_of_categorie_varsta;
    while(query.next())
    {
        QString prag_min = query.value("prag_min").toString();
        QString prag_max = query.value("prag_max").toString();
        list_of_categorie_varsta.push_back(prag_min + "-" + prag_max);
    }
    qSort(list_of_categorie_varsta.begin(), list_of_categorie_varsta.end());
    for(std::vector<QString>::const_iterator i = list_of_categorie_varsta.begin(); i != list_of_categorie_varsta.end(); ++i)
    {
        ui->comboBox->addItem(*i);
    }
}

void Clasament::GetCategoriiGreutate()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_greutate");
    query.exec();
    std::vector<QString> list_of_categorie_greutate;
    while(query.next())
    {
        QString prag_min = query.value("prag_min").toString();
        QString prag_max = query.value("prag_max").toString();
        list_of_categorie_greutate.push_back(prag_min + "-" + prag_max);
    }
    qSort(list_of_categorie_greutate.begin(), list_of_categorie_greutate.end());
    for(std::vector<QString>::const_iterator i = list_of_categorie_greutate.begin(); i != list_of_categorie_greutate.end(); ++i)
    {
        ui->comboBox_2->addItem(*i);
    }
}

void Clasament::GetCategoriiGen()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_gen");
    query.exec();
    std::vector<QString> list_of_categorie_gen;
    while(query.next())
    {
        QString gen = query.value("gen").toString();
        list_of_categorie_gen.push_back(gen);
    }
    for(std::vector<QString>::const_iterator i = list_of_categorie_gen.begin(); i != list_of_categorie_gen.end(); ++i)
    {
        ui->comboBox_3->addItem(*i);
    }
}
