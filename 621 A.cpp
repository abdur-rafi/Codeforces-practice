#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000 + 10;
int a[200];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n, d; scanf("%d %d", &n, &d);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int res = 0;
		for (int i = 1; i < n; ++i) {
			int fr = d / (i );
			if (!fr) break;
			res += min(fr, a[i]);
			d -= min(fr, a[i]) * (i);
		}
		res += a[0];
		printf("%d\n", res);
	}
}