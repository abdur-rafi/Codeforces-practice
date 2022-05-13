#include <cstdio>
#include <vector>
#include <utility>


using namespace std;


typedef pair<int, int> pii;

int mn = 1;


pii dfs(int u, int p, vector<int> adj[]){
	bool leaf = true;
	pii prevOe = {0, 0};
	for(auto v : adj[u]){
		if(v != p){
			leaf = false;
			pii currOe = dfs(v, u, adj);
			if((prevOe.first && currOe.second) || (prevOe.second && currOe.first)){
				mn = 3;
			}
			prevOe.first = prevOe.first || currOe.first;
			prevOe.second = prevOe.second || currOe.second;
		}
	}
	if(leaf)
		return {0,1};
	return {prevOe.second, prevOe.first};

}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> adj[n];

	for(int i = 0; i < n - 1; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int root = 0;

	int mx = n - 1;
	for(int i = 0; i < n ; ++i){
		if(adj[i].size() > 1) root = i;
		int leafCount = 0;
		for(auto v : adj[i]){
			if(adj[v].size() == 1) ++leafCount;
		}
		if(leafCount > 1) mx -= leafCount - 1;
	}

	dfs(root, -1, adj);
	printf("%d %d\n",mn, mx );
	// printf("%d\n",mx );



}