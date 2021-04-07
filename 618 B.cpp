#include <cstdio>
#include <algorithm>
using namespace std;
int a[200000 + 100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < 2 * n; ++i) scanf("%d", a + i);
		sort(a, a + 2 * n);
		printf("%d\n", a[n] - a[n - 1]);
	}
}