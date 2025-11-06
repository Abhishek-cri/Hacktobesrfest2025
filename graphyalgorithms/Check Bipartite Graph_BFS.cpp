#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if the graph is Bipartite using BFS
bool isBipartite(vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1); // -1 means uncolored

    // Handle disconnected graphs too
    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0; // Start coloring with 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        // Assign opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } 
                    else if (color[neighbor] == color[node]) {
                        // Adjacent nodes have same color -> Not bipartite
                        return false;
                    }
                }
            }
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

    vector<vector<int>> graph(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    if (isBipartite(graph, V))
        cout << "✅ The graph is Bipartite" << endl;
    else
        cout << "❌ The graph is NOT Bipartite" << endl;

    return 0;
}



/*Output :
Enter number of vertices: 4
Enter number of edges: 4
Enter edges (u v):
0 1
1 2
2 3
3 0
✅ The graph is Bipartite */