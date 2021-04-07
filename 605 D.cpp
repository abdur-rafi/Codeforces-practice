#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 100;
int a[MAX];
int dpl[MAX];
int dpr[MAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dpl[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			dpl[i] = dpl[i - 1] + 1;
		}
		else {
			dpl[i] = 1;
		}
	}
	dpr[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] < a[i + 1]) {
			dpr[i] = dpr[i + 1] + 1;
		}
		else
			dpr[i] = 1;
	}
	int r = 0;
	for (int i = 0; i < n; ++i) r = max(r, dpl[i]);
	for (int i = 1; i < n - 1; ++i) {
		if (a[i - 1] < a[i + 1]) r = max(r, dpl[i - 1] + dpr[i + 1]);
	}
	printf("%d", r);
}