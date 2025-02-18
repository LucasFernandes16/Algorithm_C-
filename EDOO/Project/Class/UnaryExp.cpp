#include <iostream>
#include <string>
#include "Expression.h"
#include "UnaryExp.h"
using namespace std;

template <typename T>
UnaryExp<T>::UnaryExp(Expression<T>* exp, Operand* op) : exp(exp), op(op) {}

template <typename T>
UnaryExp<T>::~UnaryExp() {
    delete exp;
    delete op;
}

template <typename T>
T UnaryExp<T>::evaluate() {
    if (op->get_value() == "-") {
        return -exp->evaluate();
    }
    return exp->evaluate();
}

// Explicit template instantiation
template class UnaryExp<int>;
template class UnaryExp<bool>;