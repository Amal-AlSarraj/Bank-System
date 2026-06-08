#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private :
	string _AccountNumber;
	string _PinCode;
    bool _MarkForDelete = false;
	float _AccountBalance;

    enum enMode
    {
        EmptyMode = 0, UpdateMode = 1,
        AddNewMode = 2
    };

    enMode _Mode;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Delim = "#//#")
    {
        string record = "";

        record += Client.FirstName + Delim;
        record += Client.LastName + Delim;
        record += Client.Email + Delim;
        record += Client.Phone + Delim;
        record += Client.AccountNumber() + Delim;
        record += Client.PinCode + Delim;
        record += to_string(Client._AccountBalance);

        return record;
    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        fstream MyFile;
        string Line;
        vector <clsBankClient> Clients;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                Clients.push_back(_ConvertLinetoClientObject(Line));
            }
        }

        MyFile.close();

        return Clients;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> Clients)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::out);

        if (MyFile.is_open())
        {
            for (clsBankClient C : Clients)
            {
                if (C._MarkForDelete == true)
                    continue;

                MyFile << _ConvertClientObjectToLine(C) << endl;
            }
        }

        MyFile.close();
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


    void _Update()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient & C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                //break;
            }
        }

        _SaveClientsDataToFile(vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    string _PrepareTransferObject(clsBankClient ClientTo, float Amount, string Seperator = "#//#")
    {
        string RecordLine = "";

        RecordLine += clsDate::GetSystemDateTimeString() + Seperator;
        RecordLine += AccountNumber() + Seperator;
        RecordLine += ClientTo.AccountNumber() + Seperator;
        RecordLine += to_string(Amount) + Seperator;
        RecordLine += to_string(AccountBalance) + Seperator;
        RecordLine += to_string(ClientTo.AccountBalance) + Seperator;
        RecordLine += CurrentUser.Username;

        return RecordLine;
    }

    void _RegisterTransfer(clsBankClient ClientTo, float Amount)
    {
        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);

        string LineRecord = _PrepareTransferObject(ClientTo, Amount);

        if (MyFile.is_open())
        {
            MyFile << LineRecord << endl;
        }

        MyFile.close();
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float SourceAccountBalanceAfter;
        float DestinitionAccountBalanceAfter;
        string Username;
    };

    clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }

    _declspec (property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    _declspec (property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static clsBankClient Find (string AccountNumber)
    {
        string Line;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        while (getline(MyFile, Line))
        {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber)
            {
                MyFile.close();
                return Client;
            }

        }

        MyFile.close();
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        string Line;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        while (getline(MyFile, Line))
        {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
            {
                MyFile.close();
                return Client;
            }

            MyFile.close();
            return _GetEmptyClientObject();
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return !(Client._Mode == enMode::EmptyMode);
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyClientObject();

        return true;
      
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool WithDraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }

        _AccountBalance -= Amount;
        Save();
    }

    bool Transfer(clsBankClient ClientTo, float Amount)
    {
        if (AccountBalance < Amount)
        {
            return false;
        }

        WithDraw(Amount);
        ClientTo.Deposit(Amount);
        _RegisterTransfer(ClientTo, Amount);
        return true;

    }

    /*
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }
    */

    enum enSaveResults
    {
        svFailedEmptyObject = 0, svSucceeced = 1,
        svFailedAccountNumberExists = 3
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode :
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode :
            _Update();
            return enSaveResults::svSucceeced;

        case enMode::AddNewMode :
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }

            _AddNew();
            return enSaveResults::svSucceeced;
        }
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

            for (clsBankClient Client : vClients)
            {

                TotalBalances += Client.AccountBalance;
            }

            return TotalBalances;

    }

    static stTransferLogRecord ConvertLineToTransferRegister(string Line)
    {
        vector <string> vsTranferLog = clsString::Split(Line, "#//#");
        stTransferLogRecord Record;

        Record.DateTime = vsTranferLog[0];
        Record.SourceAccountNumber = vsTranferLog[1];
        Record.DestinationAccountNumber = vsTranferLog[2];
        Record.Amount = stof(vsTranferLog[3]);
        Record.SourceAccountBalanceAfter = stof(vsTranferLog[4]);
        Record.DestinitionAccountBalanceAfter = stof(vsTranferLog[5]);
        Record.Username = vsTranferLog[6];

        return Record;
    }

    static vector <stTransferLogRecord> LoadTransferLogDataFromFile()
    {
        fstream MyFile;
        string Line;
        vector <stTransferLogRecord> vTransferLogs;

        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                vTransferLogs.push_back(ConvertLineToTransferRegister(Line));
            }
        }

        MyFile.close();

        return vTransferLogs;
    }

};

