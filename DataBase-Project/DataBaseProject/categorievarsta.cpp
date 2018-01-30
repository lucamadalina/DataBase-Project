#include "categorievarsta.h"

CategorieVarsta::CategorieVarsta()
{

}
CategorieVarsta::CategorieVarsta(int id, int prag_min, int prag_max){
    this->id = id;
    this->prag_min = prag_min;
    this->prag_max = prag_max;
}

CategorieVarsta::CategorieVarsta(int prag_min, int prag_max)
{
    this->prag_max = prag_max;
    this->prag_min = prag_min;
}
int CategorieVarsta::getId(){
    return this->id;
}
int CategorieVarsta::getPragMin(){
    return this->prag_min;
}
int CategorieVarsta::getPragMax(){
    return this->prag_max;
}
