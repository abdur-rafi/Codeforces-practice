#include <cstdio>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int a, b, c, n; scanf("%d %d %d %d", &a, &b, &c, &n);
		int avg = a + b + c + n;
		if (avg % 3) printf("NO\n");
		else {
			avg /= 3;
			int A = avg - a;
			int B = avg - b;
			int C = avg - c;
			if (A >= 0 && B >= 0 && C >= 0) printf("YES\n");
			else printf("NO\n");
		}
	}
}