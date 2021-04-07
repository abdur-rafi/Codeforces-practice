#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=200011;
int n,m,k,Q;
vector<int> adj[MAX];
vector<int> nxt;
ll dp[MAX][2];
int q[MAX];
int bs(int val,bool ub){
    int i=0,j=Q-1,m;
    while(i<=j){
        m=(i+j)>>1;
        if(q[m]<val) i=m+1;
        else j=m-1;
    }
    if(ub) return j+1;
    return i-1;
}
ll treasure_hunt(int i,int j,int nx){
    int nx2=nx;
    if(nx2==nxt.size()) return 0;
    nx=nxt[nx];
    if(!adj[i].empty() && j == adj[i][adj[i].size()-1] && dp[i][1] !=-1) return dp[i][1];
    if(!adj[i].empty() && j == adj[i][0] && dp[i][0] !=-1) return dp[i][0];
    int r=bs(j,1);
    int l=bs(j,0);
    int lt=adj[nx][0];
    int rt=adj[nx][adj[nx].size()-1];
    ll res=LONG_LONG_MAX;
    if(l != -1 && r < Q){
        if(lt<=q[l] && rt>=q[r]){
            ll c=(rt-q[r]+1)+(rt-lt)+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=(q[l]-lt+1)+(rt-lt)+j-q[l];
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
        else if(rt<=q[l]){
            ll c=q[l]-lt+1+j-q[l];
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
        }
        else if(lt>=q[r]){
            ll c=rt-q[r]+1+q[r]-j;
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
        else if(lt>=q[l] && rt<=q[r]){
            ll c=q[r]-lt+1+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=rt-q[l]+1+j-q[l];
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
        else if(lt>=q[l]){
            ll c=rt-q[l]+1+j-q[l];
            res=res=min(res,c+treasure_hunt(nx,rt,nx2+1));
            c=(q[r]-lt+1)+(rt-lt)+q[r]-j;
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
            c=rt-q[r]+1+rt-lt+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
        }
        else if(rt<=q[r]){
            ll c=q[r]-lt+1+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=rt-q[l]+1+(rt-lt)+j-q[l];
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=q[l]-lt+1+rt-lt+j-q[l];
            c=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
    }
    else if(l != -1){
        if(lt<=q[l] && rt>=q[l]){
            ll c=rt-q[l]+1+rt-lt+j-q[l];
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=q[l]-lt+1+rt-lt+j-q[l];
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
        else if(rt<=q[l]){
            ll c=q[l]-lt+1+j-q[l];
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
        }
        else if(lt>=q[l]){
            ll c=rt-q[l]+1+j-q[l];
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
    }
    else if(r < Q){
        if(lt<=q[r] && rt>=q[r]){
            ll c=rt-q[r]+1+rt-lt+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
            c=q[r]-lt+1+rt-lt+q[r]-j;
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
        else if(rt<=q[r]){
            ll c=q[r]-lt+1+q[r]-j;
            res=min(res,c+treasure_hunt(nx,lt,nx2+1));
        }
        else if(lt>=q[r]){
            ll c=rt-q[r]+1+q[r]-j;
            res=min(res,c+treasure_hunt(nx,rt,nx2+1));
        }
    }
    if(!adj[i].empty() && adj[i][0] == j){
        dp[i][0]=res+nx-i-1;
        return dp[i][0];
    }
    else if(!adj[i].empty()){
        dp[i][1]=res+nx-i-1;
        return dp[i][1];
    }
    return res+nx-i-1;
}
int main(){
    for(int i=0;i<MAX;++i){
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    scanf("%d %d %d %d",&n,&m,&k,&Q);
    for(int i=0;i<k;++i){
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    for(int i=0;i<Q;++i) scanf("%d",q+i);
    sort(q,q+Q);
    for(int i=0;i<=n;++i){
        if(!adj[i].empty()){
            nxt.push_back(i);
            sort(adj[i].begin(),adj[i].end());
        }
    }
    ll res=-1;
    if(adj[1].size()){
        res=treasure_hunt(1,adj[1][adj[1].size()-1],1);
        res += adj[1][adj[1].size()-1]-1;
    }
    else
        res=treasure_hunt(1,1,0);
    printf("%lld\n",res);
}
