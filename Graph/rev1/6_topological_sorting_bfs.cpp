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

    vector<int> getInDegree() {
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int neighbor : l[i]) {
                inDegree[neighbor]++;
            }
        }
        return inDegree;
    }

    // Kahn's Algorithm
    void topoSortBFS() {
        vector<int> inDegree = getInDegree();
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for (int neighbor : l[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
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

    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(3, 4, true);

    cout << "Topological Sort: ";
    g.topoSortBFS();

    return 0;
}