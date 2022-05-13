#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;


int dp[410][201];
int arr[201];
int solve(int i, int j, int n){
	if(i == 401) return 10000000;
	if(j == n-1) return abs(i - arr[j]);
	if(dp[i][j] != -1) return dp[i][j];

	dp[i][j] = min(solve(i+1, j, n), solve(i + 1, j + 1, n) + abs(i - arr[j]));
	return dp[i][j];

}

int main(){
	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n; ++i)
			scanf("%d", arr + i);
		sort(arr, arr + n);
		int res = 0;

		for(int i = 0; i <= 400; ++i){
			for(int j = 0; j <= 200; ++j){
				dp[i][j] = -1;
			}
		}

		printf("%d\n",solve(1, 0, n) );

		// printf("%d\n", res);

	}

}