#include "fraction.h"
#include <iostream>

using namespace std;

int main(){
  Fraction f1(3, 4);
  Fraction f2(5, 2);

  Fraction f4;
  cout << "-" << f1 - f2 << endl;
  f1+=f2;
  cout << "+=" << f1;

  return 0;
}