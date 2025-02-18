#include <iostream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Expression.h"
#include "Literal.h"
#include "BinaryExp.h"
#include "UnaryExp.h"
#include "Operand.h"

using namespace std;

int main() {
    int c;
    cin >> c;
    cin.ignore();  // Limpa o buffer após ler o inteiro

    for (int i = 0; i < c; ++i) {
        string line;
        getline(cin, line);  // Lê a linha de expressão

        try {
            Lexer lexer(line);  // Cria o lexer com a linha de entrada
            IntParser parser;   // Usa o IntParser para expressões inteiras
            Expression<int>* expr = parser.parse_or_exp(lexer);  // Faz o parsing da expressão
            int result = expr->evaluate();  // Avalia a expressão
            cout << result << endl;  // Imprime o resultado
            delete expr;  // Libera a memória da expressão
        } catch (const std::exception& e) {
            cout << "error" << endl;  // Captura exceções e imprime "error"
        }
    }

    return 0;
}