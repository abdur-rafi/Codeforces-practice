#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 100000 + 10;
int h[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		int a[MAX];
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		int res[MAX];
		queue<int> q;
		for (int i = 0; i <= n+1; ++i) {
			h[i] = 0;
			res[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			if (h[a[i]] == 0) {
				res[i] = a[i];
				h[a[i]] = 1;
				q.push(i);
			}
		}
		int p = 1;
		int c = 1;
		for (int i = 0; i < n; ++i) {
			if (res[i] == 0) {
				while (c <= n && h[c] == 1) ++c;
				res[i] = c;
				h[c] = 1;
				if (c > n) {
					p = 0;
					break;
				}
			}
		}
		c = res[0];
		for (int i = 0; i < n; ++i) {
			c = max(c, res[i]);
			if (c != a[i]) {
				p = 0;
				break;
			}
		}
		if (!p) printf("-1\n");
		else {
			for (int i = 0; i < n; ++i) printf("%d ", res[i]);
			printf("\n");
		}
	}
}