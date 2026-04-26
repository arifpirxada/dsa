#include <iostream>
#include <vector>
#include <list>
#include <stack>

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

    void topoSortDFS(int node, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;

        for (int neighbor : l[node]) {
            if (!vis[neighbor]) {
                topoSortDFS(neighbor, vis, st);
            }
        }
        st.push(node);
    }
    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            topoSortDFS(i, vis, st);
        }
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
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
    g.topoSort();

    return 0;
}