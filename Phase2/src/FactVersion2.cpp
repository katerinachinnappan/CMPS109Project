#include "common_headers.h"
#include "FactVersion2.h"

//default constructor
Fact::Fact(string factss){
	this->factss = factss;
}

//return the fact
vector<string> Fact:: get_Facts(){
	return stringFacts;
}

/*void Fact:: dumpFacts(SRI sriObj)
{
    //...
}*/

void Fact:: infer_query(map<string,Fact*> facts,string strFact){

	if(facts.count(strFact) == 1){
            //if fact found, output
		cout << strFact << " : " << facts[strFact] << endl;
	}
	else {
	    //else, invalid, not found
		cout << "FACT " << strFact << " is not found." << endl;
	}
}

//override, capture only the fact name
ostream& operator<< (std::ostream &os, Fact *fact)
{
	os << fact->factss<< " : ";
	for(string i : fact->stringFacts){
		if(!i.compare("|")){
			os << endl << fact->factss<< ": ";
		} else	os << i << " ";
	}

	os << endl;
    return os;
}

Fact::~Fact(){//do nothing for now
}
int main()
{
    cout<<"USAGE: FactVersion2 "<<endl;
}
