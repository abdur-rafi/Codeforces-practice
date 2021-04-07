#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(vector<int> adj[],int b,int parent[],int n){
    queue<int> q;
    q.push(b);
    int vis[n+1];
    for(int i=0;i<=n;++i) vis[i] = 0;
    vis[b] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v :adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,m,a,b,c;scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
        int price[m];
        for(int i=0;i<m;++i) scanf("%d",price+i);
        vector<int> adj[n+1];
        for(int i=0;i<m;++i){
            int e,f;scanf("%d %d",&e,&f);
            adj[e].push_back(f);
            adj[f].push_back(e);
        }
        int parent[n+1];
        parent[b] = 0;
        bfs(adj,b,parent,n);
        vector<int> path1,path2;
        int tmp1 = c;
        path1.push_back(c);
        while(parent[tmp1] != b){
            path1.push_back(parent[tmp1]);
            tmp1 = parent[tmp1];
        }
        path2.push_back(a);
        tmp1 = a;
        while(parent[tmp1] != b){
            path2.push_back(parent[tmp1]);
            tmp1 = parent[tmp1];
        }
        for(int i=1;i<=n;++i){
            printf("parent[%d]: %d\n",i,parent[i]);
        }
        for(auto p : path2){
            printf("path:%d\n",p);
        }
    }


}
