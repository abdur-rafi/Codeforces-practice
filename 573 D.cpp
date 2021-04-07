#include <cstdio>
#include <map>
#include <algorithm>
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;
const ll MAX = 100000 + 10;
ll a[MAX];
int main() {
	ll n; scanf("%lld", &n);
	map<ll,ll> mp;
	loop(i, n, 0) {
		scanf("%lld", a + i);
		mp[a[i]]++;
	}
	bool f = false;
	for (auto p : mp) {
		if (p.second > 2) {
			printf("cslnb");
			return 0;
		}
		else if (p.second == 2) {
			if (f) {
				printf("cslnb");
				return 0;
			}
			else {
				if (p.first == 0 || mp[p.first - 1] > 0) {
					printf("cslnb");
					return 0;
				}
				else f = true;
			}
		}
	}
	ll c = 0;
	sort(a, a + n);
	loop(i, n, 0) {
		c += a[i] - i;
	}
	if (c % 2) printf("sjfnb");
	else printf("cslnb");
	return 0;
}