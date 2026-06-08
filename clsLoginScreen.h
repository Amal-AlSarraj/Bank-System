#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private :

	//static int _Trials;

	static bool _Login()
	{
		bool LoginFailed = false;
		string Username, Password;
		
		//_Trials = 3;

		do
		{
			if (LoginFailed)
			{
				Trials -= 1;

				cout << "\nInvalid Username/Password!\n";
				cout << "\nYou have " << Trials << " Trials to login.\n\n";
			}

			if (Trials == 0)
			{
				cout << "\nYour are Locked after 3 failed trials.\n";
				return false;
			}



			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;

	}

public :
	static bool ShowLoginScreen()
	{
		system("CLS");
		clsScreen::_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

