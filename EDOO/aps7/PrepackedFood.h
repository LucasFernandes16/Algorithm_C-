#ifndef _PREPACKEDFOOD_H
#define _PREPACKEDFOOD_H

#include "product.h"

class PrepackedFood: public Product{
  private:
   float unitprice;
  public:
    PrepackedFood(long c = 0, string n = "random", long u = 0): Product(c,n) ,unitprice(u){}
    void getUnitPrice();
    void scanner();
    void printer();
};

  void PrepackedFood:: getUnitPrice()
  {
    cout << unitprice << endl;
  }

  void PrepackedFood::scanner()
  {
    Product::scanner();
    cout << "Digite o preco unitario: ";
    cin >> unitprice;
  }
  void PrepackedFood::printer()
  {
    Product::printer();
    cout << "O preco unitario deste produto e: " << unitprice << endl;
  }

#endif