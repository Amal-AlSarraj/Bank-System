#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsFindCurrencyScreen  : public clsScreen
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

    enum enFindBy
    {
        eCode = 1, eCountry = 2
    };

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

    static void FindByCodeScreen()
    {
        string Code;
        cout << "\nPlease Enter CurrencyCode: ";
        Code = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        _ShowResults(Currency);
    }

    static void FindByCountryScreen()
    {
        string Country;
        cout << "\nPlease Enter Country: ";
        Country = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCountry(Country);

        _ShowResults(Currency);
    }

public : 

    

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");

        int Ask;
       

        cout << "\nFind By : [1] Code or [2] Country? ";
        Ask = clsInputValidate::ReadIntNumberBetween(1, 2);

        if (enFindBy(Ask) == enFindBy::eCode)
        {
            FindByCodeScreen();
        }

        else
        {
            FindByCountryScreen();
        }
           
    }

};

