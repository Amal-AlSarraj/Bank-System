#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber;

		cout << "Please enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public :

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");

        string AccountNumber;
      //  clsBankClient Client;
        double Amount;
        char Ask;

        AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client with [" << AccountNumber << "] does not Exits, Enter another Account Number? ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "Please enter Deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "Are you sure you want to perform this transaction? Y/N? ";
        cin >> Ask;

        if (Ask == 'Y' || Ask == 'y')
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Successfully" << endl;
            cout << "\nNew Balance Is : " << Client.AccountBalance << endl;
        }

        else
        {
            cout << "\nOperation was Cancelled" << endl;
        }


      //  Deposit(vClientstAccount, AccountNumber, Amount);


	}


};

