#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
long long const MAX = 100000 + 10;
long long dp[MAX];
pair<long long, long long> antenna[100];

int main() {
	long long n, m; scanf("%lld %lld", &n, &m);
	for (long long i = 0; i < n; ++i) {
		long long a, b; scanf("%lld %lld", &a, &b);
		antenna[i] = { a,b };
	}
	sort(antenna, antenna + n);
	for (long long i = 0; i <= m; ++i) dp[i] = 1e18;
	dp[0] = 0;
	for (long long j = 0; j < n; ++j) {
		long long to = 2 * antenna[j].first - 1;
		to = min(to, m);
		long long c = antenna[j].first - antenna[j].second - 1;
		c = max((long long)0, c);
		for (long long k = 1; k <= to; ++k) dp[k] = min(dp[k], c);
	}
	for (long long i = 1; i <= m; ++i) {
		bool p = 0;
		for (int k = 0; k < n; ++k) {
			if (i <= antenna[k].first + antenna[k].second && i >= antenna[k].first - antenna[k].second) {
				p = true;
				break;
			}
		}
		if (p) {
			dp[i] = min(dp[i], dp[i - 1]);
			continue;
		}
		for (long long j = 0; j < n; ++j) {
			if (antenna[j].first > i) break;
			if ((antenna[j].first + antenna[j].second) >= i) {
				if ((antenna[j].first - antenna[j].second - 1) >= 0) {
					dp[i] = min(dp[i], dp[(antenna[j].first - antenna[j].second - 1)]);
				}
				else dp[i] = 0;
			}
			else {
				long long diff = i - antenna[j].first;
				diff -= antenna[j].second;
				if ((antenna[j].first - antenna[j].second - diff - 1) >= 0) {
					dp[i] = min(dp[i], dp[(antenna[j].first - antenna[j].second - diff - 1)] + diff);
				}
				else dp[i] = min(dp[i], diff);
			}
		}
		
	}
	printf("%lld", dp[m]);
}