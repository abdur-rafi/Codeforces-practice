#include <cstdio>
#include <queue>

#define loop(x,n,a) for(int x = a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef long long ll;

using namespace std;

bool dfs(int u, vector<int> adj[], vector<int> &color){
	for(auto v : adj[u]){
		if(color[v] == 0){
			color[v] = 1;
			if(dfs(v, adj, color)){
				return true;
			}
		}
		else if(color[v] == 1){
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int DP(int u, vector<int> adj[], vector<int> &dp){
	if(dp[u] != -1) return dp[u];
	if(adj[u].size() == 0){
		dp[u] = 1;
		return 1;
	}
	int mx = 0;
	for(auto v : adj[u]){
		if(v < u){
			mx = max(mx, DP(v, adj, dp));
		}
		else mx = max(mx, 1 + DP(v ,adj, dp));
	}
	dp[u] = mx;
	return dp[u];
}

int main(){
	int t;scanf("%d", &t);
	while(--t >= 0){

		int n;scanf("%d", &n);
		vector<int> adj[n + 1];
		loop(i, n, 0){
			int k;scanf("%d", &k);
			loop(j, k, 0){
				int b;
				scanf("%d", &b);
				--b;
				adj[i].push_back(b);
			}
		}
		vector<int> dp(n, -1);
		vector<int> color(n, 0);
		bool pos = true;
		for(int i = 0; i < n; ++i){
			if(color[i] == 0){
				if(dfs(i, adj, color)){
					pos = false;
					break;
				}
			}
		}
		if(!pos){
			printf("-1\n");
			continue;
		}
		int res = 0;
		loop(i, n , 0){
			if(dp[i] == -1){
				DP(i, adj, dp);
			}
			// printf("dp[%d] = %d\n",i, dp[i] );
			res = max(res, dp[i]);
		}
		printf("%d\n",res );

	}
}