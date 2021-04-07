#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int a[3];
		for (int i = 0; i < 3; ++i) scanf("%d", a + i);
		sort(a, a + 3);
		if ((a[0] + a[1]) <= a[2]) {
			printf("%d\n",a[0]+a[1]);

		}
		else {
			int r = 0;
			int diff = a[1] - a[0];
			r += min(a[2], diff);
			int c = a[2];
			a[2] -= min(a[2], diff);
			a[1] -= min(c, diff);
			r += a[2];
			a[1] -= (a[2] / 2) + a[2] % 2;
			a[0] -= (a[2] / 2);
			r += min(a[0], a[1]);
			printf("%d\n", r);
		}
	}
}