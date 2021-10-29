//
// Created by seant on 10/18/2021.
//
#include "Header.h"
#include <iostream>
#include <sstream>
#include <vector>

void Header::setName(std::string inputName) {
    inputName = name;
}

std::string Header::getName() {
    return name;
}
std::string Header::getHeadAttributes(unsigned int i) {
    return attributes.at(i);
}
std::vector<std::string> Header::getAttributes() {
    return attributes;
}
void Header::resetHeadAttributes(std::vector<std::string> newAttributes) {
    attributes = newAttributes;
}

void Header::addHeadAttribute(std::string inputAttribute) {
    attributes.push_back(inputAttribute);
}
std::string Header::toString() {
    std::stringstream ss;
    for (unsigned int i = 0; i < attributes.size(); i++){
        ss << attributes.at(i) << ", ";
    }
    ss << std::endl;
    return ss.str();
}
