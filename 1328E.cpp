#include <bits/stdc++.h>

using namespace std;
int *depth,*tin,*tout,*parent;
vector<int> *adj;
int tme = 0;
void dfs(int u,int par){
    tin[u] = tme++;
    for(auto &v:adj[u]){
        if(v != par){
            parent[v] = u;
            depth[v] = depth[u]+1;
            dfs(v,u);
        }
    }
    tout[u] = tme++;
}

int main(){
    int n,m;scanf("%d %d",&n,&m);
    vector<int> Adj[n+1];
    adj = Adj;
    for(int i=0;i<n-1;++i){
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int Depth[n+1],Parent[n+1],Tin[n+1],Tout[n+1];
    depth = Depth;
    parent = Parent;
    tin = Tin;
    tout = Tout;
    for(int i=0;i<=n;++i){
        depth[i]=parent[i]=tin[i]=tout[i]=0;N
    }

    dfs(1,-1);
    for(int i=0;i<m;++i){
        int k;scanf("%d",&k);
        int v[k];
        for(int i=0;i<k;++i) scanf("%d",v+i);
        int leaf = v[0];
        for(int i=1;i<k;++i){
            if(depth[v[i]]>depth[leaf]) leaf = v[i];
        }
      //  printf("here\n");
        for(int i=0;i<k;++i){
            if(v[i] != leaf && v[i] != 1){
                v[i] = parent[v[i]];
            }
        }
        bool pos = true;
        for(int i=0;i<k;++i){
            int u = v[i];
            if(tin[u]<=tin[leaf] && tout[leaf]<=tout[u]){
                ;
            }
            else{
                pos = false;
                break;
            }
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
}
