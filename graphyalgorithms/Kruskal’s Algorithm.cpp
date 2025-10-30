#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v) return;

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

// Function to find MST using Kruskal’s Algorithm
int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    DisjointSet ds(V);

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (auto edge : edges) {
        if (ds.findParent(edge.u) != ds.findParent(edge.v)) {
            mstWeight += edge.weight;
            mstEdges.push_back(edge);
            ds.unionSet(edge.u, edge.v);
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (auto e : mstEdges)
        cout << e.u << " -- " << e.v << " == " << e.weight << endl;

    return mstWeight;
}

// Main function
int main() {
    int V = 5, E = 7;
    vector<Edge> edges;

    // Graph input (u, v, weight)
    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 3, 6));
    edges.push_back(Edge(1, 2, 3));
    edges.push_back(Edge(1, 3, 8));
    edges.push_back(Edge(1, 4, 5));
    edges.push_back(Edge(2, 4, 7));
    edges.push_back(Edge(3, 4, 9));

    cout << "Kruskal's Minimum Spanning Tree Algorithm\n";
    int totalWeight = kruskalMST(V, edges);

    cout << "\nTotal weight of MST: " << totalWeight << endl;

    return 0;
}


// Kruskal's Minimum Spanning Tree Algorithm
// Edges in the Minimum Spanning Tree:
// 0 -- 1 == 2
// 1 -- 2 == 3
// 1 -- 4 == 5
// 0 -- 3 == 6

// Total weight of MST: 16
