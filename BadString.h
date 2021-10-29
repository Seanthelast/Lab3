//
// Created by seant on 9/15/2021.
//

#ifndef PROJECT_1_BADSTRING_H
#define PROJECT_1_BADSTRING_H
#include "Automaton.h"
class BadStringAutomaton : public Automaton
{
private:
void S1(const std::string& input);
    void S2(const std::string& input);

public:
    BadStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor
    void S0(const std::string& input) override;
};

#endif //PROJECT_1_BADSTRING_H
