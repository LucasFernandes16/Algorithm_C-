#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>

using namespace std;

template<typename Key>
int HashFunc(Key k, int m) {
    return k % m; 
}

template<typename Key, typename E>
class Dictionary {
private:
    int m;
    int cnt;
    vector<list<pair<Key, E>>> H;

    int HashFunc(Key k) { return k % m; } 

public:
    Dictionary(int size = 10) {
        m = size;
        cnt = 0;
        H.resize(m);
    }

    bool find(Key k, E &value) {
        int pos = HashFunc(k);
        for (const auto &it : H[pos]) {
            if (it.first == k) {
                value = it.second;
                return true;
            }
        }
        return false;
    }

    void insert(Key k, E element) {
        int pos = HashFunc(k);
        for (const auto &it : H[pos]) {
            if (it.first == k) return;
        }
        H[pos].emplace_back(k, element);
        cnt++;
    }

    void deletion(Key k) {
        int pos = HashFunc(k);
        for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
            if (it->first == k) {  
                H[pos].erase(it);
                cnt--;
                break;
            }
        }
    }

    void print() {
        cout << "alpha = " << cnt <<"/10" << endl; 
        for (int i = 0; i < m; i++) {
            cout << i << ":";
            bool first = true;
            for (const auto &it : H[i]) {
                if (!first) cout << ",";
                cout << "(" << it.first << "," << it.second << ")";
                first = false;
            }
            cout << endl;
        }
    }
};

int main() {
    int c, n;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        cin >> n;
        Dictionary<int, string> dict;
        cout << "caso " << i << ":" << endl; 

        for (int j = 0; j < n; j++) {
            string op;
            int key;
            string value;

            cin >> op >> key;
            if (op == "add") {
                cin >> value;
                dict.insert(key, value);
            } else if (op == "del") {
                dict.deletion(key);
            }
        }
        dict.print();
    }

    return 0;
}
