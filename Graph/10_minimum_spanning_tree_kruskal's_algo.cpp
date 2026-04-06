#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

// kruskal's algorithm

void initializeParents(int V, vector<int>& parents) {
    for (int i = 0; i < V; i++) {
        parents[i] = i;
    }
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        rank[pv]++;
    }
}

int minimum_spanning_tree(int V, vector<vector<int>>& Edges) {
    vector<int> parents(V);
    vector<int> rank(V, 0);

    initializeParents(V, parents);

    sort(Edges.begin(), Edges.end(), cmp);
    int cost = 0;

    for (auto& edge : Edges) {
        int u = edge[0], v = edge[1], wt = edge[2];

        int pu = findParent(u, parents);
        int pv = findParent(v, parents);

        if (pu != pv) {
            unionSet(pu, pv, parents, rank);
            cost += wt;
        }
    }
    return cost;
}


int main() {
    int V = 4;

    // View Example in: assets/9_10_spanning_tree_graph_example.png

    vector<vector<int>> Edges = {
        {0, 1, 10},
        {0, 3, 5},
        {0, 2, 20},
        {1, 3, 30},
        {2, 3, 40}
    };

    cout << "Minimum Cost: " << minimum_spanning_tree(V, Edges);


    return 0;
}