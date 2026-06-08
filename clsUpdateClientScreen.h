#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
{

private :

    static void ReadClientInfo(clsBankClient& Client)
    {


        cout << "\nPlease enter First Name : " << endl;
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease enter Last Name : " << endl;
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nPlease enter Email : " << endl;
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPlease enter Phone : " << endl;
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nPlease enter PIN Code : " << endl;
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nPlease enter Account Balance : " << endl;
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

    static void _PrintClient(clsBankClient Client)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";


    }


public :
	static void ShowUpdateClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermission::epUpdateClient))
        {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        cout << "\nenter Account Number : ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient uClient = clsBankClient::Find(AccountNumber);
        _PrintClient(uClient);

        cout << "\nUpdate Client Info";
        cout << "\n-------------------------" << endl;

        ReadClientInfo(uClient);

        clsBankClient::enSaveResults SaveReseult = uClient.Save();

        switch (SaveReseult)
        {
        case clsBankClient::enSaveResults::svSucceeced:
            cout << "Account Updated Succesfully :-)" << endl;
            _PrintClient(uClient);
            break;

        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError Account wasn't save because it is empty :-(" << endl;
            break;
        }


    }
};

