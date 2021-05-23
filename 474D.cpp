#include <cstdio>

using namespace std;
typedef long long ll;
const int MAX = 100000 + 10;
const int MOD = 1000000007;

ll dp[MAX];
ll sum[MAX];
int main(){
	dp[0] = 1;
	int t, k;
	scanf("%d %d", &t, &k);

	for(int i = 1; i < MAX; ++i){
		if(i < k){
			dp[i] = 1;
		}
		else{
			dp[i] = (dp[i - k] + dp[i - 1]) % MOD;  
		}
	}

	sum[0] = dp[0];
	for(int i = 1; i < MAX; ++i){
		sum[i] = (sum[i-1] + dp[i]) % MOD;
	}
	while(--t>=0){
		int l, r;
		scanf("%d %d", &l, &r);
		ll res = sum[r] - sum[l-1];
		res += MOD;
		res %= MOD;
		printf("%lld\n", res);
	}

}