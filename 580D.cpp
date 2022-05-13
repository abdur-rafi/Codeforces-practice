#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

struct triplet{
	ll a,b,c;
}


void dfs(int u, vector<pair<ll, ll>> adj[]){
	
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	ll s[n];
	for(int i = 0; i < n; ++i) scanf("%lld", s + i);

	triplet rules[k];
	for(int i = 0; i < k; ++i){
		ll a,b, c;scanf("%lld %lld %lld", &a, &b, &c);
		--a; --b;
		rules[i] = {a, b, c};
	}

	ll res = 0;
	ll upto = 1 << n;

	for(int i = 1; i < upto; ++i){

		ll tot = 0;
		vector<int> indices;
		vector<bool> eaten(n, false);

		for(int j = 0; j < n; ++j){
			bool taken = i & (1 << j);
			if(taken){
				tot += s[j];
				indices.push_back(j);
				eaten[j] = true;
			}
		}

		vector<<pair<ll, ll>>> adj[n];
		for(int j = 0; j < k; ++j){
			auto currRule = rules[j];
			if(taken[currRule.a] && taken[currRule.b]){
				adj[currRule.a].push_back({currRule.b, currRule.c});
			}
		}
	}

	printf("%lld\n",res );

}