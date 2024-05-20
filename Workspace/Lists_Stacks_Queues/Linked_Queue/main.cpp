#include <iostream>

using namespace std;

template<class E>
class Node{
  public:
    E element;
    Node<E>* next;
};

template<class E>
class Queue{
  private:
    Node<E>* front;
    Node<E>* rear;
    int size;

    Node<E>* create_node(E it, Node<E>* next_value){
      Node<E>* temp = new Node<E>;
      temp->element = it;
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

    void enqueue(E it){
      rear->next = create_node(it, NULL);
      rear = rear->next;
      size++;
    }

    E dequeue(){
      if(size == 0){
        cout << "The queue is empty";
      }
      Node<E>* temp = front->next;
      E it = front->next->element;
      front->next = front->next->next;
      if(front->next == NULL){
        rear = front;
      }
      size--;
      delete temp;
      return it;
    }

};

int main(){
  for(int i = 0; i<=1; i++){
    Queue<int> lucas;

    lucas.enqueue(4);
    lucas.enqueue(7);
    lucas.enqueue(12);
    lucas.dequeue();
    lucas.enqueue(98);
  }
  return 0;
}