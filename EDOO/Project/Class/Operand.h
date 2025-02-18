#ifndef _OPERAND_H
#define _OPERAND_H
#include <iostream>
#include <string>
using namespace std;

class Operand {
private:
    string value;
public:
    Operand(string value);
    string get_value();
};

#endif