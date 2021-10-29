//
// Created by seant on 9/22/2021.
//
#include "Parser.h"
#include <iostream>
#include <vector>

using namespace std;
//// datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

void Parser::MatchTokens(Token* myToken, TokenType target){   // should a pointer go here?
    if(myToken->getType() == target){
        index++;
        return;
    }
    else if (myToken->getType() == TokenType::COMMENT) {
       index++;
       return;
    }
    else if (myToken->getType() == TokenType::EOFile){
        return;
    }
    else{
        throw *myToken;
    }
}
// scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::parseSchemes(){
    if (tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        return;
    }
    parameters.clear();
    Predicate frontPredicate = Predicate(tokens.at(index)->getDescription());
    MatchTokens(tokens.at(index), TokenType::ID);
    MatchTokens(tokens.at(index), TokenType::LEFT_PAREN);
    Parameter myParam = Parameter(tokens.at(index)->getDescription());
    parameters.push_back(myParam);
    MatchTokens(tokens.at(index), TokenType::ID);
    parseIDList(); // go to idList
    MatchTokens(tokens.at(index), TokenType::RIGHT_PAREN);
    frontPredicate.setParameters(parameters);
    myProgram.addSchemes(frontPredicate);
}
// idList  	-> 	COMMA ID idList | lambda
void Parser::parseIDList(){
    if (tokens.at(index)->getType() == TokenType::COMMA){
        MatchTokens(tokens.at(index), TokenType::COMMA);
        Parameter myParam = Parameter(tokens.at(index)->getDescription());
        parameters.push_back(myParam);
        MatchTokens(tokens.at(index), TokenType::ID);
        parseIDList();
    }
    else if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        return;
    }

}
// schemeList	->	scheme schemeList | lambda
void Parser::parseSchemeList(){
    if(tokens.at(index)->getType() == TokenType::FACTS){
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        parseSchemeList();             //// in case a comment comes before a scheme
        return;
    }
    parseSchemes();
    parseSchemeList();
    // lambda
}
// factList	->	fact factList | lambda
void Parser::parseFactList() {
    if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        parseFactList(); /// checks Fact list one more time
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::RULES){
        return;
    }
    parseFact();
    parseFactList();

}
//    fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
void Parser::parseFact() {
    parameters.clear();
    Predicate frontPredicate = Predicate(tokens.at(index)->getDescription());
    MatchTokens(tokens.at(index), TokenType::ID);
    MatchTokens(tokens.at(index), TokenType::LEFT_PAREN);
    Parameter myParam = Parameter(tokens.at(index)->getDescription()); //// defines parameter object and begins adding parameters to it
    parameters.push_back(myParam);
    MatchTokens(tokens.at(index), TokenType::STRING);
    parseStringList();
    MatchTokens(tokens.at(index), TokenType::RIGHT_PAREN);
    MatchTokens(tokens.at(index), TokenType::PERIOD);
    frontPredicate.setParameters(parameters);
    myProgram.addToSet(parameters);
    myProgram.addFacts(frontPredicate);
}
// stringList	-> 	COMMA STRING stringList | lambda
void Parser::parseStringList() {
    if (tokens.at(index)->getType() == TokenType::COMMA){
        MatchTokens(tokens.at(index), TokenType::COMMA);
        Parameter myParam = Parameter(tokens.at(index)->getDescription());
        parameters.push_back(myParam);
        MatchTokens(tokens.at(index), TokenType::STRING);
        parseStringList();
}
    else if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        return;
    }

    // add follow case

}
// ruleList	->	rule ruleList | lambda
void Parser::parseRuleList() {
    if(tokens.at(index)->getType() == TokenType::QUERIES){
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        parseRuleList(); /// checks Rulelist one more time
        return;
    }
    parseRule();
    parseRuleList();

}
// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
void Parser::parseRule() {
    bodyPredicates.clear();
    Predicate headPredicate = Predicate(tokens.at(index)->getDescription()); /// create head predicate
    parseHeadPredicate();
    headPredicate.setParameters(parameters); /// connect that list of parameters with the head pred
    Rule rulePredicate = Rule(headPredicate); /// rulePredicate defined as private member of Parser class
    rulePredicate.setHeadPredicate(headPredicate);
    MatchTokens(tokens.at(index), TokenType::COLON_DASH);
    // Predicate bodyPredicate = Predicate(tokens.at(index)->getDescription());
    parsePredicate();
    parsePredicateList();
    rulePredicate.setBodyPredicates(bodyPredicates);
    myProgram.addRules(rulePredicate);
    MatchTokens(tokens.at(index), TokenType::PERIOD);
}
// predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
void Parser::parsePredicate() {
    if(tokens.at(index)->getType() == TokenType::EOFile){
        return;
    }
    else if(tokens.at(index)->getType() == TokenType::COMMENT){
        index++;
        parsePredicate(); /// checks Predicate in case comment comes before
        return;
    }
    parameters.clear();
    Predicate frontPredicate = Predicate(tokens.at(index)->getDescription());
    MatchTokens(tokens.at(index), TokenType::ID);
    MatchTokens(tokens.at(index), TokenType::LEFT_PAREN);
    Parameter myParam = Parameter(tokens.at(index)->getDescription()); //// defines parameter object and begins adding parameters to it
    parseParameter();
    parseParameterList();
    MatchTokens(tokens.at(index), TokenType::RIGHT_PAREN);
    frontPredicate.setParameters(parameters);
    if(tokens.at(index)->getType() == TokenType::Q_MARK){
        myProgram.addQueries(frontPredicate);
    }
    bodyPredicates.push_back(frontPredicate); /// if not apart of queries, push onto bodyPred vector


}
// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::parseHeadPredicate() {
    parameters.clear();
    MatchTokens(tokens.at(index), TokenType::ID);
    MatchTokens(tokens.at(index), TokenType::LEFT_PAREN);
    Parameter myParam = Parameter(tokens.at(index)->getDescription());
    parameters.push_back(myParam);
    MatchTokens(tokens.at(index), TokenType::ID);
    parseIDList();
    MatchTokens(tokens.at(index), TokenType::RIGHT_PAREN);


}

// parameter	->	STRING | ID
void Parser::parseParameter(){              ////// REMEMBER TO IMPLEMENT OR STATEMENT
    if(tokens.at(index)->getType() == TokenType::STRING){
        Parameter myParam = Parameter(tokens.at(index)->getDescription());
        parameters.push_back(myParam);
        MatchTokens(tokens.at(index), TokenType::STRING);
    }
    else if(tokens.at(index)->getType() == TokenType::ID) {
        Parameter myParam = Parameter(tokens.at(index)->getDescription());
        parameters.push_back(myParam);
        MatchTokens(tokens.at(index), TokenType::ID);
    }


}
//parameterList	-> 	COMMA parameter parameterList | lambda
void Parser::parseParameterList(){
    if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){
        return;
    }
    MatchTokens(tokens.at(index), TokenType::COMMA);
    parseParameter();
    parseParameterList();               ///// implement OR

}
// predicateList	->	COMMA predicate predicateList | lambda
void Parser::parsePredicateList() {
    if(tokens.at(index)->getType() == TokenType::PERIOD){
        return;
    }
    MatchTokens(tokens.at(index), TokenType::COMMA);
    Predicate frontPredicate = Predicate(tokens.at(index)->getDescription());
    // bodyPredicates.push_back(frontPredicate);  //// BUG::duplication happens here
    parsePredicate();
    parsePredicateList(); ///////// implement OR

}
// query	        ->      predicate Q_MARK
void Parser::parseQuery() {
    parsePredicate();
    MatchTokens(tokens.at(index), TokenType::Q_MARK);
}
// queryList	->	query queryList | lambda
void Parser::parseQueryList() {
    if(tokens.at(index)->getType() == TokenType::EOFile){
        return;
    }
    parseQuery();
    parseQueryList();
    //// implement OR statement;

}
void Parser::parseDatalogProgram() {

    MatchTokens(tokens.at(index), TokenType::SCHEMES);
    MatchTokens(tokens.at(index), TokenType::COLON);

    parseSchemes();  // from here go to parseSchemes

    parseSchemeList();         // from here got to schemeList


    MatchTokens(tokens.at(index), TokenType::FACTS);
    MatchTokens(tokens.at(index), TokenType::COLON);

    parseFactList();      // from here go to factList

    MatchTokens(tokens.at(index), TokenType::RULES);
    MatchTokens(tokens.at(index), TokenType::COLON);

    parseRuleList();  // from here go to ruleList

    MatchTokens(tokens.at(index), TokenType::QUERIES);
    MatchTokens(tokens.at(index), TokenType::COLON);

    parseQuery(); // go to Query
    parseQueryList();  // go to queryList
    MatchTokens(tokens.at(index), TokenType::EOFile);

            /// end state
}
void Parser::parse() {
    try{

        do {    ///// deals with comments at beginning of program
                index++;
        } while(tokens.at(index)->getType() == TokenType::COMMENT);
        parseDatalogProgram();
   }
    catch (Token error) {
        //std::cout << "Failure!" << std::endl;
        // std::cout << error.toString();
       return;
   }
    // std::cout << "Success!" << std::endl;
    // myProgram.toString();

    ////goes to DatalogProgram class
}
Parser::Parser(std::vector<Token*> tokens) {
    index = 0;
    this->tokens = tokens;
}
DatalogProgram Parser::getDatalog() {
    return myProgram;
}