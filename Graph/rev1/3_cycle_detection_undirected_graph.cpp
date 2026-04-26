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

    bool hasCycle() {
        vector<bool> vis(V, false);
        queue<pair<int, int>> q; // {u, parent}

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            q.push({i, -1});
            vis[i] = true;

            while (!q.empty()) {
                auto [u, parent] = q.front(); q.pop();

                for (int neighbor : l[u]) {
                    if (!vis[neighbor]) {
                        q.push({neighbor, u});
                        vis[neighbor] = true;
                    } else if (neighbor != parent) {
                        return true;
                    }
                }
            }
        }

        return false;
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

    cout << endl << "hasCycle: ";
    if (g.hasCycle()) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}