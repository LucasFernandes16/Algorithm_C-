#ifndef _LIST_H
#define _LIST_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

template <class E>
class AList{
  private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

  public:

    AList(int size) {
      maxSize = size;
      listSize = curr = 0;
      listArray = new E[maxSize];
    }
    
    ~AList(){delete[] listArray;}
    // insert 9
    // 5 6 8| 7 4 1 _ _
    void insert(const E& it){
      for(E i = listSize; i > curr; i--){
        listArray[i] = listArray[i-1];
      }
      listArray[curr] = it;
      listSize++;
    }

    int remove(){
      E it = listArray[curr];
      E i = curr;
      do{
        listArray[i] = listArray[i+1];
        i++;
      }while(i<listSize-1);
      listSize--;
      return it;
    }

    void movetostart(){
      curr = 0;
    }

    void movetoend(){
      curr = listSize;
    }

    void prev(){
      if (curr!=0){
        curr--;
      }
    }

    void next(){
      if (curr < listSize){
        curr++;
      }
    }
    void movetoPos(int pos){
      curr = pos;
    }
    const E getelement(){
      return listArray[curr];
    }

    int actualpos(){
      return listArray[curr];
    }
    int search(const E& number){
      int count = 0;
      int currpo = curr;
        for(int i = 0; i <= listSize-1;i++){
          curr = i;
          if (listArray[curr]== number){
            count++;
          }
        }
      curr = currpo;
      return count;
    }
};
#endif