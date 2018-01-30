#include "clasament.h"
#include "ui_clasament.h"


static std::vector<QString> listaCategorii;

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
    QStringList list_of_categorie_varsta;
    QString categorie_varsta;

    while(query.next())
    {
        QString id = query.value("id").toString();
        QString prag_min = query.value("prag_min").toString();
        QString prag_max = query.value("prag_max").toString();
        categorie_varsta = id+"."+prag_min+"-"+prag_max;
        list_of_categorie_varsta = list_of_categorie_varsta + (QStringList()<<categorie_varsta);
    }
    ui->comboBox->addItems(list_of_categorie_varsta);
}

void Clasament::GetCategoriiGreutate()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_greutate");
    query.exec();
    QStringList list_of_categorie_greutate;
    QString categorie_greutate;

    while(query.next())
    {
        QString id = query.value("id").toString();
        QString prag_min = query.value("prag_min").toString();
        QString prag_max = query.value("prag_max").toString();
        categorie_greutate = id+"."+prag_min+"-"+prag_max;
       list_of_categorie_greutate = list_of_categorie_greutate + (QStringList()<<categorie_greutate);
    }
    ui->comboBox_2->addItems(list_of_categorie_greutate);
}

void Clasament::GetCategoriiGen()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM categorie_gen");
    query.exec();
    QStringList list_of_categorie_gen;
    QString categorie_gen;

    while(query.next())
    {   QString id = query.value("id").toString();
        QString gen = query.value("gen").toString();
        categorie_gen = id+"."+gen;
        list_of_categorie_gen = list_of_categorie_gen + (QStringList()<<categorie_gen);
    }
    ui->comboBox_3->addItems(list_of_categorie_gen);
}

void Clasament::on_b_afisaticlasamentul_clicked()
{
    listaCategorii = getCategoriiSelectate();
    vcs = new ViewClasamentSportivi();
    this->hide();
    vcs->show();

}

std::vector<QString> Clasament::getCategoriiSelectate()
{
    std::vector<QString> lista_categorii;
    QString interval_varsta = ui->comboBox->currentText();
    QString inveral_greutate = ui->comboBox_2->currentText();
    QString gen = ui->comboBox_3->currentText();
    lista_categorii.push_back(interval_varsta);
    lista_categorii.push_back(inveral_greutate);
    lista_categorii.push_back(gen);

    return lista_categorii;
}

std::vector<QString> Clasament::getListaCategorii()
{
    return listaCategorii;
}
