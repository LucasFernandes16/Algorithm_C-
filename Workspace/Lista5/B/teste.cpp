#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> dependency;
    int numVertex;

    void create_graph(int n) {
        adjList.resize(n);
        dependency.resize(n, 0);
        numVertex = n;
    }

    void clear_graph() {
        adjList.clear();
        dependency.clear();
        numVertex = 0;
    }

public:
    Graph(int n) {
        create_graph(n);
    }
    ~Graph() { clear_graph(); }

    void setEdge(int i, int j) {
        adjList[i].push_back(j);
        dependency[j]++;
    }

    vector<int> topologicalSort() {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> result;

        for (int i = 0; i < numVertex; i++) {
            if (dependency[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            int v = pq.top();
            pq.pop();
            result.push_back(v);

            for (int u : adjList[v]) {
                dependency[u]--;
                if (dependency[u] == 0) {
                    pq.push(u);
                }
            }
        }
        return result;
    }
};

int main() {
    int n, m, x, y;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g.setEdge(x - 1, y - 1);
    }

    vector<int> sorted = g.topologicalSort();
    if(!sorted.empty()){
      for (int v : sorted) {
          cout << v + 1 << " ";
      }
      cout << endl;
    }else{
      cout << "Sandro fails.";
    }
    return 0;
}
