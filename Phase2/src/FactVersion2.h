#ifndef FACTVERSION2_H_INCLUDED
#define FACTVERSION2_H_INCLUDED
#include "common_headers.h"
#include "KB.h"
#include "SRI.h"
class Fact : public KB{
    protected:
        string factss;
	public:
	    //a vector of string facts
        vector<string> stringFacts;
        //default constructor
	    Fact(string factss);
        //returns a vector with a fact
        vector<string> get_Facts();
        //dump the facts
        void dumpFacts(SRI sriObj);
        void infer_query(map<string,Fact*> facts,string strFact);
        //override operator <<
        friend ostream& operator<<(ostream &os,Fact *fact);
        ~Fact();
};



#endif // FACTVERSION2_H_INCLUDED
