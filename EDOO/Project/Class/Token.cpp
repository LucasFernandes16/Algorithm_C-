#include <iostream>
#include "Token.h"
using namespace std;
#include <string>

template <typename T>
Token<T>::Token(string type, T value, int pos){
  this->type = type;
  this->value = value;
  this->pos = pos;
}

template <typename T>
Token<T>::~Token(){}

template <typename T>
string Token<T>::get_type(){
  return this->type;
}

template <typename T>
T Token<T>::get_value(){
  return this->value;
}

template <typename T>
int Token<T>::get_pos() {
    return pos;
}

template class Token<int>;
template class Token<bool>;
template class Token<string>;