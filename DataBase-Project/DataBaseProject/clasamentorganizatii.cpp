#include "clasamentorganizatii.h"

ClasamentOrganizatii::ClasamentOrganizatii()
{

}
ClasamentOrganizatii::ClasamentOrganizatii(int id,int id_organiatie,int nr_puncte){
    this->id = id;
    this->id_organiatie = id_organiatie;
    this->nr_puncte = nr_puncte;
}
int ClasamentOrganizatii::getId(){
    return this->id;
}
int ClasamentOrganizatii::getIdOrganizatie(){
    return this->id_organiatie;
}
int ClasamentOrganizatii::getNumarPuncte(){
    return this->nr_puncte;
}
