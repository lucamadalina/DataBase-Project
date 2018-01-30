#ifndef CLASAMENTSPORTIVI_H
#define CLASAMENTSPORTIVI_H
#include <QString>
#include <sportiv.h>

class ClasamentSportivi
{
public:
    ClasamentSportivi();
    ClasamentSportivi(int id,int id_categorie_greutate,int id_categorie_varsta,int id_categorie_gen,int nr_puncte);
    ClasamentSportivi(QString numeSportiv, int nr_puncte);
    ClasamentSportivi(Sportiv sportiv, int nr_puncte);

    int getId();
    int getIdCategorieGreutate();
    int getIdCategorieVarsta();
    int getIdCategorieGen();
    int getNumarPuncte();
    QString getNumeSportiv();
    Sportiv getSportiv();

private:
    int id;
    int id_sportiv;
    QString numeSportiv;
    Sportiv sportiv;
    int id_categorie_greutate;
    int id_categorie_varsta;
    int id_categorie_gen;
    int nr_puncte;
};

#endif // CLASAMENTSPORTIVI_H
