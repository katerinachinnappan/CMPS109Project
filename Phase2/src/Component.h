#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include <cstdarg>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

/* This will be the base class called Component which will either be a fact or a rule. */

class Component
{

public:

    vector<string> elements; //Vector of strings to hold the elements of this component.
    string identity; //the identity for the fact or rule

    Component(); //default constructor
    Component(string identity, vector<string> members);
    Component(const Component & comp); //Copy constructor.
    Component(Component && p);

    bool find(vector<string> members); //Determines if this Component exists.
    bool AND (bool first, bool second);
    bool OR (bool first, bool second);

    ~Component(); //Needed to be virtual because this class has descendants.

};

class Fact : Component
{

public:

    Fact(string identity, vector<string>elements); //Main constructor for a Fact.
    Fact(const Fact & f); //Copy constructor.
    Fact(Fact && f); //Move constructor.

    string association; //The association of the fact i.e Father, Mother, etc...
    vector<string> members; //The members of the fact i.e John, Paul, Jones, etc...
    friend ostream& operator<<(ostream &os,Fact * fact);


   // bool factExists(vector<string> members); //Takes in a vector that represents the members of a fact.

};

class Rule : Component
{

public:

    Rule(string logicalOperator, string association, vector<string> elements);
    Rule(string identity, vector<Component*> elements, vector<bool> operators); //constructor that can accept rules with multiple components in a vector of type Component.
    Rule(const Rule & r); //copy constructor.
    Rule(Rule && r); //Move constructor.

    string logicalOperator;
    string association; //The association of the rule i.e Grandfather, Grandmother, Parent, etc...
    vector<string> elementss;
    vector<int> functionOperator; //These point to AND/OR, similar to boolean ops.

    bool validate(vector<string> members); //Determines if a rule is valid based on the elements it is built from.
    friend ostream& operator<< (ostream &os, Rule* rule);

};


#endif /* Component_hpp */
