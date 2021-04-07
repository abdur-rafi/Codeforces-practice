#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
typedef long long ll;
ll bs(ll n) {
	ll i = 0, j = 1000000;
	ll m;
	while (i <= j) {
		m = (i + j) >> 1;
		if ((m * (m + 1)) / 2 < n) {
			i = m + 1;
		}
		else j = m - 1;
	}
	return j + 1;
}
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll a, b; scanf("%lld %lld", &a, &b);
		ll diff = abs(a - b);
		if (diff == 0) {
			printf("0\n");
			continue;
		}
		ll n = bs(diff);
		while (((n * (n + 1)) / 2 - diff) % 2 != 0) ++n;
		printf("%lld\n", n);
	}
}