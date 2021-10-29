//
// Created by seant on 10/12/2021.
//

#ifndef PROJECT_2_TUPLE_H
#define PROJECT_2_TUPLE_H
#include <vector>
#include <string>
#include "Header.h"

class Tuple {
public:
    bool operator<(const Tuple Tuple1) const;    //// tuple & other
        /// compare this Tuple to other Tuple
    Tuple() {};
    Tuple(std::vector<std::string> rowAttributes) { //// constructor
        attributes = rowAttributes;
    }
    std::vector<std::string> getRowAttributes() const;
    std::string toString();
    void addtoTupleVector(std::string newAttribute);
    std::string at(int index);
    unsigned int size();
private:
    std::vector<std::string> attributes;
};
#endif //PROJECT_2_TUPLE_H
