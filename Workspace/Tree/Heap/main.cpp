#include <iostream>
#include <string>

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
                int j = 2 * k; // posição do primeiro filho
                if (j < n && H[j] < H[j + 1]) { // max heap
                    j = j + 1; // encontra o maior filho
                }
                if (v >= H[j]) { // maxheap
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
    Heap(int arr[], int c) {
        create(c, arr);
        HeapBottomUp();
    }

    ~Heap() {
        delete[] H;
    }

    void printh() {
        for (int i = 1; i <= n; i++) {
            cout << H[i] << " ";
        }
        cout << endl;
    }

    void printsort(int arr[]) {
        for (int i = 1; i <= maxsize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void add(int E) {
        int v = E;
        int k = n + 1;
        bool heap = false;

        while (!heap && k > 1) {
            int j = k / 2;
            if (H[j] > v) { // maxheap
                H[k] = H[j];
            } else {
                H[k] = v;
                heap = true;
            }
            k = j;
        }
        if (!heap) {
            H[k] = v;
        }
        n++;
    }

    void heapsort() {
        int temp[maxsize + 1];
        int original_n = n;
        int i = 1;

        while (n >= 1) {
            temp[i] = H[1];
            H[1] = H[n];
            n--;
            HeapBottomUp();
            i++;
        }

        n = original_n;
        for (int i = 1; i <= original_n; i++) {
            H[i] = temp[i];
        }

        printsort(temp);
    }
};

int main() {
    int arr[12];
    int c, n;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> n;
        arr[i] = n;
    }

    Heap heap(arr, c);
    heap.printh();
    cout << endl;
    heap.heapsort();
    return 0;
}
