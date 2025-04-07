#include <iostream>
#include <string>

using namespace std;

template <typename Key,typename E>
class NODE{
  public:
    int height;
    Key key;
    NODE* left;
    NODE* right;
    E element;
};

template <typename Key, typename E>
class AVL{
  private:
    NODE* root;
    int nodecount;

  void create_avl(){
    root = NULL;
    nodecount = 0;
  }

  void clear_avl(NODE* rt){
    if(rt!= NULL){
      clear_avl(rt->left);
      clear_avl(rt->right);
      delete rt;
    }

    
  }
}