#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include<cctype>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:

	template <typename Number> bool IsNumberBetween(Number Num, Number From, Number To)
	{
		if (From > To)
			swap(From, To);

		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(short Num, short From, short To)
	{
		if (From > To)
			swap(From, To);

		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(int Num, int From, int To)
	{
		if (From > To)
			swap(From, To);

		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		if (From > To)
			swap(From, To);

		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		if (From > To)
			swap(From, To);

		return (Num >= From && Num <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{
		if (FromDate.IsDateAfterDate2(ToDate))
			clsDate::SwapDates(FromDate, ToDate);

		if ((Date.CompareDates(FromDate) == clsDate::enDateCompare::After && Date.CompareDates(ToDate) == clsDate::enDateCompare::Before)
			|| (Date.CompareDates(FromDate) == clsDate::enDateCompare::Equal || Date.CompareDates(ToDate) == clsDate::enDateCompare::Equal))
			return true;

		return false;
	}

	template <typename Number> Number ReadNumber(string Message = "Invalid Number, Enter again: \n")
	{
		Number num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << Message << endl;
		}

		return num;
	}

	template <typename Number> Number ReadNumberBetween(int From, int To, string Massege = "Invalid number, Enter again : ")

	{
		Number num = ReadIntNumber();

		while (!IsNumberBetween(num, From, To))
		{
			cout << Massege << endl;
			num = ReadNumber();
		}

		return num;
	}

	static int ReadIntNumber(string Message = "Invalid Number, Enter again: \n")
	{
		int num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << Message << endl;
		}

		return num;
	}

	static int ReadIntNumberBetween(int From, int To, string Massege = "Invalid number, Enter again : ")
	{
		int num = ReadIntNumber();

		while (!IsNumberBetween(num, From, To))
		{
			cout << Massege << endl;
			num = ReadDblNumber();
		}

		return num;
	}

	static double ReadDblNumber(string Massege = "Invalid Number, Enter again: \n")
	{
		double num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << Massege << endl;
		}

		return num;
	}

	static double ReadDblNumberBetween(double From, double To, string Massege)
	{
		double Num = ReadDblNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << Massege << endl;
			Num = ReadIntNumber();
		}

		return Num;
	}

	static float ReadFloatNumber(string Massege = "Invalid Number, Enter again: \n")
	{
		float num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << Massege << endl;
		}

		return num;
	}

	static float ReadFloatNumberBetween(float From, float To, string Massege)
	{
		float Num = ReadDblNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << Massege << endl;
			Num = ReadFloatNumber();
		}

		return Num;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string Line = "";
		getline(cin >> ws, Line);

		return Line;
	}
};

