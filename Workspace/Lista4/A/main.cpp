#include <iostream>
<<<<<<< Updated upstream
#include <algorithm>

using namespace std;

template <typename Key, typename E>
class BSTNODE {
public:
    int size;
=======
#include <string>

using namespace std;

template <typename Key,typename E>
class BSTNODE{
  public:
>>>>>>> Stashed changes
    int height;
    Key key;
    BSTNODE* left;
    BSTNODE* right;
    E element;
<<<<<<< Updated upstream
};

template <typename Key, typename E>
class BST {
private:
    BSTNODE<Key, E>* root;
    int nodecount;

    void create_bst() {
        root = NULL;
        nodecount = 0;
    }

    void clear_bst(BSTNODE<Key, E>* rt) {
        if (rt != NULL) {
            clear_bst(rt->left);
            clear_bst(rt->right);
            delete rt;
        }
        nodecount = 0;
    }

    BSTNODE<Key, E>* create_bstnode(Key k, E e) {
        BSTNODE<Key, E>* temp = new BSTNODE<Key, E>;
        temp->key = k;
        temp->element = e;
        temp->left = temp->right = NULL;
        temp->height = 0;
        temp->size = 1;
        return temp;
    }

    int h(BSTNODE<Key, E>* rt) {
        if (rt == NULL) { return -1; }
        return rt->height;
    }

    int getBalance(BSTNODE<Key, E>* rt) {
        if (rt == NULL) { return 0; }
        return h(rt->left) - h(rt->right);
    }

    void updatesize(BSTNODE<Key, E>* rt) {
        if (rt != NULL) {
            int left_size = (rt->left != NULL) ? rt->left->size : 0;
            int right_size = (rt->right != NULL) ? rt->right->size : 0;
            rt->size = left_size + right_size + 1;
        }
    }

    BSTNODE<Key, E>* inserthelp(BSTNODE<Key, E>* rt, Key k, E e) {
        if (rt == NULL) { return create_bstnode(k, e); }
        if (k < rt->key) {
            rt->left = inserthelp(rt->left, k, e);
        }
        else {
            rt->right = inserthelp(rt->right, k, e);
        }

        rt->height = 1 + max(h(rt->left), h(rt->right));
        updatesize(rt);

        int balance = getBalance(rt);

        if (balance > 1 && k < rt->left->key) { return rightRotate(rt); }
        if (balance < -1 && k > rt->right->key) { return leftRotate(rt); }
        if (balance > 1 && k > rt->left->key) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && k < rt->right->key) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    BSTNODE<Key, E>* rightRotate(BSTNODE<Key, E>* y) {
        BSTNODE<Key, E>* x = y->left;
        BSTNODE<Key, E>* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;
        updatesize(y);
        updatesize(x);
        return x;
    }

    BSTNODE<Key, E>* leftRotate(BSTNODE<Key, E>* x) {
        BSTNODE<Key, E>* y = x->right;
        BSTNODE<Key, E>* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(h(x->left), h(x->right)) + 1;
        y->height = max(h(y->left), h(y->right)) + 1;
        updatesize(x);
        updatesize(y);
        return y;
    }

    int rank(Key k, BSTNODE<Key, E>* rt) {
        if (rt == NULL) return 0;
        if (k < rt->key) {
            return rank(k, rt->left);
        }
        else if (k > rt->key) {
            int left_size = (rt->left != NULL) ? rt->left->size : 0;
            return left_size + 1 + rank(k, rt->right);
        }
        else {
            int left_size = (rt->left != NULL) ? rt->left->size : 0;
            return left_size + 1;
        }
    }

public:
    BST() { create_bst(); }
    ~BST() { clear_bst(root); }

    void insert(Key k, E e) {
        root = inserthelp(root, k, e);
        nodecount++;
    }

    int find(Key k) {
        int r = rank(k, root);
        BSTNODE<Key, E>* temp = root;
        while (temp != NULL) {
            if (k < temp->key) {
                temp = temp->left;
            } else if (k > temp->key) {
                temp = temp->right;
            } else {
                return r;
            }
        }
        return -1;
    }
};

int main() {
    BST<int, int> avl;
    int q, x, op, pos;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> op >> x;
        if (op == 1) {
            avl.insert(x, 0);
        } else {
            pos = avl.find(x);
            if (pos == -1) {
                cout << "Data tidak ada";
            } else {
                cout << pos;
            }
            if (i < q - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}
=======
    
};

template <typename Key,typename E>
class BST{
  private:
    BSTNODE<Key,E>* root;
    int nodecount;
    int cont;
    bool found;

    void create_bst(){
      root = NULL;
      nodecount = 0;
    }
    void clear_bst(BSTNODE<Key,E>* rt){
      nodecount = 0;
    }

    BSTNODE<Key,E>* create_bstnode(Key k, E e){
      BSTNODE<Key,E>* temp = new BSTNODE<Key,E>;
      temp->key = k;
      temp->element = e;
      temp->left = temp->right = NULL;
      temp->height = 0;
      return temp;
    }

    int h(BSTNODE<Key,E>* rt){
      if(rt == NULL){return -1;}
      return rt->height;
    }

    int getBalance(BSTNODE<Key,E>* rt){
      if(rt == NULL){return 0;}
      return h(rt->left) - h(rt->right);
    }

    BSTNODE<Key,E>* inserthelp(BSTNODE<Key,E>* rt, Key k, E e){
      if(rt == NULL){return create_bstnode(k,e);}
      if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
      }
      else{
        rt->right = inserthelp(rt->right, k ,e);
      }
      rt->height = 1 + max(h(rt->left),h(rt->right));
      int balance = getBalance(rt);
      if(balance < -1 && k >= rt->right->key){return leftRotate(rt);}
      if(balance > 1 && k < rt->left->key){return rightRotate(rt);}
      if (balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
      }
      if(balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
      }
      return rt;
    }
    
    BSTNODE<Key,E>* rightRotate(BSTNODE<Key,E>* rt){
      BSTNODE<Key,E>* l = new BSTNODE<Key,E>;
      BSTNODE<Key,E>* lr = new BSTNODE<Key,E>;
      l = rt->left;
      lr = l->right;
      l->right = rt;
      rt->left = lr;
      rt->height = max(h(rt->left),h(rt->right)) + 1;
      l->height = max(h(l->left),h(l->right)) + 1;
      return l;
    }

    BSTNODE<Key,E>* leftRotate(BSTNODE<Key,E>* rt){
      BSTNODE<Key,E>* r = new BSTNODE<Key,E>;
      BSTNODE<Key,E>* rl = new BSTNODE<Key,E>;
      r = rt->right;
      rl = r->left;
      r->left = rt;
      rt->right = rl;
      rt->height = max(h(rt->left),h(rt->right)) + 1;
      r->height = max(h(r->left),h(r->right)) + 1;
      return r;
    }

  Key inorder(BSTNODE<Key,E>* rt, Key k){
    if(rt != NULL && found != true){
      inorder(rt->left,k);
      if(rt->key == k){
        found = true;
        cont ++;
      }else if(found != true){
        cont++;
      }
      inorder(rt->right, k);
    }
    return cont;
  }


  public:
    BST(){create_bst();}

    void insert(Key k, E e){
      root = inserthelp(root, k, e);
      nodecount++;
    }

    E find(Key k){
        found = false;
        cont = 0;
        int c = inorder(root,k);
        if(found == false){
          return 0;
        }else{
          return c;
        }
    }
};

int main(){
  BST<int,int> avl;
  int q,x,op,pos;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> op >> x;
    if(op == 1){
      avl.insert(x,0);
    }else{
      pos = avl.find(x);
      if(pos == 0){
        cout << "Data tidak ada";
      }else{
        cout << pos;
      }
      if(i < q){
        cout << endl;
      }
    }
  }
  return 0;
}
>>>>>>> Stashed changes
