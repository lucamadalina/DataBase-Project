#ifndef CLASAMENTORGANIZATII_H
#define CLASAMENTORGANIZATII_H

class ClasamentOrganizatii
{
public:
    ClasamentOrganizatii();
    ClasamentOrganizatii(int id, int id_organizatie, int nr_puncte);
    int getId();
    void setId(int id);

    int getIdOrganizatie();
    void setIdOrganizatie(int id);

    int getNrPuncte();
    void setNrPuncte(int id);

private:
    int id;
    int id_organizatie;
    int nr_puncte;

};

#endif // CLASAMENTORGANIZATII_H
