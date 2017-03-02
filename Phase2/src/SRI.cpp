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
	string line;
	string filePath;
	cout << "Enter filename: " << endl;
	cin >> filePath;
	ifstream userFile(filePath);
	while (getline(userFile, line)) {
		if (getType(line)) {//FACT
			if (kb.facts(getFactAssoc(line)) != kb.facts.end()) {//found FactAssoc
				if (find(kb.facts[getFactAssoc(line)].begin(), kb.facts[getFactAssoc(line)].end(), getFactParam(line) != kb.facts[getFactAssoc(line)].end())) {//find factParam in vector
					return;
				}
				else {
					kb.itVector = kb.itMap.insert(kb.itVector, getFactParam(line));//insert factParam to i
				}
			}
			else {// insert FactAssocia and FactParam to facts map
				kb.facts[getFactAssoc(line)] = getFactParam(line);
			}
		}
		else if(getType(line)){//RULE
			line.erase(0, line.find(delimiterSpace) + delimiterSpace.length());
			
		}
		else {
			cout << "SRI load error: Invalid command (command FACT and RULE only)" << endl;
			continue;
		}
	}
}
/*int main()
{

}*/
