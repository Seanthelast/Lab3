//
// Created by seant on 10/18/2021.
//

#ifndef PROJECT_2_INTERPRETER_H
#define PROJECT_2_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"
#include <utility>
#include <vector>

class Interpreter {
public:
   Interpreter(DatalogProgram myDatalogProgram){    //// constructor
        this->datalogProgram = myDatalogProgram;
   }
    Interpreter() {}
    void CreateRelation(Predicate inputPredicate);
    void CreateTuple(Predicate inputPredicate);

    /// gets the vectors from schemes, creates the relations with constructor and adds them to database
    //// get tables from relation
    ///// analyze them from map to answer queries
    Relation evaluatePredicate(const Predicate& p);
    Relation evaluateQueries(Predicate p);
    void Start();

private:
    DatalogProgram datalogProgram;
    Database database;

    ///// do I create a vector to represent these tables???
};

#endif //PROJECT_2_INTERPRETER_H
