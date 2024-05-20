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
          if(curr->next = NULL){
            return NULL;
          }
          E it = curr->next->element;
          if(tail == curr->next){
            tail = curr;
          }
          curr->next = curr->next->next;
          cnt--;
          return it;
        }

        E count(E it){
          Node<E>* temp_node = new Node<E>;
          temp_node = curr;
          curr = head;
          int count = 0;
          for(int i = 0; i<cnt;i++){
            if(curr->next->element == it){
              count++;
            }
            curr = curr->next;
          }
          curr = temp_node;
          return count;
        }
};

int main(){
  int n_casos, casos, number, count;
  string operacao;
  cin >> n_casos;

  for(int i = 0; i < n_casos; i++) {
    cin >> casos;
    LList<int> list;
    cout <<"Caso "<< i+1 << ":"<< endl ;
    for(int j = 0; j < casos; j++) {
      cin >> operacao ;
      int size = number;
      if(operacao == "insert"){
        cin >> number;
        list.insert(number);
      } else if (operacao == "remove"){
        list.remove();
      }else if (operacao == "count"){
        cin >> number;
        cout << list.count(number) << endl;
      } else if (operacao == "prev"){
        list.prev();
      }else{
        list.next();
      }
    }
    list.clear();
  }
  return 0;
}