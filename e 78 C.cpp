#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int a[MAX];
int lred[MAX];
int lblue[MAX];
int rred[MAX];
int rblue[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < 2*n; ++i) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < 2* n; ++i) {
			lred[i] = 0;
			lblue[i] = 0;
		}
		for (int i = 0; i < 2 * n; ++i) {
			rred[i] = 0;
			rblue[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				lred[i] = 1;
			}
			else lblue[i] = 1;
		}
		for (int i = n; i < 2 * n; ++i) {
			if (a[i] == 1) {
				rred[i] = 1;
			}
			else rblue[i] = 1;

		}
		for (int i = 1; i < n; ++i) {
			lred[i] += lred[i - 1];
			lblue[i] += lblue[i - 1];
		}
		for (int i = n + 1; i < 2 * n; ++i) {
			rred[i] += rred[i - 1];
			rblue[i] += rblue[i - 1];
		}
		int res = 1e9;
		if (lred[n - 1] + rred[2 * n - 1] == lblue[n - 1] + rblue[2 * n - 1]) {
			printf("%d\n", 0);
			continue;
		}
		map<int, int> left;
		left[0] = 1;
		for (int i = 0; i < n; ++i) {
			int diff = lred[i] - lblue[i];
			left[diff] = i+2;
		}
		for (int i = n; i < 2 * n; ++i) {
			int red = 0;
			int blue = 0;
			red = rred[2 * n - 1] - rred[i];
			blue = rblue[2 * n - 1] - rblue[i];
			int k = left[blue - red];
			if (k != 0) {
				res = min(res, (n +1 - k) + i + 1 - n);
			}
		}
		
		map<int, int> right;
		for (int i = n; i < 2 * n; ++i) {
			int red = rred[2 * n - 1] - rred[i];
			int blue = rblue[2 * n - 1] - rblue[i];
			if (right[red - blue] == 0) {
				right[red - blue] = i + 1;
			}
		}
		right[rred[2 * n - 1] - rblue[2 * n - 1]] = n;
		if (right[0] == 0) {
			right[0] = 2 * n;
		}
		for (int i = n - 1; i >= 0; --i) {
			int red = 0;
			if (i > 0) red = lred[i - 1];
			int blue = 0;
			if (i > 0) blue = lblue[i - 1];
			int k = right[blue - red];
			if (k != 0) {
				res = min(res, (n - i) + k - n );
			}
		}
		printf("%d\n", res);
	}
}