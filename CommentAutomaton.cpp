//
// Created by seant on 9/15/2021.
//
#include "CommentAutomaton.h"


void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        if (input[index+1] == '|'){
            return;
        }
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void CommentAutomaton::S1(const std::string& input){
    if (input[index] == '\n'){
        return;
    }
    else if ((int)input.size() == index) {
        this->type = TokenType::UNDEFINED;
    }

    else {
        inputRead++;
        index++;
        S1(input);
    }

}

