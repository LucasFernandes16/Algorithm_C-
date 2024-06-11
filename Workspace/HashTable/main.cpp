#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename Key>
Key HashFunc(Key k){

    int pos = k % 10;
    return pos;
}

template<typename Key, typename E>
struct node
{
    Key key;
    E element;
};

template<typename Key, typename E>
class Dictionary{
    private:
        int m;
        int cnt;
        list<node<Key,E>>* H;

        int HashFunc(Key k){

            int pos = k % 10;
            return pos;
        }

        E find(Key k){
            int pos = HashFunc(k);
            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if(it->key == k){
                    E el = it->element;
                    return el;
                    break;
                }
            }
            return NULL;
        }

    public:
        void create_dict(int size){
            cnt = 0;
            m = 10;
            H = new list<node<Key,E>>[size];
        } 
        Dictionary(){create_dict(10);} 

        void insert(Key k, E element){
            int pos = HashFunc(k);
            if (find(k) != false){
                node<Key, E> new_node = {k, element};
                H[pos].push_back(new_node);
            }else{
                node<Key, E> new_node = {k, element};
                H[pos].push_back(new_node);
            }
        }

        void print(){
            for(int i=0; i < m; i++){
                cout  << i << " ";
                for (auto it = H[i].begin(); it != H[i].end(); ++it) {
                        std::cout << it->element << " ";
                    }
                cout << endl;
           }
        }   

        void deletion(Key k){
            int pos = HashFunc(k);
            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if(it->key == k){
                    node<Key,E> temp = {it->key, it->element};
                    H[pos].remove(temp);
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