#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int const MAX = 100000 + 10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		pair<int, int> a[MAX];
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
		int lft = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (a[i].second < lft) lft = a[i].second;
		}
		int right = INT_MIN;
		for (int i = 0; i < n; ++i) {
			if (a[i].first > right) right = a[i].first;
		}
		int z = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i].first <= lft && a[i].second >= right) {
				;
			}
			else {
				z = 0;
				break;
			}
		}
		if (z) printf("0\n");
		else printf("%d\n", right -lft);
	}
}