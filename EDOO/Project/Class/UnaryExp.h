#ifndef _UNARYEXP_H_
#define _UNARYEXP_H_
#include <iostream>
#include <string>
#include "Expression.h"
#include "Operand.h"
using namespace std;

template <typename T>
class UnaryExp : public Expression<T> {
private:
    Expression<T>* exp;
    Operand* op;
public:
    UnaryExp(Expression<T>* exp, Operand* op);
    virtual ~UnaryExp();
    T evaluate() override;
};

#endif