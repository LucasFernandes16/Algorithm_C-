#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool valid(const vector<vector<int>>& m, int l, int i, int n) {
    for (int row = 0; row < l; ++row) {
        if (m[row][i] == 1) return false;
        if (i - (l - row) >= 0 && m[row][i - (l - row)] == 1) return false;
        if (i + (l - row) < n && m[row][i + (l - row)] == 1) return false;
    }
    return true;
}

bool qns(int l, int n, vector<vector<int>>& m) {
    if (l == n) return true;
    for (int i = 0; i < n; ++i) {
        if (valid(m, l, i, n)) {
            m[l][i] = 1;
            if (qns(l + 1, n, m)) return true;
            m[l][i] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    if (qns(0, n, m)) {
        for (const auto& row : m) {
            for (int cell : row) {
                cout << (cell ? "Q" : ".") << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}