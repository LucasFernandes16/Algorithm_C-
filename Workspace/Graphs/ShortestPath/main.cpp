#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph{
  private:
    vector<vector<int>> matrix;
    vector<pair<string, int>> mark;
    int numEdge;
    int numVertex;

    void create_graph(int n){
      matrix.resize(n, vector<int>(n,0));
      mark.resize(n, make_pair("UNVISITED",-1));
      numEdge = 0;
      numVertex = n;
    }

    void clear_graph(){
      numEdge = 0;
      numVertex = 0;
      matrix.clear();
      mark.clear();
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
      for(int i = w + 1; i < numVertex; i++){
        if(matrix[v][i] != 0){
          return i;
        }
      }
      return numVertex;
    }

    void setMark(int v, string value, int pred) {
        if (v >= 0 && v < numVertex) {
            mark[v].first = value;
            mark[v].second = pred;
        }
    }

    string getMark(int v) {
        if (v >= 0 && v < numVertex) {
            return mark[v].first;
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
    ~Graph(){
      clear_graph();
    }

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

    void resetMarks() {
        for (int v = 0; v < numVertex; v++) {
            setMark(v, "UNVISITED", -1);
        }
    }

    void BFS(int start, int end){
      int v, w;
      bool find = false;
      queue<int> q;
      q.push(start);
      setMark(start,"VISITED",-1);
      while(!q.empty() and find != true){
        v = q.front();
        q.pop();
        w = first(v);
        while(w < numVertex){
          if(getMark(w) == "UNVISITED"){
            setMark(w,"VISITED",v);
            if(w == end){find = true;}
            q.push(w);
          }
          w = next(v,w);
        }
      }
      stack<int> path;
      int pred = end;
      do{
        cout << pred << " ";
        pred = mark[pred].second;
      }while(pred != -1);
    }

};
int main(){
  int n = 6;
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
  g.BFS(0,5);
  return 0;
}