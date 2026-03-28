#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numNodes; 
    vector<vector<int>> adjMatrix;

public:
    Graph(int nodes) {
        numNodes = nodes;
        adjMatrix.resize(numNodes, vector<int>(numNodes, 0));
    }

    void addEdge(int src, int dest, bool directed = false) {
        if (src >= numNodes || dest >= numNodes) {
            cout << "Invalid edge: node out of bounds\n";
            return;
        }

        adjMatrix[src][dest] = 1;

        if (!directed) {
            adjMatrix[dest][src] = 1;
        }
    }

    void bfs(int startNode) {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            cout << currentNode << " ";

            for (int neighbor = 0; neighbor < numNodes; neighbor++) {
                if (!visited[neighbor] && adjMatrix[currentNode][neighbor] == 1) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfsUtil(int currentNode, vector<bool>& visited) {
        if (currentNode >= numNodes || visited[currentNode]) return;

        visited[currentNode] = true;
        cout << currentNode << " ";

        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            if (!visited[neighbor] && adjMatrix[currentNode][neighbor] == 1) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int startNode) {
        vector<bool> visited(numNodes, false);
        dfsUtil(startNode, visited);
    }

    void printGraph() {
        for (int i = 0; i < numNodes; i++) {
            cout << "  " << i << " -> ";
            for (int j = 0; j < numNodes; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
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
    g.bfs(0);
    cout << endl << "-------";

    cout << endl << "dfs: ";
    g.dfs(0);
    cout << endl << "-------";
    return 0;
}