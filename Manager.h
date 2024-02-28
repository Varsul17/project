//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
#include "User.h"

class Manager: public User {

private:
private:
    char * location;
public:
    bool Set_Location();
    char* Get_Location(){return this->location;};
    Manager(): User(){while(!Set_Location());}
    Manager(char *n_ID, char *f_name, char *l_name, char* birth,
            char *n_phone, char *user, char *password, char *address,
            char *Location, char* gender,char* email)
            : User(n_ID,f_name,l_name,gender,email,n_phone,user,password,address,birth)
    {location = Location;}
    ~Manager(){}//delete [] this->location;}
    friend ostream& operator<<(ostream& out, Manager& print){ out << static_cast<User&>(print); out << "Location of the branch: " << print.Get_Location() << endl; return out;}
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
