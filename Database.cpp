//
// Created by seant on 10/18/2021.
//
#include "Database.h"
#include <iostream>
#include <sstream>

void Database::addToDatabase(std::string name, Relation relation){    //// don't need to make these globals to pass them in
    dlogDatabase.insert(std::pair<std::string, Relation> (name, relation));
}

Relation& Database::searchDatabase(std::string keyword) {
    return dlogDatabase.at(keyword); //// standard iterator notation for not finding something
}
