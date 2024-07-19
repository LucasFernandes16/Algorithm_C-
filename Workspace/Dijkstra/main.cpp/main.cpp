#include <bits/stdc++.h>
using namespace std;
#define ll long long;

class Graph{
  private:
    vector<vector<int>> adjList;
    int numEdge;
    int numVertex;
    vector<string> mark;

    void create_graph(int n){
      adjList.resize(n);
      mark.resize(n,"UNVISITED");
      numEdge = 0;
      numVertex = n;
    }

    void clear_graph(){
      adjList.clear();
      mark.clear();
      numEdge = 0;
      numVertex = 0;
    }

    int first(int v){
      if (adjList[v].empty()) return numVertex;
      return adjList[v][0];
    }

    int next(int v, int w){
      auto it = find(adjList[v].begin(), adjList[v].end(), w);
      if (it != adjList[v].end() && ++it != adjList[v].end()){
        return *it;
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
      if(find(adjList[i].begin(), adjList[i].end(), j) == adjList[i].end()){
        adjList[i].push_back(j);
        numEdge++;
      }
    }

    void delEdge(int i, int j){
      auto it = find(adjList[i].begin(), adjList[i].end(), j);
      if(it != adjList[i].end()){
        adjList[i].erase(it);
        numEdge--;
      }
    }

    void Dijkstra(int s, int D[]){
      int P[numVertex];
      for(int i = 0; i < numVertex-1; i++){
        D[i] = P[1] = -1;
        setMark(i,"UNVISITED");
      }
      vector<tuple<int,int,int>> heap;
      heap[1] = make_tuple(s,s,0);
      make_heap(heap.begin(),heap.end)
      D[s] = 0;
      for(int i = 0; i < numVertex-1; i++){
        do{

        }while(not(getMark(v) == "UNVISITED"))
      }
    }
};

int main(){
  return 0;
}
