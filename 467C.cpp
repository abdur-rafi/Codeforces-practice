#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX = 5010;
ll dp[MAX][MAX];
ll m;
ll calc(ll window_array[], int i, int j){
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = max(calc(window_array, i - 1, j), 
		window_array[i] + calc(window_array, i - m, j - 1));
	return dp[i][j];
}

int main(){
	ll n, k;
	scanf("%lld %lld %lld",&n,&m,&k);
	ll a[n];
	for(int i = 0; i < n; ++i){
		scanf("%lld", a + i);
	}
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			dp[i][j] = -1;
		}
	}
	ll window_array[n - m + 1];
	ll s = 0;
	for(int i = 0; i < m; ++i){
		s += a[i];
	}
	window_array[0] = s;

	for(int i = m; i < n; ++i ){
		s -= a[i - m];
		s += a[i];
		window_array[i - m + 1] = s;
	}
	printf("%lld", calc(window_array, n - m, k - 1));


}