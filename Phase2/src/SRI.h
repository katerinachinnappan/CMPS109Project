#ifndef SRI_H_INCLUDED
#define SRI_H_INCLUDED
#include "common_headers.h"
#include "KnowledgeBase.h"
#include "RuleBase.h"
class SRI{
    public:
        SRI();
        ~SRI();
        map<string, Fact* > FactDictionary;
        void inference(string input, KnowledgeBase *facts, RuleBase *brules);
        void inferFact(KnowledgeBase *facts, string lefty);
        void inferRule(RuleBase *brules, KnowledgeBase *facts, string left, string emptyLine);
        void load(KnowledgeBase *kb, RuleBase *rb);
        void loadRule(stringstream &str, stringstream &str1, string ruleElement,
                      RuleBase *rb, string operatorL, string ruleName);
        void loadFact(stringstream &str2, string factElement, KnowledgeBase *kb);
        void dump(KnowledgeBase *kb, RuleBase *rb);
        void dumpRF(ostream &os, KnowledgeBase *kb, RuleBase *rb);
        void drop(string param, KnowledgeBase *kb, RuleBase *rb);
        //fact map
        //map<string,vector<Fact*>>factmap;
        //rule map
        //map<string,vector<Rule*>>rulemap;


};



#endif // SRI_H_INCLUDED
