#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define loop(x,n,a) for(int x =a; x < n;++x)
using namespace std;
const int MAX = 200000 + 10;
int a[200];
int p[200];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int m, n; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < m; ++i) scanf("%d", p + i);
		for (int i = 0; i < m; ++i) --p[i];
		sort(p, p + m);
		int b = p[0];
		int e = p[0];
		for (int i = 1; i < m; ++i) {
			if (p[i] == p[i - 1] + 1) {
				e++;
			}
			else {
				sort(a + b, a + e + 2);
				b = p[i];
				e = p[i];
			}
		}
		sort(a + b, a + e + 2);
		
		bool pos = 1;
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) {
				pos = 0;
				break;
			}

		}
		if (pos) printf("YES\n");
		else printf("NO\n");

	}
}