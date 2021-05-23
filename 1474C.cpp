#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
const int MAX = 1001;
int isTaken[ 2 * MAX];
pair<int,int> a[2 * MAX];
const int MAX2 = 1000000 + 10;
vector<vector<int>> adj(MAX2);
vector<pair<int,int>> res;
int n;

bool solve(int k, vector<vector<int>> &adj){
	res.clear();
	isTaken[0] = true;
	isTaken[k] = true;
	res.push_back({a[0].first,a[k].first});
	int mx = a[0].first;
	int x = mx;
	for(int i = 1; i < 2 * n; ++i){
		if(isTaken[i]){
			continue;
		}
		int curr = a[i].first;
		int rem = x - curr;
		if(rem < 1){
			return false;
			
		}
		else{
			while(adj[rem].size() && (isTaken[adj[rem].back()] || adj[rem].back() == i)){
				adj[rem].pop_back();
			}
			if(adj[rem].size() == 0){
				return false;
				
			}
			int index = adj[rem].back();
			adj[rem].pop_back();
			isTaken[index] = true;
			isTaken[i] = true;
			res.push_back({a[i].first , a[index].first});
			x = max(a[i].first, a[index].first);
		}
	}
	return true;
}

int main(){
	int t;scanf("%d",&t);
	while(--t>=0){
		scanf("%d",&n);
		for(int i = 0 ; i < 2*n ; ++i){
			int c;
			scanf("%d",&c);
			a[i] = {c , i} ;

		}
		sort(a, a + 2 * n);
		reverse(a , a + 2 * n);

		
		int mx = a[0].first;
		if(adj[mx].size() > 2){
			printf("NO\n");
			for(int i = 0 ; i < 2 * n; ++i){
				adj[a[i].first].clear();
			}
			continue;
		}
		bool solved = false;
		int x = 0;
		for(int i = 1 ; i < 2 * n; ++i){

			for(int j = 0 ; j < 2 * n; ++j){
				adj[a[j].first].push_back(j);
				isTaken[j] = false;
			}

			if(solve(i,adj)){
				x = a[0].first + a[i].first;
				solved = true;
				break;
			}
		}
		if(!solved){
			printf("NO\n");
			for(int i = 0 ; i < 2 * n; ++i){
				adj[a[i].first].clear();
			}
			continue;
		}
		
		printf("YES\n");
		printf("%d\n",x );
		for(auto v : res){
			printf("%d %d\n",v.first , v.second );
		}

		for(int i = 0 ; i < 2 * n; ++i){
			adj[a[i].first].clear();
		}
		
	}
}