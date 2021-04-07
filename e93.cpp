#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;
int r,g,b;
int R[210],G[210],B[210];
ll dp[210][210][210];

ll solve(int i,int j,int k){
	int c = 0;
	c += (i >= r);
	c += j >= g;
	c += k >= b;
	if(c > 1) return 0;
	if(dp[i][j][k] != -1) return dp[i][j][k];
	ll mx = 0;
	if(j < g && k < b)
		mx = solve(i,j+1,k+1 ) + G[j] * B[k];

	if(j < g && i < r)
		mx = max(mx, solve(i+1,j+1,k) +R[i]*G[j]);
	if(i < r && k < b)
		mx = max(mx,solve(i+1,j,k+1) + R[i]*B[k]);
	dp[i][j][k] = mx;
	return dp[i][j][k];
}

int main(){
	int t = 1;
	while(--t>=0){
		scanf("%d %d %d",&r,&g,&b);
		loop(i,r,0) scanf("%d",R+i);
		loop(i,g,0) scanf("%d",G+i);
		loop(i,b,0) scanf("%d",B+i);

		loop(i,210,0){
			loop(j,210,0){
				loop(k,210,0) dp[i][j][k] = -1;
			}
		}

		sort(R,R+r);
		reverse(R,R+r);
		sort(G,G+g);
		reverse(G,G+g);
		sort(B,B+b);
		reverse(B,B+b);
		// loop(i,r,0) printf("%d\n",R[i] );
		solve(0,0,0);

		ll res = 0;

		loop(i,210,0){
			loop(j,210,0){
				loop(k,210,0) res = max(res,dp[i][j][k]);
			}
		}

		printf("%lld\n",res );

	}
}