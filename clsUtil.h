#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string.h>
#include <math.h>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
    enum enCharType
    { enCapitalLetter = 1, enSmallLetter, enSpecialCharcater, enDigit, enMix };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

	static int randomNumber(int from, int to)
    {
        int random = rand() % (to - from + 1) + from;
        return random;
    }

    static char randomCharcater(enCharType type)
    {
        if (enCharType::enMix)
            type = enCharType(randomNumber(1, 3));

        switch (type)
        {
            case enCharType::enCapitalLetter:
            return char(randomNumber(97, 122));

            case enCharType::enSmallLetter:
            return char(randomNumber(65, 90));

            case enCharType::enSpecialCharcater:
            return char(randomNumber(33, 47));

            case enCharType::enDigit :
            return char(randomNumber(48, 54));

        //    case enCharType::enMix :
        //    return char(randomNumber(33, 122));
        }
    }

    static string generateWord(enCharType type, int numOfChar)
    {
        string word = "";
        for (int i = 0; i < numOfChar; i++)
            word += randomCharcater(type);
        return word;

    }

    static string generateKey(enCharType type = enCharType::enCapitalLetter)
    {
        string word = "";
        word = generateWord(type, 4) + "-";
        word = word + generateWord(type, 4) + "-";
        word = word + generateWord(type, 4) + "-";
        word = word + generateWord(type, 4);
        return word;
    }

    static void PrintKeys(int numberKey, enCharType type)
    {
        for (int i = 1; i <= numberKey; i++)
        {
            cout << "key [" << i << "]" << ":" << generateKey(type) << endl;
        }
    }

    static void RandomArray(int ElementNum, int arr[], int from, int to)
    {
        for (int i = 0; i < ElementNum; i++)
            arr[i] = randomNumber(from, to);
    }

    static void ArrayOfWords(int ElementNum, string arr[], enCharType Type, int NumOfChar)
    {
        for (int i = 0; i < ElementNum; i++)
            arr[i] = generateWord(Type, NumOfChar);
    }

    static void ArrayOfkeys(string arr[], int numElement, enCharType Type)
    {
        for (int i = 0; i < numElement; i++)
        {
            arr[i] = generateKey(Type);
        }
    }

    static void printArrayKeys(string arr[], int numElement)
    {
        for (int i = 0; i < numElement; i++)
        {
            cout << "Key [" << i << "] : " << arr[i] << endl;
        }
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static string Tabs(int TabNum)
    {
        string sTab = "";

        for (int i = 0; i < TabNum; i++)
            sTab += "   ";

        return sTab;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text; 
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {            
            Text[i] = char((int)Text[i] - EncryptionKey);
        }

        return Text;
    }

};

