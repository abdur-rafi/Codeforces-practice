#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll res = 0;
		ll dig = 1;
		for (ll i = 1; i <= 9; ++i) {
			dig *= 10;
			ll b2 = dig - 1;
			if (b2 <= b) res += a;

		}
		printf("%lld\n", res);
	}
}