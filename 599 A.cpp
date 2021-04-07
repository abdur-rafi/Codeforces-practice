#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 10;
int a[MAX];

int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		sort(a, a + n, greater<int>());
		int r = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] >= i + 1) r = i + 1;
			else break;
		}
		printf("%d\n", r);
	}
}