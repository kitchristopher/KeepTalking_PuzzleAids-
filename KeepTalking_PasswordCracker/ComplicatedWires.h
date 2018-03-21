#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class ComplicatedWires
{
public:
	ComplicatedWires();
	~ComplicatedWires();

	string Solve(vector<bool>* setFlags);

private:
	vector<int> _redSet = { 0, 1, 2, 3, 4, 5, 6, 7 };
	vector<int> _blueSet = { 13, 2, 12, 4, 3, 5, 10, 8 };
	vector<int> _starSet = { 14, 1, 3, 10, 8, 5, 9, 7 };
	vector<int> _lightSet = { 11, 12, 4, 6, 5, 7, 8, 9 };

	vector<vector<int>*> _SetofSets = { &_redSet, &_blueSet, &_starSet, &_lightSet };

	map<int, string> _resultsMap =
	{ {0, "S"}, {1, "C"},{2, "S"}, {3, "P"}, {4, "S"},{5,"D"},
	{6, "B"},{7, "B"},{8, "P"},{9, "B"},{10, "D"},{11, "D"},
	{12, "P"},{13, "S"},{14, "C"} };

	map<string, string> _descriptionMap = { {"C","C: Cut wire!"}, {"S", "S: Cut if last digit of serial number is even."}, 
	{"P", "P: Cut if parallel port"}, {"B", "B: Cut if more than one battery"}, {"D", "D: Don't cut wire!"} };
};


