#include "stdafx.h"
#include "PasswordCracker.h"


PasswordCracker::PasswordCracker(vector<string>* guessSet)
{
	_guessSet = guessSet;
	Init_Guesses();
}

PasswordCracker::~PasswordCracker()
{
}

void PasswordCracker::Eliminate_Guesses(int index, string* letters)
{
//	vector<string> guessesCopy = *_guesses;

	for (size_t j = 0; j < _guesses.size(); ++j)//loop through all the words
	{
		for (size_t i = 0; i < letters->size(); i++)//loop through all the possible letters
		{
			if (letters->at(i) == _guesses.at(j)[index])//found a match
				break;//go to the next word

			if (i == letters->size() - 1)//went through all the letters and did not find a match
			{
				_guesses.erase(_guesses.begin() + j);//delete the jth word
				--j;
			}
		}
	}

}

void PasswordCracker::Init_Guesses()
{
	_guesses = *_guessSet;
}

string PasswordCracker::Return_Password()
{
	return _guesses.size() > 0 ? _guesses.at(0) : "ERROR!";
}
