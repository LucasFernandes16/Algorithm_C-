#ifndef _LITERAL_H
#define _LITERAL_H
#include <iostream>
#include "Expression.h"
using namespace std;

template <typename T>
class Literal : public Expression<T> {
private:
    T value;
public:
    Literal(T value);
    T evaluate() override;
};

#endif