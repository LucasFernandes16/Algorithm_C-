#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Triple {
    int w;
    int a;
    int b;

    Triple(int c, int v, int p) : w(c), a(v), b(p) {}
};

// Implementação do operador greater para a struct Triple
struct Greater {
    bool operator()(const Triple& a, const Triple& b) const {
        return a.w > b.w;
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // Adjacency list with weights
    int numEdge;
    int numVertex;
    vector<string> mark;

    void create_graph(int n) {
        adjList.resize(n);
        mark.resize(n, "UNVISITED");
        numEdge = 0;
        numVertex = n;
    }

    void clear_graph() {
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

    void setEdge(int i, int j, int weight) {
        adjList[i].emplace_back(j, weight);
        adjList[j].emplace_back(i, weight);
        numEdge++;
    }


    int first(int v) {
        if (!adjList[v].empty()) {
            return adjList[v][0].first;
        }
        return numVertex;
    }

    int next(int v, int w) {
        for (size_t i = 0; i < adjList[v].size(); ++i) {
            if (adjList[v][i].first == w && i + 1 < adjList[v].size()) {
                return adjList[v][i + 1].first;
            }
        }
        return numVertex;
    }

    int weight(int v, int w) {
        for (const auto& edge : adjList[v]) {
            if (edge.first == w) {
                return edge.second;
            }
        }
        return INT_MAX; // Retornar infinito se não houver aresta
    }

    void Dijkstra(int s, int D[]) {
        vector<int> P(numVertex, -1);
        int v, p, w;
        for (int i = 0; i < numVertex; i++) {
            D[i] = INT_MAX;
            setMark(i, "UNVISITED");
        }
        priority_queue<Triple, vector<Triple>, Greater> H;
        H.push(Triple(0, s, s));
        D[s] = 0;
        for(int i = 0; i < numVertex-1; i++) {
            do {
                Triple min_element = H.top();
                H.pop();
                v = min_element.b;
                p = min_element.a;
                if (v == NULL) {return;}
            } while (getMark(v) == "UNVISITED");
            setMark(v, "VISITED");
            P[v] = p;
            w = first(v);
            while (w < numVertex) {
                if (getMark(w) != "VISITED" && D[w] > D[v] + weight(v, w)) {
                    D[w] = D[v] + weight(v, w);
                    H.push(Triple(D[w], w, v));
                }
                w = next(v, w);
            }
        }
    }
};

int main(){
  int cases,n,m,s,t;
  // n = numVertex, m = numEdges, // s = vertice de origem, t = vértice de chegada
  // grafo é não direcionado
  int a1,a2,p; // variáveis para a inserção das arestas no grafo

  cin >> cases;
  for(int i = 0; i < cases; i++){
    cin >> n >> m >> s >> t;
    Graph g (n);
    for(int i = 0; i < m; i++){
      cin >> a1 >> a2 >> p;
      g.setEdge(a1,a2,p);
    }
    int D[n];
    g.Dijkstra(a1,D);
    cout << "Case #" << i+1 << ": " << D[a2];
   
  }

  return 0;
}