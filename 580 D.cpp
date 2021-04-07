#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
vector<int> adj[100];
int level[100];
int n;
int bfs(int i,int j){
    bool vis[100];
    for(int i=0;i<100;++i) vis[i]=false;
    queue<int> q;
    q.push(i);vis[i]=true;q.push(-1);int l=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u == -1){
            ++l;
            if(!q.empty()) q.push(-1);
            continue;
        }
        if(u == j) return l;
        for(auto v:adj[u]){
            if(!vis[v]){
                if(u == i && v == j) continue;
                vis[v]=true;q.push(v);
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d",&n);
    ll a[n];
    int fre[65];
    for(int i=0;i<65;++i) fre[i]=0;
    for(int i=0;i<n;++i) scanf("%lld",a+i);
    for(int i=0;i<n;++i){
        for(int j=0;j<=60;++j){
            ll d=1;
            d= d<<j;
            if(d & a[i]){
                printf("d : %lld a:%lld\n",d,a[i]);
            }
        }
    }
    for(int i=0;i<65;++i){
        if(fre[i]>=3){
            printf("3");
            return 0;
        }
    }
    vector<int> fr[65];
    for(int j=0;j<=60;++j){
        ll d=1;
        d=d<<j;
        for(int i=0;i<n;++i){
            if(a[i]&d) fr[j].push_back(i);
        }
    }
    int k=1;
    map<int,int> m;
    for(int j=0;j<=60;++j){
        if(fr[j].size()==2){
            int a=fr[j][0];
            int b=fr[j][1];
            if(m[a]==0) m[a]=k++;
            if(m[b]==0) m[b]=k++;
            a=m[a];
            b=m[b];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    int res=-2;
    for(int i=1;i<k;++i){
        for(int j=1;j<k;++j){
            if(i==j) continue;
            int b=bfs(i,j);
            if(b != -1){
                if(res == -2) res=b;
                else res=min(res,b);
            }
        }
    }
  //  printf("%d",res+1);
}
