#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {

        cout << "\nUser Card:";
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

    static void ShowDeleteUserScreen()
    {
        string Username;
        char Ask;

        _DrawScreenHeader("\tDelete User Screen");

        cout << "\nPlease enter Username : ";
        Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUser is not found, choose another one : ";
            Username = clsInputValidate::ReadString();
        }

        clsUser dUser = clsUser::Find(Username);

        _PrintUser(dUser);

        cout << "Are you sure do you want to Delete this User? y/s ";
        cin >> Ask;

        if (Ask == 'Y' || Ask == 'y')
        {
            if (dUser.Delete())
            {
                cout << "\nUser Deleted Successfully :-)" << endl;
                _PrintUser(dUser);
            }

            else
            {
                cout << "\nError User Was Not Deleted :-(" << endl;
            }
        }

    }
};

