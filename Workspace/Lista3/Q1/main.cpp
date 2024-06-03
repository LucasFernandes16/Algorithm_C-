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
    Entry<Key, E> deleted = {0, "deleted"};

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
      delete[] H;
      m = 0;
      cnt = 0;
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
      int pos = hashF(K);
      int newPos;
      int i = 0;
      if(H[pos].element != K){
        do{
            i = i+1;
            int offset = (hashF(K)+(i*i)+23*i)%101;
            newPos = offset;
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
      int pos = hashF(e);
      Key k = hashK(e);
      if(find(e) == "-1" ){
        int newPos;
        if (H[pos].element != ""  and H[pos].element != "deleted"){
          int i= 0;
          do{
            i = i+1;
            int offset = (hashF(e)+(i*i)+23*i)%101;
            newPos = offset;
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
  Dictionary<int,string> lucas;
  lucas.insert("marsz");
  lucas.insert("Dabrowski");
  lucas.insert("z");
  lucas.insert("ziemii");
  lucas.insert("Polski");
  lucas.insert("Polski");
  lucas.insert("wloskiej");
  lucas.insert("do");
  lucas.print();
  return 0;
}