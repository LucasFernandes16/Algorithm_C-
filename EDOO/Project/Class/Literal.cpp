#include <iostream>
#include "Literal.h"
#include "Expression.h"
#include <string>
using namespace std;

template <typename T>
Literal<T>::Literal(T value) : value(value) {}

template <typename T>
T Literal<T>::evaluate() {
    return value;
}

// Explicit template instantiation
template class Literal<int>;
template class Literal<bool>;
