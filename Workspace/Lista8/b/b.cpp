#include <bits/stdc++.h>
using namespace std;

int frog(int N, int K, int index, int h[], vector<int>& F) {
    if (index == N - 1) {
        return 0;
    }
    if (F[index] != -1) {
        return F[index];
    }
    int cost = INT_MAX;
    for (int i = 1; i <= K; i++) {
        if (index + i >= N) {break;}
        cost = min(cost, frog(N, K, index + i, h, F) + abs(h[index + i] - h[index]));
    }
    F[index] = cost;
    return cost;
}

int main() {
    int N, K;
    cin >> N >> K;

    int h[N];
    for (int i = 0; i < N; i++) { 
        cin >> h[i];
    }

    vector<int> F(N, -1); 
    int answer = frog(N, K, 0, h, F); 
    cout << answer << endl;

    return 0;
}
