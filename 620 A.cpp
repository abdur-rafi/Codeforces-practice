#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll x, y, a, b; scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if ((y - x) % (a + b) == 0) {
			printf("%lld\n", (y - x) / (a + b));
		}
		else printf("-1\n");
	}
}