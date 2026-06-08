#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "clsUsersListScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen 
{

private:

    enum enManageUserOptions
    {
        eListUser = 1, eAddNewUser = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5, eMainMenue = 6
    };

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		int Option = clsInputValidate::ReadIntNumberBetween(1, 6);

		return Option;
	}

	static void _ShowListUserScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUser::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOption(enManageUserOptions Option)
	{
		system("CLS");

		switch (Option)
		{
		case enManageUserOptions::eListUser :
			_ShowListUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUserOptions::eAddNewUser:
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUserOptions::eDeleteUser:
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUserOptions::eUpdateUser:
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUserOptions::eFindUser:
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUserOptions::eMainMenue:
			break;

		}
	}

public:


	static void ShowManageUsersMenue()
	{

		if (!CheckAccessRights(clsUser::enPermission::epManageUsers))
		{
			return;
		}

		system("CLS");
		_DrawScreenHeader("\t\tManage Users Menue Screen");

		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t[1] List Users.\n";
		cout << setw(40) << left << "" << "\t[2] Add New User.\n";
		cout << setw(40) << left << "" << "\t[3] Delete User.\n";
		cout << setw(40) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(40) << left << "" << "\t[5] Find User.\n";
		cout << setw(40) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(40) << left << "" << "========================================\n";

		_PerformManageUsersMenueOption(enManageUserOptions(_ReadManageUsersMenueOption()));
	}


};

