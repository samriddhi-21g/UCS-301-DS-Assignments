#include<bits/stdc++.h>
using namespace std;

void dfss (int node, vector<int> adj[], int vis[], vector<int> &dfs) {
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) { 
            dfss(it,adj,vis,dfs);
        }
    }
}

vector<int> dfsOfGraph (int n, vector<int> adj[]) {
    int vis[n+1]={0};
    int start = 1;
    vector<int> dfs;
    dfss(start,adj,vis,dfs);
    return dfs;
}

int main () {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for (int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dfs = dfsOfGraph(n,adj);

    cout<<"DFS Traversal : ";
    for (int x : dfs) cout << x << " ";

    return 0;
}