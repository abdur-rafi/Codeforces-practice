#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[300000 + 100][8];
int l, r;
int can(int mid, int m, int n) {
	vector<int> v(1 << m, -1);
	for (int j = 0; j < n; ++j) {
		int curr = 0;
		for (int i = 0; i < m; ++i) {
			if (a[j][i] >= mid) curr = curr | (1 << i);
		}
		v[curr] = j;
	}
	if (v[(1 << m) - 1] != -1) {
		l = r = v[(1 << m) - 1];
		return 1;
	}
	for (int i = 0; i < (1 << m); ++i) {
		for (int j = 0; j < (1 << m); ++j) {
			if (v[i] != -1 && v[j] != -1 && (i | j) == ((1 << m) - 1)) {
				l = v[i];
				r = v[j];
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int n, m;
	int mx = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			mx = max(mx, a[i][j]);
		}
	}
	int i = 0;
	int j = mx;
	int mid;
	while (i <= j) {
		mid = (i + j) >> 1;
		if (can(mid, m, n)) i = mid + 1;
		else j = mid - 1;
	}
	printf("%d %d",l+1,r+1);
	return 0;
}