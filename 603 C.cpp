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
		set<ll> ans;
		for (ll i = 1; i * i <= n; ++i) {
			ans.insert(n / i);
			ans.insert((n / (n / i)));
		}
		ans.insert(0);
		printf("%d\n", ans.size());
		for (auto p : ans) {
			printf("%d ", p);
		}
		printf("\n");
	}
}