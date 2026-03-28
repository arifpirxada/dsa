#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adjList;

public:
    Graph(int numNodes) {
        n = numNodes;
        adjList.resize(n);
    }

    void addEdge(int u, int v, bool directed) {
        adjList[u].push_back(v);
        if (directed) return;
        adjList[v].push_back(u);
    }

    bool dfs(int node, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, pathVisited)) return true;
            }
            else if (pathVisited[neighbor]) {
                return true;
            }
        }

        pathVisited[node] = false;
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited)) {
                    return true;
                }
            }
        }
        return false;
    }

    void printGraph() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int node : adjList[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    /*
    5 <-- 0 <-- 1 <-- 4
         ⬇️    ⬆️
          2 --> 3
    */

    Graph g(6);

    g.addEdge(0, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 1, true);
    g.addEdge(1, 0, true);
    g.addEdge(4, 1, true);
    g.addEdge(0, 5, true);

    if (g.hasCycle()) {
        cout << "Graph has cycle"; 
    } else {
        cout << "Graph does not have cycle"; 
    }

    return 0;
}