#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

    static void ReadUserInfo(clsUser& User)
    {


        cout << "\nPlease enter First Name : " << endl;
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease enter Last Name : " << endl;
        User.LastName = clsInputValidate::ReadString();

        cout << "\nPlease enter Email : " << endl;
        User.Email = clsInputValidate::ReadString();

        cout << "\nPlease enter Phone : " << endl;
        User.Phone = clsInputValidate::ReadString();

        cout << "\nPlease enter PIN Code : " << endl;
        User.Password = clsInputValidate::ReadString();

        cout << "\nPlease enter Account Balance : " << endl;
        User.Permissions = _ReadPermissionsToSet();
    }

    static int _ReadPermissionsToSet()
    {
        int Permission = 0;
        char Ask = 'N';

        cout << "\nDo you want to give full acces? y/n?" << endl;
        cin >> Ask;

        if (Ask == 'Y' || Ask == 'y')
            return -1;

        else
        {
            cout << "\nDo you want to gove access to :" << endl;

            cout << "\nShow List Users? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epShowListClients;

            cout << "\nAdd New User? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epAddNewClient;

            cout << "\nDelete User? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epDeleteClient;

            cout << "\nUpdate User? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epUpdateClient;

            cout << "\nFind User? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epFindClient;

            cout << "\nTransaction? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epTransaction;
        }

        return Permission;
    }

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
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        cout << "\nEnter Username : ";
        string Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one ";
            Username = clsInputValidate::ReadString();
        }

        clsUser uUser = clsUser::Find(Username);
        _PrintUser(uUser);

        cout << "\nUpdate User Info";
        cout << "\n-------------------------" << endl;

        ReadUserInfo(uUser);

        clsUser::enSaveResults SaveReseult = uUser.Save();

        switch (SaveReseult)
        {
        case clsUser::enSaveResults::svSucceeced:
            cout << "User Updated Succesfully :-)" << endl;
            _PrintUser(uUser);
            break;

        case clsUser::enSaveResults::svFailedEmptyObject:
            cout << "\nError User wasn't save because it is empty :-(" << endl;
            break;
        }


    }
};

