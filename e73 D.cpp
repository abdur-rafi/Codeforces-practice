#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll const MAX = 300000 + 100;
ll h[MAX];
ll c[MAX];
ll dpsame[MAX], dpinc[MAX], dpinc2[MAX];
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n; scanf("%lld", &n);
		for (ll i = 0; i < n; ++i) {
			scanf("%lld %lld", h + i, c + i);
		}
		dpinc[0] = c[0];
		dpinc2[0] = 2 * c[0];
		dpsame[0] = 0;
		for (ll i = 1; i < n; ++i) {
			if (h[i] == h[i - 1]) {
				dpsame[i] = min(dpsame[i - 1] + c[i - 1], dpinc[i - 1]);
				dpsame[i] = min(dpsame[i], dpinc2[i - 1]);

			}
			else if (h[i] == h[i - 1] + 1) {
				dpsame[i] = min(dpsame[i - 1], dpinc[i - 1] + c[i - 1]);
				dpsame[i] = min(dpsame[i], dpinc2[i - 1]);
			}
			else if (h[i] == h[i - 1] + 2) {
				dpsame[i] = min(dpsame[i - 1], dpinc[i - 1]);
				dpsame[i] = min(dpsame[i], dpinc2[i - 1] + c[i - 1]);
			}
			else {
				dpsame[i] = min(dpsame[i - 1], dpinc[i - 1]);
				dpsame[i] = min(dpsame[i], dpinc2[i - 1]);
			}

			if (h[i] + 1 == h[i - 1]) {
				dpinc[i] = min(dpsame[i - 1] + c[i - 1], dpinc[i - 1]);
				dpinc[i] = min(dpinc[i], dpinc2[i - 1]);
			}
			else if (h[i] == h[i - 1]) {
				dpinc[i] = min(dpsame[i - 1], dpinc[i - 1] + c[i - 1]);
				dpinc[i] = min(dpinc[i], dpinc2[i - 1]);
			}
			else if (h[i] + 1 == h[i - 1] + 2) {
				dpinc[i] = min(dpsame[i - 1], dpinc[i - 1]);
				dpinc[i] = min(dpinc[i], dpinc2[i - 1] + c[i - 1]);
			}
			else {
				dpinc[i] = min(dpsame[i - 1], dpinc[i - 1]);
				dpinc[i] = min(dpinc[i], dpinc2[i - 1]);
			}
			dpinc[i] += c[i];

			if (h[i] + 2 == h[i - 1]) {
				dpinc2[i] = min(dpsame[i - 1] + c[i - 1], dpinc[i - 1]);
				dpinc2[i] = min(dpinc2[i], dpinc2[i - 1]);
			}
			else if (h[i] + 2 == h[i - 1] + 1) {
				dpinc2[i] = min(dpsame[i - 1], dpinc[i - 1] + c[i - 1]);
				dpinc2[i] = min(dpinc2[i], dpinc2[i - 1]);
			}
			else if (h[i] == h[i - 1]) {
				dpinc2[i] = min(dpsame[i - 1], dpinc[i - 1]);
				dpinc2[i] = min(dpinc2[i], dpinc2[i - 1] + c[i - 1]);
			}
			else {
				dpinc2[i] = min(dpinc[i - 1], dpsame[i - 1]);
				dpinc2[i] = min(dpinc2[i - 1], dpinc2[i]);
			}
			dpinc2[i] += 2 * c[i];
		}
		printf("%lld\n", min(dpsame[n - 1], min(dpinc[n - 1], dpinc2[n - 1])));
	}
}