#include "common_headers.h"
#include "RuleBase.h"
RuleBase::RuleBase()
{
    map<string, Rule* > rules = *new map<string, Rule * >();
}

void RuleBase::AddRule(Rule * rule)
{
    /*for (Rule * r : rules)
    {
        if (r == rule)
            cout << "Rule is already in the rule base. \n";
        else
            rules.push_back(rule);

    }*/

}
void RuleBase::identifyRule(string emptyStr, RuleBase *rules, KnowledgeBase *facts)
{

}

void RuleBase::dropRule(string param, RuleBase *rb)
{
    if(rules.find(param)!= rules.end())
        rules.erase(param);
    cout<<"Dropped rules"<<endl;
}
