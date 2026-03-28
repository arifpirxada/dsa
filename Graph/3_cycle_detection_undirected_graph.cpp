#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int n;
    int vector<vector<int>> adjList;

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

    void bfs() {
        vector<bool> visited(n, false);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
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

    void dfsHelper(int node, vector<int>& visited) {
        if (node >= n || visited[node]) return;
        
        cout << node << " ";
        visited[neighbor] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

    // Detect cycle bfs

    bool detectCycleBFS() {
        vector<bool> visited(n, false);
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            q.push({i, -1});
            visited[i] = true;

            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();

                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        q.push({neighbor, node});
                        visited[neighbor] = true;
                    } else if (parent != neighbor) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // Detect cycle dfs

    bool detectCycleDFS(int currentNode, vector<bool>& visited, int parent) {
        visited[currentNode] = true;

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                if (dfsDetectCycleHelper(neighbor, visited, currentNode)) {
                    return true;
                }
            }
            else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool hasCycle() {
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (detectCycleDFS(i, -1, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    // Detect cycle dfs end

    void printGraph() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j : adjList[i]) {
                cout << j;
            }
        }
    }
};

int main() {
    return 0;
}