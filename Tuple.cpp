//
// Created by seant on 10/14/2021.
//
#include "Tuple.h"
#include <sstream>
bool Tuple::operator<(const Tuple Tuple1) const {
    return this->attributes < Tuple1.attributes;
}
std::vector<std::string> Tuple::getRowAttributes() const {
    return this->attributes;
}
std::string Tuple::toString() {
    std::stringstream ss;
    for(unsigned int i = 0; i < attributes.size(); i++){
        if (i == attributes.size() - 1){
            ss << attributes.at(i);
        }
        else {
            ss << attributes.at(i) << ",";
        }
    }
    ss << std::endl;
    return ss.str();
}
void Tuple::addtoTupleVector(std::string newAttribute) {
    attributes.push_back(newAttribute);
}
std::string Tuple::at(int index) {
    return attributes.at(index);
}
unsigned int Tuple::size() {
    return attributes.size();
}