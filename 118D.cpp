#include <cstdio>
using namespace std;
typedef long long ll;
const int MOD = 100000000;
int dp[110][110][2][11];

ll calc(int n1, int n2, int i, int j, int k1, int k2){
	if(n1 < 0 || n2 < 0 || j < 0) return 0;
	if(dp[n1][n2][i][j] != -1) return dp[n1][n2][i][j];
	if(i == 0){
		if(n2 == 0){
			if(n1 <= k1){
				if(j != n1) return 0;
				return 1;
			}
			else return 0;
		}

		if(j == 1){
			ll res = 0 ;
			for(int k = 1; k <= k2 ;++k){
				res = (res + calc(n1 - 1, n2, 1, k , k1, k2) % MOD) % MOD;
			}
			dp[n1][n2][i][j] = res;
			// printf("%d %d %d %d %d\n",n1,n2,i,j,res );
			return res;
		}
		else{
			dp[n1][n2][i][j] = calc(n1 - 1, n2, 0, j-1, k1, k2);
			return dp[n1][n2][i][j];
		}
	}
	else{
		if(n1 == 0){
			if(n2 <= k2){
				if(j != n2) return 0;
				return 1; 
			}
			return 0;
		}
		if(j == 1){
			ll res = 0 ;
			for(int k = 1; k <= k1 ;++k){
				res = (res + calc(n1, n2 - 1, 0, k , k1, k2) % MOD) % MOD;
			}
			dp[n1][n2][i][j] = res;
			return res;
		}
		else{
			dp[n1][n2][i][j] = calc(n1, n2 - 1, 1, j-1, k1, k2);
			return dp[n1][n2][i][j];
		}
	}

}

int main(){

	int n1, n2, k1, k2;
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	for(int i = 0 ; i<= n1; ++i){
		for(int j = 0; j <= n2; ++j){
			for(int k = 0; k < 2; ++k){
				for(int l = 0; l<= 10; ++l){
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	ll res = 0 ;
	for(int i = 0; i < 2; ++i){
		int to = i == 0 ? k1 : k2;
		for(int j = 1; j <= to; ++j){
			res = (res + calc(n1, n2, i, j , k1, k2)) % MOD;
		}
	}
	printf("%lld\n", res);
	// printf("%lld\n",calc(1, 2, 0, 1, k1, k2 ) );

}