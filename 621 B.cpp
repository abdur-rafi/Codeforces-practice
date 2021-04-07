#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100000 + 10;
ll a[MAX];
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n, x; scanf("%lld %lld", &n, &x);
		for (int i = 0; i < n; ++i) scanf("%lld", a + i);
		set<ll> st;
		for (int i = 0; i < n; ++i) st.insert(a[i]);
		ll cst = 0;
		if (st.find(x) != st.end()) {
			printf("1\n");
			continue;
		}
		sort(a, a + n, greater<ll>());
		ll x2 = x;
		x = x2;
		ll cst2 = 0;
		ll fr = x / a[0];
		cst2 = fr;
		if (fr == 0) cst2 += 2;
		else if(x % a[0]) {
			cst2 = fr + 1;
		}
		printf("%lld\n", cst2);
	}
}