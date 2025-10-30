#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void bellmanFord(int V, int E, vector<tuple<int, int, int>> &edges, int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto [u, v, w] : edges)
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    }

    for (auto [u, v, w] : edges)
        if (dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle!";
            return;
        }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << i << " -> " << dist[i] << endl;
}

int main() {
    int V = 5, E = 8;
    vector<tuple<int, int, int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellmanFord(V, E, edges, 0);
    return 0;
}
