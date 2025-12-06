// Dijkstra algo for shortest path to every node from the source

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<pair<int,int>> adj[], int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, INT_MAX);

    // {dist, node}
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int d = it.first;

        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;

            if (d + edW < dist[adjNode]) {
                dist[adjNode] = d + edW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    int src = 0; // Starting node
    vector<int> dist = dijkstra(n, adj, src);
    cout << "Sum of shortest distances from source = " << distSum;

    return 0;
}