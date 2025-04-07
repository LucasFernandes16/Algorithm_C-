#include <iostream>

using namespace std;

class Heap {
private:
    int* H;
    int n;
    int maxsize;

    void create(int size, int array[]) {
        maxsize = size;
        n = size;
        H = new int[maxsize + 1];
        for (int i = 1; i <= n; i++) {
            H[i] = array[i];
        }
    }

    void HeapBottomUp() {
        for (int i = n / 2; i >= 1; i--) {
            int k = i;
            int v = H[k];
            bool heap = false;
            while (!heap && (2 * k) <= n) {
                int j = 2 * k;
                if (j < n && H[j] > H[j + 1]) {
                    j = j + 1;
                }
                if (v <= H[j]) {
                    heap = true;
                } else {
                    H[k] = H[j];
                    k = j;
                }
            }
            H[k] = v;
        }
    }

    void Heapify(int i) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && H[left] < H[smallest])
            smallest = left;
        
        if (right <= n && H[right] < H[smallest])
            smallest = right;
        
        if (smallest != i) {
            int temp = H[i];
            H[i] = H[smallest];
            H[smallest] = temp;
            Heapify(smallest);
        }
    }

public:
    Heap(int arr[], int c) {
        create(c, arr);
        HeapBottomUp();
    }

    ~Heap() {
        delete[] H;
    }
    
    void add(int E) {
        int k = ++ n;
        while (k > 1 && H[k / 2] > E) {
            H[k] = H[k / 2];
            k = k/2;
        }
        H[k] = E;
    }

    int pop() {
        int min = H[1];
        H[1] = H[n];
        n--;
        Heapify(1);
        return min;
    }

    void cost(){
      int a,b;
      long long int sum = 0;

      while(n > 1){
          a = pop();
          b = pop();
          add(a+b);
          sum += (a+b);
        }
      cout << sum << endl;
    }
};

int main(){
  int n,c;
  int* arr;
  bool op = true;
  while(op != false){
    cin >> n;
    if(n != 0){
      arr = new int[n+1];
      for(int i = 1; i <= n; i++){
        cin >> c;
        arr[i] = c;
      }
      Heap heap(arr,n);
      heap.cost();
    }else{op = false;}
  }
  return 0;
}