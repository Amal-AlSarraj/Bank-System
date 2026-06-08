#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"

#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"


using namespace std;

class clsTransactionScreen : protected clsScreen
{
private :

	enum enTransactionsMenueOption
	{
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalances = 3, eTransfer = 4,
		eShowTransferLog = 5, eShowMainMenue = 6
	};

	static void _GoBackToTransactionMenue()
	{
		cout << "\n\nPress any key to go back to Transaction Menue...";
		system("pause>0");
		ShowTransactionMenue();
	}

	static short _ReadTransactionMenueOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		int Option = clsInputValidate::ReadIntNumberBetween(1, 6);

		return Option;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOption Option)
	{
		system("CLS");

		switch (Option)
		{
		case enTransactionsMenueOption::eDeposit :
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransactionsMenueOption::eWithdraw :
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransactionsMenueOption::eShowTotalBalances :
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransactionsMenueOption::eTransfer :
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransactionsMenueOption::eShowTransferLog :
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransactionsMenueOption::eShowMainMenue :
			break;

		}
	}

public :

	static void ShowTransactionMenue()
	{

		if (!CheckAccessRights(clsUser::enPermission::epTransaction))
		{
			return;
		}

		system("CLS");
		_DrawScreenHeader("\t\tTransaction Menue");

		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t\tTransaction Menue\n";
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t[1] Deposit.\n";
		cout << setw(40) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(40) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(40) << left << "" << "\t[4] Transfer.\n";
		cout << setw(40) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(40) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(40) << left << "" << "========================================\n";

		_PerformTransactionsMenueOption(enTransactionsMenueOption(_ReadTransactionMenueOption()));
	}

};

