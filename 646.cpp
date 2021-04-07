#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int n,int r,int level[]){
    int vis[n+1];
    for(int i=0;i<=n;++i) vis[i] = 0;
    queue<int> q;
    q.push(r);
    vis[r] = 1;
    level[r] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,x;scanf("%d %d",&n,&x);
        vector<int> adj[n+1];
        for(int i=0;i<n-1;++i){
            int a,b;scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int level[n+1];
        bfs(adj,n,x,level);
      //  for(int i=1;i<=n;++i) printf("level[%d]: %d\n",i,level[i]);
        int fr = 0;
        for(int i=1;i<=n;++i){
            if(level[i] == 1) ++fr;
        }
        int rem = n-fr-1;
        if(fr == 1 || n == 1){
            printf("Ayush\n");
        }
        else if(rem%2 == 0 && (fr-1) % 2 == 0){
            printf("Ayush\n");
        }
        else if(rem%2 == 0 && (fr-1) % 2 == 1){
            printf("Ashish\n");
        }
        else if(rem%2 == 1 && (fr-1) % 2 == 1){
            printf("Ayush\n");
        }
        else{
            printf("Ashish\n");
        }
    }

}
