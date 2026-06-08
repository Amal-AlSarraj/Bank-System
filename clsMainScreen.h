#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsInputValidate.h"

#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"

#include "clsLogInRegisterScreen.h"

#include "Global.h"

#include "clsCurrencyExchangeScreen.h"

class clsMainScreen : protected clsScreen
{
private :
	enum enMainMenueOption
	{
		eListUser = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8,
		eCurrencyExchange = 9,
		eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		int Option = clsInputValidate::ReadIntNumberBetween(1, 10);

		return Option;
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClient::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenueScreen()
	{
		clsTransactionScreen::ShowTransactionMenue();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterListScreen()
	{
		clsLogInRegisterScreen::ShowLogInRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenueScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyEchangeMenue();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerformMainMenueOption(enMainMenueOption Option)
	{
		system("CLS");

		switch (Option)
		{
		case enMainMenueOption::eListUser :
			_ShowAllClientsScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eAddNewClient :
			_ShowAddNewClientScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eDeleteClient :
			_ShowDeleteClientScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eUpdateClient :
			_ShowUpdateClientScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eFindClient :
			_ShowFindClientScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eShowTransactionsMenue :
			_ShowTransactionsMenueScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eManageUsers :
			_ShowManageUsersScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eLoginRegister :
			_ShowLoginRegisterListScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eCurrencyExchange :
			_ShowCurrencyExchangeMenueScreen();
		//	_GoBackToMainMenue();
			break;

		case enMainMenueOption::eExit:
			_Logout();
			break;

		}

		if (Option != enMainMenueOption::eExit)
			_GoBackToMainMenue();
	}

public :

	static void ShowMainMenue()
	{
		system("CLS");
		_DrawScreenHeader("Main Menue");

		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t\tMain Menue\n";
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(40) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(40) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(40) << left << "" << "\t[4] Update Client.\n";
		cout << setw(40) << left << "" << "\t[5] Find Client.\n";
		cout << setw(40) << left << "" << "\t[6] Transaction.\n";
		cout << setw(40) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(40) << left << "" << "\t[8] LogIn Register.\n";
		cout << setw(40) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(40) << left << "" << "\t[10] Logout.\n";
		cout << setw(40) << left << "" << "========================================\n";

		_PerformMainMenueOption(enMainMenueOption(_ReadMainMenueOption()));
	}

};
