#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000 + 10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll n, g, b; scanf("%lld %lld %lld", &n, &g, &b);
		ll n2 = n / 2;
		if (n % 2 == 1) n2++;
		ll fg = n2 / g;
		if (n2 % g) ++fg;
		ll fb = fg - 1;
		ll res = 0;
		res = fg * g + fb * b;
		ll rem = n - n2;
		rem -= min(rem, fb * b);
		if (fg * g - n2 > rem) {
			res -= fg * g - n2 - rem;
			rem = 0;
		}
		else {
			rem -= fg * g - n2;
		}
		res += rem;

		printf("%lld\n", res);
	}
}