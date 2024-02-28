#include "Manager.h"

bool Manager::Set_Location() {
    char loc[MAX];
    cout << "Enter the address of the branch, up to 30 characters:" << endl;
    msg06();
    cin.getline(loc, MAX);
    int len = int(strlen(loc));
    if (Blank_Line(len))
        return false;
    if (len > ADDRESS_LIM){
        cout << "The address is to long, please try again" << endl;
        return false;
    }
    for (int i = 0; i < len; ++i){
        if (!Check_Number(loc[i]) && !Check_Let(loc[i]) && loc[i] != SLASH && loc[i] != SPACE && loc[i] != BACKSLASH){
            cout << "Incorrect char was entered, please try again." << endl;
            return false;
        }
    }
    this->location = Set_String(loc);
    return true;
}