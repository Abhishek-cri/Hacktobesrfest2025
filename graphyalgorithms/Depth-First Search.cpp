#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int x : adj[node])
        if (!visited[x])
            DFSUtil(x, adj, visited);
}

void DFS(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    DFSUtil(start, adj, visited);
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2, 4};
    adj[4] = {2, 3};

    cout << "DFS Traversal: ";
    DFS(adj, V, 0);
    return 0;
}
