#include <iostream>
#include <string>
#include <utility>

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
    ~Queue(){
      clear_queue();
      delete front;
    }

    void enqueue(E it, string side){
      rear->next = create_node(it,side,NULL);
      rear = rear->next;
      size++;
    }

    pair<E, string> dequeue(){
      if(size == 0){
        throw std::runtime_error("The queue is empty"); // Lança uma exceção se a fila estiver vazia
      }
      Node<E>* temp = front->next;
      E element = temp->element;
      string side = temp->side;
      front->next = temp->next;
      if(front->next == NULL){
        rear = front;
      }
      size--;
      delete temp;
      return make_pair(element, side); // Retorna um par (element, side)
    }

    bool is_empty() const {
      return size == 0;
    }

    int carsize(){
      return front->element;
    }
    string car_arrive(){
      return front->side;
    }
};


void solve(Queue<int>& ferry, string ferryside,int count,int l){
  int capacity = 0;
  while (!ferry.is_empty())
  {
    if(ferryside == ferry.car_arrive()){
      while (capacity <= l && ferry.car_arrive() == ferryside)
      {
        auto car = ferry.dequeue();
        capacity += car.first;
      }
      count ++;
      capacity = 0;
      ferryside = (ferryside == "left") ? "right" : "left"; // Alterna o lado da balsa
    }else{
      while (capacity <= l && ferry.car_arrive() == ferryside)
      {
        capacity += ferry.carsize();
        cout << ferry.dequeue().first << " "<<ferry.dequeue().second << endl;
      }
      count++;
      ferryside = (ferryside == "left") ? "right" : "left"; // Alterna o lado da balsa
    }
  }
  cout << count;
}

int main(){
    int count = 0;
    string ferryside = "left";
    int c, l, m, boat_size;
    string side;

    cin >> c;
    for(int i = 0; i < c ; i++){
      cin >> l >> m;
      Queue<int> ferry;
      for(int j = 0 ; j < m; j++){
          cin >> boat_size >> side;
          ferry.enqueue((boat_size/100), side);
          cout << j << endl;
      }
      solve(ferry,ferryside,count,l);
      cout << i << "solved" << endl;
    }
    cout << "end";
    return 0;
}
