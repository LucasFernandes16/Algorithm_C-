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
        numEdge++;
    }

    void delEdge(int i, int j) {
        auto it = remove_if(adjList[i].begin(), adjList[i].end(), [j](const pair<int, int>& p) {
            return p.first == j;
        });
        if (it != adjList[i].end()) {
            adjList[i].erase(it, adjList[i].end());
            numEdge--;
        }
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
        H.push(Triple(0, s, s)); // Corrigido: O custo inicial é 0
        D[s] = 0;
        while (!H.empty()) {
            do {
                Triple min_element = H.top();
                H.pop();
                v = min_element.vertex;
                p = min_element.predecessor;
                if (v == -1) {
                    return;
                }
            } while (getMark(v) != "UNVISITED");
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

int main() {
    int n = 5; // Número de vértices
    Graph g(n);

    // Adicionando arestas com pesos
    g.setEdge(0, 1, 10);
    g.setEdge(0, 4, 5);
    g.setEdge(1, 2, 1);
    g.setEdge(1, 4, 2);
    g.setEdge(2, 3, 4);
    g.setEdge(3, 0, 7);
    g.setEdge(3, 2, 6);
    g.setEdge(4, 1, 3);
    g.setEdge(4, 2, 9);
    g.setEdge(4, 3, 2);

    int D[n];
    g.Dijkstra(0, D);

    for (int i = 0; i < n; ++i) {
        cout << "Distance from 0 to " << i << " is " << D[i] << endl;
    }

    return 0;
}
