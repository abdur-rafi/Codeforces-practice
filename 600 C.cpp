#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int const MAX = 200000 + 10;
ll a[MAX];
ll dp[MAX];
ll sum[MAX];
int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	sort(a, a + n);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		dp[i] = sum[i+1];
		if (i - m + 1 >= 0) dp[i] -= sum[i - m + 1];
		if (i - m >= 0) {
			dp[i] += 2 * dp[i - m];
		}
		if (i - 2 * m >= 0) {
			dp[i] -= dp[i - 2 * m];
		}
	}
	for (int i = 0; i < n; ++i) printf("%lld ", dp[i]);
}