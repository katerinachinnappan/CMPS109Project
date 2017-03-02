//this is purely for testing parse class
/*
#include"common_headers.h"

size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)
{
	size_t found = haystack.find(needle, pos);
	if (0 == n || string::npos == found) 
		return found;
	return betterFind(haystack, found + 1, needle, n - 1);
}

int main()
{
	string str = "Father(roger,john,mitch,alex,jack,tarik)";
	vector<int> index;
	
	int i = 0;
	while (betterFind(str, 0, ",", i)<999999) {

		size_t paramCount = betterFind(str, 0, ",", i);
		index.push_back(paramCount);
		cout << index[i] << endl;
		i++;
	}
	
	vector<string> param;
	param.push_back(str.substr(str.find('(')+1, (str.find(',') - str.find('(')-1)));   //param[1] = first parameter
	
	for (int j = 1; j < index.size();j++)
	{
		param.push_back(str.substr(betterFind(str, 0, ",", j)+1, (betterFind(str, 0, ",", j + 1)- betterFind(str, 0, ",", j))-1));   //push the rest of the paramters to the vector param
	}
	

	
	return 0;
}
*/