#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll const MAX = 100000;
struct range {
	ll l, r, u, d;
};
ll l, u, r, d;
range robots[MAX + 10];
void range_transform(ll i, ll x,ll y) {
//	printf("asd %lld %lld\n", l, r);
	if (l) robots[i].l = -MAX;
	else robots[i].l = x;
	if (u) robots[i].u = MAX;
	else robots[i].u = y;
	if (r) robots[i].r = MAX;
	else robots[i].r = x;
	if (d) robots[i].d = -MAX;
	else robots[i].d = y;
}
bool intersection(range &a, range &b) {
	if (a.l <= b.l && a.r >= b.r) {
		a.l = b.l; a.r = b.r;
	}
	else if (b.l <= a.l && b.r >= a.r) {
		;
	}
	else if (a.r < b.l) return 0;
	else if (b.r < a.l) return 0;
	else {
		a.l = max(a.l, b.l);
		a.r = min(a.r, b.r);
	}
	if (a.u >= b.u && a.d <= b.d) {
		a.u = b.u; a.d = b.d;
	}
	else if (b.u >= a.u && b.d <= a.d) {
		;
	}
	else if (a.d > b.u) return 0;
	else if (b.d > a.u) return 0;
	else {
		a.u = min(a.u, b.u);
		a.d = max(a.d, b.d);
	}
	return 1;
}
int main() {
	ll q; scanf("%lld", &q);
	while (--q >= 0) {
		ll n; scanf("%lld", &n);
		for (ll i = 0; i < n; ++i) {
			ll x, y;
			scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &l, &u, &r, &d);
			range_transform(i, x, y);
		}
	/*	for (int i = 0; i < n; ++i) {
			printf("%lld %lld %lld %lld\n", robots[i].l, robots[i].r, robots[i].u, robots[i].d);
		}*/
		range curr = robots[0];
		bool f = true;
		for (ll i = 1; i < n; ++i) {
			if (!intersection(curr, robots[i])) {
				printf("0\n");
				f = false;
				break;
			}
		}
		if(f) printf("1 %lld %lld\n", (curr.l + curr.r) / 2, (curr.u + curr.d) / 2);
	}
	return 0;
}
