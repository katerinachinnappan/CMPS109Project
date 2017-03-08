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


Fact::Fact(string a)
{
    association = a; //Association of the fact.
    vector<string>members;
}

Fact::Fact(const Fact & f)
{
    association = f.identity;
    elements = f.elements;
}

Rule::Rule()
{
    string association = ""; //Association of the rule.
    vector<Component*> members; //Vector of the Components that will define this rule. These can be rules or facts.
    vector<bool> operators; //Vector to store the operators we come across in the rule.
}

Rule::Rule(string i, vector<Component*> e, vector<bool> operators)
{
    string association = i;
    vector<Component*> elements = e;
    vector<bool> function = operators;
}

