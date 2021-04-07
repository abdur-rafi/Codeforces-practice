#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
pair<int, int> a[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int c; scanf("%d", &c);
			a[i].first = c;
			a[i].second = i;
		}
		sort(a, a + n);
		vector<int> r;
		int mn = 1e9;
		int mx = -1;
		for (int i = 0; i < n; ++i) {
			mn = min(mn, a[i].second);
			mx = max(mx, a[i].second);
			if (mx - mn == i) r.push_back(1);
			else r.push_back(0);
		}
		for (auto p : r) printf("%d", p);
		printf("\n");
	}
}