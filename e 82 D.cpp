#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
map<ll, ll> power;
ll fre[50];
ll a[100000 + 100];
ll up(ll p, ll inc) {
	ll i = p + 1;
	while (i <= 35) {
		if (fre[i]) {
			if (inc) {
				fre[i] -= 1;
				i--;
				while (i >= p) {
					fre[i]++;
					--i;
				}
				return 0;
			}
			return i - p;
		}
		i++;
	}
	return 0;
}
ll down(ll p,bool cut) {
	ll i = p - 1;
	ll c = 2;
	while (i >= 0) {
		if (fre[i] >= c) {
			if (cut) fre[i] -= c;
			return 1;
		}
		else {
			c -= fre[i];
			c *= 2;
			if(cut) fre[i] = 0;
		}
		--i;
	}
	return 0;
}
int main() {
	ll p = 0;
	power[1] = 0;
	ll b = 1;
	while (p <= 35) {
		b *= 2;
		p++;
		power[b] = p;
	}
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		for (int i = 0; i < 50; ++i) fre[i] = 0;
		ll m, n; scanf("%lld %lld", &m, &n);
		for (int i = 0; i < n; ++i) scanf("%lld", a + i);
		for (int i = 0; i < n; ++i) {
			fre[power[a[i]]]++;
		}
		ll res = 0, b = 1, p = 0, pos = 1;
		while (p < 35) {
			b *= 2;
			p++;
		}
		vector<ll> s;
		while (m) {
			if (b <= m) {
				m -= b;
				s.push_back(p);
			}
			else {
				b /= 2;
				--p;
			}
			
		}
		reverse(s.begin(), s.end());

		for(auto p : s) {
			if (fre[p])  fre[p]--;
			else if (down(p, 0)) down(p, 1);
			else {
				ll k = up(p, 0);
				res += k;
				if (k) up(p, 1);
				else {
					pos = 0;
					break;
				}
			}
		}
			
		
		if (!pos) res = -1;
		printf("%lld\n", res);
	}
}