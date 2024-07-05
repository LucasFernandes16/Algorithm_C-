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
    int nodecount
}