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
class LQueue{
    private:
        Node<E>* front;
        Node<E>* rear;
        int sz;

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
           sz = 0;
        }

        void clear_queue(){
            while(front->next != NULL){
                Node<E>* temp = new Node<E>;
                temp = front->next;
                front->next = front->next->next;
                delete temp;    
            }
        }

    public:
        LQueue(){
           create_queue();
        }
        ~LQueue(){
            clear_queue();
        }
        void clear(){
            clear_queue();
            create_queue();
        }

        void enqueue(E it){
            rear->next = create_node(it, NULL);
            rear = rear->next;
            sz++;
        }

        E dequeue(){
            if(sz == 0){
                cout << "er";
            }
            Node<E>* temp = new Node<E>;
            temp = front->next;
            E it = front->next->element;
            front->next = front->next->next;
            if(front->next == NULL){
                rear = front;
            }
            sz--;
            delete temp;
            return it;
        }

        void print(){
            Node<E>* temp = new Node<E>;
            temp = front->next;
            int cont = 0;
            while(temp != NULL){
                cont ++;
                cout << temp->element; 
                if (cont != sz){cout << " ";}
                temp = temp->next;
            }
        }

        E length(){
            return sz;
        }
};

int main(){
    string status;
    long long int id;
    int solved = 0;
    LQueue<long long int> banco;
    int cont = 0;
    do{
        cin >> status;
        cont ++;
        if(status == "add"){
            cin >> id;
            banco.enqueue(id);
        }else if(status == "solve"){
            banco.dequeue();
            solved ++;
        }else if(status == "print"){
            banco.print();
            cout << endl;
        }else if(status == "stats"){
            cout << solved;
            if(cont != 0){cout << " ";}
            cout<< banco.length();
            cout << endl;
        }
    }while(status !="end");

    return 0;
}