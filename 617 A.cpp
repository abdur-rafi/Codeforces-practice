#include <cstdio>
using namespace std;
int a[2000];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int oddc = 0, evenc = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] % 2) oddc++;
			else evenc++;
		}
		if (oddc % 2) {
			printf("YES\n");
		}
		else {
			if (oddc > 0 && evenc > 0) printf("YES\n");
			else printf("NO\n");
		}
	}
}