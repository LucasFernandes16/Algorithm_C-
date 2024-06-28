#include <bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int** matrix;
    int numEdge;
    int* mark;

    void create_graph(int n){
      mark = new int[n];
      matrix = new int[n][n];
      numEdge = 0;
    }
};    

int main() {
    return 0;
}