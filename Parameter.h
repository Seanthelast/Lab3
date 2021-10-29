//
// Created by seant on 9/22/2021.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H
#include "Token.h"
#include <string>

class Parameter {

public:
    std::string toString() const;
    Parameter() {};
    ~Parameter() {};
    void setParameters(Token myToken);
    Parameter(const std::string &param) : param(param) {}
    bool isConstant();
private:
    std::string param;


};
#endif //PROJECT_2_PARAMETER_H
