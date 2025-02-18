#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* splice(int a1[],int size1, int a2[],int size2, int pos);
int j3 = 0;

int main(){
  int size1,size2,pos;
  cout << "Digite o tamanho da primeira array: "<< endl;
  cin >> size1;
  cout << "Digite o da Segunda: "<< endl;
  cin >> size2;
  cin >> pos;

  int* a1 = new int[size1];
  int* a2 = new int[size2];

  srand( (unsigned)time(NULL));

  for(int i = 0; i < size1; i++){
    a1[i] = (rand()%30);
  }
   for(int j = 0; j < size2; j++){
    a2[j] = -(rand()%30);
  }
  cout<< "array1:";
  for(int i = 0; i < size1;++i){
    cout << a1[i] << " ";
  }
  cout << endl;
  cout<< "array2:";
  for(int i = 0; i < size2; ++i){
    cout << a2[i] << " ";
  }
  cout<< endl;

  auto a3 = splice(a1,size1,a2,size2,pos);
  
  for(int i = 0; i < size1 + size2;++i){
    cout << a3[i] << " ";
  }
  cout << endl;
  return 0;
}

int* splice(int v1[],int size1, int v2[],int size2, int pos){
  int i = 0, i1 = 0, i2 = 0;
  int *v = new int[size1+size2];
  for( i = 0, i1 = 0; i1 < pos; ++i, ++i1){
    v[i] = v1[i1];
  }
  for( i2 = 0; i2 < size2; ++i, ++i2){ 
    v[i] = v2[i2];
  }
  for( ; i1 < size1; ++i, ++i1){ 
    v[i] = v1[i1];
  }
  return v;
}