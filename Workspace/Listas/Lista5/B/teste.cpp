#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>

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
    Dictionary(int size = 100000) {
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
            if (it.first == k) return; // Evita duplicatas
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
    string english, foreign, word;

    // Leitura do dicionário
    while (true) {
        getline(cin, english, ' ');
        if (english.empty()) break; // Para quando encontra uma linha em branco
        getline(cin, foreign);
        dict.insert(foreign, english);
    }

    // Leitura e tradução da mensagem
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
