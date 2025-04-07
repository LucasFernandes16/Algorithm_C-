#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

template<typename Key, typename E>
class Entry{
  public:
    Key k;
    E element;
};

template<typename Key, typename E>
class Dictionary{
  private:
    int m;
    int cnt;
    Entry<Key,E>* H;
    Entry<Key, E> deleted = {0, "deleted"};
    vector<int> Perm;

    int hashF(string k){
      int s = k.length();
      int sum = 0;
      for(int i = 0; i < s; i++){
        int s = k[i];
        sum = sum + k[i];
      }
      return abs(sum);
    }

    int fold(string k){
      int s = k.length();
      int sum = 0;
      for(int i = 0; i < s; i++){
        sum = sum + k[i];
      }
      return sum % m;
    }

    vector<int> create_perm(int m){
      vector<int> p;
      for(int i = 1; i < m ;i++){
        p.push_back(i);
      }
      random_device rd; 
      mt19937 g(rd());
      shuffle(p.begin(), p.end(), g); 
      return p;
    }   

    void create_dict(int size){
      m = size;
      cnt = 0;
      H = new Entry<Key,E>[size];
      Perm = create_perm(m);
    }
    void clear(){
      delete[] H;
      m = 0;
      cnt = 0;
    }
  public:
    Dictionary(){create_dict(10);}
    ~Dictionary(){clear();}

    int find(const string& K) {
      int pos = fold(K);
      int start = pos;
      
      while (H[pos].element != "" && H[pos].element != K) {
          pos = (pos + 1) % m; // Sondagem linear
          if (pos == start) return -1; // Se voltou ao início, elemento não encontrado
      }
      
      return (H[pos].element == K) ? pos : -1;
  }

    int index(string K){
      int pos = fold(K);
      int newPos;
      int i = 0;
      if(H[pos].element != K){
        do{
            i = i+1;
            int offset = Perm[i-1];
            newPos = (pos+offset)%m;
          }while(not(H[newPos].element == K or i > cnt));
        pos = newPos;
      }
      if(i >= cnt ){
        return -1;
      }else{
        return pos;
      }
    }

    void insert(const E& e) {
      if (cnt >= m) return; // Evita inserção em tabela cheia
      
      Key k = hashF(e);
      if (find(e) != -1) return; // Já existe na tabela, não insere novamente
      
      int pos = fold(e);
      
      while (H[pos].element != "" && H[pos].element != "deleted") {
          pos = (pos + 1) % m; // Sondagem linear
      }

      H[pos] = {k, e};
      cnt++;
  }

  E remove(const E& e) {
    int pos = find(e);
    if (pos == -1) return ""; // Elemento não encontrado

    E temp = H[pos].element;
    H[pos] = deleted; // Marca como "deleted"
    cnt--;
    return temp;
}

    void print(){
            for(int i=0; i < m; i++){
                cout  << i << " ";
                cout << (H[i]).element << " ";
                cout << endl;
           }
        }
};

int main(){
  Dictionary<int,string> lucas;
  int c;
  string op,str;
  cin >> c;
  for(int i = 0; i < c; i++){
    cin >> op >> str;
    if(op =="add"){
      lucas.insert(str);
    }else if(op == "sch"){
      int t = lucas.find(str); 
      if(t == -1){
        cout << str << " " << t << endl;
      }else{
        cout << str << " " << t << endl;
      }
    }else{
      lucas.remove(str);
    }
  }
  return 0;
}