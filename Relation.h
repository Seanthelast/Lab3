//
// Created by seant on 10/11/2021.
//

#ifndef PROJECT_2_RELATION_H
#define PROJECT_2_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include <string>
#include <set>
#include <utility>

///// set of Tupules
///// string name;
///// constructor will take name and Header
//// also toString
class Relation {
public:
    Relation(std::string name, Header header) {
        this->name = std::move(name);
        this->header = std::move(header);
        this->select1 = true;
    }

    Relation() {
        select1 = true;
    }
    void addToTupleSet(Tuple newTuple);
    std::string toString(Header inputHeader);
    int getTupleSize();
    Relation select1Row(std::string constant, int index);
    Relation select2Row(int index1, int index2);
    void rename(std::vector<std::string> names);
    Relation project(std::vector<int> indices);
    std::set<Tuple> getTuple(int index);
    std::string getName();
    void isSelect2();
    bool getIsSelect();
    void setName(std::string name);


private:
    std::string name;
    std::set<Tuple> rows;
    Header header;
    bool select1;
    Header oldcopy;
};
#endif //PROJECT_2_RELATION_H
