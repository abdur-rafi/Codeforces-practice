#include <cstdio>
#include <vector>
#include <climits>
#include <string>


using namespace std;
typedef long long ll;
ll dp[2][1010], count[2][1010];
ll n, m ,x, y;

ll calc(ll i, bool flip){
	// printf("%d\n",i );
	if(i > m) return 0;
	if(dp[flip][i] != -1) return dp[flip][i];

	ll mn = INT_MAX;
	ll to = min(i + y, m + 1);
	for(ll j = i + x - 1; j < to ; ++j)
		mn = min(mn, calc(j + 1, !flip) + count[flip][j] - count[flip][i-1]);
	dp[flip][i] = mn;
	return mn; 
}



int main(){
	scanf("%lld %lld %lld %lld", &n , &m, &x, &y);
	// int dp[2][m + 1], count[2][m + 1];
	for(ll i = 0; i <= m; ++i){
		count[0][i] = count[1][i] = 0;
		dp[0][i] = dp[1][i] = -1;
	}
	char inp[n][m + 1];
	for(ll i = 0; i < n; ++i){
		scanf("%s", &inp[i]);
		// printf("%s\n",inp );
	}
	for(ll i = 0; i < m; ++i){
		ll c = 0;
		for(ll j = 0; j < n; ++j){
			if(inp[j][i] == '.')
				++c;
		}
		count[0][i + 1] = c + count[0][i];
		count[1][i + 1] = n - c + count[1][i];
		// printf("%d %d\n",count[0][i+1], count[1][i+1] );
	}

	printf("%lld",min(calc(1, 0),calc(1, 1)));

}