//
// Created by seant on 9/12/2021.
//
#include "Right_ParenAutomaton.h"

void Right_ParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
