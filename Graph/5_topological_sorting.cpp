#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool directed) {
        l[u].push_back(v);
        if (!directed) {
            l[v].push_back(u); // FIXED
        }
    }

    void dfsHelper(int node, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;

        for (int neighbor : l[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited, st);
            }
        }

        st.push(node);
    }

    stack<int> topologicalSortDFS() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited, st);
            }
        }

        return st;
    }
};

int main() {
    Graph g(5);

    /* Graph:
        0 --> 2 --> 3
      ↙️   ↗️
     1 --> 4 
    */


    g.addEdge(0, 2, true);
    g.addEdge(0, 1, true);
    g.addEdge(1, 4, true);
    g.addEdge(2, 3, true);
    g.addEdge(4, 2, true);

    stack<int> st = g.topologicalSortDFS();

    cout << "Topological Sort: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}