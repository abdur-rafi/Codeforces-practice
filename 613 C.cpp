#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 200000 + 10;
typedef long long ll;
ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
int main() {
	ll x; scanf("%lld", &x);
	ll y = sqrt(x) + 1;
	for (ll i = y; i >= 1; --i) {
		if (x % i == 0 && gcd(i, x / i) == 1) {
			printf("%lld %lld", i, x / i);
			break;
		}
	}
}