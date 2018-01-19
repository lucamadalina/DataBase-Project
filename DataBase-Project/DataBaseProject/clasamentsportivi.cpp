#include "clasamentsportivi.h"

ClasamentSportivi::ClasamentSportivi()
{

}
ClasamentSportivi::ClasamentSportivi(int id,int id_sportiv,int id_categorie_greutate,int id_categorie_varsta,
                                     int id_categorie_gen,int nr_puncte){
    this->id = id;
    this->id_categorie_gen = id_categorie_gen;
    this->id_categorie_greutate = id_categorie_greutate;
    this->id_categorie_varsta = id_categorie_varsta;
    this->nr_puncte = nr_puncte;
}
int ClasamentSportivi::getId(){
    return  this->id;
}
int ClasamentSportivi::getIdCategorieGreutate(){
    return  this->id_categorie_gen;
}
int ClasamentSportivi::getIdCategorieVarsta(){
    return this->id_categorie_greutate;
}
int ClasamentSportivi::getIdCategorieGen(){
    return this->id_categorie_varsta;
}
int ClasamentSportivi::getNumarPuncte(){
    return this->nr_puncte;
}
