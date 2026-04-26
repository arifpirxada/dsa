#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

vector<int> shortest_path(vector<vector<Edge>>& g, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Edge e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    return dist;
}

int main() {
    // View assets/Bellman-Ford_algo_example_graph.png for visual of example

    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 5));

    g[1].push_back(Edge(2, -5));
    g[1].push_back(Edge(4, 3));

    g[2].push_back(Edge(3, 1));

    g[3].push_back(Edge(4, -3));
    g[3].push_back(Edge(5, 3));

    g[4].push_back(Edge(5, 7));

    vector<int> dist = shortest_path(g, V, 0);

    cout << "Shortest Path: "; // Expect: 0 2 -3 -2 -5 1
    for (int d : dist) {
        cout << d << " ";
    }


    return 0;
}