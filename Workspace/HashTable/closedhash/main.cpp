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
      for(int i = 0; i < s-1; i++){
        sum = sum + k[i];
      }
      return abs(sum);
    }

    int fold(string k){
      int s = k.length();
      int sum = 0;
      for(int i = 0; i < s-1; i++){
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

    E find(string K){
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
        return "-1";
      }else{
        return H[pos].element;
      }
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

    void insert(E e){
      Key k = hashF(e);
      if(find(e) == "-1" ){
        int newPos;
        int pos = fold(e);
        if (H[pos].element != ""  and H[pos].element != "deleted"){
          int i= 0;
          do{
            i = i+1;
            int offset = Perm[i-1];
            newPos = (pos+offset)%m;
          }while(not(H[newPos].element == "" or H[newPos].element == "deleted"));
          pos = newPos;
        }
        Entry<Key, E> new_entry = {k, e};
        H[pos] = new_entry ;
        cnt++;
      }
    }

    E remove(E e){
      Key k = hashF(e);
      if(find(e) != "-1"){
        int pos = index(e);
        Entry<Key, E> temp = H[pos];
        Entry<Key, E> deleted = {0, "deleted"};
        H[pos] = deleted;
        return temp.element;
        cnt--;
      }
      return "";
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
 
  for(int i = 0; i < 2; i++){
    Dictionary<int,string> lucas;
    lucas.insert("ALGORITHMS");
    lucas.insert("SALGORITHM");
    lucas.insert("MSALGORITH");
    lucas.remove("SALGORITHM");
    lucas.insert("HMSALGORIT");
    lucas.print();
  }
  return 0;
}