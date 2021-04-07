#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[400000 + 100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
		}
		ll mx = 0, mn = 1e9;
		a[n + 1] = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != -1) {
				if (a[i - 1] == -1 || a[i + 1] == -1) {
					mx = max(mx, a[i]);
					mn = min(mn, a[i]);
				}
			}
		}
		ll d = (mx + mn) / 2;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == -1) a[i] = d;
		}
		ll res = 0;
		for (int i = 2; i <= n; ++i) {
			res = max(res, abs(a[i] - a[i - 1]));
		}
		printf("%lld %lld\n", res, d);
	}
}