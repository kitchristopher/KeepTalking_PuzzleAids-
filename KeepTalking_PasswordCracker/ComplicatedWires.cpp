#include "stdafx.h"
#include "ComplicatedWires.h"
#include <algorithm>

ComplicatedWires::ComplicatedWires()
{
}


ComplicatedWires::~ComplicatedWires()
{
}

string ComplicatedWires::Solve(vector<bool>* setFlags)
{
	vector<int> newSet = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };//the universe
	vector<int>::iterator it;
	string result;

	//loop through each set
	for (size_t i = 0; i < _SetofSets.size() && i < setFlags->size(); i++)
	{
		sort(_SetofSets[i]->begin(), _SetofSets[i]->end());

		if (setFlags->at(i) == true)//intersect the new set with this set
			it = set_intersection(newSet.begin(), newSet.end(), _SetofSets[i]->begin(), _SetofSets[i]->end(), newSet.begin());

		else if (newSet.size() > 0)//diff
			it = set_difference(newSet.begin(), newSet.end(), _SetofSets[i]->begin(), _SetofSets[i]->end(), newSet.begin());

		newSet.resize(it- newSet.begin());
	}

	if (newSet.size() > 0)
		result = _descriptionMap[_resultsMap[newSet[0]]];//there will only one result remaining
	else
		result = "Cut the wire!";//out of domain is a cut

	return result;
}
