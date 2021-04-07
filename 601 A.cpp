#include <cstdio>
#include <algorithm>
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int a, b; scanf("%d %d", &a, &b);
		int diff = abs(a - b);
		int c = diff / 5;
		int d = diff % 5;
		if (d > 2) c += 2;
		else if (d > 0) c += 1;
		printf("%d\n", c);
	}
}