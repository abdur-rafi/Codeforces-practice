#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

ll res = 0;
vector<ll> dfs(int u, 
	int k,
	int parent, 
	vector<int> adj[]
	){
	ll mp[k+1];
	for(int i = 0; i <= k; ++i) mp[i] = 0;
	vector<ll> t(k+1, 0);
	t[0] = 1;
	mp[0] = 1;


	for(auto v : adj[u]){
		if(v != parent){
			auto t2 = dfs(v, k, u, adj);
			for(int i = 0; i < k - 1 ; ++i){
				res += t2[i] * mp[k-i-1];
			}
			res += t2[k-1];
			for(int i = 0; i < k; ++i){
				t[i + 1] += t2[i];
				mp[i+1] += t2[i];
			}
		}
	}
	// printf("-----%d------\n",u );
	// for(auto v : dist[u])
	// 	printf("%d ",v );

	// printf("\n");
	// printf("\n-------------\n");
	// for(int i = 0; i <= k; ++i){
	// 	printf("%d ",mp[i] );
	// }
	// printf("\n");
	// ll tmp = 0;


	// for(auto v : adj[u]){
	// 	if(v != parent){
	// 		for(int i = 0; i < k; ++i){
	// 			mp[i+1] -= dist[v][i];
	// 		}
	// 		for(int i = 0; i < k - 1 ; ++i){
	// 			tmp += dist[v][i] * mp[k-i-1];
	// 		}
	// 		for(int i = 0; i < k; ++i){
	// 			mp[i+1] += dist[v][i];
	// 		}
	// 		res += dist[v][k-1];
	// 	}
	// }
	// // printf("val: %d\n", tmp);
	// res += tmp / 2;

	return t;
}


int main(){

	int t = 1;
	while(--t>=0){
		int n, k;
		scanf("%d %d", &n, &k);
		vector<int> adj[n];
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u;
			--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		// vector<ll> dist[n];
		dfs(0, k, -1, adj);
		printf("%lld\n",res );
	}

}