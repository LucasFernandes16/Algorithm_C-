#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {
private:
    vector<vector<int>> adjList;
    int numEdge;
    int numVertex;
    vector<string> mark;

    void create_graph(int n){
      adjList.resize(n);
      mark.resize(n, "UNVISITED");
      numEdge = 0;
      numVertex = n;
    }

    void clear_graph(){
      adjList.clear();
      mark.clear();
      numEdge = 0;
      numVertex = 0;
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

public:
    Graph(int n) {
        create_graph(n);
    }
    ~Graph() { clear_graph(); }

    void setEdge(int i, int j) {
        if (find(adjList[i].begin(), adjList[i].end(), j) == adjList[i].end()) {
            adjList[i].push_back(j);
            numEdge++;
        }
    }

    void delEdge(int i, int j) {
        auto it = find(adjList[i].begin(), adjList[i].end(), j);
        if (it != adjList[i].end()) {
            adjList[i].erase(it);
            numEdge--;
        }
    }

    int first(int v) {
        if (!adjList[v].empty()) {
            return adjList[v][0];
        }
        return numVertex;
    }

    int next(int v, int w) {
        for (size_t i = 0; i < adjList[v].size(); ++i) {
            if (adjList[v][i] == w && i + 1 < adjList[v].size()) {
                return adjList[v][i + 1];
            }
        }
        return numVertex;
    }

    void Dijkstra(int s, int D[]){
      int P[numVertex-1];
      for(int i = 0; i < numVertex-1; i++){
        D[i] = -1;
        P[i] = -1;
        
      }
    }
};

struct Triple{
  int pred;
  int n;
  int distance;

};

int main() {

    return 0;
}
