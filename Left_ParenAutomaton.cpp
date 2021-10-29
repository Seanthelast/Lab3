//
// Created by seant on 9/12/2021.
//
#include "Left_ParenAutomaton.h"

void Left_ParenAutomaton::S0(const std::string& input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}


