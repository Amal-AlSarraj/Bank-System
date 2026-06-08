#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private :

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

public:

    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermission::epDeleteClient))
        {
            return;
        }

        string AccountNumber;
        char Ask;

        _DrawScreenHeader("\tDelete Client Screen");

        cout << "\nPlease enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient dClient = clsBankClient::Find(AccountNumber);

        _PrintClient(dClient);

        cout << "Are you sure do you want to Delete this Client? y/s ";
        cin >> Ask;

        if (Ask == 'Y' || Ask == 'y')
        {
            if (dClient.Delete())
            {
                cout << "\nClient Deleted Successfully :-)" << endl;
                _PrintClient(dClient);
            }

            else
            {
                cout << "\nError Client Was Not Deleted :-(" << endl;
            }
        }

    }

};

