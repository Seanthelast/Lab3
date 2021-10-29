//
// Created by seant on 9/15/2021.
//
#include "BadString.h"
void BadStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void BadStringAutomaton::S1(const std::string& input) {
    if ((int)input.size() == inputRead){
    return;
    }
    else if (input[index] == '\n'){
        inputRead++;
        index++;
        newLines++;
        S1(input);
    }
    else if (input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}
void BadStringAutomaton::S2(const std::string& input){
    if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}