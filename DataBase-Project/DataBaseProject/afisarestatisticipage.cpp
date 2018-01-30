#include "afisarestatisticipage.h"
#include "ui_afisarestatisticipage.h"
#include "clasament.h"

AfisareStatisticiPage::AfisareStatisticiPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfisareStatisticiPage)
{
    ui->setupUi(this);
    list = getClasamentForChart();
    QString legend;
    int n = list.size();
    QVector<QColor> colors = rndColors(n);
    QVector<double> values;
    for(int i = 0; i < list.size(); i++){
          values.push_back((double)(list[i].getNrPuncte()));
          legend +=(colors[i].name()+ " -- "+getNumeOrganizatieForChart((list[i].getIdOrganizatie()))+'\n');
    }
    ui->pieChart->SetData(values, colors);
    ui->legend->setText(legend);
}

AfisareStatisticiPage::~AfisareStatisticiPage()
{
    delete ui;
}

std::vector<ClasamentOrganizatii> AfisareStatisticiPage::getClasamentForChart()
{
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM clasament_organizatii");
    query.exec();

    std::vector<ClasamentOrganizatii> list;
    while(query.next()) {

        int id = query.value("id").toInt();
        int id_organizatie = query.value("id_organizatie").toInt();
        int nr_puncte = query.value("numar_puncte").toInt();
        ClasamentOrganizatii co(id, id_organizatie, nr_puncte);
        list.push_back(co);
    }
    return list;
}

QString AfisareStatisticiPage::getNumeOrganizatieForChart(int id)
{
    m_db = mw->getDataBase();
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM club_sportiv where id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    QString name;

    if (query.next()) {
         name = query.value("denumire").toString();
       }
    return name;
}

QVector<QColor> AfisareStatisticiPage::rndColors(int count)
{
    QVector<QColor> colors;

        float currentHue = 0.0;

        for (int i = 0; i < count; i++){

            colors.push_back( QColor::fromHslF(currentHue, 1.0, 0.5) );

            currentHue += 0.618033988749895f;

            currentHue = std::fmod(currentHue, 1.0f);

        }

        return colors;
}

void AfisareStatisticiPage::on_b_backToClasament_clicked()
{
    Clasament c;
    this->hide();
    c.setModal(true);
    c.exec();

}
