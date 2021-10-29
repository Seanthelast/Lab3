//
// Created by seant on 9/15/2021.
//
#include "IDAutomaton.h"
void IDAutomaton::S0(const std::string& input) {
    if(isalpha(input[index])){
        inputRead++;
        index++;
        S1(input);
    }
    else {
            Serr();
    }
}
void IDAutomaton::S1(const std::string& input) {
    if(isalnum(input[index])){
        inputRead++;
        index++;
        S1(input);
    }
    else if (!isalpha(input[index]) || !isdigit(input[index])) {
        return;
    }

}
