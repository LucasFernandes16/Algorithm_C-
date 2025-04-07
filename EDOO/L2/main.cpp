#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template<typename Key>
int HashFunc(Key k, int m) {
    hash<Key> hasher;
    return hasher(k) % m;
}

template<typename Key, typename E>
class Dictionary {
private:
    int m;
    int cnt;
    vector<list<pair<Key, E>>> H;

public:
    Dictionary(int size = 10) {
        m = size;
        cnt = 0;
        H.resize(m);
    }

    bool find(Key k, E &value) {
        int pos = HashFunc(k, m);
        for (const auto &it : H[pos]) {
            if (it.first == k) {
                value = it.second;
                return true;
            }
        }
        return false;
    }

    void insert(Key k, E element) {
        int pos = HashFunc(k, m);
        for (const auto &it : H[pos]) {
            if (it.first == k) return; 
        }
        H[pos].emplace_back(k, element);
        cnt++;
    }

    void print() {
        for (int i = 0; i < m; i++) {
            cout << i << ": ";
            for (const auto &it : H[i]) {
                cout << "(" << it.first << ", " << it.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary<string, string> dict;
    string line;

    // Leitura do dicionário
    while (getline(cin, line)) {
        if (line.empty()) break; // Para quando encontra uma linha em branco
        stringstream ss(line);
        string english, foreign;
        ss >> english >> foreign;
        dict.insert(foreign, english);
    }

    // Leitura e tradução da mensagem
    string word;
    while (cin >> word) {
        string translation;
        if (dict.find(word, translation)) {
            cout << translation << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}