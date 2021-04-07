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
const ll MOD = (1e9) + 7;
ll a[1010][1010];

int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[0][i] = n - i;
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = j; k < n; ++k) a[i][j] = (a[i][j] + (k-j+1) * a[i - 1][k]) % MOD;
		}
		
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) res = (res + a[m - 1][i]) % MOD;
	printf("%lld\n", res);
}