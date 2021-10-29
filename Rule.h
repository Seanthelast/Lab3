//
// Created by seant on 9/22/2021.
//
#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H
#include "Token.h"
#include "Predicate.h"
#pragma once

class Rule {
//public:
//void toString();
//
public:
    Rule(const Predicate &headPredicate);
    Predicate &getHeadPredicate();
    void setHeadPredicate(Predicate myPredicate);
    std::vector<Predicate> getBodyPredicates() const;
    void setBodyPredicates(std::vector<Predicate> myBodyPredicates);
    std::string toString();

private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;
};
#endif // PROJECT_2_RULE_H
