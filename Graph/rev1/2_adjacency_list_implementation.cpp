#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;
public:
    Graph (int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v, bool directed = false) {
        l[u].push_back(v);
        if (directed) return;
        l[v].push_back(u);
    }

    void bfs() {
        vector<bool> vis(V, false);
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                cout << u << " ";

                for (int neighbor : l[u]) {
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
        }
    }

    void dfsHelper (int node, vector<bool>& vis) {
        vis[node] = true;
        cout << node << " ";

        for (int neighbor : l[node]) {
            if (!vis[neighbor]) {
                dfsHelper(neighbor, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
            }
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

    cout << endl << "bfs: ";
    g.bfs();
    cout << endl << "-------";

    cout << endl << "dfs: ";
    g.dfs();
    cout << endl << "-------";

    return 0;
}