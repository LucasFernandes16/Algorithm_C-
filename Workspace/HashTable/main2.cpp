#include <iostream>
#include <utility>
#include <list>
#include <string>

using namespace std;

template<typename Key>
Key HashFunc(Key k){
    int pos = k % 10;
    return pos;
}


template<typename Key, typename E>
class Dictionary{
    private:
        int m;
        int cnt;
        list<pair<Key,E>>* H;

        int HashFunc(Key k){
            int pos = k % 10;
            return pos;
        }

        E find(Key k){
            int pos = HashFunc(k);
            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if(it->first == k){
                    return it->first;
                    break;
                }
            }
            return NULL;
        }

    public:
        void create_dict(int size){
            cnt = 0;
            m = 10;
            H = new list<pair<Key,E>>[size];
        } 
        Dictionary(){create_dict(10);} 

        void insert(Key k, E element){
            int pos = HashFunc(k);
            if (find(k) != false){
                pair<Key, E> temp;
                temp = make_pair(k, element);
                H[pos].push_back(temp);
            }else{
                pair<Key, E> temp;
                temp = make_pair(k, element);
                H[pos].push_back(temp);
            }
        }

        void print(){
            for(int i=0; i < m; i++){
                cout  << i << " ";
                for (auto it = H[i].begin(); it != H[i].end(); ++it) {
                        std::cout << it->second << " ";
                    }
                cout << endl;
           }
        }   

        void deletion(Key k){
            int pos = HashFunc(k);
            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if(it->second == k){
                    pair<Key,E> temp;
                    temp = make_pair(it->first, it->second);
                    cout << temp.second << endl;
                    H[pos].remove(temp);
                    break;
                }
            }
        }
};


int main(){
    Dictionary<int, int> lucas;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int number, key;
        cin >> number;
        key = HashFunc(number);
        lucas.insert(key, number);
    }
    lucas.print();
    lucas.deletion(12);
    lucas.print();

    return 0;
}