#ifndef KNOWLEDGEBASE_H_INCLUDED
#define KNOWLEDGEBASE_H_INCLUDED
#include "common_headers.h"
#include "Component.h"
class KnowledgeBase
{

public:

    map<string, Fact* > FactDictionary; //Map "dictionary" to hold the facts.

    KnowledgeBase(); //Constructor

    bool findFactAssociation(Fact * fact); //Find the association of a certain fact.
    void AddFact(Fact * fact); //Add a fact to the Knowledge Base FactDictionary.
    void dropFact(string param, KnowledgeBase *fact); //Drop fact from the FactDictuionary.
    void loadFact(stringstream &str2, string factElement);

    ~KnowledgeBase(); //Deconstructor to delete the map.

};



#endif // KNOWLEDGEBASE_H_INCLUDED
