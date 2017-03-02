//created by Katerina Chinnappan
#ifndef SRI_H_INCLUDED
#define SRI_H_INCLUDED
#include "common_headers.h"
#include "KnowledgeBase.h"
#include "RuleBase.h"
class SRI{
    private:
        string emptyString;
        string right, left;
        string predicate;
        string separator;
    public:
        SRI();
        ~SRI();
        void inference();
        void load();
        void dump();
        void dumpRF(ostream &os, KnowledgeBase *facts, RuleBase *brules);
        void drop(string param);
        //fact map
        //map<string,vector<Fact*>>factmap;
        //rule map
        //map<string,vector<Rule*>>rulemap;


};
#endif // SRI_H_INCLUDED
