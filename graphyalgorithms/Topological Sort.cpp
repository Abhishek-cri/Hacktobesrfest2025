#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSortUtil(int v, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[v] = true;
    for (int x : adj[v])
        if (!visited[x])
            topoSortUtil(x, adj, visited, st);
    st.push(v);
}

void topoSort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topoSortUtil(i, adj, visited, st);

    cout << "Topological Order: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    int V = 6;
    vector<int> adj[V];

    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    topoSort(V, adj);
    return 0;
}
