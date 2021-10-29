//
// Created by seant on 9/24/2021.
//
#include "Parameter.h"
#include <sstream>


std::string Parameter::toString() const {
    return param;
}

void Parameter::setParameters(Token myToken) {
    param = myToken.getDescription();
}
bool Parameter::isConstant() {
    if(param[0] == '\''){
        return true;
    }
    else{
            return false;
    }
}
