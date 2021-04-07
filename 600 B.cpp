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
int sum[MAX];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	vector<int> res;
	for (int i = 1; i <= n; ++i) {
		sum[i] = a[i - 1] + sum[i - 1];
	}
	int b = 1;
	for (int i = 1; i <= n; ++i) {
		if (sum[i] == 0) {
			map<int, int> pos, neg;
			int d = 1;
			int e = 1;
			for (int j = b; j <= i; ++j) {
				if (a[j - 1] < 0) {
					neg[-a[j - 1]]++;
					if ((neg[-a[j - 1]] > 1) || (pos[-a[j-1]] < neg[-a[j-1]])) {
						e = 0;
						break;
					}
				}
				else {
					pos[a[j - 1]]++;
					if (pos[a[j - 1]] > 1) {
						e = 0;
						break;
					}
				}
			}
			if (!e) break;
			res.push_back(i - b + 1);
			b = i + 1;
			
		}
	}
	int sum2 = 0;
	for (auto p : res) sum2 += p;
	if (sum2 != n) printf("-1\n");
	else {
		printf("%d\n", res.size());
		for (auto p : res) {
			printf("%d ", p);
		}
	}
}