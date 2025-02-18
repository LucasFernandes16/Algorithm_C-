#include "Lexer.h"
#include <cctype>

Lexer::Lexer(string input) : input(input), pos(0) {
    currentChar = input[pos];
}

void Lexer::advance() {
    pos++;
    if (pos < input.size()) {
        currentChar = input[pos];
    } else {
        currentChar = '\0';
    }
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && isspace(currentChar)) {
        advance();
    }
}

Token<int> Lexer::integer() {
    string result;
    while (currentChar != '\0' && isdigit(currentChar)) {
        result += currentChar;
        advance();
    }
    return Token<int>("INTEGER", stoi(result), pos);
}

Token<bool> Lexer::boolean() {
    if (input.substr(pos, 4) == "true") {
        pos += 4;
        currentChar = input[pos];
        return Token<bool>("BOOLEAN", true, pos);
    } else if (input.substr(pos, 5) == "false") {
        pos += 5;
        currentChar = input[pos];
        return Token<bool>("BOOLEAN", false, pos);
    }
    return Token<bool>("ERROR", false, pos);
}

Token<string> Lexer::next_token() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            skipWhitespace();
            continue;
        }

        if (isdigit(currentChar)) {
            Token<int> intToken = integer();
            return Token<string>(intToken.get_type(), to_string(intToken.get_value()), intToken.get_pos());
        }

        if (isalpha(currentChar)) {
            Token<bool> boolToken = boolean();
            return Token<string>(boolToken.get_type(), boolToken.get_value() ? "true" : "false", boolToken.get_pos());
        }

        switch (currentChar) {
            case '+':
                advance();
                return Token<string>("PLUS", "+", pos);
            case '-':
                advance();
                return Token<string>("MINUS", "-", pos);
            case '*':
                advance();
                return Token<string>("MULTIPLY", "*", pos);
            case '/':
                advance();
                return Token<string>("DIVIDE", "/", pos);
            case '(':
                advance();
                return Token<string>("LPAREN", "(", pos);
            case ')':
                advance();
                return Token<string>("RPAREN", ")", pos);
            case '|':
                if (pos + 1 < input.size() && input[pos + 1] == '|') {
                    advance();
                    advance();
                    return Token<string>("OR", "||", pos);
                }
                break;
            case '&':
                if (pos + 1 < input.size() && input[pos + 1] == '&') {
                    advance();
                    advance();
                    return Token<string>("AND", "&&", pos);
                }
                break;
            case '=':
                if (pos + 1 < input.size() && input[pos + 1] == '=') {
                    advance();
                    advance();
                    return Token<string>("EQUAL", "==", pos);
                }
                break;
            case '!':
                if (pos + 1 < input.size() && input[pos + 1] == '=') {
                    advance();
                    advance();
                    return Token<string>("NOT_EQUAL", "!=", pos);
                }
                break;
            case '<':
                advance();
                return Token<string>("LESS", "<", pos);
            case '>':
                advance();
                return Token<string>("GREATER", ">", pos);
            default:
                advance();
                return Token<string>("ERROR", string(1, currentChar), pos);
        }
    }
    return Token<string>("END", "", pos);
}