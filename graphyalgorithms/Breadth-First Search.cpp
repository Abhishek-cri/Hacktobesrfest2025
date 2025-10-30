#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int x : adj[node]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2, 4};
    adj[4] = {2, 3};

    cout << "BFS Traversal: ";
    BFS(adj, V, 0);
    return 0;
}
