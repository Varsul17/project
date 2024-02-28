//
// Created by segev on 2/28/2024.
//

#include "DataBase.h"


DataBase::DataBase()
{
    cout <<"data base constructor" << endl;

    string FILE_PATH = "C:\\Users\\user\\Desktop\\work-fix\\Player list";
    {
        List.open(FILE_PATH, ios::in);

        if (!List) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH << endl;
            return;
        }

        playerCounter = 0;
        char temp[1000];

        // Use List.peek() to check for end-of-file
        while (List.peek() != EOF) {
            List.getline(temp, 1000);
            playerCounter++;
        }

        List.clear(); // Clear the end-of-file flag
        List.seekg(0, std::ios::beg);

        playerArray = new Player* [playerCounter];
        char id[50],fName[50],lName[50],date[50],phone[50],userName[50],password[50],address[50],vip[50],gender[50],email[100];

        for (int i = 0; i < playerCounter; ++i)
        {
            List.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address, vip, gender, email);
            playerArray[i] = new Player(id,fName,lName,date,phone,userName,password,address,vip,gender,email);
        }

    }
    List.close();

    cout <<"data base constructor" << endl;

    FILE_PATH = "C:\\Users\\user\\Desktop\\work-fix\\manager list";
    {
        List.open(FILE_PATH, ios::in);

        if (!List) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH << endl;
            return;
        }

        ManagerCounter = 0;
        char temp[1000];

        // Use List.peek() to check for end-of-file
        while (List.peek() != EOF) {
            List.getline(temp, 1000);
            ManagerCounter++;
        }

        List.clear(); // Clear the end-of-file flag
        List.seekg(0, std::ios::beg);

        ManagerArray = new Manager * [ManagerCounter];
        char id[50],fName[50],lName[50],date[50],phone[50],userName[50],password[50],address[50],location[50],gender[50],email[100];

        for (int i = 0; i < ManagerCounter; ++i)
        {
            List.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address, location, gender, email);
            ManagerArray[i] = new Manager(id,fName,lName,date,phone,userName,password,address,location,gender,email);
        }

    }
    List.close();



//    PrintPlayers();
}


DataBase::~DataBase()
{
    cout << "destructor" << std::endl;

    string FILE_PATH = "C:\\Users\\user\\Desktop\\work-fix\\Player list";

    ofstream ofs1(FILE_PATH, ofstream::out | ofstream::trunc);

    if (!ofs1.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH << std::endl;
        return;
    }

    for (int i = 0; i < playerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = playerArray[i]->Get_ID();
        const char* firstName = playerArray[i]->Get_First_Name();
        const char* lastName = playerArray[i]->Get_Last_Name();
        const char* birthday = playerArray[i]->Get_Birthday();
        const char* phone = playerArray[i]->Get_Phone();
        const char* username = playerArray[i]->Get_Username();
        const char* password = playerArray[i]->Get_Password();
        const char* address = playerArray[i]->Get_Address();
        const char* vip = playerArray[i]->Get_VIP();
        const char* gender = playerArray[i]->Get_Gender();
        const char* email = playerArray[i]->Get_Email();

        // Write values to the file
        ofs1 << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << vip << " " << gender << " " << email << std::endl;

    }


    ofs1.close(); // Close the file after writing

    FILE_PATH = "C:\\Users\\user\\Desktop\\work-fix\\manager list";

    ofstream ofs2(FILE_PATH, ofstream::out | ofstream::trunc);

    if (!ofs2.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH << endl;
        return;
    }

    for (int i = 0; i < ManagerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = ManagerArray[i]->Get_ID();
        const char* firstName = ManagerArray[i]->Get_First_Name();
        const char* lastName = ManagerArray[i]->Get_Last_Name();
        const char* birthday = ManagerArray[i]->Get_Birthday();
        const char* phone = ManagerArray[i]->Get_Phone();
        const char* username = ManagerArray[i]->Get_Username();
        const char* password = ManagerArray[i]->Get_Password();
        const char* address = ManagerArray[i]->Get_Address();
        const char* location = ManagerArray[i]->Get_Location();
        const char* gender = ManagerArray[i]->Get_Gender();
        const char* email = ManagerArray[i]->Get_Email();

        // Write values to the file
        ofs2 << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << location << " " << gender << " " << email << endl;

    }


    ofs2.close(); // Close the file after writing

    for (int i = 0; i < playerCounter; ++i)
        delete playerArray[i];
    delete[] playerArray;

    for (int i = 0; i < ManagerCounter; ++i)
        delete ManagerArray[i];
    delete[] ManagerArray;
}


void DataBase::PrintPlayers() {
    for (int i = 0; i < playerCounter; ++i)
        cout << *playerArray[i] << endl;
}


void DataBase::PrintManager() {
    for (int i = 0; i < ManagerCounter; ++i)
        cout << *ManagerArray[i] << endl;
}


void DataBase::AddPlayer(const Player &newPlayer)
{
// Create a new array with increased size
    auto** newArray = new Player*[playerCounter + 1];

    // Copy existing players to the new array
    for (int i = 0; i < playerCounter; ++i)
        newArray[i] = playerArray[i];

    // Add the new player to the end of the array
    newArray[playerCounter] = new Player(newPlayer);

    // Delete the old array
    delete[] playerArray;

    // Update the playerArray pointer
    playerArray = newArray;

    // Increment the playerCounter
    ++playerCounter;
}


void DataBase::AddManager(const Manager &newManager) {
    // Create a new array with increased size
    auto** newArray = new Manager*[ManagerCounter + 1];

    // Copy existing players to the new array
    for (int i = 0; i < ManagerCounter; ++i)
        newArray[i] = ManagerArray[i];

    // Add the new player to the end of the array
    newArray[ManagerCounter] = new Manager(newManager);

    // Delete the old array
    delete[] ManagerArray;

    // Update the playerArray pointer
    ManagerArray = newArray;

    // Increment the playerCounter
    ++ManagerCounter;
}


void DataBase::RemovePlayer(const char* playerID)
{
    // Find the index of the player with the given ID
    int index = -1;
    for (int i = 0; i < playerCounter; ++i) {
        if (strcmp(playerArray[i]->Get_ID(), playerID) == 0) {
            index = i;
            break;
        }
    }
    // If player found, remove from the array
    if (index != -1) {
        // Delete the player at the found position
        delete playerArray[index];

        // Shift the remaining players to fill the gap
        for (int i = index; i < playerCounter - 1; ++i)
            playerArray[i] = playerArray[i + 1];

        // Decrement the playerCounter
        --playerCounter;
    }
    else
        cerr << "Error: Player with ID " << playerID << " not found." << endl;
}


void DataBase::RemoveManager(const char* ManagerID)
{
    // Find the index of the player with the given ID
    int index = -1;
    for (int i = 0; i < ManagerCounter; ++i) {
        if (strcmp(ManagerArray[i]->Get_ID(), ManagerID) == 0) {
            index = i;
            break;
        }
    }
    // If player found, remove from the array
    if (index != -1) {
        // Delete the player at the found position
        delete ManagerArray[index];

        // Shift the remaining players to fill the gap
        for (int i = index; i < ManagerCounter - 1; ++i)
            ManagerArray[i] = ManagerArray[i + 1];

        // Decrement the playerCounter
        --ManagerCounter;
    }
    else
        cerr << "Error: Player with ID " << ManagerID << " not found." << endl;
}
