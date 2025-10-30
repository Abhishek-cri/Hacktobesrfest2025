#include <iostream>
#include <vector>
using namespace std;

bool dfsCycle(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (auto x : adj[node]) {
        if (!visited[x]) {
            if (dfsCycle(x, node, adj, visited))
                return true;
        } else if (x != parent)
            return true;
    }
    return false;
}

bool hasCycle(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (dfsCycle(i, -1, adj, visited))
                return true;
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};

    cout << (hasCycle(adj, V) ? "Cycle detected!" : "No cycle found.");
    return 0;
}
