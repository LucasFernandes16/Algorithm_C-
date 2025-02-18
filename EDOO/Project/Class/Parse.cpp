#include <iostream>
#include <string>
#include "Parser.h"
#include "Expression.h"
#include "Lexer.h"
#include "Token.h"
#include "Operand.h"
#include "BinaryExp.h"
#include "UnaryExp.h"
#include "Literal.h"
using namespace std;

template <typename T>
Parse<T>::Parse(Expression<T>* exp) {
    this->expression = exp;
}

template <typename T>
Expression<T>* Parse<T>::parse_or_exp(Lexer& lexer) {
    Expression<T>* e1 = parse_and_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "OR") {
        Operand* op = new Operand(token.get_value());
        Expression<T>* e2 = parse_and_exp(lexer);
        e1 = new BinaryExp<T>(e1, op, e2);
    }
    return e1;
}

template <typename T>
Expression<T>* Parse<T>::parse_and_exp(Lexer& lexer) {
    Expression<T>* e1 = parse_eq_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "AND") {
        Operand* op = new Operand(token.get_value());
        Expression<T>* e2 = parse_eq_exp(lexer);
        return new BinaryExp<T>(e1, op, e2);
    }
    return e1;
}

template <typename T>
Expression<T>* Parse<T>::parse_eq_exp(Lexer& lexer) {
  Expression* e1 = parse_rel_exp(lexer);
  Token token = lexer.next_token();
  if (token.get_type() == "EQUAL" || token.get_type() == "NEQUAL") {
    Operand* op = new Operand(token.get_value());
    Expression* e2 = parse_rel_exp(lexer);
    e1 = new BinaryExp(e1, op, e2);
  } else {
    return e1;
  }
}
template <typename T>
Expression<T>* Parse<T>::parse_rel_exp(Lexer& lexer) {
  Expression* e1 = parse_add_exp(lexer);
  Token token = lexer.next_token();
  if (token.get_type() == "LESS" || token.get_type() == "GREATER" ||
      token.get_type() == "LESS_EQ" || token.get_type() == "GREATER_EQ") {
    Operand* op = new Operand(token.get_value());
    Expression* e2 = parse_add_exp(lexer);
    e1 = new BinaryExp(e1, op, e2);
  } else {
    return e1;
  }
}
template <typename T>
Expression<T>* Parse<T>::parse_add_exp(Lexer& lexer) {
  Expression* e1 = parse_mul_exp(lexer);
  Token token = lexer.next_token();
  if (token.get_type() == "ADD" || token.get_type() == "SUB") {
    Operand* op = new Operand(token.get_value());
    Expression* e2 = parse_mul_exp(lexer);
    e1 = new BinaryExp(e1, op, e2);
  } else {
    return e1;
  }
}

template <typename T>
Expression<T>* Parse<T>::parse_mul_exp(Lexer& lexer) {
  Expression* e1 = parse_primary_exp(lexer);
  Token token = lexer.next_token();
  if (token.get_type() == "MUL" || token.get_type() == "DIV") {
    Operand* op = new Operand(token.get_value());
    Expression* e2 = parse_primary_exp(lexer);
    e1 = new BinaryExp(e1, op, e2);
  } else {
    return e1;
  }
}

template <typename T>
Expression<T>* Parse<T>::parse_primary_exp(Lexer& lexer) {
    Token<string> token = lexer.next_token();
    if (token.get_type() == "INTEGER") {
        return new Literal<int>(stoi(token.get_value()));
    } else if (token.get_type() == "BOOLEAN") {
        return new Literal<bool>(token.get_value() == "true");
    } else if (token.get_type() == "LPAREN") {
        Expression<T>* exp = parse_or_exp(lexer);
        token = lexer.next_token();
        if (token.get_type() == "RPAREN") {
            return exp;
        }
    }
    return nullptr;
}

// Explicit template instantiation
template class Parse<int>;
template class Parse<bool>;
