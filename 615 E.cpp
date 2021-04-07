#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 100;
int a[MAX];
int fre[MAX];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; ++i) {
		scanf("%d", a + i);
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) fre[j] = 0;
		for (int j = 0; j < n; ++j) {
		//	printf("%d\n", a[j * m + i]);
			if (a[j * m + i] % m == (i + 1) % m && a[j * m + i] <= n * m) {
				//	printf("das\n");
				int pos = a[j * m + i] / m;
				if (a[j * m + i] % m == 0) pos--;
				int curr = j;

				if (pos <= curr) fre[curr - pos]++;
				else fre[curr - pos + n]++;
			}
		}
		int mn = 1e9;
		for (int j = 0; j < n; ++j) {
			mn = min(n - fre[j] + j, mn);
		}
		res += mn;
	}
	printf("%d", res);

}