#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int a[100000 + 100];
int  Or[100000 + 100];
int revor[100000 + 100];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		Or[i] = Or[i - 1] | a[i-1];
	}
	for (int i = n; i > 0; --i) {
		revor[i] = revor[i + 1] | a[i - 1];
	}
	int res = 0;
	int pr = -1;
	for (int i = 0; i < n; ++i) {
		int k = a[i];
		k |= (Or[i] | revor[i + 2]);
		k -= (Or[i] | revor[i + 2]);
		if (k > res) {
			res = k;
			pr = a[i];
		}
	}
	if (pr != -1) printf("%d ", pr);
	for (int i = 0; i < n; ++i) {
		if (a[i] == pr) {
			pr = -1;
			continue;
		}
		printf("%d ", a[i]);
	}
}