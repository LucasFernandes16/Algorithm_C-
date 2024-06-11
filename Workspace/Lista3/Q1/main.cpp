#include <iostream>
#include <vector>
#include <string>

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
    Entry<Key, E> deleted = {0, "apagado"};

    int hashK(string k){
      int s = k.length();
      int sum = 0;  
      for(int i = 0; i < s; i++){
        sum = sum + k[i]*(i+1);
      }
      sum = 19*sum;
      return sum;
    }

    int hashF(string k){
      return hashK(k)%101;
    }

    void create_dict(int size){
      m = size;
      cnt = 0;
      H = new Entry<Key,E>[size];
    }
    void clear(){
      for (int i = 0; i < m; ++i) {
        if (H[i].element != "") {
          H[i].element = "";
        }
      }
    }
  public:
    Dictionary(){create_dict(101);}
    ~Dictionary(){clear();}

    E find(string K){
      int pos = hashF(K);
      int newPos;
      int i = 0;
      if(H[pos].element != K){
        do{
            i = i+1;
            int offset = (hashF(K)+(i*i)+23*i)%101;
            newPos = offset;
          }while(not(H[newPos].element == K or i == 20));
        pos = newPos;
      }
      if(i == 20 ){
        return "-1";
      }else{
        return H[pos].element;
      }
    }

    int index(string K){
      int pos = hashF(K);
      int newPos;
      int i = 0;
      if(H[pos].element != K){
        do{
            i = i+1;
            int offset = (hashF(K)+(i*i)+23*i)%101;
            newPos = offset;
          }while(not(H[newPos].element == K or i == 20));
        pos = newPos;
      }
      if(i == 20){
        return -1;
      }else{
        return pos;
      }
    }

    void insert(E e){
      int pos = hashF(e);
      Key k = hashK(e);
      if(find(e) == "-1" ){
        int newPos;
        int i= 0;
        if (H[pos].element != ""  and H[pos].element != "apagado"){
          do{
            i = i+1;
            int offset = (hashF(e)+(i*i)+23*i)%101;
            newPos = offset;
          }while(not(H[newPos].element == "" or H[newPos].element == "apagado" or i == 20));
          pos = newPos;
        }
      if(i != 20){
        Entry<Key, E> new_entry = {k, e};
        H[pos] = new_entry ;
        cnt++;
      }
      }
    }

    E remove(E e){
      Key k = hashF(e);
      if(find(e) != "-1"){
        int pos = index(e);
        Entry<Key, E> temp = H[pos];
        Entry<Key, E> deleted = {0, "apagado"};
        H[pos] = deleted;
        cnt--;
        return temp.element;
      }
      return "";
     }

    int size(){
      return cnt;
    } 

    void print(){
      for(int i=0; i < m; i++){
        auto e = (H[i]).element;
        if((H[i]).element != "" and (H[i]).element != "apagado")
          cout << i << ':' << (H[i]).element << endl;
      }
    }
};

int solve(Dictionary<int,string> lucas){
  string op, key; 
  int n;
  cin >> n;
  cin.get();
  for (int i = 0; i < n; i++) {
      getline(cin, op, ':');
      getline(cin, key, '\n');
      if (op == "ADD") {
          lucas.insert(key);
      } else
      if (op == "DEL") {
          lucas.remove(key);
      }        
  }
  cout << lucas.size() << endl;
  lucas.print();
  return 0;
}

int main(){
  
  int c;
  cin >> c;
  for(int i = 0; i < c; i++){
    Dictionary<int,string> lucas;
    solve(lucas);
  }
  return 0;
}