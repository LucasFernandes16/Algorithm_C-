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
class Stack{  
  private:
    Node<E>* top;
    int size;

    Node<E>* create_node(E it, Node<E>* next_val){
      Node<E>* temp_node = new Node<E>;
      temp_node->element = it;
      temp_node->next = next_val;
      return temp_node;
    }

    void create_stack(){
      top = NULL;
      size = 0;
    }

    void clear(){
      while(top != NULL){
        Node<E>* node_temp = top;
        top = top->next;
        delete node_temp;
      }
      size = 0;
    }

  public:
    Stack(){
      create_stack();
    }
    ~Stack(){
      clear();
    }

    void push(E it){
      top = create_node(it, top);
      size++;
    }

    E pop(){
      if (top == NULL){
        cout << "list is empty";
      } 
      E it = top->element;
      top = top->next;
      size--;
      return it;
    }
};

int main(){
  Stack<int> lucas;
  lucas.push(5);
  lucas.push(4);
  lucas.push(3);
  lucas.pop();

  return 0;
}