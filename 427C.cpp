#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MOD = (1e9) + 7;

void dfs(vector<bool> &vis, int u, vector<int> adj[], vector<int> &topSorted){

	for(auto v : adj[u]){
		if(!vis[v]){
			vis[v] = true;
			dfs(vis, v, adj, topSorted);
		}
	}
	topSorted.push_back(u);

}

int main(){

	int n;scanf("%d", &n);
	int costs[n];

	for(int i = 0; i < n; ++i) scanf("%d", costs + i);

	int m;
	scanf("%d", &m);

	vector<int> adj[n];

	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		adj[a].push_back(b);

	}

	vector<bool> vis(n, false);
	vector<int> topSorted;

	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			vis[i] = true;
			dfs(vis, i, adj, topSorted);
		}
	}

	reverse(topSorted.begin(), topSorted.end());


	vector<int> reverseAdj[n];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < adj[i].size(); ++j){
			reverseAdj[adj[i][j]].push_back(i);
		}
	}

	vector<bool> vis2(n, false);
	vector<vector<int>> components;
	long long totalWays = 1;
	long long totCost = 0;
	for(auto x : topSorted){
		vector<int> component;
		if(!vis2[x]){
			vis2[x] = true;
			dfs(vis2, x,reverseAdj,component);
			components.push_back(component);
			int mnCost = INT_MAX;
			for(auto x : component){
				mnCost = min(mnCost, costs[x]);
			}
			totCost += mnCost;
			long long mnCount = 0;
			for(auto x : component){
				if(costs[x] == mnCost)
					++mnCount;
			}


			totalWays = (mnCount * totalWays) % MOD;
		}
	}  



	printf("%lld %lld\n",totCost, totalWays );

}