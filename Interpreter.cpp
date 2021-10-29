//
// Created by seant on 10/18/2021.
//
#include "Interpreter.h"
#include <iostream>
#include <unordered_map>

void Interpreter::CreateRelation(Predicate inputPredicate){
    std::string name;
    Header newHeader;
    Relation newRelation;
    /// create new header each time it goes through
    name = inputPredicate.getPredicate();  /// get name from schemes
        for (unsigned int j = 0; j < inputPredicate.getParameters().size(); j++){
            newHeader.addHeadAttribute(inputPredicate.getParameters().at(j).toString());   /// get parameters from schemes
        }
        newRelation = Relation(name, newHeader);
    database.addToDatabase(name, newRelation); /// add to map
}
//// create tuple from parameters of facts
void Interpreter::CreateTuple(Predicate inputPredicate) {
    std::vector<std::string> tupleRow;    //// create vector for each individual tuple row
        /// extract parameters from facts
        for (unsigned int j = 0; j < inputPredicate.getParameters().size(); j++){
            tupleRow.push_back(inputPredicate.getParameters().at(j).toString());
        }
        Tuple newTuple = Tuple(tupleRow); /// set new Tuple row as tuple class object
        Relation& matchedRelation = database.searchDatabase(inputPredicate.getPredicate());   /// find proper place on map for new tupule
        matchedRelation.addToTupleSet(newTuple);
        /// add tuple to relation
        /// search the map for relation, link relation to tuple
        /// add tuple to relation to map

}

///// add tuple to relation

Relation Interpreter::evaluatePredicate(const Predicate& p) {
   ///// evalaute predicates for the queries
   std::string queryName = p.getPredicate();
   Relation newQueryRelation = database.searchDatabase(queryName);
   newQueryRelation.setName(queryName);
   return newQueryRelation;
}
Relation Interpreter::evaluateQueries(Predicate p) {
    Relation myRelation = evaluatePredicate(p); // myrelation is corresponding relation found in database, with all associated tuples
    std::vector<Parameter> queryParam = p.getParameters();
    std::vector<Parameter> select1Param;

    std::unordered_map<std::string, int> projVals;
    std::vector<std::string> newNames;
    std::vector<int> varibPositions;
    for (unsigned int i = 0; i < queryParam.size(); i++) { /// parse through the parameters of your input queries
        // get parameters from predicate, iterate through
        if (queryParam.at(i).isConstant()) {
            // do a select type one
            select1Param.push_back(queryParam.at(i)); /// go to select one
            myRelation = myRelation.select1Row(queryParam.at(i).toString(), i);
        }
         else {   /// is variable
            if (projVals.find(queryParam.at(i).toString()) != projVals.end()) {
                /// have seen variable before
                // std::vector<int> select2Param;    //// define it in the branch when we need to use it
                // select2Param.push_back(i);         //// if multiple select 2 happen, they all go into same vector
                int firstIndex = i;
                int compIndex = projVals[queryParam.at(i).toString()];
                myRelation = myRelation.select2Row(firstIndex, compIndex);
            }
             else { // haven't seen variable before, add to map
                projVals.insert(std::pair<std::string, int>(queryParam.at(i).toString(), i));
                /// iterate through map
                myRelation.isSelect2();
                newNames.push_back(queryParam.at(i).toString());
                varibPositions.push_back(i);

             }
         }
    }
    /// iterate over map


    myRelation = myRelation.project(varibPositions);   /// things get switched here

    myRelation.rename(newNames);

    return myRelation;
}




void Interpreter::Start() {
    Relation myQueryRelation;
    Relation outputRelation;
    std::string outputString;
    std::vector<Predicate> headerVals = datalogProgram.getSchemes();    /// gets schemes vector from Datalog
    for (unsigned int i = 0; i < headerVals.size(); i++) {
        CreateRelation(headerVals.at(i));
    }
    std::vector<Predicate> rowVals = datalogProgram.getFacts();
    for (unsigned int i = 0; i < rowVals.size(); i++){
        CreateTuple(rowVals.at(i));
        ///// use if statement to link the Tuple to it's relevant keyword name?
        ///// how do I return a name and a tuple?
    }
    std::vector<Predicate> queryVals = datalogProgram.getQueries();
    for (unsigned int i = 0; i < queryVals.size(); i++){
        Header oldHeader;
        for(unsigned int j = 0; j < queryVals.at(i).getParameters().size(); j++){
            oldHeader.addHeadAttribute(queryVals.at(i).getParameters().at(j).toString());
        }

        outputRelation = evaluateQueries(queryVals.at(i));
        outputString = outputRelation.toString(oldHeader);
        std::cout << outputString;
    }


}