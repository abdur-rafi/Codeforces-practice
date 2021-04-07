#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 200000 + 10;
int a[MAX], b[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < n; ++i) scanf("%d", b + i);
		int s = 1;
		int p = 1;
		int diff = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				s = 0;
				diff = b[i] - a[i];
				int j = 0;
				if (diff < 0) {
					p = 0;
					break;
				}
				for (j = i + 1; j < n; ++j) {
					if (b[j] == a[j]) break;
					if ((b[j] - a[j] != diff) || (diff < 0) ) {
						p = 0;
						break;
					}
				}
				for (; j < n; ++j) {
					if (a[j] != b[j]) {
						p = 0;
						break;
					}
				}
				break;
			}
		}
		if (s || p) printf("YES\n");
		else printf("NO\n");
	}
}