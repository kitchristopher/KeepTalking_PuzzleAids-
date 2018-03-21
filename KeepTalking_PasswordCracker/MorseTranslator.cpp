#include "stdafx.h"
#include "MorseTranslator.h"
#include <vector>


MorseTranslator::MorseTranslator(map<string, string>* wordsAndFrequency)
{
	_translations = new map<string, string>
	{ {".-", "a"}, { "-...","b" },
	{ "-.-.","c" }, { "-..","d" },
	{ ".","e" }, { "..-.","f" },
	{ "--.","g" }, { "....","h" },
	{ "..","i" }, { ".---","j" },
	{ "-.-","k" }, { ".-..","l" },
	{ "--","m" }, { "-.","n" },
	{ "---","o" }, { ".--.","p" },
	{ "--.-","q" }, { ".-.","r" },
	{ "...","s" }, { "-","t" },
	{ "..-","u" }, { "...-","v" },
	{ ".--","w" }, { "-..-","x" },
	{ "-.--","y" }, { "--..","z" } };

	_wordsAndFrequency = wordsAndFrequency;

	_letterMatch = new map<string, int>();

	for (auto it = _wordsAndFrequency->begin(); it != _wordsAndFrequency->end(); ++it)
		_letterMatch->emplace(it->first, 0);

}


MorseTranslator::~MorseTranslator()
{
	delete _translations;
	delete _letterMatch;
}

string MorseTranslator::Translate(string * input)
{
	string result = "|";

	if (_translations->count(*input) > 0)//if there are elements
		result = _translations->at(*input);

	return result;
}

string MorseTranslator::Guess_Matching(string * input)
{
	vector<string> bestGuesses;

	int highestFitness = 0;

	for (auto it = _letterMatch->begin(); it != _letterMatch->end(); ++it)//loop through all the possible words
	{
		it->second = 0;//reset the fitness to 0

		for (size_t i = 0; i < it->first.size(); i++)
		{
			if (input->size() == i)//the input is too small here
				break;

			if (input->at(i) == it->first.at(i))//found matching letter and position
				it->second++;//update fitness
		}

		if (it->second >= highestFitness && it->second != 0)//dont bother counting words with no fitness
		{
			highestFitness = it->second;
			bestGuesses.push_back(it->first);
		}
	}

	return Find_Results(&bestGuesses, highestFitness);
}

string MorseTranslator::Guess_Count(string * input)
{
	vector<string> bestGuesses;

	int highestFitness = 0;

	for (auto it = _letterMatch->begin(); it != _letterMatch->end(); ++it)//loop through all the possible words
	{
		it->second = 0;//reset the fitness to 0
		string currentWord = it->first;//clone the word for mutation

		for (size_t i = 0; i < input->size(); i++)//loop through all the letters and count how many letters are in the word but not matching order
		{
			size_t letterIndex = currentWord.find(input->at(i));

			if (letterIndex != string::npos)//found matching letter
			{
				currentWord.erase(letterIndex, 1);//erase all used letters in the copied word
				it->second++;//update its fitness
			}
		}

		if (it->second >= highestFitness && it->second != 0)//dont bother counting words with no fitness
		{
			highestFitness = it->second;
			bestGuesses.push_back(it->first);
		}
	}

	return Find_Results(&bestGuesses, highestFitness);
}

string MorseTranslator::Find_Results(vector<string>* bestGuesses, int highestFitness)
{
	string bestGuess = "[" + to_string(highestFitness) + "] ";//all the best values will share the same fitness
	int count = 0;//succesful words found

	for (auto it = bestGuesses->begin(); it != bestGuesses->end(); ++it)//only take the top three
	{
		if (_letterMatch->at(*it) < highestFitness)//weed through all words that are inferior now
			continue;

		++count;//count first so we can break if over 3 were found and not add the 4th word

		if (count > 3)
			break;

		bestGuess += (*it + ": " + _wordsAndFrequency->at(*it) + " ");
	}

	if (bestGuesses->size() == 0)//couldnt find any good matches
		bestGuess = "None";
	else if (count > 3)//add a warning that the odds are more than 3
		bestGuess += " **";

	return bestGuess;
}

