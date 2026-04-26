#include <iostream>
#include <queue>
#include <list>

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

// Prim's Algo
int min_spanning_tree_cost(int V, list<Edge> g[], int src) {
    vector<int> MSTSet(V, false);
    // {wt, u}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > pq;
    
    int cost = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [wt, u] = pq.top(); pq.pop();

        if (MSTSet[u]) continue;
        MSTSet[u] = true;
        cost += wt;

        for (Edge e : g[u]) {
            if (!MSTSet[e.v]) pq.push({e.wt, e.v});
        }
    }
    return cost;
}

int main() {
    int V = 4;
    list<Edge> g[V];

    g[0].push_back(Edge(1, 10));
    g[0].push_back(Edge(3, 5));
    g[0].push_back(Edge(2, 20));

    g[1].push_back(Edge(0, 10));
    g[1].push_back(Edge(3, 30));

    g[2].push_back(Edge(0, 20));
    g[2].push_back(Edge(3, 40));

    g[3].push_back(Edge(0, 5));
    g[3].push_back(Edge(1, 30));
    g[3].push_back(Edge(2, 40));

    cout << "Cost: " << min_spanning_tree_cost(V, g, 0);

    return 0;
}