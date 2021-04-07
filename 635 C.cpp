#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> v1,pair<int,int> v2){
    if(v1.first == v2.first) return v1.second<=v2.second;
    return v1.first>=v2.first;
}

int dfs(int u,vector<int> adj[],int depth[],int parent[],int sub_nodes[]){
    bool node = 1;
    for(auto v : adj[u]){
        if(v != parent[u]){
            node = 0;
            if(depth[v] != -1){
                depth[v] = depth[u] + 1;
            }
            else depth[v] = depth[u];
            parent[v] = u;
            sub_nodes[u] += dfs(v,adj,depth,parent,sub_nodes);
        }
    }
    if(node){
        sub_nodes[u] = 0;
    }
    return sub_nodes[u]+1;
}

int main(){
    int n,k;scanf("%d %d",&n,&k);
    vector<int> adj[n+1];
    for(int i=1;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int depth[n+1],parent[n+1],sub_nodes[n+1];
    for(int i=0;i<=n;++i) depth[i] = parent[i] = sub_nodes[i] = 0;
    dfs(1,adj,depth,parent,sub_nodes);
   /* for(int i=1;i<=n;++i){
        printf("node:%d depth:%d contr:%d\n",i,depth[i],sub_nodes[i]);
    }*/

    pair<int,int> contr[n+1];

    for(int i=1;i<=n;++i){
        contr[i-1] = {depth[i]-sub_nodes[i],i};
    }
    long long res = 0;
    sort(contr,contr+n,comp);
    for(int i=0;i<k;++i){
        res += contr[i].first;
    }
    printf("%lld",res);
}
