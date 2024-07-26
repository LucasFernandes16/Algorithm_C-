//monitoria
#include <bits/stdc++.h>
using namespace std;

int dp_fibonacci(int n){
  vector<int> dp(n+1,0);
  dp[1] = 1;
  for(int i = 2; i <= n; n++){

  }
}

int coinRowProblem(vector<int>& C) {
    int n = C.size();
    if (n == 0) return 0;
    if (n == 1) return C[0];
    vector<int> F(n+1);
    F[0] = 0;
    F[1] = C[0];
    for (int i = 2; i <= n; ++i) {
        F[i] = max(C[i-1] + F[i-2], F[i-1]);
    }
    return F[n];
}
int main() {
    vector<int> C = {5, 1, 2, 10, 6, 2}; // Exemplo de valores das moedas
    cout << "Valor máximo que pode ser obtido: " << coinRowProblem(C) << endl;
    return 0;
}

//bottom up: resolve todos os subproblemas para construir a resposta final
//top down: resolve apenas os necessários para a solução final
//knapsack