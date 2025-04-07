#include<iostream>
#include<math.h>
#include<string>
#include<vector>

using namespace std;

class Entry{
  public:
    int key;
    int element;
};

class Dictionary{
  private:
    int m;
    int cnt;
    Entry* H;
    vector<int> Perm;

    int hashF(int key, int mod){
         int temp = (int) floor((((double) key) / ((double) mod))); return (key - (mod * temp));
         return temp;
    }

    void create_dict(int size, vector<int> perm){
      m = size;
      cnt = 0;
      H = new Entry[size];
      Perm = perm;
    }

    void clear(){
      delete[] H;
      m = 0;
      cnt = 0;
    }
  public:
    Dictionary(int m, vector<int> perm){
      create_dict(m, perm);
      }
    ~Dictionary(){clear();}

    int find(int k){
      int pos = k;
      int newPos;
      int i = 0;
      if(H[pos].key != k){
        do{
            i = i+1;
            int offset = Perm[i-1];
            newPos = (pos+offset)%m;
          }while(not(H[newPos].key == k or i > cnt));
        pos = newPos;
      }
      if(i >= cnt ){
        return 0;
      }else{
        return H[pos].key;
      }
    }

    int index(int K){
      int pos = hashF(K, m);
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

    void insert(int k, int e){  
      if(find(k) == 0 ){
        int newPos;
        int pos = k % m;
        int p = H[pos].key;
        if (H[pos].key != 0){
          int i= 0;
          do{
            i = i+1;
            int offset = Perm[i-1];
            newPos = (pos+offset)%m;
          }while(not(H[newPos].element == 0));
          pos = newPos;
        }
        Entry new_entry = {k, e};
        H[pos] = new_entry ;
        cnt++;
      }
    }

    void ffind(int k){
      if (find(k) == 0){
        cout << index(k) << find(k);
      }
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
  int n,a,op,key,element;
  string input;
  cin >> n;
  vector<int> per_list;
//  template<typename Key, typename E>;

  for (int i = 0; i < n-1; i++){
    cin >> a;
    per_list.push_back(a);
  }

  Dictionary lucas(n, per_list);
  cin >> op;
  for(int j = 0; j < op; j++){
    cin >> input >> key >> element ;
    if (input == "add"){
      lucas.insert(key, element);
      lucas.print();
    }else{
      lucas.ffind(key);
      lucas.print();
    }
  }
  


  return 0;
}