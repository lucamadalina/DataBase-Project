#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#endif // CAMPIONAT_H


class Campionat
{

public:
    Campionat(int id, QString denumire, int puncteParticipare,  QString locatie,
        int puncteRunda1, int puncteSemiFinala, int puncteFinala);
    ~Campionat();

    int getId();
    QString getDenumire();
    QString getLocatie();
    int getPuncteParticipare();
    int getPuncteRunda1();
    int getPuncteSemiFinala();
    int getPuncteFinala();

private:
    int id;
    QString denumire;
    QString locatie;
    int puncteParticipare;
    int puncteRunda1;
    int puncteSemiFinala;
    int puncteFinala;
};
