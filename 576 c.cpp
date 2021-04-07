#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[400000 + 100];
ll b[400000 + 100];
int main() {
	ll n, I; scanf("%lld %lld", &n, &I);
	map<ll, ll> mp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		mp[a[i]] += 1;
	}
	int i = 0;
	for (auto p : mp) {
		b[i++] = p.second;
	}
	ll N = n;
	n = mp.size();
	a[0] = b[0];
	for (int i = 1; i < n; ++i) {
		a[i] = b[i];
		a[i] += a[i - 1];
	}
	int p =(I * 8) / N;
	ll k = 1;
	for (int i = 1; i <= p; ++i) {
		k *= 2;
		if (k > n) break;
	}
	k = min(k, n);
	ll res = 1e15;
	for (int i = 0; i + k - 1 < n; ++i) {
		ll res2 = 0;
		if (i > 0) res2 += a[i - 1];
		res2 += a[n - 1] - a[i + k - 1];
		res = min(res, res2);
	}
	printf("%lld", res);
}