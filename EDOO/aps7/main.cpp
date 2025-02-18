#include <iostream>
#include "product.h"
#include "FreshFood.h"
#include "PrepackedFood.h"
using namespace std;

int main(){
  Product product(1, "banana");
  FreshFood fresh(23, "banana", 2.3, 3.4);
  fresh.printer();
  fresh.scanner();
  fresh.printer();

  cout << "-------------------------------------" << endl;

  PrepackedFood prepacked(69, "sarro", 2.4);
  prepacked.printer();
  prepacked.scanner();
  prepacked.printer();


  return 0;
}