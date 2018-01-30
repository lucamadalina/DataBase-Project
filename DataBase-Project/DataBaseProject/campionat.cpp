#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "campionat.h"


Campionat::Campionat(int id, QString denumire, int puncteParticipare, QString locatie,
                     int puncteRunda1, int puncteSemiFinala, int puncteFinala){
    this->id = id;
    this->denumire = denumire;
    this->locatie = locatie;
    this->puncteParticipare = puncteParticipare;
    this->puncteRunda1 = puncteRunda1;
    this->puncteSemiFinala = puncteSemiFinala;
    this->puncteFinala = puncteFinala;

}

Campionat::Campionat(QString denumire, int puncteParticipare, QString locatie, int puncteRunda1, int puncteSemiFinala, int puncteFinala)
{
    this->denumire = denumire;
    this->locatie = locatie;
    this->puncteParticipare = puncteParticipare;
    this->puncteRunda1 = puncteRunda1;
    this->puncteSemiFinala = puncteSemiFinala;
    this->puncteFinala = puncteFinala;
}

Campionat::~Campionat(){

}
int Campionat::getId(){
    return this->id;
}

QString Campionat::getDenumire(){
    return this->denumire;
}

QString Campionat::getLocatie(){
    return this->locatie;
}

int Campionat::getPuncteParticipare(){
    return this->puncteParticipare;
}

int Campionat::getPuncteRunda1(){
    return this->puncteRunda1;
}

int Campionat::getPuncteSemiFinala(){
    return this->puncteSemiFinala;
}

int Campionat::getPuncteFinala(){
    return this->puncteFinala;
}
