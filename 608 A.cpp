#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, d, e, f;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	ll a1 = a, b1 = b, c1 = c, d1 = d, e1 = e, f1 = f;
	ll res = -1;
	ll fc = 0;
	ll first = min(a1, d1);
	a1 -= first;
	d1 -= first;
	fc += first * e;
	ll second = min(b1, min(c1, d1));
	fc += second * f;
	res = fc;
	fc = 0;
	a1 = a, b1 = b, c1 = c, d1 = d, e1 = e, f1 = f;
	first = 0;
	second = 0;
	second = min(b1, min(c1, d1));
	d1 -= second;
	fc += second * f;
	first = min(a1, d1);
	fc += first * e;
	res = max(res, fc);
	printf("%lld", res);
}