#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	ll adj[n][n];
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n; ++j){
			scanf("%lld", &adj[i][j]);
		}
	}
	int order[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", order+i);

	reverse(order, order + n);

	ll result[n];

	for(int k = 0; k < n;++k){
		int mid = order[k] - 1;
		for(int i = 0; i < n;++i){
			for(int j = 0; j < n;++j){
				adj[i][j] = min(adj[i][j], adj[i][mid] + adj[mid][j] ); 
			}
		}
		ll res = 0; 
		for(int i = 0; i <= k; ++i){
			for(int j = 0; j <= k; ++j){
				res += adj[order[i] - 1][order[j] - 1];
			}
		}
		result[k] = res;
	}

	reverse(result, result + n);
	for(int i = 0; i < n;++i)
		printf("%lld ",result[i] );



	return 0;
}
