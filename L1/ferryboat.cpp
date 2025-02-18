#include <iostream>
#include <string>

using namespace std;

template<class E>
class Node{
  public:
    E element;
    string side;
    Node<E>* next;
};

template<class E>
class Queue{
  private:
    Node<E>* front;
    Node<E>* rear;
    int size;

    Node<E>* create_node(E it, string s, Node<E>* next_value){
      Node<E>* temp = new Node<E>;
      temp->element = it;
      temp->side = s;
      temp->next = next_value;
      return temp;
    }

    Node<E>* create_head(Node<E>* next_value){
      Node<E>* temp = new Node<E>;
      temp->next = next_value;
      return temp;
    }

    void create_queue(){
      front = rear = create_head(NULL);
      size = 0;
    }
    
    void clear_queue(){
      while(front->next != NULL){
        Node<E>* temp = front->next;
        front->next = front->next->next;
        delete temp;
      }
      size = 0;
    }

  public:
    Queue(){create_queue();}
    ~Queue(){clear_queue(); delete front; }

    void enqueue(E it, string side){
      rear->next = create_node(it,side , NULL);
      rear = rear->next;
      size++;
      cout << rear->element << rear->side;
    }

    void dequeue(){
      if(size == 0){
        cout << "The queue is empty";
      }
      Node<E>* temp = front->next;
      E it = front->next->element;
      string side = front->next->side;
      front->next = front->next->next;
      if(front->next == NULL){
        rear = front;
      }
      size--;
      delete temp;
    }

};

void solve(Queue<int>, bool leftside){
    
}

int main(){

    int count = 0;
    bool leftside = true;
    int c,l,m,boat_size;
    string side;

    cin >> c;
    for(int i = 0; i < c ; i++){
        cin >> l >> m;
        Queue<int> ferry;
        for(int j = 0 ; j < c; j++){
            cin >> boat_size >> side;
            ferry.enqueue(boat_size,side);
        }
        solve(ferry,leftside);
    }

        
    return 0;
}