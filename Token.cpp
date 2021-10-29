#include "Token.h"
#include <sstream>
#include <iostream>
#include <string>

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->type = type;
    this->description = description;
    this->line = line;
}
std::string Token::getDescription() {
    return description;
}
TokenType Token::getType() {
    return type;
}
std::string Token::ConvertTokens(TokenType type) {
    switch(type){
        case TokenType::COMMA:
            return "COMMA";
        case TokenType::PERIOD:
            return "PERIOD";
        case TokenType::Q_MARK:
            return "Q_MARK";
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
        case TokenType::COLON:
            return "COLON";
        case TokenType::COLON_DASH:
            return "COLON_DASH";
        case TokenType::MULTIPLY:
            return "MULTIPLY";
        case TokenType::ADD:
            return "ADD";
        case TokenType::SCHEMES:
            return "SCHEMES";
        case TokenType::FACTS:
            return "FACTS";
        case TokenType::RULES:
            return "RULES";
        case TokenType::QUERIES:
            return "QUERIES";
        case TokenType::ID:
            return "ID";
        case TokenType::STRING:
            return "STRING";
//        case TokenType::LINE_COMMENT:
//           return "LINE_COMMENT";
        case TokenType::COMMENT:
            return "COMMENT";
        case TokenType::EOFile:
            return "EOF";
        case TokenType::UNDEFINED:
            return "UNDEFINED";
        default: return "NULL";
    }
}
int Token::getLine() {
    return line;
}
std::string Token::toString() {
    std::ostringstream myString;
    myString << "(" << ConvertTokens(getType()) << ",\"" << getDescription() << "\"," << getLine() << ")\n";
    std::string test = myString.str();
    return myString.str();
}
