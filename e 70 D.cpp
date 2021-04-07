#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000 + 10;
char str[MAX];
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		ll n; scanf("%lld", &n);
		ll i = 2;
		while ((i * (i + 1)) / 2 <= n) ++i;
		ll c3 = i;
		ll c1 = n - (i * (i - 1)) / 2;
		int j = 0;
		str[j++] = '1';
		for (i = 0; i < c3 - 2; ++i) {
			str[j++] = '3';
		}
		for (i = 0; i < c1; ++i) str[j++] = '1';
		str[j++] = '3';
		str[j++] = '3';
		str[j++] = '7';
		str[j] = '\0';
		printf("%s\n", str);
	}
}