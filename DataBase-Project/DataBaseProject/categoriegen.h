#ifndef CATEGORIEGEN_H
#define CATEGORIEGEN_H
#include<QString>

class CategorieGen
{
public:
    CategorieGen();
     CategorieGen(int id, QString gen);
     int getId();
     SQtring getGen();

private:
    int id;
    QString gen;
};

#endif // CATEGORIEGEN_H
