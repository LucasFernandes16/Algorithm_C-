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

    void Dijkstra(int s, vector<int>& D) {
        vector<int> P(numVertex, -1);
        int v, p, w;
        for (int i = 0; i < numVertex; i++) {
            D[i] = INT_MAX;
            setMark(i, "UNVISITED");
        }
        priority_queue<Triple, vector<Triple>, Greater> H;
        H.push(Triple(0, s, s));
        D[s] = 0;

        while (!H.empty()) {
            Triple min_element = H.top();
            H.pop();
            v = min_element.vertex;
            p = min_element.predecessor;

            if (getMark(v) == "VISITED") continue;
            setMark(v, "VISITED");
            P[v] = p;

            for (const auto& edge : adjList[v]) {
                w = edge.first;
                int edgeWeight = edge.second;
                if (getMark(w) != "VISITED" && D[w] > D[v] + edgeWeight) {
                    D[w] = D[v] + edgeWeight;
                    H.push(Triple(D[w], w, v));
                }
            }
        }
    }
};

int main() {
    int cases, n, m, s, t;
    int a1, a2, p; // Variáveis para a inserção das arestas no grafo

    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> n >> m >> s >> t;
        Graph g(n);
        for (int j = 0; j < m; j++) {
            cin >> a1 >> a2 >> p;
            g.setEdge(a1, a2, p);
        }
        vector<int> D(n);
        g.Dijkstra(s, D);
        cout << "Case #" << i + 1 << ": ";
        if(D[t] == INT_MAX){
          cout << "unreachable" << endl;
        }else{
          cout << D[t] << endl;
        }
    }

    return 0;
}
