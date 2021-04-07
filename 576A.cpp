#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000 + 10];
int main() {
	int n, x, y; scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) {
		int curr = a[i];
		bool day = true;
		for (int j = max(0, i - x); j <= i; ++j) {
			if (a[j] < curr) {
				day = false;
				break;
			}
		}
		for (int j = min(n - 1, i + y); j >= i; --j) {
			if (a[j] < curr) {
				day = false;
				break;
			}
		}
		if (day) {
			printf("%d", i + 1);
			return 0;
		}
	}
}
