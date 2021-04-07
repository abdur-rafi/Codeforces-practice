#include <cstdio>
#include <algorithm>
using namespace std;
int a[1100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n, s, k; scanf("%d %d %d", &n, &s, &k);
		int res = n+1;
		for (int i = 0; i < k; ++i) scanf("%d", a + i);
		int f = 0;
		sort(a, a + k);
		for (int i = 0; i < k; ++i) {
			if (a[i] == s) {
				f = i + 1;
				break;
			}
		}
		if (!f) {
			printf("0\n");
			continue;
		}
		int i = f - 1;
		while (i > 0 && a[i] == a[i - 1] + 1) {
			--i;
		}

		if(a[i] > 1) res = abs(s - a[i] + 1);
		i = f - 1;
		while (i + 1 < k && a[i + 1] == a[i] + 1) ++i;
		if (a[i] < n) res = min(res, abs(s - a[i] - 1));
		printf("%d\n", res);
	}
}