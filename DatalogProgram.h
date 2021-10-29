//
// Created by seant on 9/22/2021.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H
#include "Token.h"
#include "Predicate.h"
#include <vector>
#include <set>
#include "Rule.h"

#pragma once

class DatalogProgram {
public:

    //// vector of Schemes
    //// vector of Facts
    //// vector of Rules
    //// vector of Queries
    void addSchemes(Predicate myPredicate);
    void addFacts(Predicate myPredicate);
    std::vector<Predicate> getFacts();
    void addQueries(Predicate myPredicate);
    void addRules(Rule myRuleList);
    void toString();
    void addToSet(std::vector<Parameter> myParameter);
    std::vector<Predicate> getSchemes();
    std::vector<Predicate> getQueries();
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Rule> rules;
    std::vector<Predicate> queries;
    std::set<std::string> factsParameters;


};

#endif //PROJECT_2_DATALOGPROGRAM_H
