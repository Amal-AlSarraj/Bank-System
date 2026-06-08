#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{

private:

    static void _PrintUser(clsUser User)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUsername    : " << User.Username;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";


    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");

        string Username;
        char Ask;

        cout << "\nPlease enter Username : ";
        Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUser is not found, choose another one : ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(Username);

        if (User.IsEmpty())
        {
            cout << "\nUser Was not Found :-(" << endl;
        }

        else
        {
            cout << "\nUser Found :-)" << endl;
            _PrintUser(User);
        }


    }

};

