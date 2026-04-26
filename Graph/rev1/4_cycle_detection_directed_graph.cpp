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

    bool checkCycleDFS(int node , vector<bool>& vis, vector<bool>& recurPath) {
        vis[node] = true;
        recurPath[node] = true;

        for (int neighbor : l[node]) {
            if (!vis[neighbor]) {
                if (checkCycleDFS(neighbor, vis, recurPath)) return true;
            } else if (recurPath[neighbor] == true) {
                return true;
            }
        }
        recurPath[node] = false;
        return false;
    }
    bool hasCycle() {
        vector<bool> vis(V, false);
        vector<bool> recurPath(V, false);

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            if (checkCycleDFS(i, vis, recurPath)) {
                return true;
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
      ----1   2
     /     |
    |      3
     \     |
      ----4

    */

    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(3, 4, true);
    g.addEdge(4, 1, true);

    cout << "hasCycle: ";
    if (g.hasCycle()) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}