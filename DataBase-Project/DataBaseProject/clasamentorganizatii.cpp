#include "clasamentorganizatii.h"

ClasamentOrganizatii::ClasamentOrganizatii()
{

}
ClasamentOrganizatii::ClasamentOrganizatii(int id,int id_organiatie,int nr_puncte){
    this->id = id;
    this->id_organiatie = id_organiatie;
    this->nr_puncte = nr_puncte;
}
ClasamentOrganizatii::getId(){
    return this->id;
}
ClasamentOrganizatii::getIdOrganizatie(){
    return this->id_organiatie;
}
ClasamentOrganizatii::getNumarPuncte(){
    return this->nr_puncte;
}
