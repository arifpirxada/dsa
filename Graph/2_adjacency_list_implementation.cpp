#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// using vector<vector<int>>
class GraphVec {
private:
    int numNodes;
    vector<vector<int>> adjList;

public:
    GraphVec(int numNodes) {
        this->numNodes = numNodes;
        adjList.resize(numNodes);
    }

    void addEdge(int src, int dest, bool directed = false) {
        adjList[src].push_back(dest);

        if (!directed) {
            adjList[dest].push_back(src);
        }
    }

    void bfs() {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        for (int i = 0; i < numNodes; i++) {
            if (visited[i]) continue;

            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                cout << node << " ";

                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    void dfsHelper(int node, vector<bool>& visited) {
        if (visited[node]) return;

        cout << node << " ";
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    // recursive dfs
    void dfs() {
        vector<bool> visited(numNodes, false);

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

    // iterative dfs

    void dfsIterative() {
        vector<bool> visited(numNodes, false);

        for (int i = 0; i < numNodes; i++) {
            if (visited[i]) continue;

            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int node = st.top();
                st.pop();

                if (visited[node]) continue;

                cout << node << " ";
                visited[node] = true;

                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
    }

    void printGraph() const {
        for (int i = 0; i < numNodes; i++) {
            cout << "    " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// using vector<list<int> - list: doubly linkedlist

class GraphVecList {
private:
    int n;
    vector<list<int>> adjList;

public:
    GraphVecList(int numNodes) {
        n = numNodes;
        adjList.resize(n);
    }

    void addEdge(int u, int v, bool directed) {
        adjList[u].push_back(v);

        if (directed) return;

        addEdge[v].push_back(u);
    }

    void bfs() {
        queue<int> q;
        vector<int> visited(n, bool);

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                cout << node << " ";

                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    void dfsHelper(int node, vector<int>& visited) {
        if (node >= n || visited[node]) return;

        cout << node << " ";
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs() {
        vector<int> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

    void printGraph() const {
        for (int i = 0; i < n; i++) {
            cout << "    " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};


// using unordered_map<list<int>> - used when the max node value is a lot larger
// Implement later
class GraphMapList {

};

int main() {
    GraphVec gv(7);

    /*
        6
        |  
        0
       / \
      1   2
      |    \
      3     5
      |
      4

    */

    gv.addEdge(0, 1);
    gv.addEdge(0, 2);
    gv.addEdge(0, 6);
    gv.addEdge(1, 3);
    gv.addEdge(2, 5);
    gv.addEdge(3, 4);

    cout << "GraphVec: " << endl;
    cout << "  printGraph: " << endl;
    gv.printGraph();
    
    cout << endl << "  bfs: ";
    gv.bfs();
    
    cout << endl << endl << "  dfs: ";
    gv.dfs();

    cout << endl << "----------";

    return 0;
}