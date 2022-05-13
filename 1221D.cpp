#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MX = 1e18;

int main(){
	int t;scanf("%d", &t);
	while(--t>=0){
		int n;scanf("%d", &n);
		ll a[n], b[n];
		for(int i = 0; i < n; ++i)
			scanf("%lld %lld", a + i, b + i);
		ll dp[n][3];
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];
		
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < 3; ++j){
				dp[i][j] = 	MX;
				for(int k = 0; k < 3; ++k){
					if(a[i - 1] + k != a[i] + j){
						dp[i][j] = min(dp[i][j], dp[i-1][k] + j * b[i]);
					} 
				}
			}
		}
		printf("%lld\n",min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));	
	}
}