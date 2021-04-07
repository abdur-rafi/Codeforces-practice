#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 400000 + 10;
int a[MAX];

int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int n2 = n / 2;
		if (n2 < 3) {
			printf("0 0 0\n");
			continue;
		}
		int n3 = n2;
		while (n2 > 0 && a[n2 - 1] == a[n3]) {
			n2--;
		}
		set<int> s;
		int g = 0, b = 0, sl = 0;
		for (int i = 0; i < n2; ++i) {
			s.insert(a[i]);
			if (s.size() == 1) ++g;
			else if (s.size() == 2) ++sl;
			else if (sl <= g) {
				++sl;
				while (i+1 < n2 && sl <= g) {
					++i;
					s.insert(a[i]);
					++sl;
				}
				while (i + 1 < n2 && a[i] == a[i + 1]) {
					++i;
					sl++;
				}
			}
			else ++b;
		}
		if (sl == 0 || g == 0 || b == 0 || g >= b) {
			printf("0 0 0\n");
		}
		else {
			printf("%d %d %d\n", g, sl, b);
		}

	}
}