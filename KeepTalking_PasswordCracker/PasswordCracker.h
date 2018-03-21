#include <vector>
#include <string>

using namespace std;

#pragma once
class PasswordCracker
{
public:
	PasswordCracker(vector<string>* guessSet);
	~PasswordCracker();

	void Eliminate_Guesses(int index, string* letters);
	void Init_Guesses();

	string Return_Password();

private:
	vector<string> _guesses;
	vector<string>* _guessSet;
};

