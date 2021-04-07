#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000+10;
vector<int> adj[MAX];
int childs[MAX],color[MAX],res[MAX],vis[MAX];

int dfs(int u,int par){
    for(auto &v:adj[u]){
        if(v != par){
            childs[u] += dfs(v,u);
        }
    }
    return max(0,max(0,childs[u])+color[u]);
}
void bfs(){
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                res[v] = max(res[u]-max(0,max(0,childs[v])+color[v]),0)+max(0,childs[v])+color[v];
                q.push(v);
            }
        }
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",color+i);
        if(!color[i]) color[i] = -1;
    }
    for(int i=0;i<n-1;++i){
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    res[1] = childs[1]+color[1];
    bfs();
    for(int i=1;i<=n;++i) printf("%d ",res[i]);
}
