#include "Parse.h"
#include "common_headers.h"

bool Parse::getType(string s)
{
	string str = s.substr(0,4);
	if (str == "FACT")
		return true;
	else if(str == "RULE")
	    return false;
}

bool Parse::getGate(string s)
{
	int str = s.find(" AND ");
	if (str > 999999)
		return false;
	else
	    return true;
}

string Parse::getFactAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex, paranIndex);
	return strtemp;
}

string Parse::getRuleAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex, paranIndex);
	return strtemp; 
}

vector<string> Parse::getFactParam(string str)
{
	vector<int> index;

	int i = 0;
	while (betterFind(str, 0, ",", i)<999999) {

		size_t paramCount = betterFind(str, 0, ",", i);
		index.push_back(paramCount);
		cout << index[i] << endl;
		i++;
	}

	vector<string> param;
	param.push_back(str.substr(str.find('(') + 1, (str.find(',') - str.find('(') - 1)));   //param[1] = first parameter

	for (int j = 1; j < index.size(); j++)
	{
		param.push_back(str.substr(betterFind(str, 0, ",", j) + 1, (betterFind(str, 0, ",", j + 1) - betterFind(str, 0, ",", j)) - 1));   //push the rest of the paramters to the vector param
	}


	return param;
}

vector<string> Parse::getRuleParam(string)
{
	return vector<string>();
}









