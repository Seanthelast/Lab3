//
// Created by seant on 9/12/2021.
//
#include "CommaAutomaton.h"

void CommaAutomaton::S0(const std::string& input) {
    if (input[index] == ',') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
