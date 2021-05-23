#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200000 + 100;

vector<int> adj[MAX];

vector<int> calculateLevels(vector<int> &parent){

	queue<int> q;
	q.push(0);
	q.push(-1);
	parent[0] = -1;
	vector<int> res;
	int c = 0;
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		if(fr == -1){
			res.push_back(c);
			if(!q.empty())
				q.push(-1);
			c = 0;
		}
		else{
			c++;
			for(auto v:adj[fr]){
				if(v != parent[fr]){
					parent[v] = fr;
					q.push(v);
				}
			}
		}
	}
	return res;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int a,b;
		scanf("%d %d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> parent(n);
	vector<int> levels = calculateLevels(parent);
	// for(auto v:levels) printf("%d\n",v );

	vector<int> prevLavel;
	int a[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
		--a[i];
	}
	if(a[0] != 0){
		printf("No\n");
		return 0;
	}
	int s = 1;
	int currLevel = 1;
	for(int i = 1; i < n; ++i){
		int v = a[i];
		if(prevLavel.empty() || prevLavel.back() != parent[v]){
			prevLavel.push_back(parent[v]);
		}
		if(s + levels[currLevel] == i + 1){
			int k = 0;
			// for(auto p:prevLavel) printf("%d ",p );
			// printf("\n");
			for(int j = s - levels[currLevel - 1]; j < s ; ++j){
				if(prevLavel[k] == a[j]){
					++k;
					if(k == prevLavel.size()) break;
				}
			}
			if(k != prevLavel.size()){
				printf("No\n");
				return 0;
			}
			prevLavel.clear();
			s += levels[currLevel];
			++currLevel;
		}
	}
	printf("Yes\n");
}