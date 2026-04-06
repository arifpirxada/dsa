#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMat;

public:
    Graph(int V) {
        this->V = V;
        adjMat.resize(V, vector<int> (V, 0));
    }

    void addEdge(int u, int v, bool directed = false) {
        adjMat[u][v] = 1;
        if (directed) return;
        adjMat[v][u] = 1;
    }

    void bfs() {
        vector<bool> vis(V, false);
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                cout << node << " ";

                for (int neighbor = 0; neighbor < V; neighbor++) {
                    if (!vis[neighbor] && adjMat[node][neighbor] == 1) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
        }
    }

    void dfsHelper(int node, vector<bool>& vis) {
        vis[node] = true;
        cout << node << " ";

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (!vis[neighbor] && adjMat[node][neighbor] == 1)
                dfsHelper(neighbor, vis);
        }
    }

    void dfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfsHelper(i, vis);
        }
    }

    void printGraph() {
        for (int node = 0; node < V; node++) {
            cout << "  " << node << " --> ";
            for (int neighbor = 0; neighbor < V; neighbor++) {
                if (adjMat[node][neighbor] == 1) cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    /*
        0
       / \
      1   2
      |
      3
      |
      4

    */

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    
    cout << "-------" << endl << "printGraph: " << endl;
    g.printGraph();

    cout << endl << "bfs: ";
    g.bfs();
    cout << endl << "-------";

    cout << endl << "dfs: ";
    g.dfs();
    cout << endl << "-------";

    return 0;
}