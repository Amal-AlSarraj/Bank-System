#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private :
    
    string _Username;
    string _Password;
    bool _Deleted = false;
    int _Permissions;

    enum enMode {
        EmptyMode = 0, UpdateMode = 1,
        AddNewMode = 2
    };

    

    enMode _Mode;

    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += Username + Seperator;
        LoginRecord += clsUtil::EncryptText(Password) + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }

    

    static clsUser _ConvertLineToUserObject(string Line, string Delim = "#//#")
    {
        vector <string> vsUsers = clsString::Split(Line, Delim);

        return clsUser(enMode::UpdateMode, vsUsers[0], vsUsers[1], vsUsers[2], vsUsers[3], vsUsers[4], clsUtil::DecryptText(vsUsers[5]), stoi(vsUsers[6]));
    }

    static string _ConvertUserObjectToLine(clsUser User, string Delim = "#//#")
    {
        string record = "";

        record += User.FirstName + Delim;
        record += User.LastName + Delim;
        record += User.Email + Delim;
        record += User.Phone + Delim;
        record += User._Username + Delim;
        record += clsUtil::EncryptText(User._Password) + Delim;
        record += to_string(User._Permissions);

        return record;
    }

    static vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream FileStream;
        string Line;
       // clsUser User;

        FileStream.open("Users.txt", ios::in);

        if (FileStream.is_open())
        {
            while (getline(FileStream, Line))
            {
                vUsers.push_back(_ConvertLineToUserObject(Line));
            }
        }

        FileStream.close();

        return vUsers;
    }

    static void _SaveUsersDataToFile(vector <clsUser>& vUsers)
    {
        fstream MyFile;

        MyFile.open("Users.txt", ios::out);

        string Line;

        if (MyFile.is_open())
        {
            for (clsUser& C : vUsers)
            {
                if (C._Deleted)
                {
                    continue;
                }
                    
                Line = _ConvertUserObjectToLine(C);
                MyFile << Line << endl;
            
            }
        }

        MyFile.close();
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _Update()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : vUsers)
        {
            if (U.Username == Username)
            {
                U = *this;
                //break;
            }
        }

        _SaveUsersDataToFile(vUsers);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }



public:

    struct stLogInRegisterRecord
    {
        string DateTime;
        string Username;
        string Password;
        int Permissions;
    };

    enum enPermission
    {
        epAll = -1,
        epShowListClients = 1, epAddNewClient = 2,
        epDeleteClient = 4, epUpdateClient = 8,
        epFindClient = 16, epTransaction = 32,
        epManageUsers = 64, epLogInRegister = 128
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _Deleted;
    }
   
    string GetUsername()
    {
        return _Username;
    }

    void SetUsername(string Username)
    {
        _Username = Username;
    }

    _declspec (property(get = GetUsername, put = SetUsername)) string Username;

    string GetPassword()
    {
        return _Password;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    _declspec (property(get = GetPassword, put = SetPassword)) string Password;

    int GetPermissions()
    {
        return _Permissions;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    _declspec (property(get = GetPermissions, put = SetPermissions)) int Permissions;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    static clsUser Find(string Username)
    {
        string Line;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        while (getline(MyFile, Line))
        {
            clsUser User = _ConvertLineToUserObject(Line);
            if (User.Username == Username)
            {
                MyFile.close();
                return User;
            }

        }

        MyFile.close();
        return _GetEmptyUserObject();
    }

    static clsUser Find(string Username, string Password)
    {
        string Line;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        while (getline(MyFile, Line))
        {
            clsUser User = _ConvertLineToUserObject(Line);
            if (User.Username == Username && User.Password == Password)
            {
                MyFile.close();
                return User;
            }
        }

        MyFile.close();
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string Username)
    {
        clsUser User = Find(Username);
        return !(User._Mode == enMode::EmptyMode);
    }

    static clsUser GetAddNewUserObject(string Username)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
    }

    bool Delete()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : vUsers)
        {
            if (U.Username == Username)
            {
                U._Deleted = true;
                break;
            }
        }

        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();

        return true;

    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static vector <stLogInRegisterRecord> GetLoginRegisterRecords()
    {
        return LoadLogInRegisterDataFromFile();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0, svSucceeced = 1,
        svFailedAccountNumberExists = 3
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeced;

        case enMode::AddNewMode:
            if (IsUserExist(_Username))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }

            _AddNew();
            return enSaveResults::svSucceeced;
        }
    }


    bool CheckAccessPermission(enPermission ePermission)
    {
        if (this->Permissions == -1)
            return true;

        if ((this->Permissions & ePermission) == ePermission)
            return true;

        else
            return false;
    }

    void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static stLogInRegisterRecord ConvertLineToLogInRegister(string Line)
    {
        vector <string> vsLogInRegister = clsString::Split(Line, "#//#");
        stLogInRegisterRecord Record;

        Record.DateTime = vsLogInRegister[0];
        Record.Username = vsLogInRegister[1];
        Record.Password = clsUtil::DecryptText(vsLogInRegister[2]);
        Record.Permissions = stoi(vsLogInRegister[3]);

        return Record;
    }

    static vector <stLogInRegisterRecord>  LoadLogInRegisterDataFromFile()
    {
        vector <stLogInRegisterRecord> vLogInRegister;
        fstream FileStream;
        string Line;
        // clsUser User;

        FileStream.open("LoginRegister.txt", ios::in);

        if (FileStream.is_open())
        {
            while (getline(FileStream, Line))
            {
                vLogInRegister.push_back(ConvertLineToLogInRegister(Line));
            }
        }

        FileStream.close();

        return vLogInRegister;
    }
};

