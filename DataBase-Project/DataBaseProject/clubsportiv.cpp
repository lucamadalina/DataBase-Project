#include "clubsportiv.h"

ClubSportiv::ClubSportiv()
{

}
ClubSportiv::ClubSportiv(int id, QString denumire, QString tara, QString adresa){
            this->id = id;
            this->denumire = denumire;
            this->adresa = adresa;
            this->tara = tara;
}
int ClubSportiv::getId(){
    return this->id;
}
QString ClubSportiv::getDenumire(){
    return this->denumire;
}
QString ClubSportiv::getTara(){
    return this->tara;
}
QString ClubSportiv::getAdresa(){
    return this->adresa;
}
