#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H


#include "User.h"

class Player: public User {
private:
    char* VIP;

public :
    Player(): User(){Set_VIP();}
    Player(char *n_ID, char *f_name, char *l_name, char* birth,
           char *n_phone, char *user, char *password, char *address,
           char *VIP, char* gender,char* email)
            : User(n_ID,f_name,l_name,gender,email,n_phone,user,password,address,birth)
    {this->VIP = Set_String(VIP);}
//    ~Player(){delete [] this->VIP;}

    void Set_VIP();
    char* Get_VIP(){return this->VIP;}
    friend ostream& operator<<(ostream& out, Player& print){ out << static_cast<User&>(print); out << "VIP: " << print.Get_VIP() << endl; return out;}
};

#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
