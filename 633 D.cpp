#include <bits/stdc++.h>

using namespace std;

int bfs(int root,vector<int> adj[],int n){
    int level = 1;
    int vis[n+1];
    for(int i=0;i<=n;++i) vis[i] = 0;
    vis[root] = 1;
    queue<int> q;
    q.push(root);
    q.push(-1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == -1){
            ++level;
            if(!q.empty()) q.push(-1);
            continue;
        }
        int node = 1;
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
                node = 0;
            }
        }
        if(node == 1 && level%2 == 0) return 1;
    }
    return 0;
}

int main(){
    int n;scanf("%d",&n);
    vector<int> adj[n+1];
    for(int i=1;i<n;++i){

        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res_max = 0;
    int parent_edge = 0;
    set<int> parent;
    int root = 0;
    for(int i=1;i<=n;++i){
        if(adj[i].size() == 1){
            parent.insert(adj[i][0]);
            ++parent_edge;
            root = i;
        }
    }
    res_max = parent.size()+n-1-parent_edge;
    int res_min = 1;
    if(bfs(root,adj,n)) res_min = 3;
    printf("%d %d\n",res_min,res_max);

}
