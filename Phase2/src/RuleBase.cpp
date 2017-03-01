//
//  RuleBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 2/28/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "RuleBase.hpp"
#include <iostream>
using namespace std;

RuleBase::RuleBase()
{
    vector<Rule*> rules;
}

void RuleBase::AddRule(Rule * rule)
{
    for (Rule * r : rules)
    {
        if (r == rule)
            cout << "Rule is already in the rule base. \n";
        else
            rules.push_back(rule);
       
    }
    
}

void RuleBase::DropRule(Rule * rule)
{
    
    
}

