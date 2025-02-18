#ifndef _PREPACKEDFOOD_H
#define _PREPACKEDFOOD_H

#include "product.h"

class PrepackedFood: public Product{
  private:
   double unitprice;
  public:
    PrepackedFood(long c = 0, string n = "random", long u = 0): Product(c,n) ,unitprice(u){}
    double getUnitPrice();
    void scanner() override;
    void printer() override;
};

  double PrepackedFood:: getUnitPrice()
  {
    return unitprice;
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