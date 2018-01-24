#include "clasamentorganizatii.h"


ClasamentOrganizatii::ClasamentOrganizatii(){


}

ClasamentOrganizatii::ClasamentOrganizatii(int id, int id_organizatie, int nr_puncte){
    this->id = id;
    this->id_organizatie = id_organizatie;
    this->nr_puncte = nr_puncte;

}

int ClasamentOrganizatii::getId(){
    return this->id;
}
int ClasamentOrganizatii::getIdOrganizatie(){
    return this->id_organizatie;
}

int ClasamentOrganizatii::getNrPuncte(){
    return this->nr_puncte;
}

void ClasamentOrganizatii::setId(int id){
    this->id = id;
}

void ClasamentOrganizatii::setIdOrganizatie(int id){
    this->id_organizatie = id;
}

void ClasamentOrganizatii::setNrPuncte(int nr){
    this->nr_puncte = nr;
}
