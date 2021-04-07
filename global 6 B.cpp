#include <cstdio>
typedef long long ll;
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n; scanf("%lld", &n);
		if (n % 14 < 7 &&  n > 14 && n % 14 != 0) printf("YES\n");
		else printf("NO\n");
	}
}