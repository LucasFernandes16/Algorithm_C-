#include <bits/stdc++.h>
using namespace std;

class Graph{
  private:
    vector<vector<int>> matrix;
    int numEdge;
    int numVertex;
    vector<string> mark;

    void create_graph(int n){
      matrix.resize(n,vector<int>(n,0));
      mark.resize(n,"UNVISITED");
      numEdge = 0;
      numVertex = n;
    }

    int first(int v){
      for(int i = 0; i < numVertex; i++){
        if(matrix[v][i] != 0){
          return i;
        }
      }
      return numVertex;
    }

    int next(int v, int w){
      for(int i = w + 1; i < numVertex-1; i++){
        if(matrix[v][i] != 0){
          return i;
        }
      }
      return numVertex;
    }

    void setMark(int v, string value) {
        if (v >= 0 && v < numVertex) {
            mark[v] = value;
        }
    }

    string getMark(int v) {
        if (v >= 0 && v < numVertex) {
            return mark[v];
        }
        return "UNVISITED";
    }

    void preVisit(int v){
      cout << v << " "; 
    }

public:
    Graph(int n) {
        create_graph(n);
    }
    ~Graph(){}

    void setEdge(int i, int j){
      if(matrix[i][j] == 0){
        matrix[i][j] = 1;
        numEdge++;
      }
    }

    void delEdge(int i,int j){
      if(matrix[i][j] != 0){
        numEdge--;
        matrix[i][j] = 0;
      }
    }

    void toposort(int v, stack<int>& s){
      setMark(v,"VISITED");
      int w = first(v);
      while(w < numVertex){
        if(getMark(w) == "UNVISITED"){
          toposort(w,s);
        }
        w = next(v,w);
      }
      s.push(v);
    }
};

int main(){
  int n = 7;
  int t = 8;
  Graph g(n);
  g.setEdge(0,2);
  g.setEdge(0,4);
  g.setEdge(2,1);
  g.setEdge(2,3);
  g.setEdge(2,5);
  g.setEdge(1,5);
  g.setEdge(3,5);
  g.setEdge(4,5);
  stack<int> s;
  g.toposort(0,s);
  for(int i = 0; i < 7; i++){
    cout << (s.top() + 1);
    s.pop();
  }
  return 0;
}