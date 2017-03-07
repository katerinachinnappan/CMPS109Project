//
//  KnowledgeBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 2/25/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
#include "common_headers.h"
#include "KnowledgeBase.h"
string factName;
KnowledgeBase::KnowledgeBase()
{
    map<string, vector<Fact *>> FactDictionary = *new map<string, vector<Fact *> >();
}

bool KnowledgeBase::findFactAssociation(Fact * fact)
{
    if (FactDictionary.find(fact->association) == FactDictionary.end())
        return false;

    return true;
}

void KnowledgeBase::AddFact(Fact * fact)
{
    bool found = findFactAssociation(fact);

    if (found == false)
    {
        vector<Fact *> tempVector;
        tempVector.push_back(fact);
        FactDictionary[fact->association] = tempVector;
    }
    else
    {
        for (Fact * f : FactDictionary[fact->association])
        {
            if (f->members == fact->members)
                cout << "This fact is already in our knowledge base.\n";
        }

        FactDictionary[fact->association].push_back(fact);

    }

}
void KnowledgeBase::dropFact(string param){
}
void KnowledgeBase::loadFact(stringstream &str2, string factElement)
{
    //KnowledgeBase *facts;
    getline(str2, factName, ')');
    cout<<"Val in FactName="<<factName<<endl;
    if(FactDictionary.count(factName) > 0){//check if fact is in dictionary
        Fact *factt;
        factt = new Fact(factName);//invokes constructor in Fact class, factName is now Father, Mother, etc...
        FactDictionary[factName] = factt;
        while(getline(str2, factElement, ',')){
            factt->members.push_back(factElement);//magic
        }//push all the members into the vector
        cout<<"Facts loaded bruhhhhs"<<endl;
    }
    /*if(FactDictionary.count(factName) != LEFT){//check if fact is in dictionary
    Fact *factt;
    factt = new Fact(factName);
    FactDictionary[factName] = factt;
    while(getline(str1, factElement, ',')){
        factt->members.push_back(factElement);
    }
    }
    //if fact is already in dictionary
    else if(FactDictionary.count(factName) == LEFT)
    {
        FactDictionary.find(factName)->second->members.push_back("|");
        while(getline(str1, factElement, ',')){
            FactDictionary.find(factName)->second->members.push_back(factElement);
        }
    }*/

}
void testFact()
{
    cout<<"Fact"<<endl;
}
void testRule()
{
    cout<<"Rule"<<endl;
}

KnowledgeBase::~KnowledgeBase()
{
    FactDictionary.clear();
}
/*int main()
{

}*/

