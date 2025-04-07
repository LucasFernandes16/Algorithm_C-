#include <iostream>
#include <string>

using namespace std;

template <typename Key,typename E>
class BSTNODE{
  public:
    int height;
    Key key;
    BSTNODE* left;
    BSTNODE* right;
    E element;
    
};

template <typename Key,typename E>
class BST{
  private:
    BSTNODE<Key,E>* root;
    int nodecount;

    void create_bst(){
      root = NULL;
      nodecount = 0;
    }
    void clear_bst(BSTNODE<Key,E>* rt){
      if(rt!= NULL){
        clear_bst(rt->left);
        clear_bst(rt->right);
        delete rt;
      }
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

  void preorder(BSTNODE<Key,E>* rt){
    if (rt != NULL){
      cout << rt->key << endl;
      preorder(rt->left);
      preorder(rt->right);
    }
    }
  public:
    BST(){create_bst();}
    ~BST(){clear_bst(root);}

    void insert(Key k, E e){
      root = inserthelp(root, k, e);
      nodecount++;
    }

    void print(){
      preorder(root);
      cout << "END" << endl;
    }
};

int main(){
  int c,n,k;
  cin >> c;
  for(int i = 0; i < c; i++){
    cin >> n;
    BST<int,int> avl;
    for(int j = 0; j < n; j++){
      cin >> k;
      avl.insert(k,0);
    }
    avl.print();
  }
  return 0;
}