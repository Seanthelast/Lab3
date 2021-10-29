#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();
    int lineNumber;
    int maxRead;
    Automaton* maxAutomaton;
    int inputRead;
    Token* newToken;


    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    std::vector<Token*> getTokenList ();
    void Print(std::vector<Token*> tokens);
    
    // TODO: add other public methods here

};

#endif // LEXER_H

