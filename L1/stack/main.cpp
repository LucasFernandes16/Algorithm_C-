#include <iostream>
#include <string>

using namespace std;

template<class E>
class Node {
  public:
    E element;
    Node<E>* next;
};

template<class E>
class Stack {
  private:
    Node<E>* top;
    int size;

    Node<E>* create_node(E it, Node<E>* next_val) {
      Node<E>* temp_node = new Node<E>;
      temp_node->element = it;
      temp_node->next = next_val;
      return temp_node;
    }

    void create_stack() {
      top = NULL;
      size = 0;
    }

    void clear() {
      while (top != NULL) {
        Node<E>* node_temp = top;
        top = top->next;
        delete node_temp;
      }
      size = 0;
    }

  public:
    Stack() {
      create_stack();
    }
    ~Stack() {
      clear();
    }

    void push(E it) {
      top = create_node(it, top);
      size++;
    }

    E pop() {
      if (top == NULL) {
        throw runtime_error("Stack is empty");
      }
      E it = top->element;
      Node<E>* temp = top;
      top = top->next;
      delete temp;
      size--;
      return it;
    }

    bool is_empty() {
      return top == NULL;
    }

    E top_element() {
      if (top == NULL) {
        throw runtime_error("Stack is empty");
      }
      return top->element;
    }
};

bool is_correct(const string& str) {
  Stack<char> stack;
  for (char ch : str) {
    if (ch == '(' || ch == '[') {
      stack.push(ch);
    } else if (ch == ')' || ch == ']') {
      if (stack.is_empty()) {
        return false;
      }
      char top = stack.pop();
      if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
        return false;
      }
    } else {
      // Caracteres inválidos
      return false;
    }
  }
  return stack.is_empty();
}

int main() {
  int c;
  cin >> c;
  cin.ignore();
  string str;
  for (int i = 0; i < c; i++) {
    getline(cin, str);
    if (str.empty() || is_correct(str)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}