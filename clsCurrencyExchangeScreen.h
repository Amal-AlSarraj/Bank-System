#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : public clsScreen
{

private:
	enum enCurrancyExhangeMenueOption
	{
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4,
		eMainMenue = 5

	};

	static short _ReadCurrencyExhangeMenueOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Option = clsInputValidate::ReadIntNumberBetween(1, 5);

		return Option;
	}

	static void _GoBackToCurrencyEchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currency Exhange Menue...";
		system("pause>0");
		ShowCurrencyEchangeMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExhangeMenueOption(enCurrancyExhangeMenueOption Option)
	{
		system("CLS");

		switch (Option)
		{
		case enCurrancyExhangeMenueOption::eListCurrencies :
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyEchangeMenue();
			break;

		case enCurrancyExhangeMenueOption::eFindCurrency :
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyEchangeMenue();
			break;

		case enCurrancyExhangeMenueOption::eUpdateRate :
			_ShowUpdateRateScreen();
			_GoBackToCurrencyEchangeMenue();
			break;

		case enCurrancyExhangeMenueOption::eCurrencyCalculator :
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyEchangeMenue();
			break;

		case enCurrancyExhangeMenueOption::eMainMenue :
			break;

		}

	}

public :

	static void ShowCurrencyEchangeMenue()
	{
		system("CLS");
		_DrawScreenHeader("Currancy Exhange Main Screen");

		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t\tCurrancy Exhange Menue\n";
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(40) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(40) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(40) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(40) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(40) << left << "" << "========================================\n";

		_PerformCurrencyExhangeMenueOption(enCurrancyExhangeMenueOption(_ReadCurrencyExhangeMenueOption()));
	}

};

