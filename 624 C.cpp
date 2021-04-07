#include <cstdio>
using namespace std;
typedef long long ll;
int a[200000 + 100];
char str[200000 + 100];
ll dr[200000 + 100];
ll fr[26];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; ++i) dr[i] = 0;
		for (int i = 0; i < 26; ++i) fr[i] = 0;
		scanf("%s", str);
		for (int i = 0; i < m; ++i) {
			scanf("%d", a + i);
			dr[a[i] - 1] += 1;
		}
		dr[n - 1] = 1;
		ll curr = 0;
		for (int i = n - 1; i >= 0; --i) {
			curr += dr[i];
			fr[str[i] - 'a'] += curr;
		}
		for (int i = 0; i < 26; ++i) {
			printf("%lld ", fr[i]);
		}
		printf("\n");
	}
}