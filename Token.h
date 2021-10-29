#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    // LINE_COMMENT,
    COMMENT, //// block and line comment
    EOFile,
    UNDEFINED,

};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);

    std::string ConvertTokens(TokenType type);
    std::string getDescription();
    TokenType getType();
    int getLine();
    std::string toString();
    // TODO: add other needed methods
};

#endif // TOKEN_H



