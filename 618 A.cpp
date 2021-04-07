#include <cstdio>
using namespace std;
int a[110];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		int res = 0;
		int sum = 0;
		int f = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (a[i] == 0) {
				a[i] = 1;
				res++;
			}
			sum += a[i];
			if (a[i] > 0 || a[i] < -1) f = 1;
		}
		if (sum == 0) {
			if (f) ++res;
			else res += 2;
		}
		printf("%d\n", res);
	}
}