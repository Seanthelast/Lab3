//
// Created by seant on 9/15/2021.
//

#ifndef PROJECT_1_ENDOFFILE_H
#define PROJECT_1_ENDOFFILE_H
#include "Automaton.h"

class EndOfFileAutomaton : public Automaton
{
private:
public:
    EndOfFileAutomaton() : Automaton(TokenType::EOFile) {}
    void S0(const std::string& input);
};
#endif //PROJECT_1_ENDOFFILE_H
