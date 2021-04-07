#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxm=200005;
ll n,m,k,q,a[mxm][2],b[mxm],x,y,dp[mxm][2];
inline ll trans(ll j,ll u,ll i,ll v){
	ll p=lower_bound(b+1,b+q+1,a[j][u])-b,rt=1e9;
	if(p<=q)rt=abs(a[j][u]-b[p])+abs(a[i][v^1]-b[p])+abs(a[i][v]-a[i][v^1]);
	p=upper_bound(b+1,b+q+1,a[j][u])-b-1;
	if(p)rt=min(rt,abs(a[j][u]-b[p])+abs(a[i][v^1]-b[p])+abs(a[i][v]-a[i][v^1]));
	return rt;
}
int main(){
	cin>>n>>m>>k>>q;
	for(int i=1;i<=n;++i)a[i][0]=1e9,a[i][1]=-1e9;
	for(int i=1;i<=k;++i)cin>>x>>y,a[x][0]=min(a[x][0],y),a[x][1]=max(a[x][1],y);
	a[1][0]=1,a[1][1]=max(a[1][1],1ll);
	for(int i=1;i<=q;++i)cin>>b[i];
	sort(b+1,b+q+1);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=abs(a[1][1]-1)+abs(a[1][1]-a[1][0]),dp[1][1]=abs(a[1][1]-1);
	int j=1;
	for(int i=2;i<=n;++i){
		if(a[i][0]==1e9)continue;
		for(ll v=0;v<2;++v)for(ll u=0;u<2;++u)dp[i][v]=min(dp[i][v],dp[j][u]+trans(j,u,i,v)+i-j);
		j=i;
	}
	cout<<min(dp[j][0],dp[j][1])<<endl;
}
