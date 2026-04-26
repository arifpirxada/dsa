#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
        if (!directed) l[v].push_back(u);
    }

    vector<int> calculateIndegree() {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
            for (int neighbor : l[i])
                inDegree[neighbor]++;
        return inDegree;
    }

    // Kahn's Algorithm
    vector<int> topologicalSortBFS() {
        vector<int> inDegree = calculateIndegree();
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < V; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int neighbor : l[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if ((int)ans.size() != V) {
            cout << "Cycle detected! Topological sort not possible." << endl;
            return {};
        }

        return ans;
    }
};