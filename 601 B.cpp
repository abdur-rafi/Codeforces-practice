#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 200000 + 10;
pair<int,int> a[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i].first);
			a[i].second = i+1;
		}
		if (m < n || n == 2) {
			printf("-1\n");
			continue;
		}
		int c = 0;
		sort(a, a + n);
		for (int i = 1; i < n; ++i) {
			c += a[i].first + a[i - 1].first;
		}
		c += a[0].first + a[n - 1].first;
		printf("%d\n", c);
		for (int i = 1; i < n; ++i) {
			printf("%d %d\n", a[i].second, a[i - 1].second);
		}
		printf("%d %d\n", a[n - 1].second, a[0].second);

		
	}
}