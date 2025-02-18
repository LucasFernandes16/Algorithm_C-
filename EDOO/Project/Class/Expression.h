#ifndef _EXPRESSION_H
#define _EXPRESSION_H
#include <iostream>
#include <variant>
using namespace std;

template <typename T>
class Expression {
public:
    virtual ~Expression() = default;
    virtual T evaluate() = 0;
};

#endif