#include <cstdio>;
using namespace std;
const int MAX = 200000 + 10;
int a[MAX];
int m[MAX];
int loopCount(int a[], int b, int m[], int curr, int c) {
	if (b == curr) return c;
	m[curr] = loopCount(a, b, m, a[curr], c + 1);
	return m[curr];
}
int main() {
	int q;
	scanf("%d", &q);
	while (--q >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < n; ++i) m[i] = -1;
		for (int i = 0; i < n; ++i) --a[i];
		for (int i = 0; i < n; ++i) {
			if (m[i] == -1) {
				m[i] = loopCount(a, i, m, a[i], 1);
			}
		}
		for (int i = 0; i < n; ++i) printf("%d ", m[i]);
		printf("\n");

	}
}