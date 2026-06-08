#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsCurrencyCalculatorScreen : public clsScreen
{

private :

	static void _PrintCurrency(clsCurrency Currency, string Title = "\nConvert From :\n")
	{
		cout << "\n\n" << Title;
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _Calculate(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		_PrintCurrency(CurrencyFrom);
		float Price = CurrencyFrom.CalculateCurrencyToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << Price << " USD";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		_PrintCurrency(CurrencyTo, "\n\nConvert From USD To");

		Price = CurrencyFrom.CalculateToOtherCurrency(CurrencyTo, Amount);
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << Price << " " << CurrencyTo.CurrencyCode();
	}

	static clsCurrency _ReadCurrency(string Message = "\n\nPlease Enter Currency Code: ")
	{
		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();


		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was not Found :-(\n";
			cout << "\nEnter Another Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	/*
	static void _CalculateToUSD(clsCurrency CurrencyFrom, float Amount)
	{
		cout << "\n\nConvert From" << endl;
		_PrintCurrency(CurrencyFrom);

		float Price = CurrencyFrom.CalculateCurrencyToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << Price << " USD";
		

	}

	static void _Calculate(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		cout << "\n\nConvert From USD To" << endl;
		_PrintCurrency(CurrencyTo);

		float Price = CurrencyFrom.CalculateToOtherCurrency(CurrencyTo, Amount);
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << Price << " " << CurrencyTo.CurrencyCode();
	}
	*/

public : 

	static void ShowCurrencyCalculatorScreen()
	{
		char Ask = 'y';


		do{
			system("CLS");
			_DrawScreenHeader("\tCalculate Currency Screen");

			clsCurrency CurrencyFrom = _ReadCurrency("\n\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _ReadCurrency("\n\nPlease Enter Currency2 Code: ");
			

			cout << "\nEnter Amount To Exchange: ";
			float Amount = clsInputValidate::ReadFloatNumber();

			_Calculate(CurrencyFrom, CurrencyTo, Amount);

			cout << "\n\n\nDo You Want To Perform Another Calculation? y/n?";
			cin >> Ask;

		} while (Ask == 'y' || Ask == 'Y');
	}

};

