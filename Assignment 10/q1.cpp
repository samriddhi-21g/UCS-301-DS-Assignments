// Graph basic operations - traversal, degree, adjacent vertices, number of edges, display

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;                          // number of vertices
    vector<vector<int>> adj;        // adjacency list
    int edgeCount;                  // number of edges

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
        edgeCount = 0;
    }

    // Add edge u -> v (directed)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        edgeCount++;
    }

    // Return out-degree of a vertex
    int outDegree(int v) {
        return adj[v].size();
    }

    // Return in-degree of a vertex
    int inDegree(int v) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int x : adj[i]) {
                if (x == v) cnt++;
            }
        }
        return cnt;
    }

    // Print adjacent vertices of a vertex
    void getAdjacent(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int x : adj[v]) cout << x << " ";
        cout << "\n";
    }

    // Return number of edges
    int edges() {
        return edgeCount;
    }

    // Display the graph
    void display() {
        cout << "Graph (Adjacency List):\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " -> ";
            for (int x : adj[i]) cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Graph g(n);

    cout << "Enter " << m << " directed edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    int v;
    cout << "\nEnter vertex to get in-degree & out-degree: ";
    cin >> v;

    cout << "Out-degree of " << v << " = " << g.outDegree(v) << "\n";
    cout << "In-degree of " << v << " = " << g.inDegree(v) << "\n";

    g.getAdjacent(v);

    cout << "\nTotal number of edges = " << g.edges() << "\n";

    return 0;
}