#include <cstdio>
#include <algorithm>
using namespace std;
int dp[2][100][100];
int a[110];
int n, odd, tot;
int fre[110];
int solve(int i,int oddc,int state,int filled) {
	if (dp[state][i][oddc] != -1) return dp[state][i][oddc];
	if (i >= n) return 0;
	if (a[i]) {
		if (state != a[i] % 2) return dp[state][i][oddc] = 1e9;
		return dp[state][i][oddc] = min(1 + solve(i + 1, oddc, !state, filled), solve(i + 1, oddc, state, filled));
	}
	if (state && oddc > 0) {
		return dp[state][i][oddc] = min(1 + solve(i + 1, oddc - 1, 0,filled+1), solve(i + 1, oddc - 1, 1,filled+1));
	}
	else if (state) {
		return dp[state][i][oddc] = 1e9;
	}

	int ev = tot - oddc - filled;
	if (ev <= 0) {
		return dp[0][i][oddc] = 1e9;
	}
	return dp[state][i][oddc] = min(1 + solve(i + 1, oddc, 1,filled+1), solve(i + 1, oddc, 0,filled+1));
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) fre[a[i]] = 1;
	for(int i=1;i<=n;++i)
		if (!fre[i]) {
			tot++;
			if (i % 2) ++odd;
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[0][i][j] = -1;
			dp[1][i][j] = -1;
		}
	}
	printf("%d\n", min(solve(0, odd, 0,0), solve(0, odd, 1,0)));
	
}