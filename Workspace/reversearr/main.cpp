#include <iostream>
using namespace std;

void reverse_array(int* arr, int size) {
  int* start = arr;
  int* end = arr + size -1;

  while(start < end){
    int temp;
    temp = *start;
    *start = *end;
    *end = temp;

    *start++;
    *end--;
  }
}

int main(){

  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  reverse_array(arr, size);
  for(auto s : arr){
    cout << s<< " ";
  }
  return 0;
}
