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
string ruleName, ruleName1, ruleName2;
string rt1, rt2;
string element;
string operatorL;
string factName;
vector<string>elements;
int LEFT = 1;
SRI::SRI(){}
SRI::~SRI(){}
void SRI::dumpRF(ostream &os, KnowledgeBase *kb)
{   cout<<"DUMP"<<endl;
    for(auto iteratorx = kb->FactDictionary.begin(); iteratorx != kb->FactDictionary.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }
    /*for (auto p : kb->FactDictionary) {
        cout << "m[" << p.first << "] = " << p.second << '\n';*/
            //dump rules
    /*for(auto iteratorx = brules->rules.begin(); iteratorx != brules->rules.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }*/
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
void SRI::dump(KnowledgeBase *kb)
{
    ofstream out;
    //open file
    out.open("dump.sri");
    dumpRF(out, kb);

}
void SRI::drop(string param, KnowledgeBase *kb, RuleBase *rb)
{
    kb->dropFact(param, kb);
    rb->dropRule(param, rb);

}
void SRI::loadRule(stringstream &str, stringstream &str1, string ruleElement, RuleBase *rb)
{
    getline(str1, ruleName, ':');
    getline(str, operatorL, ' ');//parse the logical operator
    stringstream str2(ruleName);
    getline(str2, ruleName1, '(');
    getline(str2, rt1, ')');
    stringstream str3(rt1);
    cout<<"Val in ruleName="<<ruleName<<endl;
    if(rb->rules.empty()){cout<<"Rule map empty"<<endl;}
    else{cout<<"Rule map not empty"<<endl;}
}
void SRI::loadFact(stringstream &str2, string factElement, KnowledgeBase *kb)
 {
    getline(str2, factName, '(');
    cout<<"Val in FactName="<<factName<<endl;
    while(getline(str2, factElement, ',')){
            cout<<"loadFact"<<endl;
            cout<<"Fact memebers: "<<factElement<<endl;
            elements.push_back(factElement);//magic
        }
    if(kb->FactDictionary.empty()){cout<<"Fact map empty"<<endl;}
    else{cout<<"Fact map not empty"<<endl;}
        //factt = new Fact(factName, elements);//invokes constructor in Fact class, factName is now Father, Mother, etc...
    if(kb->FactDictionary.count(factName) != 1)
    {
        cout<<"is not element in the map"<<endl;
        Fact *factt;
        factt = new Fact(factName, elements);//invokes constructor in Fact class, factName is now Father, Mother, etc...
        kb->FactDictionary[factName] = factt;
        kb->FactDictionary.insert(make_pair(factName, new Fact(factName, elements)));
       // kb->FactDictionary[factName] = factt;
        while(getline(str2, factElement, ',')){
                cout<<"loadFact"<<endl;
                cout<<"Fact memebers: "<<factElement<<endl;
            factt->members.push_back(factElement);//magic
        }///push all the members into the vector

        for(auto i = factt->members.begin(); i!= factt->members.end(); i++)
            cout<<"vector contents: "<<*i<<endl;
        cout<<"Facts loaded bruhhhhs"<<endl;
    }
    else if(kb->FactDictionary.count(factName) ==1){
        cout<<factName<<" is  an element in the Fact map already"<<endl;
    }
    for(auto iteratorx = kb->FactDictionary.begin(); iteratorx != kb->FactDictionary.end(); iteratorx++)
    {
        cout<<iteratorx->second<<endl;
    }
    for (auto &p : kb->FactDictionary) {
        cout << "m[" << p.first << "] = " << p.second << '\n';
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
void SRI::load(KnowledgeBase *kb, RuleBase *rb)
{
	string filePath;
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
        //cout<<"Parse"<<parse<<endl;
        if(parse == ":-"){
            loadRule(str1, str2, element, rb);
            testRule();
        }
        else{
            loadFact(str2,element, kb);
            //testFact();
        }

	}
    cout<<"Loaded"<<endl;
}
/*int main()
{

}*/
