#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll a[3];
		scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		ll res = 0;
		if (a[0] != a[1] && a[1] != a[2]) {
			a[0]++;
			a[2]--;
			res = abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]);
		}
		else if (a[0] == a[1] && a[1] == a[2]) {
			res = 0;
		}
		else if (a[0] == a[1]) {
			a[0]++;
			a[1]++;
			if (a[2] != a[0]) a[2]--;
			res = abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]);
		}
		else if (a[1] == a[2]) {
			a[1]--;
			a[2]--;
			if (a[1] != a[0]) a[0]++;
			res = abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]);
		}
		printf("%lld\n", res);
	}
}