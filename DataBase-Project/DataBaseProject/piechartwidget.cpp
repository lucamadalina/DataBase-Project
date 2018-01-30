#include "piechartwidget.h"
#include <QPainter>
PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent)
{

}

void PieChartWidget::SetData(QVector<double> values, QVector<QColor> colors)
{
    qvValues = values;
    qvColors = colors;
    repaint();
    update();

}

void PieChartWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QRectF size;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    if(this->height() > this->width()){
        size = QRectF(5,5,this->width()-10, this->width()-10);
    }else{
        size = QRectF(5,5,this->height()-10, this->height()-10);
    }
    double sum = 0;
    double startAngle = 0.0;
    double angle, endAngle, percent;

    for(int i = 0; i< qvValues.size(); i++){
        sum += qvValues.at(i);
    }

    for(int i =0; i< qvValues.size(); i++){
        percent = qvValues.at(i) / sum;
        angle = percent * 360.0;
        endAngle = startAngle + angle;
        painter.setBrush(qvColors.at(i));
        painter.drawPie(size, startAngle*16, angle*16);
        startAngle = endAngle;
    }




}
