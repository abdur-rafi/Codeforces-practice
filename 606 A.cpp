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
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n; scanf("%lld", &n);
		ll c = 0;
		for (ll i = 1; i < 10; ++i) {
			ll n2 = i;
			while (n2 <= n) {
				++c;
				n2 = n2 * 10 + i;
			}
		}
		printf("%lld\n", c);
	}

}