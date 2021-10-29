//
// Created by seant on 9/22/2021.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H
#include "Token.h"
#include "Parameter.h"
#include <vector>
#pragma once

class Predicate {
public:
    void setParameters(const std::vector<Parameter> parameters);
    Predicate(const std::string &myPredicateId);
    std::string getPredicate() const;
    std::string getParameter(int i) const;
    std::vector<Parameter> getParameters() const;
    std::string toString();
private:
    std::string myPredicateID;
    std::vector<Parameter> parameters;
};
#endif //PROJECT_2_PREDICATE_H
