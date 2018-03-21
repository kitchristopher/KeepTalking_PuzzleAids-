// KeepTalking_PasswordCracker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "PasswordCracker.h"
#include "MorseTranslator.h"
#include "ComplicatedWires.h"
#include <map>
#include <sstream>

using namespace std;

void Solve_Password(PasswordCracker* passwordCracker);
void Translate_Morse(MorseTranslator* morseTranslator);
void Complicated_Wires(ComplicatedWires* complicatedWires);

int main()
{
	vector<string> possible_Guesses =
	{ "about", "after", "again", "below", "could",
	"every", "first", "found", "great", "house",
	"large", "learn", "never", "other", "place",
	"plant", "point", "right", "small", "sound",
	"spell", "still", "study", "their", "there",
	"these", "thing", "think", "three", "water",
	"where", "which", "world", "would", "write" };

	map<string, string> wordsAndFrequency =
	{ {"shell","3.505 MHz"},
	{ "halls","3.515 MHz" },
	{ "slick","3.522 MHz" },
	{ "trick","3.532 MHz" },
	{ "boxes","3.535 MHz" },
	{ "leaks","3.542 MHz" },
	{ "strobe","3.545 MHz" },
	{ "bistro","3.552 MHz" },
	{ "flick","3.555 MHz" },
	{ "bombs","3.565 MHz" },
	{ "break","3.572 MHz" },
	{ "brick","3.575 MHz" },
	{ "steak","3.582 MHz" },
	{ "sting","3.592 MHz" },
	{ "vector","3.595 MHz" },
	{ "beats","3.600 MHz" } };

	PasswordCracker passwordCracker(&possible_Guesses);
	MorseTranslator morseTranslator(&wordsAndFrequency);
	ComplicatedWires complicatedWires;
	string input;

	while (true)
	{
		system("cls");
		cout << "[0] Password Cracker\n[1] Morse Translator\n[2] Complicated Wires" << endl;
		cin >> input;

		if (input == "0")
			Solve_Password(&passwordCracker);
		else if (input == "1")
			Translate_Morse(&morseTranslator);
		else if (input == "2")
			Complicated_Wires(&complicatedWires);
		else if (input == "/")
			break;
	}

	return 0;
}

void Complicated_Wires(ComplicatedWires* complicatedWires)
{
	cin.get();

	while (true)
	{
		vector<bool> inputBools;

		system("cls");

		cout << "MODE: COMPLICATED WIRES[/]" << endl;

		cout << "Enter wire codes:\n\n" << endl;

		for (size_t i = 0; i < 4; i++)
		{
			string input;

			if (i == 0)
				cout << "Wire has red coloring? [t/f]" << endl;
			else if (i == 1)
				cout << "Wire has blue coloring? [t/f]" << endl;
			else if (i == 2)
				cout << "Wire has Star Symbol? [t/f]" << endl;
			else if (i == 3)
				cout << "Wire has LED On? [t/f]" << endl;

			cin >> input;

			if (input == "t")
				inputBools.push_back(true);
			else if (input == "f")
				inputBools.push_back(false);
			else if (input == "/")
				return;
			else
				break;

			if (i == 3)//solve wire
			{
				cout << "\n" + complicatedWires->Solve(&inputBools) << endl;
				cin.get();
				cin.get();
			}
		}
	}

}

void Translate_Morse(MorseTranslator* morseTranslator)
{
	system("cls");

	cout << "MODE: MORSE TRANSLATOR[/]" << endl;

	cin.get();

	while (true)
	{
		string translation;
		string input = "";
		stringstream ss;

		getline(cin, input);

		if (input == "/")
			return;

		ss.str(input);

		while (!ss.eof() && input != "")//loop through all the cin by the spaces, and add translate them, then add the results together
		{
			ss >> input;

			translation += morseTranslator->Translate(&input);
		}

		cout << translation + "\n" << endl;
		cout << "Count Letters: " + morseTranslator->Guess_Count(&translation) << endl;
		cout << "Matching Letters: " + morseTranslator->Guess_Matching(&translation) + "\n\n" << endl;
	}

}

void Solve_Password(PasswordCracker* passwordCracker)
{
	system("cls");

	cout << "MODE: PASSWORD CRACKER[/]" << endl;

	string letters;
	int index = 0;

	passwordCracker->Init_Guesses();//reset the guesses for next time

	while (index < 5)
	{
		cout << "Enter letters for [" << (index + 1) << "] Position.\n" << endl;
		cin >> letters;

		if (letters == "/")
			return;

		passwordCracker->Eliminate_Guesses(index, &letters);
		++index;
	}

	cout << endl << passwordCracker->Return_Password() << endl;
	cin.get();
	cin.get();
}