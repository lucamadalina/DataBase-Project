#ifndef CATEGORIEGREUTATE_H
#define CATEGORIEGREUTATE_H


class CategorieGreutate
{
public:
    CategorieGreutate();
    CategorieGreutate(int id, int prag_min, int prag_max);
    int getId();
    int getPragMin();
    int getPragMax();

private:
    int id;
    int prag_min;
    int prag_max;
};

#endif // CATEGORIEGREUTATE_H
