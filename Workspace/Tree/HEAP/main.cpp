#include <iostream>
#include <vector>
#include<string>

using namespace std;


class Heap{
  private:
    int *H;
    int n;
    int maxsize;

    void create(int size,int array[]){
      maxsize = size;
      n = size;
      H = array;
    }

    void HeapBottomUp(int* H) {
      for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int v = H[k];
        bool heap = false;
        while (!heap && (2 * k) <= n) {
          int j = 2 * k; // posição do primeiro filho
          if (j < n && H[j] > H[j + 1]) {// max heap
            j = j + 1; // encontra o maior filho
          }
          if (v <= H[j]) {// maxheap
            heap = true;
          } else {
            H[k] = H[j];
            k = j;
          }
        }
        H[k] = v;
      }
    }

  public:
    Heap(int arr[], int c){
      create(c,arr);
      HeapBottomUp(arr);
    }
    ~Heap(){}

    void printh(){
      for(int i = 1; i <= n; i++){
        cout << H[i] << " ";
      }
    }
    void printsort(int arr[]){
      for(int i = 1; i <= maxsize; i++){
        cout << arr[i] << " ";
      }
    }

    void add(int E){
      int v = E;
      int k = n+1;
      bool heap = false;

      while (heap != true && k >= 1){
        int j = k/2;
        if(H[j] > v){// maxheap
          H[k] = H[j];
        }
        else{
          H[k] = v;
          heap = true;
        }
        k = j;
      }
      n++;
    }
  
  void heapsort(){
    int temp[n+1];
    int i = 1;
    while(n >= 1){
      int v = H[n];
      temp[i] = H[n] = H[1];
      H[1] = v;
      i++;
      n--;
      HeapBottomUp(H);
      printh();
      cout << endl;
    }
    printsort(temp);
  }
  
};

int main(){
  int arr[12];
  int c,n;
  cin >> c;
  for(int i = 1; i <= c; i++){
    cin >> n;
    arr[i] = n;
  }

  Heap lucas(arr,c);
  lucas.printh();
  cout << endl;
//  lucas.add(12);
//  lucas.printh();
//  cout << endl;
  lucas.heapsort();
  return 0;
}


