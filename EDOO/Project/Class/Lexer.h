#ifndef _LEXER_H
#define _LEXER_H
#include <iostream>
#include <string>
#include "Token.h"
using namespace std;

class Lexer {
private:
    string input;
    int pos;
    char currentChar;
    void advance();
    void skipWhitespace();
    Token<int> integer();
    Token<bool> boolean();
public:
    Lexer(string input);
    Token<string> next_token();
};

#endif
