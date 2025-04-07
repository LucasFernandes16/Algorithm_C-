#include <iostream>
#include <string>
#include <utility>

using namespace std;

template<class E>
class Node {
  public:
    E element;
    Node<E>* next;
};

template<class E>
class Queue {
  private:
    Node<E>* front;
    Node<E>* rear;
    int size;

    Node<E>* create_node(E it, Node<E>* next_value) {
      Node<E>* temp = new Node<E>;
      temp->element = it;
      temp->next = next_value;
      return temp;
    }

    Node<E>* create_head(Node<E>* next_value) {
      Node<E>* temp = new Node<E>;
      temp->next = next_value;
      return temp;
    }

    void create_queue() {
      front = rear = create_head(NULL);
      size = 0;
    }
    
    void clear_queue() {
      while (front->next != NULL) {
        Node<E>* temp = front->next;
        front->next = front->next->next;
        delete temp;
      }
      size = 0;
    }

  public:
    Queue() { create_queue(); }
    ~Queue() {
      clear_queue();
      delete front;
    }

    void enqueue(E it) {
      rear->next = create_node(it, NULL);
      rear = rear->next;
      size++;
    }

    E dequeue() {
      if (size == 0) {
        throw runtime_error("The queue is empty");
      }
      Node<E>* temp = front->next;
      E element = temp->element;
      front->next = temp->next;
      if (front->next == NULL) {
        rear = front;
      }
      size--;
      delete temp;
      return element; 
    }

    bool is_empty() const {
      return size == 0;
    }

    int carsize() {
        if (!is_empty()) {
            return front->next->element.first;
        } else {
            throw runtime_error("Queue is empty");
        }
    }

    string car_arrive() {
        if (!is_empty()) {
            return front->next->element.second;
        } else {
            throw runtime_error("Queue is empty");
        }
    }
};

void solve(Queue<pair<int, string>>& ferry, string ferryside, int l) {
    int count = 0;
    int capacity = 0;

    while (!ferry.is_empty()) {
        if (ferryside == ferry.car_arrive()) {
            while (!ferry.is_empty() && ferry.car_arrive() == ferryside && capacity + ferry.carsize() <= l) {
                auto car = ferry.dequeue();
                capacity += car.first;
            }
            count++;
            capacity = 0;
            ferryside = (ferryside == "left") ? "right" : "left"; // Alterna o lado da balsa
        } else {
            count++;
            ferryside = (ferryside == "left") ? "right" : "left"; // Alterna o lado da balsa
        }
    }
    cout << count << endl;
}

int main() {
    int c, l, m;
    int boat_size;
    string side;

    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> l >> m;
        Queue<pair<int, string>> ferry;
        for (int j = 0; j < m; j++) {
            cin >> boat_size >> side;
            ferry.enqueue(make_pair(boat_size, side));
        }
        solve(ferry, "left", l * 100);
    }
    return 0;
}