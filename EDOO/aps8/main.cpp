#include <iostream>
#include "product.h"
#include "FreshFood.h"
#include "PrepackedFood.h"
using namespace std;

void record(){
  Product* products[100];
  // count conta a quantidade de produtos enquanto é usado para acha-los na array de pointers
  int count = 0;
  char choice;
  double total = 0.0;
  //alocando dinamicamente os produtos até terminar
  do{
    cout << "Digite 1 para produto fresco e 2 para produto pre-embalado: ";
    cin >> choice;

    if(choice == '1'){
      products[count] = new FreshFood();
    }else if (choice == '2'){
      products[count] = new PrepackedFood();
    }
    count++;
  }while(choice != 'n');
  // agora pegaremos a lista de produtos e daremos seus valores

  for(int i = 0; i < count-1; i++){
    //usando dynamic cast
    if(FreshFood *ff = dynamic_cast<FreshFood*>(products[i])){
      ff->scanner();
      total += ff->getWeight() * ff->getPricePerKilo();
    } else if (PrepackedFood *pf = dynamic_cast<PrepackedFood*>(products[i])){
      pf->scanner();
      total += pf->getUnitPrice();
    }
  }
      cout << "O total a pagar e: " << total << endl;
  
}

int main(){
  record();
  return 0;
}