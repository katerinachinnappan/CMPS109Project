#include<string>
#include "KB.h"
#include "RB.h"
using namespace std; 

class SRI
{
	KB kb;
	RB rb;

	void load(string);
	void dump(string);
};
