#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
const int MAX = 200000 + 10;

using namespace std;

vector<int> bfs(int start, int n, vector<int> adj[]){
	queue<int> q;
	q.push(start);
	vector<bool> vis(n, false);
	vis[start] = true;
	int level = 0;
	q.push(-1);
	vector<int> odd;
	vector<int> even;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == -1){
			level++;
			if(!q.empty()){
				q.push(-1);
			}
			continue;
		}
		if(level % 2) odd.push_back(u);
		else even.push_back(u);
		
		for(auto v : adj[u]){
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
	}
	if( odd.size() > even.size() ) return even;
	return odd;
}

int main(){

	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> adj[n];
		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u;
			--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		auto v = bfs(0, n, adj);
		printf("%d\n",v.size() );
		for(auto x : v) printf("%d ", x + 1 );
		printf("\n");

	}

}