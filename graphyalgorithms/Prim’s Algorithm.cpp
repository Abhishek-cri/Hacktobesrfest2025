#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

// Function to find MST using Prim’s Algorithm
void primsMST(int V, vector<vector<pii>> &adj) {
    vector<int> key(V, INT_MAX);    // Minimum weight edge to reach vertex
    vector<bool> inMST(V, false);   // To track included vertices
    vector<int> parent(V, -1);      // To store MST structure

    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap {weight, vertex}

    key[0] = 0;
    pq.push({0, 0}); // Start from vertex 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // Skip if already in MST
        inMST[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "  weight: " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "\nTotal weight of MST: " << totalWeight << endl;
}

// Main function
int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add edges: adj[u].push_back({v, weight});
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    cout << "Prim's Minimum Spanning Tree Algorithm\n\n";
    primsMST(V, adj);

    return 0;
}


// output
// Prim's Minimum Spanning Tree Algorithm

// Edges in Minimum Spanning Tree:
// 0 - 1  weight: 2
// 1 - 2  weight: 3
// 1 - 4  weight: 5
// 0 - 3  weight: 6

// Total weight of MST: 16
