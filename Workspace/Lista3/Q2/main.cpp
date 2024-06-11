#include <iostream>
#include <string>

using namespace std;

template <typename Key,typename E>
class BSTNODE{
  public:
    Key key;
    E element;
    BSTNODE* left;
    BSTNODE* right;
};

template <typename Key,typename E>
class BST{
  private:
    BSTNODE<Key,E>* root;
    int nodecount;

    BSTNODE<Key,E>* create_bstnode(Key k, E e){
      BSTNODE<Key,E>* temp = new BSTNODE<Key,E>;
      temp->key = k;
      temp->element = e;
      temp->left = temp->right = NULL;
      return temp;
    }

    void create_bst(){
      root = NULL;
      nodecount = 0;
    }
    void clear_bst(){
      nodecount = 0;
    }

    BSTNODE<Key,E>* getmin(BSTNODE<Key,E>* rt){
      if(rt->left == NULL){return rt;}
      return getmin(rt->left);
    }

    BSTNODE<Key,E>* deletemin(BSTNODE<Key,E>* rt){
      if(rt->left == NULL){return rt->right;}
      rt->left = deletemin(rt->left);
      return rt;
    }

    E findhelp(BSTNODE<Key,E>* rt, Key k){
      if(rt == NULL){
        return NULL;
      }
      if(rt->key > k){
        return findhelp(rt->left,k);
      }
      else if(rt->key == k){
        return rt->element;
      }
      else{
        return findhelp(rt->right,k);
      }
    }

    BSTNODE<Key,E>* inserthelp(BSTNODE<Key,E>* rt, Key k, E e){
      if(rt == NULL){
        return create_bstnode(k,e);
      }
      if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
      }
      else{
        rt->right = inserthelp(rt->right, k ,e);
      }
      return rt;
    }

    BSTNODE<Key,E>* removehelp(BSTNODE<Key,E>* rt, Key k){
      if(rt == NULL){return NULL;}
      if(rt->key > k){
        rt->left = removehelp(rt->right, k);
      }
      else if(rt->key < k){
        rt->right = removehelp(rt->right, k);
      }
      else{
        if(rt->left == NULL){return rt->right;}
        else if(rt->right == NULL){return rt->left;}
        else{
          BSTNODE<Key,E>* temp = new BSTNODE<Key,E>;
          temp = getmin(rt->right);
          rt->element = temp->element;
          rt->key = temp->key;
          rt->right = deletemin(rt->right);
        }
      }
      return rt;
    }

    void preorder(BSTNODE<Key,E>* rt){
    if (rt != NULL){
      cout << " " <<rt->key;
      preorder(rt->left);
      preorder(rt->right);
    }
  }

  void inorder(BSTNODE<Key,E>* rt){
    if(rt != NULL){
      inorder(rt->left);
      cout << " " << rt->key;
      inorder(rt->right);
    }
  }

  void posorder(BSTNODE<Key,E>* rt){
    if(rt != NULL){
      posorder(rt->left);
      posorder(rt->right);
      cout << " " <<rt->key;
    }
  }
  public:
    BST(){create_bst();}
    ~BST(){clear_bst();}

    E find(Key k){
      return findhelp(root,k);
    }

    void insert(Key k, E e){
      root = inserthelp(root, k, e);
      nodecount++;
    }

    E remove(Key k){
      E temp = findhelp(root,k);
      if(temp != NULL){
        root = removehelp(root,k);
        nodecount--;
      }
      return temp;
    }

    void print(){
      cout << "Pre order :";
      preorder(root);
      cout << endl;
      cout << "In order  :";
      inorder(root);
      cout << endl;
      cout << "Post order:";
      posorder(root);
    }

};


void solve(BST<int,int> tree){
  int n, p;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> p;
    tree.insert(p,0);
  }
  tree.print();
}

int main(){ 
  BST<int,int> tree;
  solve(tree);
  return 0;
}