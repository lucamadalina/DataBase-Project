#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void SetData(QVector<double> values, QVector<QColor> colors);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QVector<double> qvValues;
    QVector<QColor> qvColors;
signals:

public slots:

};

#endif // PIECHARTWIDGET_H
