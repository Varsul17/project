#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Player.h"
#include "Manager.h"

class DataBase {

protected:
    std::fstream List;
    int playerCounter;
    int ManagerCounter;
    Player** playerArray;
    Manager** ManagerArray;

public:
    DataBase();
    ~DataBase();
    void AddPlayer(const Player& newPlayer);
    void AddManager(const Manager& newManager);
    void RemovePlayer(const char *playerID);
    void RemoveManager(const char *ManagerID);
    void PrintManager();
    void PrintPlayers();
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
