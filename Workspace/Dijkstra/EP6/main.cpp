#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Triple {
    int cost;
    int vertex;
    int predecessor;

    Triple(int c, int v, int p) : cost(c), vertex(v), predecessor(p) {}
};

// Implementação do operador greater para a struct Triple
struct Greater {
    bool operator()(const Triple& a, const Triple& b) const {
        return a.cost > b.cost;
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // Lista de adjacência com pesos
    int numVertex;
    vector<string> mark;

    void create_graph(int n) {
        adjList.resize(n);
        mark.resize(n, "UNVISITED");
        numVertex = n;
    }

    void clear_graph() {
        adjList.clear();
        mark.clear();
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
        adjList[j].emplace_back(i, weight); // Adicionando a aresta para grafos não direcionados
    }

    int weight(int v, int w) {
        for (const auto& edge : adjList[v]) {
            if (edge.first == w) {
                return edge.second;
            }
        }
        return INT_MAX; // Retornar infinito se não houver aresta
    }

    void Prim(vector<int>& D, vector<int>& V) {
        int v, p, w;
        for (int i = 0; i < numVertex; i++) {
            D[i] = INT_MAX;
            setMark(i, "UNVISITED");
        }
        priority_queue<Triple, vector<Triple>, Greater> H;
        H.push(Triple(0, 0, 0));
        D[0] = 0;

        // Usando o loop for com a condição de parada
        for (int i = 0; i < numVertex - 1; i++) {
            do {
                if (H.empty()) return; // Se a heap estiver vazia, sai da função
                Triple min_element = H.top();
                H.pop();
                v = min_element.vertex;
                p = min_element.predecessor;
                if (getMark(v) == "VISITED") continue; // Pular vértices já visitados
            } while (getMark(v) != "UNVISITED");

            setMark(v, "VISITED");
            V[v] = p;

           
            for (const auto& edge : adjList[v]) {
                w = edge.first;
                int edgeWeight = edge.second;
                if (getMark(w) != "VISITED" && D[w] > edgeWeight) {
                    D[w] = edgeWeight;
                    H.push(Triple(D[w], w, v));
                }
            }
        }
    }
};

int main() {
    int n,m,c1,c2,d;
    while(cin >> n >> m){
      if(n == 0 && m == 0){break;}
      Graph g(n);
      for(int i = 0; i < m ; i++){
        cin >> c1 >> c2 >> d;
        g.setEdge(c1,c2,d);
      }
      vector<int> D(n);
      vector<int> V(n);
      g.Prim(D,V);
      int s = *max_element(D.begin(),D.end());
      if(s == INT_MAX){cout << "IMPOSSIBLE"<< endl;}
      else{cout << s << endl;}
    }
    
    return 0;
}
