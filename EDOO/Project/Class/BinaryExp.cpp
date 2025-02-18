#include <iostream>
#include <string>
#include "BinaryExp.h"
#include "Expression.h"
#include <stdexcept>
using namespace std;

template <typename T>
BinaryExp<T>::BinaryExp(Expression<T>* left, Operand* op, Expression<T>* right)
    : left(left), op(op), right(right) {}

template <typename T>
BinaryExp<T>::~BinaryExp() {
    delete left;
    delete right;
    delete op;
}

template <typename T>
T BinaryExp<T>::evaluate() {
    T leftVal = left->evaluate();
    T rightVal = right->evaluate();

    if (op->get_value() == "+") {
        return leftVal + rightVal;
    } else if (op->get_value() == "-") {
        return leftVal - rightVal;
    } else if (op->get_value() == "*") {
        return leftVal * rightVal;
    } else if (op->get_value() == "/") {
        if (rightVal == 0) {
            throw std::runtime_error("Division by zero");
        }
        return leftVal / rightVal;
    } else if (op->get_value() == "&&") {
        return leftVal && rightVal;
    } else if (op->get_value() == "||") {
        return leftVal || rightVal;
    } else if (op->get_value() == "==") {
        return leftVal == rightVal;
    } else if (op->get_value() == "!=") {
        return leftVal != rightVal;
    } else if (op->get_value() == "<") {
        return leftVal < rightVal;
    } else if (op->get_value() == ">") {
        return leftVal > rightVal;
    } else if (op->get_value() == "<=") {
        return leftVal <= rightVal;
    } else if (op->get_value() == ">=") {
        return leftVal >= rightVal;
    }
    throw std::runtime_error("Unknown operator");
}

// Explicit template instantiation
template class BinaryExp<int>;
template class BinaryExp<bool>;