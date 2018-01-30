#include "sportiv.h"

Sportiv::Sportiv()
{

}
Sportiv::Sportiv(int id, QString nume, QString prenume, int varsta,
                 int greutate, QString tara, QString gen, int id_clubSportiv){
    this->id = id;
    this->nume = nume;
    this->prenume = prenume;
    this->tara = tara;
    this->gen = gen;
    this->varsta = varsta;
    this->greutate = greutate;
    this->id_clubSportiv = id_clubSportiv;

}

Sportiv::Sportiv(QString nume, QString prenume,long cnp, int varsta, int greutate, QString tara, QString gen, int id_clubSportiv)
{
    this->nume = nume;
    this->prenume = prenume;
    this->cnp = cnp;
    this->tara = tara;
    this->gen = gen;
    this->varsta = varsta;
    this->greutate = greutate;
    this->id_clubSportiv = id_clubSportiv;

}

Sportiv::Sportiv(QString nume, QString prenume, int varsta, int greutate)
{
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->greutate = greutate;

}
int Sportiv::getId(){
    return this->id;
}
QString Sportiv::getNume(){
    return this->nume;
}
QString Sportiv::getPrenume(){
    return this->prenume;
}

QString Sportiv::getTara(){
    return this->tara;
}
QString Sportiv::getGen(){
    return this->gen;
}
int Sportiv::getVarsta(){
    return this->varsta;
}
int Sportiv::getGreutate(){
    return this->greutate;
}
int Sportiv::getIdClubSportiv(){
    return this->id_clubSportiv;
}

long Sportiv::getCNP()
{
    return this->cnp;
}
