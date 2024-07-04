#include <bits/stdc++.h>
using namespace std;
#define ll long long;

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

    void clear_graph(){
      matrix.clear();
      mark.clear();
      numEdge = 0;
      numVertex = 0;
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
    ~Graph(){clear_graph();}

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
  int n,m,x,y;
  int start;
  cin >> n >> m;
  Graph g(8);
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    g.setEdge(x-1,y-1);
  }
  stack<int> s;
  g.toposort(0,s);
  return 0;
}