#include <cstdio>
#include <algorithm>
using namespace std;
int const MAX = 200000 + 10;
int s[MAX];
int e[MAX];
int dps[MAX];
int dpe[MAX];
int main() {
	int n, c; scanf("%d %d", &n, &c);
	for (int i = 0; i < n-1; ++i) scanf("%d", s + i);
	for (int i = 0; i < n-1; ++i) scanf("%d", e + i);
	dps[0] = s[0];
	dpe[0] = e[0] + c;
	for (int i = 1; i < n-1; ++i) {
		dps[i] = min(dps[i - 1], dpe[i - 1]) + s[i];
		dpe[i] = min(dpe[i - 1], dps[i - 1] + c) + e[i];
	}
	printf("0 ");
	for (int i = 0; i < n-1; ++i) printf("%d ", min(dpe[i], dps[i]));
}