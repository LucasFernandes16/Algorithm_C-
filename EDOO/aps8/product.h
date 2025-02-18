#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

class Product
{
  private:
    long code;
    string name;

  public:
    Product(long c = 0, string n = "random") : code(c), name(n){}

    virtual ~Product(){}

    void setCode(long bc);
    long getCode();
    virtual void scanner();
    virtual void printer();
};

void Product::setCode(long bc)
{
  code = bc;
}

long Product::getCode()
{
  return code;
}

void Product::scanner()
{
  cout << "Digite o Codigo: ";
  cin >> code;
  cout << "Digite o nome: ";
  cin >> name;
}

void Product::printer()
{
  cout << "O codigo deste produto e: " << code << endl;
  cout << "O nome do produto e: "<< name << endl;
}
#endif