#include <cstdio>
#include <algorithm>

using namespace std;

int dp[5001][5001];
int n, m;
char A[5001], B[5001];

int dp_(int i, int j){
	if(i >= n || j >= m) return 0; 
	if(dp[i][j] != -1) return dp[i][j];
	if(A[i] == B[j]){
		int a = max(dp_(i + 1, j + 1) + 2, dp_(i+1, j) - 1);
		int b = max(dp_(i, j + 1) - 1, 0);
		dp[i][j] = max(a, b);
	}
	else{

		int b = max(dp_(i, j + 1) - 1, 0);
		dp[i][j] = max(b, dp_(i+1, j) - 1);
	}
	return dp[i][j];
}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s %s", A, B);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) dp[i][j] = -1;

	dp_(0, 0);
	int res = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) res = max(res, dp[i][j]);
			// printf("%d ",dp[i][j] );
		// printf("\n");
	}
	printf("%d\n",res );
}