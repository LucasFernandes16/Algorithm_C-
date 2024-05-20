#include <iostream>
#include <string>

using namespace std;

template<class E>
class Node{
  public:
    E element;
    Node<E>* next;
};

template<class E>
class LList{
  private:
      Node<E>* head;
      Node<E>* tail;
      Node<E>* curr;
      int cnt;

      void create_list(){
          curr = tail = head = create_head(NULL);
          cnt = 0;
      }
      void removeall(){
          while(head != NULL){
              curr = head;
              head = head->next;
              delete curr;    
          }
      }
      Node<E>* create_node(E it, Node<E>* nextval){

          Node<E>* temp_node = new Node<E>;
          temp_node->element = it;
          temp_node->next = nextval;
          return temp_node;
      }

      Node<E>* create_head(Node<E>* nextval){    
          Node<E>* temp_node = new Node<E>;
          temp_node->next = nextval;
          return temp_node;
      }

  public:
      
      LList(){
          create_list();
      }
      ~LList(){
          removeall();
      }
      void clear(){
          removeall();
          create_list();
      }

      void insert(E it){
          curr->next = create_node(it, curr->next);
          if (tail == curr){
            tail = curr->next;
          }
          cnt++;
      }


      void moveToStart(){
        curr = head;
      }
      void moveToEnd(){
        curr = tail;
      }
      void prev(){
        if(curr == head){
          return; 
        }
        Node<E>* temp_node = new Node<E>;
        temp_node = head;
        do{
          temp_node = temp_node->next;
        }while(temp_node != curr);
        curr = temp_node;
      }

      void next(){
        if(curr != tail){
          curr = curr->next;
        }
      }

      E remove(){
        if(curr->next == NULL){
          cout << "error";
        }
        E it = curr->next->element;
        if(tail == curr->next){
          tail = curr;
        }
        curr->next = curr->next->next;
        cnt--;
        return it;
      }
      E get_curr(){
        return curr->element;
      }
      int listsize(){
        return cnt;
      }
};
int main(){
  bool enter = false;
  string frase;
  LList<char> texto;
  while(cin>>frase){
    texto.clear();
    for(int i = 0; i<frase.size(); i++){
      if(frase[i] == '['){
        texto.moveToStart();
        enter = true;
      }else if(frase[i] == ']'){
        texto.moveToEnd();
        enter = false;
      }else if(enter == true){
        texto.insert(frase[i]);
        texto.next();
      }else{
        texto.insert(frase[i]);
        texto.next();
      }
    }
    texto.moveToStart();
    for(int i = 0; i< texto.listsize();i++){
      texto.next();
      cout << texto.get_curr();
    }
    cout << '\n';
  };
  
  return 0;
}