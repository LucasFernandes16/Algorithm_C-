<<<<<<< Updated upstream
  #include <bits/stdc++.h>
  using namespace std;
  #define ll long long;

  class Graph{
    private:
      vector<vector<int>> matrix;
      int numEdge;
      int numVertex;
      vector<string> mark;

      void create_graph(int n){
        matrix.resize(n,vector<int>(1,0));
        mark.resize(n,"UNVISITED");
        numEdge = 0;
        numVertex = n;
      }

      void clear_graph(){
        matrix.clear();
        mark.clear();
        numEdge = 0;
        numVertex = 0;
      }

      int first(int v){
        for(int i = 0; i < numVertex; i++){
          if(matrix[v][i] != 0){
            return i;
          }
        }
        return numVertex;
      }

      int next(int v, int w){
        for(int i = w + 1; i < numVertex-1; i++){
          if(matrix[v][i] != 0){
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
      ~Graph(){clear_graph();}

      void setEdge(int i, int j){
        if(matrix[i][j] == 0){
          matrix[i][j] = 1;
          numEdge++;
        }
      }

      void delEdge(int i,int j){
        if(matrix[i][j] != 0){
          numEdge--;
          matrix[i][j] = 0;
        }
      }

      void toposort(int v, stack<int>& s){
        setMark(v,"VISITED");
        int w = first(v);
        while(w < numVertex){
          if(getMark(w) == "UNVISITED"){
            toposort(w,s);
          }
          w = next(v,w);
        }
        s.push(v);
      }
  };

  int main(){
    int n,m,x,y;
    int start;
    cin >> n >> m;
    Graph g(8);
    for(int i = 0; i < m; i++){
      cin >> x >> y;
      g.setEdge(x-1,y-1);
    }
    stack<int> s;
    g.toposort(0,s);
    return 0;
  }
=======
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> result;
    vector<int> indegree;
    int numVertex;
    bool op;

    void create_graph(int n) {
        adjList.resize(n);
        visited.resize(n, false);
        indegree.resize(n, 0);
        numVertex = n;
        op = true;
    }

    void clear_graph() {
        adjList.clear();
        visited.clear();
        result.clear();
        indegree.clear();
        numVertex = 0;
        op = false;
    }

    void dfs(int u) {
        visited[u] = true;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        result.push_back(u);
    }

public:
    Graph(int n) {
        create_graph(n);
    }

    ~Graph() {
        clear_graph();
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        indegree[v]++;
    }

    void topologicalSort() {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < numVertex; i++) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            result.push_back(u);

            for (int v : adjList[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    pq.push(v);
                }
            }
        }

        if (result.size() != numVertex) {
            op = false;
        }
    }

    void printResult() {
        if (!op) {
            cout << "Sandro fails." << endl;
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0) cout << " ";
                cout << result[i] + 1;
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x - 1, y - 1); 
    }

    g.topologicalSort();
    g.printResult();

    return 0;
}
>>>>>>> Stashed changes
