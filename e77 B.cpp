#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		ll a, b; scanf("%lld %lld", &a, &b);
		if (a == 0 && b == 0) printf("YES\n");
		else if (a == 0 || b == 0) printf("NO\n");
		else {
			ll d = abs(a - b);
			if (a > b) {
				a -= 2 * d;
				b -= d;
			}
			else {
				a -= d;
				b -= 2 * d;
			}
			if (a == 0) {
				printf("YES\n");
				continue;
			}
			if (a < 0 || a % 3 != 0 )
				printf("NO\n");
			else printf("YES\n");
		}
	}
}