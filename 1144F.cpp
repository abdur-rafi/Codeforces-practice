#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
const int MAX = 200000 + 100;

bool colorGraph(vector<int> adj[], vector<int> &color, int n){
	queue<int> q;
	q.push(0);
	vector<bool> vis(n, false);
	vis[0] = true;

	color[0] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		// printf("here\n");
		for(auto v : adj[u]){
			if(!vis[v]){
				vis[v] = true;
				color[v] = (color[u] + 1) % 2;
				q.push(v);
			}
			else if(color[u] == color[v]){
				return false;
			}
		}

	}
	return true;

}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> edges;
	vector<int> adj[n];
	for(int i = 0; i < m; ++i){
		int a,b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.push_back({a, b});
	}
	vector<int> color(n, 0);


	if(!colorGraph(adj, color, n)){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(auto x : edges){
			if(color[x.first]){
				printf("1");
			}
			else{
				printf("0");
			}
		}
	}

}