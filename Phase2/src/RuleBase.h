#ifndef RULEBASE_H_INCLUDED
#define RULEBASE_H_INCLUDED
#include "common_headers.h"
#include "Component.h"
class RuleBase
{

public:
    map<string, Rule* > rules;
    RuleBase(); //default constructor
    ~RuleBase(); //Destructor

    void AddRule(Rule * rule);
    void dropRule(string param, RuleBase *rb);
    void identifyRule(string emptyStr, RuleBase *rules, KnowledgeBase *facts);

};



#endif // RULEBASE_H_INCLUDED
