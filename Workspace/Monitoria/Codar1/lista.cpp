#include <iostream>
#include <string>

using namespace std;

template<class E>
class Node {
public:
    E element;
    Node<E>* next;
    Node() : next(nullptr) {}
    Node(E e, Node<E>* n = nullptr) : element(e), next(n) {}
};

template<class E>
class LList {
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int cnt;

    void create_list() {
        head = new Node<E>(); // Dummy head node
        tail = curr = head;
        cnt = 0;
    }

    void removeall() {
        Node<E>* temp = head;
        while (temp != nullptr) {
            Node<E>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = curr = nullptr;
        cnt = 0;
    }

    Node<E>* create_node(E it, Node<E>* nextval) {
        return new Node<E>(it, nextval);
    }

public:
    LList() {
        create_list();
    }

    ~LList() {
        removeall();
    }

    void clear() {
        removeall();
        create_list();
    }

    void insert(E it) {
        curr->next = create_node(it, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        cnt++;
    }

    void moveToStart() {
        curr = head;
    }

    void moveToEnd() {
        curr = tail;
    }

    void prev() {
        if (curr == head) return;
        Node<E>* temp = head;
        while (temp != nullptr && temp->next != curr) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            curr = temp;
        }
    }

    void next() {
        if (curr != tail && curr != nullptr) {
            curr = curr->next;
        }
    }

    E remove() {
        if (curr == nullptr || curr->next == nullptr) {
            throw std::runtime_error("Cannot remove: no next element");
        }
        Node<E>* temp = curr->next;
        E it = temp->element;
        curr->next = temp->next;
        if (tail == temp) {
            tail = curr;
        }
        delete temp;
        cnt--;
        return it;
    }

    int count() const {
        return cnt;
    }

    void insert_on_start(int value) {
      moveToStart();
      insert(value);
  }
  
  void insert_on_end(int value) {
      moveToEnd();
      insert(value);
  }
  
/*  void remove_from_start(LList<int>& list) {
      this->moveToStart();
      try {
          this.remove();
      } catch (const std::runtime_error& e) {
          cout << e.what() << endl;
      }
  }
  
  void remove_from_end() {
      this->moveToEnd();
      this->prev();
      try {
          this->remove();
      } catch (const std::runtime_error& e) {
          cout << e.what() << endl;
      }
  }
  
  void print_list(LList<int>& list) {
      Node<int>* curr = this->head->next; // Skip dummy head
      while (curr != nullptr) {
          cout << curr->element << " ";
          curr = curr->next;
      }
      cout << endl;
  }
  
  void invert_list(LList<int>& list) {
      LList<int> temp_list;
      this->moveToStart();
      while (list.count() > 0) {
          try {
              temp_list.insert_on_start(temp_list, this->remove_from_end());
          } catch (const std::runtime_error& e) {
              cout << e.what() << endl;
              break;
          }
          list.next();
      }
      list.clear();
      list.moveToStart();
      Node<int>* curr = temp_list.head->next;
      while (curr != nullptr) {
          list.insert(curr->element);
          curr = curr->next;
      }
  }*/
};



int main() {
    LList<int> list;
    list.insert_on_start(10);
    list.insert_on_start(20);
    list.insert_on_end(30);
    list.insert_on_end(40);
    return 0;
}