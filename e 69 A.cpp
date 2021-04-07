#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000 + 100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		sort(a, a + n);
		int res = a[n - 2];
		res = min(res-1, n - 2);
		printf("%d\n", res);
	}
}