#include <cstdio>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int MAX = 200000 + 10;

vector<int> adj[MAX];

set<int> component(int i, bool vis[], vector<int> adj[], int index, int compo[]){
	queue<int> q;
	q.push(i);
	vis[i] = true;
	set<int> s;
	s.insert(i);
	compo[i] = index;
	while(!q.empty()){
		int top = q.front();
		// printf("%d\n",top );
		q.pop();
		for(auto v: adj[top]){
			if(!vis[v]){
				q.push(v);
				s.insert(v);
				vis[v] = true;
				compo[v] = index;
			}
		}
	}
	return s;
}


int main(){
	int n, m;scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a , &b);
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool vis[n] = {false};
	int compo[n];
	vector<set<int>> sets;
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			sets.push_back(component(i, vis, adj,sets.size(), compo));
		}
	}
	// for(auto v: sets){
	// 	for(auto u: v)
	// 		printf("%d  ",u );
	// 	printf("\n");
	// 	for(auto u: v)
	// 		printf("%d  ",compo[u] );
	// 	printf("\n");
	// }

	int res = 0;
	int curr = compo[n - 1];
	int currMn = *sets[curr].begin();
	for(int i = n - 1; i > -1; --i){
		if(compo[i] != curr){
			if(i > currMn){
				int si = compo[i];
				for(auto v : sets[si]){
					compo[v] = curr;
					sets[curr].insert(v);
				}
				currMn = *sets[curr].begin();
				++res;
			}
			else{
				curr = compo[i];
				currMn = *sets[curr].begin();
			}
		}
	}
	printf("%d\n",res );

}

