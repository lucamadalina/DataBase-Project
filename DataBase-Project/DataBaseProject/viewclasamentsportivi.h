#ifndef VIEWCLASAMENTSPORTIVI_H
#define VIEWCLASAMENTSPORTIVI_H

#include <QDialog>
namespace Ui {
class ViewClasamentSportivi;
}

class ViewClasamentSportivi : public QDialog
{
    Q_OBJECT

public:
    explicit ViewClasamentSportivi(QWidget *parent = 0);
    ~ViewClasamentSportivi();

private slots:
    void on_b_backToClasament_clicked();

private:
    Ui::ViewClasamentSportivi *ui;
};

#endif // VIEWCLASAMENTSPORTIVI_H
