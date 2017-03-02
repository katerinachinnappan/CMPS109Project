//created by Katerina Chinnappan
#include "common_headers.h"
#include "SRI.h"
#include "Component.h"
#include "KnowledgeBase.cpp"
#include "RuleBase.cpp"
SRI::SRI(){}
SRI::~SRI(){}
inline void SRI::dumpRF(ostream &os, KnowledgeBase *facts, RuleBase *brules)
{
    //dump facts
    for(auto iterator = facts->FactDictionary.begin(); iterator != facts->FactDictionary.end(); iterator++)
    {
        //os<<iterator->second<<endl;
    }
    //dump rules
    for(auto iterator = brules->rules.begin(); iterator != brules->rules.end(); iterator++)
    {
        //os<<iterator->second<<endl;
    }

}
void SRI::inference()
{

}
void SRI::dump()
{
    ofstream out;
    KnowledgeBase *facts;
    RuleBase *brules;
    //open file
    out.open("out.sri");
    dumpRF(out, facts, brules);

}
void SRI::drop(string param)
{
    RuleBase *rules;
    KnowledgeBase *facts;
    facts->dropFact(param);
    rules->dropRule(param);

}
void SRI::load()
{
    cout<<"Load"<<endl;
}
/*int main()
{

}*/
