#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;
    int numEdge;
    int numVertex;
    vector<string> mark;

    void create_graph(int n) {
        mark.resize(n, "UNVISITED");
        matrix.resize(n, vector<int>(n, 0));
        numEdge = 0;
        numVertex = n;
    }

    int first(int v) {
        for (int i = 0; i < numVertex; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return numVertex;
    }

    int next(int v, int w) {
        for (int i = w + 1; i < numVertex; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
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

    void setEdge(int i, int j) {
        if (matrix[i][j] == 0) {
            numEdge++;
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    void BFS(int start) {
        queue<int> Q;
        Q.push(start);
        setMark(start, "VISITED");

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            cout << v << " ";
            int w = first(v);
            while (w < numVertex) {
                if (getMark(w) == "UNVISITED") {
                    setMark(w, "VISITED");
                    Q.push(w);
                }
                w = next(v, w);
            }
        }
        cout << endl;
    }

    void DFS(int v) {
        preVisit(v);
        setMark(v, "VISITED");
        int w = first(v);
        while (w < numVertex) {
            if (getMark(w) == "UNVISITED") {
                DFS(w);
            }
            w = next(v, w);
        }
    }

    void resetMarks() {
        for (int v = 0; v < numVertex; v++) {
            setMark(v, "UNVISITED");
        }
    }
};

int main() {
    int n, q, e1, e2;
    string op;
    cin >> n >> q;

    Graph graph(n);

    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == "add") {
            cin >> e1 >> e2;
            graph.setEdge(e1, e2);
        } else if (op == "BFS") {
            int v;
            cin >> v;
            graph.resetMarks();
            graph.BFS(v);
        } else if (op == "DFS") {
            int v;
            cin >> v;
            graph.resetMarks();
            graph.DFS(v);
        }
    }

    return 0;
}