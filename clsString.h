#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string
		Value;

	static int Length(string Value)
	{
		return Value.length();
	}
	int Length()
	{
		return Length(_Value);
	}

	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
			while ((pos = S1.find(delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos); // store the word
				if (sWord != "")
				{
					Counter++;
				}
				//erase() until positon and move to next word.
				S1.erase(0, pos + delim.length());
			}
		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	};


	//////////////////////////////////////////////////////

	static void PrintFirstLetterOfEachWord(string st)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] != ' ' && isFirstLetter)
			{
				cout << st[i] << "  ";
			}

			isFirstLetter = (st[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetterOfEachWord()
		{
			PrintFirstLetterOfEachWord(_Value);
		}
	
	char Upper(char ch)
		{
			return ((ch - 'a') + 'A');
		}
	static string UpperFirstLetterOfEachWord(string& s)
		{
			bool isFirstLetter = true;

			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] != ' ' && isFirstLetter)
				{
					s[i] = toupper(s[i]);
					// char ch = s[i];
					 //s[i] = ((ch - 'a') + 'A');
				}

				isFirstLetter = (s[i] == ' ' ? true : false);
			}

			return s;

		}
	void UpperFirstLetterOfEachWord()
	{
		 UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string& s)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isFirstLetter)
			{
				s[i] = tolower(s[i]);
			}

			isFirstLetter = (s[i] == ' ' ? true : false);
		}

		return s;
	}
	void LowerFirstLetterOfEachWord()
	{
		 LowerFirstLetterOfEachWord(_Value);
	}

	static string LowerAllString(string st)
	{
		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] >= 'A' && st[i] <= 'Z')
				st[i] = tolower(st[i]);
		}

		return st;
	}
	void LowerAllString()
	{
		 LowerAllString(_Value);
	}

	static string UpperAllString(string st)
	{
		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] >= 'a' && st[i] <= 'z')
				st[i] = toupper(st[i]);
		}

		return st;
	}
	void UpperAllString()
	{
		UpperAllString(_Value);
	}

	static char EditChar(char ch)
	{
		return (isupper(ch) ? tolower(ch) : toupper(ch));
	}
	static string EditString(string st)
	{
		for (int i = 0; i < st.length(); i++)
		{
			st[i] = EditChar(st[i]);
		}

		return st;

	}
	void EditString()
	{
		EditString(_Value);
	}



	enum enWhatCount { SmallLetters, CapitalLetters, All };

	int enCount(string st, enWhatCount WhatCount)
	{
		int counter = 0;
		if (WhatCount == enWhatCount::All)
		{
			return st.length();
		}

		for (int i = 0; i < st.length(); i++)
		{
			if (WhatCount == enWhatCount::SmallLetters && isupper(st[i]))
			{
				counter++;
			}

			if (WhatCount == enWhatCount::CapitalLetters && islower(st[i]))
			{
				counter++;
			}
		}

		return counter;
	}

	static int CountCapitalLetters(string st)
	{
		int CapitalL = 0;

		for (int i = 0; i < st.length(); i++)
		{
			if (isupper(st[i]))
				CapitalL++;
		}

		return CapitalL;
	}
	static int CountSmallLetters(string st)
	{
		int SmallL = 0;

		for (int i = 0; i < st.length(); i++)
		{
			if (islower(st[i]))
				SmallL++;
		}

		return SmallL;
	}
	static void PrintInfoString(string st)
	{
		int Capital = CountCapitalLetters(st);
		int Small = CountSmallLetters(st);

		cout << "String length = " << st.length() << endl;
		cout << "Capital letters counts = " << Capital << endl;
		cout << "Small letters counts = " << Small << endl;
	}
	int CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}
	int CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}
	void PrintInfoString()
	{
		PrintInfoString(_Value);
	}


	static int CountSpecificLetterInString(string st, char ch, bool MatchCase = true)
	{
		int Count = 0;

		for (int i = 0; i < st.length(); i++)
		{
			if (MatchCase)
			{
				if (st[i] == ch)
					Count++;
			}

			else
			{
				if (tolower(st[i]) == tolower(ch))
					Count++;
			}
		}

		return Count;
	}
	int CountSpecificLetterInString(char ch, bool MatchCase = true)
	{
		return CountSpecificLetterInString(_Value, ch, MatchCase);
	}

	static bool IsVowel(char ch)
	{
		ch = toupper(ch);

		return ((ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I'));
	}
	static int CountVowelInString(string st)
	{
		int Count = 0;

		for (int i = 0; i < st.length(); i++)
		{
			if (IsVowel(st[i]))
				Count++;
		}

		return Count;
	}
	int CountVowelInString()
	{
		return CountVowelInString(_Value);
	}

	static void PrintVowellettersInString(string st)
	{
		cout << "Vowel letters in your string are :";

		for (int i = 0; i < st.length(); i++)
		{
			if (IsVowel(st[i]))
			{
				cout << st[i] << "      ";
			}
		}

		cout << endl;
	}
	void PrintVowellettersInString()
	{
		PrintVowellettersInString(_Value);
	}

	static void PrintWords(string st)
	{
		string delim = " ";
		int pos = 0;
		string word = "";

		while ((pos = st.find(delim)) != std::string::npos)
		{
			word = st.substr(0, pos);

			if (word != "")
				cout << word << endl;

			st.erase(0, pos + delim.length());


		}

		if (st != "")
			cout << st << endl;
	}
	void PrintWords()
	{
		PrintWords(_Value);
	}



	static vector <string> Split(string st, string delim = " ")
	{
		int pos = 0;
		string word = "";
		vector <string> vWord;

		while ((pos = st.find(delim)) != std::string::npos)
		{
			word = st.substr(0, pos);

			if (word != "")
				vWord.push_back(word);

			st.erase(0, pos + delim.length());
		}

		if (st != "")
			vWord.push_back(st);

		return vWord;
	}
	vector <string> SplitwordsInVector(string delim = " ")
	{
		return Split(_Value, delim);
	}

	static string TrimLift(string st)
	{
		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] != ' ')
				return st.substr(i, st.length() - i);
		}

		return "";
	}
	static string TrimRight(string st)
	{
		for (int i = st.length() - 1; i >= 0; i--)
		{
			if (st[i] != ' ')
				return st.substr(0, i + 1);
		}

		return "";
	}
	static string Trim(string st)
	{
		return (TrimLift(TrimRight(st)));
	}
	void TrimLift()
	{
		 TrimLift(_Value);
	}
	void TrimRight()
	{
		 TrimRight(_Value);
	}
	void Trim()
	{
		 Trim(_Value);
	}

	static string JoinString(vector <string>& vSt, string Delim = " ")
	{
		string contact;
		string* s;

		for (string &s : vSt)
		{
			contact = contact + s + Delim;
		}

		return contact.substr(0, contact.length() - Delim.length());
	}
	

	static string ReverseWordsInString(string st)
	{
		vector <string> vWords = Split(st, " ");
		string st1 = "";

		vector <string> ::iterator vPtr = vWords.end();
		string* s;

		while (vPtr != vWords.begin())
		{
			--vPtr;
			st1 += *vPtr + " ";
		}

		return (st1.substr(0, st1.length() - 1));
	}
	void ReverseWordsInString()
	{
		 ReverseWordsInString(_Value);
	}

	static string ToLowerWord(string word)
	{
		for (int i = 0; i < word.length(); i++)
			word[i] = tolower(word[i]);

		return word;
	}
	static string ReplaceWordInString(string st, string OldWord, string NewWord, bool MatchCase = true)
	{
		vector <string> vWords = Split(st, " ");
		string* s;

		for (string &s : vWords)
		{
			if (MatchCase)
			{
				if (s == OldWord)
					s = NewWord;
			}

			else
			{
				if (ToLowerWord(s) == ToLowerWord(OldWord))
					s = NewWord;
			}

		}

		return JoinString(vWords, " ");
	}
	void ReplaceWordInString(string OldWord, string NewWord, bool MatchCase = true)
	{
		 ReplaceWordInString(_Value, OldWord, NewWord, MatchCase);
	}


	static string RemovePunctuationsFromString(string st)
	{
		string st1 = "";

		for (int i = 0; i < st.length(); i++)
		{
			if (!ispunct(st[i]))
				st1 += st[i];
		}

		return st1;
	}
	void RemovePunctuationsFromString()
	{
	   RemovePunctuationsFromString(_Value);
	}


};