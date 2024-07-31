#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Triple {
    int w;
    int a;
    int b;

    Triple(int c, int v, int p) : w(c), a(v), b(p) {}
};


struct Greater {
    bool operator()(const Triple& a, const Triple& b) const {
        return a.w > b.w;
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
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
        return INT_MAX;
    }

    void Prim(int D[], int V[]) {
        int v, p, w;
        for (int i = 0; i < numVertex; i++) {
            D[i] = INT_MAX;
            setMark(i, "UNVISITED");
        }
        priority_queue<Triple, vector<Triple>, Greater> H;
        H.push(Triple(0, 0, 0));
        D[0] = 0;
        for (int i = 0; i < numVertex; i++) {
            do {
                if(H.empty()) return;
                Triple min_element = H.top();
                H.pop();
                v = min_element.b;
                p = min_element.a;
            } while (getMark(v) == "VISITED");
            setMark(v, "VISITED");
            V[v] = p;
            w = first(v);
            while (w < numVertex) {
                if (getMark(w) != "VISITED" && D[w] > weight(v, w)) {
                    D[w] = weight(v, w);
                    H.push(Triple(D[w], v, w));
                }
                w = next(v, w);
            }
        }
    }
};

int main(){
  int c,o,c1,c2,p;
  int aux = 0;
  while(cin >> c >> o){
    if(c == 0 && o == 0){break;}
    aux++;
    Graph g(c);
    for(int i = 0; i < o; i++){
      cin >> c1 >> c2 >> p;
      g.setEdge(c1,c2,p);
    }
    int D[c];
    int V[c];
    g.Prim(D,V);
    int sum = 0;
    for(int j = 0; j < c ; j++){
      sum += D[j];
    }
    cout << "Caso " << aux << ": " << sum << endl;
  }
  
  
  return 0;
}