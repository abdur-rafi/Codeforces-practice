#include <cstdio>
typedef long long ll;
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n, m; scanf("%lld %lld", &n, &m);
		ll div = (n - m) / (m + 1);
		ll res = (n * (n - 1)) / 2 + n;
		res -= (m + 1 - (n - m) % (m + 1)) * ((div * (div - 1)) / 2);
		res -= ((n - m) % (m + 1)) * ((div * (div + 1)) / 2);
		res -= n - m;
		printf("%lld\n", res);
	}
}