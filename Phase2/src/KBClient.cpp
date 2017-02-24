#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <map>
#include "KB.h"
using namespace std;
KB::KB() :facts(), factType() {}//initialize to null
KB::KB(map<FactType, vector<Fact*>> facts, map<FactType, vector<Fact*>>::iterator myMapIterator){
    for(myMapIterator = facts.begin(); myMapIterator != facts.end(); myMapIterator++)
    {
        this->myMapIterator = myMapIterator;
    }

}
int main(){

}
