#include <iostream>
#include <vector>
#include <queue>
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

// Dikstra's Algorithm: Dijkstra's algorithm is necessary for graphs that can contain cycles because they can't be topologically sorted.

void shortest_dist(int V, vector<vector<Edge>> &g) {
    vector<int> dist(V, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > pq; // {wt, v}

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [wt, u] = pq.top(); pq.pop();
        if (wt > dist[u]) continue;

        for (Edge e : g[u]) {
            if (dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    cout << "Shortest Distances: ";
    for (int d : dist) {
        cout << d << " ";
    }
}

int main() {
    int V = 6;

    vector<vector<Edge>> g(V); // Directed weighted Graph

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    shortest_dist(V, g);

    return 0;
}