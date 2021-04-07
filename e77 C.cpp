#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main() {
 /*	vector<int> r;
	for (int i = 0; i <= 1000; ++i) {
		if (i % 13 == 0 || i % 15 == 0) r.push_back(i);
	}
	sort(r.begin(), r.end());
	for (auto p : r) {
		if (p % 13 == 0 && p % 15 == 0) printf("a \n");
		else if (p % 13 == 0) printf("%d : 0 \n",p);
		else printf("%d : 1 \n",p);
	}*/
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll r, b, k;
		scanf("%lld %lld %lld", &r, &b, &k);
		ll mx = max(r, b);
		ll mn = min(r, b);
		ll c = mx / mn;
		if (mx % mn == 0) c--;
		ll g = gcd(mx, mn);
		mx /= g;
		mn /= g;
		if (mx % mn > 1) c++;
		if (c >= k) printf("REBEL\n");
		else printf("OBEY\n");
	}
}