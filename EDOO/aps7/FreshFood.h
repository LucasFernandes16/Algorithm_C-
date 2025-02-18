#ifndef _FREESHFOOD_H
#define _FREESHFOOD_H

#include "product.h"

class FreshFood: public Product{

  private:
    float weight;
    float priceperkilo;

  public:
    FreshFood(long c = 0, string n = "random", float w = 0, float p = 0): Product(c,n), weight(w), priceperkilo(p){}
    void getWeight();
    void getPricePerKilo();
    void scanner();
    void printer();
};

void FreshFood::getWeight()
{
  cout << weight << endl;
}

void FreshFood::getPricePerKilo()
{
  cout << priceperkilo << endl;
}

void FreshFood::scanner()
{
  Product::scanner();
  cout << "Digite o peso: ";
  cin >> weight;
  cout << "Digite o preco por kilo: ";
  cin >> priceperkilo;
}

void FreshFood::printer()
{
  Product::printer();
  cout << "O peso deste produto e: " << weight;
  cout << "O preco por kilo deste produto e: " << priceperkilo << endl;
}

#endif
