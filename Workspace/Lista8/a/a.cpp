#include <bits/stdc++.h>
using namespace std;

int MFKnapsack(int i, int j, int w[], int v[], vector<vector<int>>& F) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (F[i][j] < 0) {
        int value;
        if (j < w[i])
            value = MFKnapsack(i - 1, j, w, v, F);
        else
            value = max(MFKnapsack(i - 1, j, w, v, F), v[i] + MFKnapsack(i - 1, j - w[i], w, v, F));
        F[i][j] = value;
    }
    return F[i][j];
}

int main() {
    int S, N, w1, v1;
    cin >> S >> N;
    int w[N + 1];
    int v[N + 1];
    w[0] = v[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> w1 >> v1;
        w[i] = w1;
        v[i] = v1;
    }

    vector<vector<int>> F(N + 1, vector<int>(S + 1, -1));

    int answer = MFKnapsack(N, S, w, v, F);
    cout << answer << endl;

    return 0;
}
