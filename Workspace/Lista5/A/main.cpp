#include <bits/stdc++.h>
using namespace std;
#define long long ll;

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph{
  private:
    vector<vector<string>> matrix;
    vector<pair<string, int>> mark;
    int numEdge;
    int numVertex;

    void create_graph(int n){
      matrix.resize(n, vector<string>(n,""));
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
        if(matrix[v][i] != ""){
          return i;
        }
      }
      return numVertex;
    }

    int next(int v, int w){
      for(int i = w + 1; i < numVertex; i++){
        if(matrix[v][i] != ""){
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

    void setVertex(int i){
      
    }

    void setEdge(int i, int j, string name){
      if(matrix[i][j] == ""){
        matrix[i][j] = name ;
        numEdge++;
      }
    }

    void delEdge(int i,int j){
      if(matrix[i][j] != ""){
        numEdge--;
        matrix[i][j] = "";
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

    int n(){
      return numVertex;
    }
};

int main(){
  int t,n;
  for(int i = 0; i < t; i++){
    
    Graph g()
  }
  return 0;
}