#include "common_headers.h"
#include "SRI.h"
#include "Component.h"
#include "Component.cpp"
#include "KnowledgeBase.cpp"
#include "RuleBase.cpp"
/***global**/
string line;
string right;
string lefty;
string predicate;
string parse;
string factName, ruleName;
string element; //members of the fact (Rick, Bob, Billy...etc)
string operatorL;
int LEFT = 1;
SRI::SRI(){}
SRI::~SRI(){}
inline void SRI::dumpRF(ostream &os, KnowledgeBase *facts, RuleBase *brules)
{
    //dump facts
    for(auto iteratorx = facts->FactDictionary.begin(); iteratorx != facts->FactDictionary.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }
    //dump rules
    for(auto iteratorx = brules->rules.begin(); iteratorx != brules->rules.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }

}
/*void SRI::inference(string input, KnowledgeBase *facts, RuleBase *brules)
{
    ifstream in(input);//input file passed to infer on
    getline(in, line);
    stringstream str(line);
    getline(str, lefty, '(');

    inferFact(facts, lefty);
    inferRule(brules, facts, lefty, line);


}*/
void SRI::inferFact(KnowledgeBase *facts, string left)
{
    if(facts->FactDictionary.count(left) == LEFT){
        //print
        cout<<"Facts: "<<facts->FactDictionary[left]<<endl;
    }
}
void SRI::inferRule(RuleBase *brules, KnowledgeBase *facts, string left, string emptyLine)
{
    if(brules->rules.count(left) == LEFT){
        brules->identifyRule(emptyLine, brules, facts);
    }

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
void SRI::loadRule(stringstream &str, stringstream &str1, string ruleElement)
{
    getline(str, ruleName, ':');
    getline(str, operatorL, ' ');//parse the logical operator
}
void SRI::loadFact(stringstream &str1, string factElement)
{
    KnowledgeBase *facts;
    getline(str1, factName, ')');
    if(facts->FactDictionary.count(factName) != LEFT){//check if fact is in dictionary
    Fact *factt;
    factt = new Fact(factName);
    facts->FactDictionary[factName] = factt;
    while(getline(str1, factElement, ',')){
        factt->members.push_back(factElement);
    }
    }
    //if fact is already in dictionary
    else if(facts->FactDictionary.count(factName) == LEFT)
    {
        facts->FactDictionary.find(factName)->second->members.push_back("|");
        while(getline(str1, factElement, ',')){
            facts->FactDictionary.find(factName)->second->members.push_back(factElement);
        }
    }

}
void testFact()
{
    cout<<"Fact"<<endl;
}
void testRule()
{
    cout<<"Rule"<<endl;
}
void SRI::load()
{
	string filePath;
	KnowledgeBase *kb;
	RuleBase *rb;
	cout << "Enter filename: " << endl;
	cin >> filePath;
	ifstream userFile(filePath);
	while (getline(userFile, line)) {
        stringstream str(line);
        getline(str, lefty, ')');
        getline(str, parse, ' ');
        stringstream str1(line);
        stringstream str2(lefty);

        //load rule
        cout<<"Parse"<<parse<<endl;
        if(parse == ":-"){
            //loadRule(str, str1, element);
            testRule();
        }
        else{
            kb->loadFact(str2,element);
            testFact();
        }

	}
    cout<<"Loaded"<<endl;
}
/*int main()
{

}*/
