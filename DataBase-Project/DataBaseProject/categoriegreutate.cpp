#include "categoriegreutate.h"

CategorieGreutate::CategorieGreutate()
{

}
CategorieGreutate::CategorieGreutate(int id, int prag_min, int prag_max){
    this->id = id;
    this->prag_min = prag_min;
    this->prag_max = prag_max;
}
int CategorieGreutate::getId(){
    return this->id;
}
int CategorieGreutate::getPragMin(){
    return this->prag_min;
}
int CategorieGreutate::getPragMax(){
    return this->prag_max;
}
