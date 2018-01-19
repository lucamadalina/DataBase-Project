#ifndef CATEGORIEVARSTA_H
#define CATEGORIEVARSTA_H


class CategorieVarsta
{
public:
    CategorieVarsta();
    CategorieVarsta(int id, int prag_min, int prag_max);
    int getId();
    int getPragMin();
    int getPragMax();

private:
    int id;
    int prag_min;
    int prag_max;
};

#endif // CATEGORIEVARSTA_H
