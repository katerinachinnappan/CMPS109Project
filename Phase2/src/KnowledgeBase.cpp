#include "common_headers.h"
#include "KnowledgeBase.h"
string factNamee;
KnowledgeBase::KnowledgeBase()
{
    map<string, Fact *> FactDictionary = *new map<string, Fact * >();
}

bool KnowledgeBase::findFactAssociation(Fact * fact)
{
    if (FactDictionary.find(fact->association) == FactDictionary.end())
        return false;

    return true;
}

void KnowledgeBase::dropFact(string param, KnowledgeBase *kb)
{
    if(kb->FactDictionary.find(param)!=kb->FactDictionary.end())
    {
        kb->FactDictionary.erase(param);
    }
}

KnowledgeBase::~KnowledgeBase()
{
    FactDictionary.clear();
}
