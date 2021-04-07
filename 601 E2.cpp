#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int const MAX = 1000000 + 100;
typedef long long ll;
ll a[MAX];
ll s[MAX];
ll cst(ll m, ll n) {
	ll t = 0;
	for (int i = 1; i <= n; ++i) {
		t += min(s[i] % m, m - (s[i] % m));
	}
	return t;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		s[i] = s[i - 1] + a[i];
	}
	if (s[n] == 1) {
		printf("-1");
		return 0;
	}
	ll mn = 1e18;
	ll c = s[n]; ll t = 2;
	while (t * t <= c) {
		if (c % t == 0) mn = min(mn, cst(t, n));
		while (c % t == 0) c /= t;
		++t;
	}
	if (c > 1) mn = min(mn, cst(c, n));
	printf("%lld", mn);
	return 0;
}