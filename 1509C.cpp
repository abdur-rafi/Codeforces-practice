#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[2001];
ll dp[2001][2001];

ll solve(int i, int j){
	if(i == j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = min(solve(i + 1, j), solve(i, j-1)) + arr[j] - arr[i];
	return dp[i][j];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n; ++i)
		scanf("%lld", arr + i);

	sort(arr, arr + n);

	for(int i = 0; i <= 2000;++i){
		for(int j = 0; j <= 2000; ++j){
			dp[i][j] = -1;
		}
	}

	ll res = solve(0, n - 1);
	printf("%lld\n",res );

}