#ifndef KB_H_INCLUDED
#define KB_H_INCLUDED
#include <map>
#include <vector>
#include <iterator>
#include "Fact.h"
#include "FactType.cpp"
class KB{
    protected:
        std::map<FactType, std::vector<Fact*>> facts;//store fact into a vector with the same amount of parameters
        std::map<std::string, FactType*> factType;//identify if there are duplicate facts with same name and same num of parameters
        std::map<FactType, std::vector<Fact*>>::iterator myMapIterator;
    public:
        KB();//default constructor
        KB(std::map<FactType, std::vector<Fact*>> facts, map<FactType, std::vector<Fact*>>::iterator myMapIterator);//constructor with params
        Fact getFact();
        friend class Fact;

};



#endif // KB_H_INCLUDED