#include <iostream>
#include <vector>
using namespace std;

// Função para criar heap de baixo para cima
void HeapBottomUp(vector<int>& H) {
    int n = H.size() - 1;
    for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int v = H[k];
        bool heap = false;
        
        while (!heap && (2 * k) <= n) {
            int j = 2 * k; // posição do primeiro filho
            
            if (j < n && H[j] < H[j + 1]) {
                j = j + 1; // encontra o maior filho
            }
            
            if (v >= H[j]) {
                heap = true;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        
        H[k] = v;
    }
}

int main() {
    vector<int> H = {0, 4, 7, 8, 3, 2, 6, 5}; // o índice 0 é ignorado para utilização intuitiva com o índice começando de 1
    HeapBottomUp(H);
    
    // Imprime o heap resultante
    for (int i = 1; i < H.size(); ++i) {
        cout << H[i] << " ";
    }
    
    return 0;
}
