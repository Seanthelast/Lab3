//
// Created by seant on 9/24/2021.
//
#include "Predicate.h"
#include <sstream>

void Predicate::setParameters(const std::vector<Parameter> parameters) {
    this->parameters = parameters;
}
std::vector<Parameter> Predicate::getParameters() const {
    return parameters;
}
std::string Predicate::getParameter(int i) const {
    return parameters.at(i).toString();
}
std::string Predicate::getPredicate() const{
    return myPredicateID;
}
std::string Predicate::toString() {
        std::ostringstream myString;
        myString << getPredicate() << "(";
        for(unsigned int j = 0; j < parameters.size(); j++){
            myString << parameters.at(j).toString();
            if(j != parameters.size() - 1){
                myString << ",";
            }
        }
        myString << ")";
        return myString.str();
}

Predicate::Predicate(const std::string &myPredicateId) : myPredicateID(myPredicateId) {}
