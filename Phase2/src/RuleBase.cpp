//
//  RuleBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 2/28/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
#include "common_headers.h"
#include "RuleBase.h"
RuleBase::RuleBase()
{
    vector<Rule*> rules;
}

void RuleBase::AddRule(Rule * rule)
{
    //this won't work for a map, not sure how to implement
    for (Rule * r : rules)
    {
        if (r == rule)
            cout << "Rule is already in the rule base. \n";
        else
            rules.push_back(rule);

    }

}

void RuleBase::dropRule(string param)
{
    if(rules.find(param)!= rules.end())
        rules.erase(param);
    cout<<"Dropped rules"<<endl;
}

