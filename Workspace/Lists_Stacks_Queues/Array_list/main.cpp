#include <iostream>
#include "list.h"
#include <string>

using namespace std;

int main(){
  int n_casos, casos, number, count;
  string operacao;
  cin >> n_casos;

  for(int i = 0; i < n_casos; i++) {
    cin >> casos;
    AList<int> list(14);
    cout <<"Caso "<< i+1 << ":"<< endl ;
    for(int j = 0; j < casos; j++) {
      cin >> operacao ;
      int size = number;
      if(operacao == "insert"){
        cin >> number;
        list.insert(number);
      } else if (operacao == "remove"){
        list.remove();
      }else if (operacao == "count"){
        cin >> number;
        cout << list.search(number) << endl;
      } else if (operacao == "prev"){
        list.prev();
      }else{
        list.next();
      }
    }
  }
  return 0;
}