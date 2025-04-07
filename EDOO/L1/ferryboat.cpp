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

void solve(Queue<pair<int, string>>& left_queue, Queue<pair<int, string>>& right_queue, int l) {
    int count = 0;
    string ferryside = "left"; // A balsa começa no lado esquerdo
    int capacity = 0;

    while (!left_queue.is_empty() || !right_queue.is_empty()) {
        if (ferryside == "left") {
            capacity = 0;
            while (!left_queue.is_empty() && capacity + left_queue.carsize() <= l) {
                auto car = left_queue.dequeue();
                capacity += car.first;
            }
            count++;
            ferryside = "right"; // Alterna para o lado direito
        } else {
            capacity = 0;
            while (!right_queue.is_empty() && capacity + right_queue.carsize() <= l) {
                auto car = right_queue.dequeue();
                capacity += car.first;
            }
            count++;
            ferryside = "left"; // Alterna para o lado esquerdo
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
        Queue<pair<int, string>> left_queue, right_queue;
        for (int j = 0; j < m; j++) {
            cin >> boat_size >> side;
            if (side == "left") {
                left_queue.enqueue(make_pair(boat_size, side));
            } else {
                right_queue.enqueue(make_pair(boat_size, side));
            }
        }
        solve(left_queue, right_queue, l * 100); // Converte o tamanho da balsa para centímetros
    }
    return 0;
}