#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[200000 + 100];
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n; scanf("%lld", &n);
		for (int i = 0; i < n; ++i) scanf("%lld", a + i);
		ll yasser = 0; 
		for (int i = 0; i < n; ++i) yasser += a[i];
		ll pre = 0;
		ll len = 0;
		ll pos = 1;
		int mxlen = 1;
		ll adel = a[0];
		for (int i = 0; i < n; ++i) {
			if (adel < pre + a[i]) {
				adel = pre + a[i];
				mxlen = len + 1;
			}
			if (pre + a[i] <= 0) {
				len = 0;
			}
			else ++len;
			pre = max(pre + a[i],(ll) 0);
		}
		if (adel > yasser) printf("NO\n");
		else if (mxlen < n) printf("NO\n");
		else printf("YES\n");
	}
}