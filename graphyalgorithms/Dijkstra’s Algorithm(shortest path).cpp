#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

void dijkstra(int V, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto edge : adj[node]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > d + weight) {
                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << " -> " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({3, 4});

    dijkstra(V, adj, 0);
    return 0;
}
