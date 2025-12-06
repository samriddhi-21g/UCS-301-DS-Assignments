// Kruskal Algo for minimum spanning tree

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent,size,rank;
    
    public:
    DisjointSet (int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar (int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank (int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
        else if (rank[ulp_u]>rank[ulp_v]) parent[ulp_v]=ulp_u;
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize (int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        } else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int mst (int n, vector<pair<int,int>> adj[]) {
    vector <pair<int,pair<int,int>>> edges;
    for (int i=1; i<=n; i++) {
        for (auto it : adj[i]) {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(),edges.end());
    DisjointSet ds(n);
    int mstwt = 0;

    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUPar(u)!=ds.findUPar(v)) {
            mstwt+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstwt;
}

int main () {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
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