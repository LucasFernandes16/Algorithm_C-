#ifndef _PARSER_H
#define _PARSER_H
#include <iostream>
#include <string>
#include "Expression.h"
#include "Lexer.h"
using namespace std;

class Parser {
public:
    virtual ~Parser() {}
    virtual Expression<int>* parse_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_or_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_and_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_eq_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_rel_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_add_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_mul_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_unary_exp(Lexer& exp) = 0;
    virtual Expression<int>* parse_primary_exp(Lexer& exp) = 0;
};

class IntParser : public Parser {
public:
    Expression<int>* parse_exp(Lexer& exp) override;
    Expression<int>* parse_or_exp(Lexer& exp) override;
    Expression<int>* parse_and_exp(Lexer& exp) override;
    Expression<int>* parse_eq_exp(Lexer& exp) override;
    Expression<int>* parse_rel_exp(Lexer& exp) override;
    Expression<int>* parse_add_exp(Lexer& exp) override;
    Expression<int>* parse_mul_exp(Lexer& exp) override;
    Expression<int>* parse_unary_exp(Lexer& exp) override;
    Expression<int>* parse_primary_exp(Lexer& exp) override;
};

class BoolParser : public Parser {
public:
    Expression<bool>* parse_exp(Lexer& exp) override;
    Expression<bool>* parse_or_exp(Lexer& exp) override;
    Expression<bool>* parse_and_exp(Lexer& exp) override;
    Expression<bool>* parse_eq_exp(Lexer& exp) override;
    Expression<bool>* parse_rel_exp(Lexer& exp) override;
    Expression<bool>* parse_add_exp(Lexer& exp) override;
    Expression<bool>* parse_mul_exp(Lexer& exp) override;
    Expression<bool>* parse_unary_exp(Lexer& exp) override;
    Expression<bool>* parse_primary_exp(Lexer& exp) override;
};


#endif