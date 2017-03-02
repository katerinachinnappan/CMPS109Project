#pragma once
#include "common_headers.h"

class Parser {
	bool getType(string);     //determine whether a given line is a fact, rule, or inference. 
	                          //returns 'true' for fact and 'false' for rule
	bool getGate(string);     //returns the type of gate used in any given rule 
	                            //returns 'true' for AND and 'false' for OR
	string getFactAssoc(string);   //returns association type of a fact line
	string getRuleAssoc(string);     //returns leftmost association type of a rule line
	
	vector<string> getFactParam(string);     //returns a vector of the parameters in any given fact line
	vector<string> getRuleParam(string);     //returns a vector of the paramte

	size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)    //find the nth instance of a substring
	{
		size_t found = haystack.find(needle, pos);
		if (0 == n || string::npos == found)
			return found;
		return betterFind(haystack, found + 1, needle, n - 1);
	}
	
	

	
};

