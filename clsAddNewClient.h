#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClient : protected clsScreen
{
private :

    static void _ReadClientInfo(clsBankClient& Client)
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

	static void ShowAddNewClientScreen()
    {
        string AccountNumber;

        _DrawScreenHeader("Add New Client Screen");

        cout << "\nPlease enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose Another One : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        cout << "\Add New Client Info";
        cout << "\n-------------------------" << endl;

        clsBankClient nClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(nClient);

        clsBankClient::enSaveResults SaveResult = nClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeced:
            cout << "Account Added Succesfully :-)" << endl;
            _PrintClient(nClient);
            break;

        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError Account wasn't save because it is empty :-(" << endl;
            break;

        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            cout << "\nAccount Already Used :-(" << endl;
            break;

        }

    }

};

