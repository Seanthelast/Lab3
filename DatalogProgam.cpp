//
// Created by seant on 9/27/2021.
//
#include "DatalogProgram.h"
#include <iostream>

void DatalogProgram::addSchemes(Predicate myPredicate) {
    schemes.push_back(myPredicate);
}
std::vector<Predicate> DatalogProgram::getSchemes() {
    return schemes;
}
void DatalogProgram::addFacts(Predicate myPredicate) {
    facts.push_back(myPredicate);
}
std::vector<Predicate> DatalogProgram::getFacts() {
    return facts;
}
void DatalogProgram::addQueries(Predicate myPredicate){
    queries.push_back(myPredicate);
}
std::vector<Predicate> DatalogProgram::getQueries(){
    return queries;
}
void DatalogProgram::addRules(Rule myRuleList){
    rules.push_back(myRuleList);
}
void DatalogProgram::addToSet(std::vector<Parameter> myParameter){
    for(unsigned int i = 0; i < myParameter.size(); i++){
        factsParameters.insert(myParameter.at(i).toString());
    }
}
void DatalogProgram::toString() {
    std::cout << "Schemes(" << schemes.size() << "):" << std::endl;
    for (unsigned int i = 0; i < schemes.size(); i++){
            std::cout << "\t" << schemes.at(i).toString() << std::endl;  /// defined toString in Predicate to easily access parameter vector
    }
    std::cout << "Facts(" << facts.size() <<  "):" << std::endl;
    for (unsigned int i = 0; i < facts.size(); i++){
        std::cout << "\t" << facts.at(i).toString() << "." << std::endl;
    }
    std::cout << "Rules(" << rules.size() << "):" << std::endl;
    for (unsigned int i = 0; i < rules.size(); i++){
        std::cout << "\t" << rules.at(i).toString() << "." << std::endl;
    }
    std::cout << "Queries(" << queries.size() << "):" << std::endl;
    for (unsigned int i = 0; i < queries.size(); i++){
        std::cout << "\t" << queries.at(i).toString() << "?" << std::endl;
    }
    std::cout << "Domain(" << factsParameters.size() << "):" << std::endl;
    for (auto it = factsParameters.begin(); it != factsParameters.end(); ++it) {
        std::cout << "\t" << *it << std::endl;
    }
}