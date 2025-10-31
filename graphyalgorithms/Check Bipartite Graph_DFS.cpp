#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and check if the graph is bipartite
bool dfs(int node, int color, vector<int>& colors, vector<vector<int>>& adj) {
    colors[node] = color; // Assign current color to node

    for (int neighbor : adj[node]) {
        // If neighbor not colored, assign opposite color
        if (colors[neighbor] == -1) {
            if (!dfs(neighbor, 1 - color, colors, adj))
                return false; // If conflict found in recursion
        }
        // If neighbor has same color → Not bipartite
        else if (colors[neighbor] == colors[node]) {
            cout << "❌ Conflict found between nodes " << node << " and " << neighbor << endl;
            return false;
        }
    }
    return true;
}

// Function to check if the graph is bipartite using DFS
bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> colors(V, -1); // -1 means uncolored

    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) { // Unvisited node
            if (!dfs(i, 0, colors, adj))
                return false;
        }
    }
    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    if (isBipartite(V, adj))
        cout << "✅ Graph is Bipartite" << endl;
    else
        cout << "❌ Graph is NOT Bipartite" << endl;

    return 0;
}

/* Output1 :  
Enter number of vertices: 4
Enter number of edges: 4
Enter edges (u v):
0 1
1 2
2 3
3 0
✅ Graph is Bipartite
*/

/* Output 2 
Enter number of vertices: 5
Enter number of edges: 5
Enter edges (u v):
0 1
1 2
2 3
3 4
4 0
❌ Conflict found between nodes 4 and 0
❌ Graph is NOT Bipartite
*/