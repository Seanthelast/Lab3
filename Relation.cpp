//
// Created by seant on 10/14/2021.
//
#include "Relation.h"
#include <iostream>
#include <sstream>

void Relation::addToTupleSet(Tuple newTuple) {
        rows.insert(newTuple);
}
std::string Relation::getName() {
    return name;
}
void Relation::setName(std::string name) {
    this->name = name;
}
std::string Relation::toString(Header inputHeader) {
    std::stringstream ss;
    ss << name << "(";
    for(unsigned int i = 0; i < inputHeader.getAttributes().size(); i++){
        if(i == inputHeader.getAttributes().size() - 1){
            ss << inputHeader.getHeadAttributes(i);
        }
        else {
            ss << inputHeader.getHeadAttributes(i) << ",";
        }
    }
    ss << ")?";
    if(rows.size() == 0){
        ss << " No";
        ss << std::endl;
        return ss.str();
    }
        ss << " Yes(" << rows.size() << ")" << std::endl;
        if (select1 == true){
            return ss.str();
        }
        for(Tuple currTup : rows) {
            ss << "  ";
            for (unsigned int i = 0; i < currTup.size(); i++){
                if(i == header.getAttributes().size() - 1){
                    ss << header.getHeadAttributes(i) << "=" << currTup.at(i);
                }
                else{
                    ss << header.getHeadAttributes(i) << "=" << currTup.at(i) << ", ";
                }
        }
        ss << std::endl;
    }
        return ss.str();

}
Relation Relation::select1Row(std::string constant, int index) {
    Relation selectRelation(name, header);
    for(Tuple currTup : rows) {
        if(currTup.getRowAttributes().at(index) == constant){
            selectRelation.addToTupleSet(currTup);
        }
    }
    if(this->select1 == false){
        selectRelation.isSelect2();
    }
    return selectRelation;
}
Relation Relation::select2Row(int index1, int index2){
    Relation selectRelation(name, header);
    std::string temp;
    for(Tuple currTup : rows){
        // save first value{
        if(currTup.getRowAttributes().at(index2) == currTup.getRowAttributes().at(index1)) {   /// compare values in tuple to the first value
                selectRelation.addToTupleSet(currTup);
        }
    }
    selectRelation.isSelect2();
    return selectRelation;
}

void Relation::rename(std::vector<std::string> names){
    oldcopy = header;
    header.resetHeadAttributes(names);
}

Relation Relation::project(std::vector<int> indices) {
    Relation myNewRelation;
    myNewRelation.setName(this->name);
    if(this->select1 == false){
        myNewRelation.isSelect2();
    }
    for(Tuple currTuple : rows ){
        Tuple newTuple;
        for(unsigned int i = 0; i < indices.size(); i++) {
            newTuple.addtoTupleVector(currTuple.at(indices.at(i)));    //// adds them in scrambled order
        }
        myNewRelation.addToTupleSet(newTuple);
    }
   return myNewRelation;
}
void Relation::isSelect2() {
    select1 = false;
}
bool Relation::getIsSelect(){
    return select1;
}
int Relation::getTupleSize() {
    return rows.size();
}

