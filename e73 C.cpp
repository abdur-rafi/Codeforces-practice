#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int c, m, x; scanf("%d %d %d", &c, &m, &x);
		int mn = min(c, m);
		c -= mn; m -= mn;
		int p = 0;
		p += min(mn, x);
		mn -= min(x, mn);
		p += min(mn, m);
		mn -= min(mn, m);
		p += min(mn, c);
		mn -= min(mn, c);
		mn *= 2;
		p += mn / 3;
		printf("%d\n", p);

	}
}