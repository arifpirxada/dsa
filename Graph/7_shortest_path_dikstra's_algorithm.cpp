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

vector<int> shortest_dist(int V, vector<vector<Edge>> &g) {
    // Min heap: (distance, node)
    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>
    > pq;

    vector<int> dist(V, INT_MAX);

    int src = 0;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [wt, v] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (wt > dist[v]) continue;

        for (const auto &neighbor : g[v]) {
            int next = neighbor.v;
            int weight = neighbor.wt;

            // Relaxation
            if (dist[next] > dist[v] + weight) {
                dist[next] = dist[v] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
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

    vector<int> dist = shortest_dist(V, g);

    cout << "Shortest Distances: ";
    for (int d : dist) {
        cout << d << " ";
    }

    return 0;
}