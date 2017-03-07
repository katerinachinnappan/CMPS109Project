//
//  KnowledgeBase.hpp
//  SRI
//
//  Created by Babbie Monahelis on 2/25/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
#ifndef KNOWLEDGEBASE_H_INCLUDED
#define KNOWLEDGEBASE_H_INCLUDED
#include "common_headers.h"
#include "Component.h"
class KnowledgeBase
{

public:

    map<string, vector<Fact*> > FactDictionary; //Map "dictionary" to hold the facts.

    KnowledgeBase(); //Constructor

    bool findFactAssociation(Fact * fact); //Find the association of a certain fact.
    void AddFact(Fact * fact); //Add a fact to the Knowledge Base FactDictionary.
    void dropFact(string param); //Drop fact from the FactDictuionary.
    void loadFact(stringstream &str1, string factElement);//load the fact into KB

    ~KnowledgeBase(); //Deconstructor to delete the map.

};



#endif // KNOWLEDGEBASE_H_INCLUDED


