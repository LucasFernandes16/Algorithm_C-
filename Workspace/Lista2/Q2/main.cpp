#include <iostream>

using namespace std;

template<class E>
class Node{
  public:
    E element;
    E element2;
    Node<E>* next;
};

template<class E>
class Queue{
  private:
    Node<E>* front;
    Node<E>* rear;
    int size;

    Node<E>* create_node(E it, E it2, Node<E>* next_value){
      Node<E>* temp = new Node<E>;
      temp->element = it;
      temp->element2 = it2;
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
    void clear_queue1(){
      while(front->next != NULL){
        Node<E>* temp = new Node<E>;
        temp = front->next;
        front->next = front->next->next;
        delete temp;
      }
    }
    
  public:
    
    Queue(){create_queue();};

    void clear_queue(){
      while(front->next != NULL){
        Node<E>* temp = new Node<E>;
        temp = front->next;
        front->next = front->next->next;
        delete temp;
      }
    }
    
    void enqueue(E it, E it2){
      rear->next = create_node(it, it2, NULL);
      rear = rear->next;
      size++;
    }

    E dequeue(){
      if(size == 0){
        cout << "Empty";
      }
      Node<E>* temp = new Node<E>;
      temp = front;
      E it = front->next->element;
      front->next = front->next->next;
      if(front->next == NULL){
        rear = front;
      }
      size--;
      return it;
    }
    E chegada(){
      return front->next->element;
    }
    E limite(){
      return front->next->element2;
    }
    int length(){
      return size;
    }

    E chegada2(){
      return front->next->next->element;
    }
    E limite2(){
      return front->next->next->element2;
    }

};

int tempo_espera(Queue<int> fila, int saida){
  if(fila.limite2() <= saida){
    return 0;
  }else if(fila.chegada2() > saida){
    return fila.chegada2();
  }else{
    int saida2 = saida+1;
    return saida2;
  }
}

int main(){
  int t = 1, n_students, l, r, saida;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n_students;
    Queue<int> fila;
    for(int j = 0; j < n_students; j++){
      cin >> l >> r;
      fila.enqueue(l, r);
      if(fila.length() == 1){
        cout << fila.chegada();
        saida = fila.chegada();
        cout << endl;
      }else if(j == 0){
        cout << fila.chegada() << " ";
        cout << endl;
        saida = fila.chegada();
      }else if(tempo_espera(fila, saida)!=0){
        saida = tempo_espera(fila, saida);
        cout << saida << " ";
        cout << endl;
        fila.dequeue();
      }else{
        cout << 0 << " ";;
        cout << endl;
        fila.dequeue();
      }
    }
    
    fila.clear_queue(); 
  }
  return 0;
}