#include <iostream>
//207938085 segev isaac 12/06/1995 0524700771 segevis 01478963 givati_8/5 yes m segev11isaac@gmail.com
#include "DataBase.h"


int main() {

    DataBase d;
    Player newPlayer("newID7", "NewFirstName", "NewLastName", "NewDate", "NewPhone", "NewUsername", "NewPassword", "NewAddress", "NewVIP", "NewGender", "NewEmail");
    Manager newManager("newID7", "NewFirstName", "NewLastName", "NewDate", "NewPhone", "NewUsername", "NewPassword", "NewAddress", "NewVIP", "NewGender", "NewEmail");
    cout << newPlayer <<endl;
    cout << newManager <<endl;
    d.AddPlayer(newPlayer);
    d.PrintPlayers();
    d.AddManager(newManager);
    d.PrintManager();
//    d.RemoveManager("newID6");
//    d.RemovePlayer("newID6");
    return 0;
}
