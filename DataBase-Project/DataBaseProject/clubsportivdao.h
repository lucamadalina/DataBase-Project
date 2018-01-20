#ifndef CLUBSPORTIVDAO_H
#define CLUBSPORTIVDAO_H
#include<clubsportiv.h>
#include<vector>
#include "clubsportiv.h"
#include<mainwindow.h>
#include<QSqlDatabase>
class ClubSportivDao
{
public:
    ClubSportivDao();
    void existTable();
    void AddClubSportiv(ClubSportiv& clubSportiv);
    void RemoveClubSportiv(int id);
    std::vector<ClubSportiv> getCluburiSportive();

private:
    bool ExistClubSportiv(int id);
    MainWindow* mw;
    QSqlDatabase m_db;
};

#endif // CLUBSPORTIVDAO_H
