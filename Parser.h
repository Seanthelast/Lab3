//
// Created by seant on 9/22/2021.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "Predicate.h"
#include "Parameter.h"
#include "DatalogProgram.h"
#include <vector>
#pragma once

class Parser {
private:
    std::vector<Token*> tokens;
    std::vector<Parameter> parameters;
    std::vector<Predicate> bodyPredicates;
    int index = 0;
    DatalogProgram myProgram;
    // Rule rulePredicate;


public:
    Parser(std::vector<Token*> myTokens);
    void parse();
    void parseDatalogProgram();
    void MatchTokens(Token* myToken, TokenType target);
    void parseSchemes();
    void parseIDList();
    void parseQueryList();
    void parseQuery();
    void parsePredicateList();
    void parseParameterList();
    void parseParameter();
    void parsePredicate();
    void parseRule();
    void parseRuleList();
    void parseStringList();
    void parseFact();
    void parseFactList();
    void parseSchemeList();
    void parseHeadPredicate();
    DatalogProgram getDatalog();





};

#endif //PROJECT_2_PARSER_H
