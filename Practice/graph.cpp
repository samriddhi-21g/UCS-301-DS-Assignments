#include<bits/stdc++.h>
using namespace std;

vector<int> bfs (vector<vector<int> adj, int n) {
    int vis[n+1] = {0};
    queue<int> q;
    vector<int> bfs;
    q.push(1);
    vis[1]=1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (it : adj[node]) {
            if (vis[it]==0) {
                vis[it]=1;
                q.push(it;)
            }
        }
    }
}

void dfs_helper (int node, vector<int> adj[], int vis[], vector<int>& dfs) {
    vis[node]=1;
    dfs.push_back(node);
    for (auto it : adj[node]) {
        if(vis[node]==0) dfs_helper(node, adj, vis, dfs); 
    }
}
vector<int> dfs_main (int n, vector<int> adj[]) {
    int vis[n+1]={0};
    vector<int> dfs;
    dfs_helper (1,adj,vis,dfs);
    return dfs;
}

int prim_mst (int n, vector<pair<int,int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int vis[n+1];
    pq.push{0,1};
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if (vis[node]) continue;
        vis[node]=1;
        sum+=wt;
        for (auto x : adj[node]) {
            int neighbour = x.first;
            int edge_weight = x.second;
            if (!vis[neighbour]) pq.push({edge_weight,neighbour});
        }
    }
    return sum;
}

class DisjointSet {
    vector<int> parent, size;

    public:
    DisjointSet (int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar (int node) {
        if (parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize (int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u]>size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

int kruskal_mst (int n, vector<pair<int,int>> adj[]) {
    vector<int,pair<int,int>> edges;
    for (auto it : adj[i]) {
        int wt = it.second;
        int u = it.first;
        int v = i;
        edges.push_back(wt,{u,v});
    }

    sort(edges.begin(),edges.end());
    DisjointSet d(n+1);
    int sum = 0;

    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (d.findUPar(u)!=d.findUPar(v)) {
            d.unionBySize(u,v);
            sum += wt;
        }
    }

    return sum;
}

vector<int> dijkstra_shortestPath (int n, vector<pair<int,int>> adj[], int source) {
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance (n+1,INT_MAX);
    distance[source] = 0;
    pq.push({0,source});

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int d = x.first;
        int node = x.second;

        if (d>distance[node]) continue;

        for (auto it : adj[node]) {
            int neighbour = it.seond;
            int edge_weight = it.first;

            if (d+edge_weight < distance[neighbour]) {
                distance[neighbour] = d+edge_weight;
                pq.push({distance[neighbour],neighbour});
            }
        }
    }
    return distance;
}