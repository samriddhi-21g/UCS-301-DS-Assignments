// prims algo using min heap for minimum spanning tree (greedy algo)

#include<bits/stdc++.h>
using namespace std;

int mst (int n, vector<pair<int,int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(n,0);

    //{wt,node}
    pq.push({0,0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;

        vis[node]=1;
        sum+=wt;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode]) {
                pq.push({edW,adjNode});
            }
        }
    } 
    return sum;
}

int main () {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for (int i=0; i<m; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    int mstSum = mst(n,adj);
    cout<<"MST Sum : "<<mstSum;
    return 0;
}