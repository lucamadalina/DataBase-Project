#ifndef CAMPIONATDAO_H
#define CAMPIONATDAO_H

#endif // CAMPIONATDAO_H
class Campionat;

class CampionatDao
{
public:
    CampionatDao();
    void existTable();
    void AddCampionat(Campionat& campionat);
    void RemoveCampionat(int id);

    std::vector<Campionat> getCampionate();

private:
    bool campionatExist(int id);
    MainWindow* mw;
    QSqlDatabase m_db;
};
