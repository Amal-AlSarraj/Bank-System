#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsUpdateCurrencyRateScreen : public clsScreen
{

private :

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float Rate = clsInputValidate::ReadFloatNumber();

        return Rate;
    }

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "Please Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        //_PrintCurrency(Currency);
        _ShowResults(Currency);

        char Ask = 'n';

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
        cin >> Ask; 

        if (Ask == 'Y' || Ask == 'y')
        {
            cout << "\nUpdate Currency Rate :";
            cout << "\n______________________";

            float Rate = _ReadRate();

            Currency.UpdateRate(Rate);

            cout << "\nCurrency Rate Updated Successfully :-)";
            _PrintCurrency(Currency);
        }

        else
            return;
	}

};

