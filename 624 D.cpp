#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		int res = 1e9;
		int curr = 0;
		for (int i = 1;; i++) {
			curr = 0;
			int s = a * i;
			curr += abs(s - b);
			if (s >= 2 * max(b,c)) break;
			int fr = c / s;
			curr += min(abs(c - fr * s), abs(c - (fr + 1) * s));
			res = min(curr, res);
		}
		curr = 0;
		int fr = c / b;
		int bmn = min(abs(c - fr * b), abs(c - (fr + 1) * b));
		for (int i = 1; i <= b; ++i) {

			if (b % i == 0) {
				curr = 0;
				curr += abs(a - i);
				curr += bmn;
				res = min(res, bmn);
			}
		}

	}
}