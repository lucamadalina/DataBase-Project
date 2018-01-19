#include "categoriegen.h"

CategorieGen::CategorieGen()
{

}
CategorieGen::CategorieGen(int id, QString gen){
    this->id = id;
    this->gen = gen;
}
int CategorieGen::getId(){
    return this->id;
}
SQtring CategorieGen::getGen(){
    return this->gen;
}
