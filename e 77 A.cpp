#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int const MAX = 200000 + 10;
int main() {
	ll n; scanf("%lld", &n);
	for (int i = 0; i < n; ++i) {
		ll c, d;
		scanf("%lld %lld", &c, &d);
		ll per = d / c;
		ll extra = d % c;
		ll res = extra * (per + 1) * (per + 1);
		res += (per) * (per) * (c - extra);
		printf("%lld\n", res);
	}

}