#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph (int n, vector<int> adj[]) {
    int vis[n+1]={0};
    vis[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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

    vector<int> bfs = bfsOfGraph(n,adj);

    cout<<"BFS Traversal : ";
    for (int x : bfs) cout << x << " ";

    return 0;
}