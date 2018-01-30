#ifndef SPORTIV_H
#define SPORTIV_H
#include <QString>

class Sportiv
{
public:
    Sportiv();
    Sportiv(int id, QString nume, QString prenume, int varsta,
            int greutate, QString tara, QString gen, int id_clubSportiv);
    Sportiv( QString nume, QString prenume,long cnp, int varsta,
            int greutate, QString tara, QString gen, int id_clubSportiv);
    Sportiv(QString nume, QString prenume, int varsta, int greutate);
    int getId();
    QString getNume();
    QString getPrenume();
    QString getTara();
    QString getGen();
    int getVarsta();
    int getGreutate();
    int getIdClubSportiv();
    long getCNP();


private:
    int id;
    int varsta;
    int greutate;
    int id_clubSportiv;
    long cnp;
    QString nume;
    QString prenume;
    QString tara;
    QString gen;
};


#endif // SPORTIV_H
