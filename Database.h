//
// Created by seant on 10/11/2021.
//

#ifndef PROJECT_2_DATABASE_H
#define PROJECT_2_DATABASE_H
#include <map>
#include "Relation.h"
class Database {
public:
    Database() {};
    void addToDatabase(std::string name, Relation relation);
    std::string toString();
    Relation& searchDatabase(std::string keyword);
private:
    std::map<std::string, Relation> dlogDatabase;
};


///// map from name to Relation
///// no logic done here, that will all be done in interpreter

#endif //PROJECT_2_DATABASE_H
