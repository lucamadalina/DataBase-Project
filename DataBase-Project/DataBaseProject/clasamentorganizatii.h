#ifndef CLASAMENTORGANIZATII_H
#define CLASAMENTORGANIZATII_H


class ClasamentOrganizatii
{
public:
    ClasamentOrganizatii();
    ClasamentOrganizatii(int id,int id_organiatie,int nr_puncte);
    getId();
    getIdOrganizatie();
    getNumarPuncte();

private:
    int id;
    int id_organiatie;
    int nr_puncte;
};

#endif // CLASAMENTORGANIZATII_H
