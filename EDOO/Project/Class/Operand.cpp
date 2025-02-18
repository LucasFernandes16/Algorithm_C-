#include <iostream>
#include <string>
#include "Operand.h"
#include "Expression.h"
using namespace std;

// Construtor da classe Operand
Operand::Operand(string value) : value(value) {}


// Método para obter o valor do operando
string Operand::get_value() {
    return value;
}

