#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsTransferScreen : protected clsScreen
{
private :

    static void _PrintClient(clsBankClient Client)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber;

        cout << Message;
        cin >> AccountNumber;

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

public :

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        string AccNumFrom, AccNumTo;
        float Amount = 0;

        AccNumFrom = _ReadAccountNumber("\nPlease Enter Account Number To Transfer From : ");

        clsBankClient ClientFrom = clsBankClient::Find(AccNumFrom);
        _PrintClient(ClientFrom);

        AccNumTo = _ReadAccountNumber("\nPlease Enter Account Number To Transfer To : ");

        clsBankClient ClientTo = clsBankClient::Find(AccNumTo);
        _PrintClient(ClientTo);

        cout << "Enter Transfer Amount? ";
        Amount = clsInputValidate::ReadFloatNumberBetween(0, ClientFrom.AccountBalance, "Amount Exceed The Available Balance, Enter Another Amount? ");

        char Ask = 'n';

        cout << "\nAre You Sure You Want To Perform This Operation? ";
        cin >> Ask;

        if (Ask == 'Y' || Ask == 'y')
        {
            if (ClientFrom.Transfer(ClientTo, Amount))
            {
                cout << "\nTransfer done Successfully\n";

                _PrintClient(ClientFrom);
                _PrintClient(ClientTo);
            }

            else
                cout << "\nTransfer Failed\n";

        }

        


    }

};

