#include "Parser.h"
#include "Token.h"
#include "Operand.h"
#include "BinaryExp.h"
#include "UnaryExp.h"
#include "Literal.h"

Expression<bool>* BoolParser::parse_exp(Lexer& lexer) {
    return parse_or_exp(lexer);
}

Expression<bool>* BoolParser::parse_or_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_and_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "OR") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_and_exp(lexer);
        e1 = new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_and_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_eq_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "AND") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_eq_exp(lexer);
        return new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_eq_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_rel_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "EQUAL" || token.get_type() == "NOT_EQUAL") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_rel_exp(lexer);
        e1 = new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_rel_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_add_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "LESS" || token.get_type() == "GREATER") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_add_exp(lexer);
        e1 = new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_add_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_mul_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "PLUS" || token.get_type() == "MINUS") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_mul_exp(lexer);
        e1 = new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_mul_exp(Lexer& lexer) {
    Expression<bool>* e1 = parse_primary_exp(lexer);
    Token<string> token = lexer.next_token();
    if (token.get_type() == "MULTIPLY" || token.get_type() == "DIVIDE") {
        Operand* op = new Operand(token.get_value());
        Expression<bool>* e2 = parse_primary_exp(lexer);
        e1 = new BinaryExp<bool>(e1, op, e2);
    }
    return e1;
}

Expression<bool>* BoolParser::parse_primary_exp(Lexer& lexer) {
    Token<string> token = lexer.next_token();
    if (token.get_type() == "BOOLEAN") {
        return new Literal<bool>(token.get_value() == "true");
    } else if (token.get_type() == "LPAREN") {
        Expression<bool>* exp = parse_or_exp(lexer);
        token = lexer.next_token();
        if (token.get_type() == "RPAREN") {
            return exp;
        }
    }
    return nullptr;
}