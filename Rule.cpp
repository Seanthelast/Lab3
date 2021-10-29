//
// Created by seant on 9/25/2021.
//
#include "Rule.h"
#include <sstream>


Rule::Rule(const Predicate &headPredicate) : headPredicate(headPredicate) {}

Predicate &Rule::getHeadPredicate() {
    return headPredicate;
}
void Rule::setHeadPredicate(Predicate myPredicate) {
    headPredicate = myPredicate;
}
void Rule::setBodyPredicates(std::vector<Predicate> myBodyPredicates) {
    bodyPredicates = myBodyPredicates;
}
std::vector<Predicate> Rule::getBodyPredicates() const {
    return bodyPredicates;
}
std::string Rule::toString() {
    std::ostringstream myString;
    myString << getHeadPredicate().toString()  << " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); i++){
        if (i == bodyPredicates.size() - 1) {
            myString << bodyPredicates.at(i).toString();
        }
        else {
            myString << bodyPredicates.at(i).toString() <<", ";
        }


    }
    return myString.str();
}