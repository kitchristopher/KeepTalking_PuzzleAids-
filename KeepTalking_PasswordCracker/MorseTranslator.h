#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

class MorseTranslator
{
public:
	MorseTranslator(map<string, string>* wordsAndFrequency);
	~MorseTranslator();

	string Translate(string* input);
	string Guess_Matching(string* input);
	string Guess_Count(string* input);

private:
	map<string, string>* _translations;//key:morse; value: letter
	map<string, string>* _wordsAndFrequency;//key: word; value: frequency
	map<string, int>* _letterMatch;//key: word; value: matching letters found

	string Find_Results(vector<string>* bestGuesses, int highestFitness);
};

