#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"


class clsAddNewUser : protected clsScreen
{

private : 
    static void _ReadUserInfo(clsUser& User)
    {


        cout << "\nPlease enter First Name : " << endl;
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease enter Last Name : " << endl;
        User.LastName = clsInputValidate::ReadString();

        cout << "\nPlease enter Email : " << endl;
        User.Email = clsInputValidate::ReadString();

        cout << "\nPlease enter Phone : " << endl;
        User.Phone = clsInputValidate::ReadString();

        cout << "\nPlease enter Username : " << endl;
        User.Username = clsInputValidate::ReadString();

        cout << "\nPlease enter Password Code : " << endl;
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

            cout << "\nLogIn Register? y/n?" << endl;
            cin >> Ask;
            if (Ask == 'Y' || Ask == 'y')
                Permission += clsUser::enPermission::epLogInRegister;
        }

        return Permission;
    }

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

public :

    static void ShowAddNewUserScreen()
    {
        string Username;

        _DrawScreenHeader("Add New User Screen");

        cout << "\nPlease enter Username : ";
        Username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(Username))
        {
            cout << "\nUsername Is Already Used, Choose Another One : ";
            Username = clsInputValidate::ReadString();
        }

        cout << "\Add New User Info";
        cout << "\n-------------------------" << endl;

        clsUser nUser = clsUser::GetAddNewUserObject(Username);
        _ReadUserInfo(nUser);

        clsUser::enSaveResults SaveResult = nUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeced:
            cout << "User Added Succesfully :-)" << endl;
            _PrintUser(nUser);
            break;

        case clsUser::enSaveResults::svFailedEmptyObject:
            cout << "\nError User wasn't save because it is empty :-(" << endl;
            break;

        case clsUser::enSaveResults::svFailedAccountNumberExists:
            cout << "\nUser Already Used :-(" << endl;
            break;

        }

    }

};

