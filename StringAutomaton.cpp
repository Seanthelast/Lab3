//
// Created by seant on 9/15/2021.
//
#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {
    if(input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\n'){
            inputRead++;
            index++;
            newLines++;
            S1(input);
    }
    else if((int)input.size() == inputRead){
        this->type = TokenType::UNDEFINED;
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}
void StringAutomaton::S2(const std::string& input) {
    if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        return;
    }
}
