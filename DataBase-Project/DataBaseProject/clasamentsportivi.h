#ifndef CLASAMENTSPORTIVI_H
#define CLASAMENTSPORTIVI_H


class ClasamentSportivi
{
public:
    ClasamentSportivi();
    ClasamentSportivi(int id,int id_sportiv,int id_categorie_greutate,int id_categorie_varsta,int id_categorie_gen,int nr_puncte);
    int getId();
    int getIdCategorieGreutate();
    int getIdCategorieVarsta();
    int getIdCategorieGen();
    int getNumarPuncte();

private:
    int id;
    int id_sportiv;
    int id_categorie_greutate;
    int id_categorie_varsta;
    int id_categorie_gen;
    int nr_puncte;
};

#endif // CLASAMENTSPORTIVI_H
