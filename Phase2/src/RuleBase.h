//
//  RuleBase.hpp
//  SRI
//
//  Created by Babbie Monahelis on 2/28/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef RULEBASE_H_INCLUDED
#define RULEBASE_H_INCLUDED
#include "common_headers.h"
#include "Component.h"
class RuleBase
{

public:
    map<string, vector<Rule*> > rules;
    RuleBase(); //default constructor
    ~RuleBase(); //Destructor

    void AddRule(Rule * rule);
    void dropRule(string param);

};



#endif // RULEBASE_H_INCLUDED