#include "Component.h"
#include "common_headers.h"
/* Methods for Component - a base class that fact and rule will derive from */

//Our default constructor.
Component::Component()
{
    string identity = "";
    vector<string> elements;

}

//Main constructor for our Components. This will take in a string for its
//identity along with a vector of 'members' that represent the arguments
//for a component.
Component::Component(string i, vector<string> members)
{
    string identity = i;
    vector<string> elements;

}

//Copy constructor
Component::Component(const Component & copyComponent)
{
    identity = copyComponent.identity;
    elements = copyComponent.elements;
}

//Method for AND operator
bool Component::AND(bool first, bool second)
{
    return (first && second);

}

//Method for OR operator
bool Component::OR(bool first, bool second)
{
    return (first || second);
}

//Deconstructor
Component::~Component()
{

}

/************** Methods for Fact **************/


Fact::Fact(string a, vector<string>elements)
{
    cout<<"constructor"<<endl;
    association = a; //Association of the fact.
    members = elements;
    for(auto i = members.begin(); i!= members.end(); i++)
            cout<<"vector contents: "<<*i<<endl;
}

Fact::Fact(const Fact & f)
{
    association = f.identity;
    elements = f.elements;
}

ostream& operator<< (ostream &os, Fact* fact)
{
    //name of fact
	os << fact->association << "(";
	for(int i=0; i < fact->members.size(); i++){
		string params = fact->members[i];
		os << params <<",";
	}
	os << ")" << endl;
    return os;
}

Rule::Rule(string logicalOperator, string association, vector<string> elements)
{
    cout<<"Rule constructor"<<endl;
    this->logicalOperator = logicalOperator;
    this->association = association;
    cout<<"association: "<<this->association<<endl;
    elementss = elements;
    for(auto i = elementss.begin(); i!= elementss.end(); i++)
            cout<<"vector contents: "<<*i<<endl;
    /*string association = ""; //Association of the rule.
    vector<Component*> members; //Vector of the Components that will define this rule. These can be rules or facts.
    vector<bool> operators; //Vector to store the operators we come across in the rule.*/
}

Rule::Rule(string i, vector<Component*> e, vector<bool> operators)
{
    string association = i;
    vector<Component*> elements = e;
    vector<bool> function = operators;
}
ostream& operator<<(ostream &os, Rule* rule)
{
    os << rule->association << ":-";
	for(int i=0; i < rule->elementss.size(); i++){
		string params = rule->elementss[i];
		os <<" "<< params ;
	}
    return os;
}

