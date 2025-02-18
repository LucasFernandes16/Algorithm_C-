#ifndef _BINARYEXP_H
#define _BINARYEXP_H
#include <iostream>
#include <string>
#include "Expression.h"
#include "Operand.h"
using namespace std;

template <typename T>
class BinaryExp : public Expression<T> {
private:
    Expression<T>* left;
    Expression<T>* right;
    Operand* op;
public:
    BinaryExp(Expression<T>* left, Operand* op, Expression<T>* right);
    virtual ~BinaryExp();
    T evaluate() override;
};

#endif