#ifndef _TOKEN_H
#define _TOKEN_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Token{
  private:
    string type;
    T value;
    int pos;
  public:
    Token(string type, T value, int pos);
    virtual ~Token();
    string get_type();
    T get_value();
    Token next_token(string exp, int pos);
    int get_pos();
};

#endif