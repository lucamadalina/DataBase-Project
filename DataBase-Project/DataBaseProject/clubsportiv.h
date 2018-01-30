#ifndef CLUBSPORTIV_H
#define CLUBSPORTIV_H
#include<QString>


class ClubSportiv
{
public:
    ClubSportiv();
    ClubSportiv(int id, QString denumire, QString tara, QString adresa);
     ClubSportiv( QString denumire, QString tara, QString adresa);
    int getId();
    QString getDenumire();
    QString getTara();
    QString getAdresa();

private:
    int id;
    QString denumire;
    QString tara;
    QString adresa;
};

#endif // CLUBSPORTIV_H
