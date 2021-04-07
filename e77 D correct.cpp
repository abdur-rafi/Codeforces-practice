#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int const MAX = 200000 + 10;
pair<int, pair<int, int>> traps[MAX];
int soldier[MAX];
bool segUnion(int k,int t,int n) {
	int n1 = (n - k);
	vector<pair<int, int>> points(2 * n1);
	for (int i = 0; (i+k) < n; ++i) {
		points[2 * i].first = traps[i + k].second.first;
		points[2 * i].second = 0;
		points[2 * i + 1].first = traps[i + k].second.second;
		points[2 * i + 1].second = 1;
	}
	sort(points.begin(), points.end());
	int cnt = 0;
	int res = 0;
	for (unsigned i = 0; i < (2*n1); ++i) {
		if (cnt)
			res += points[i].first - points[i - 1].first;
		(points[i].second) ? ++cnt : --cnt;
	}
//	printf("r:%d\n", res);
	return (2*res <= t);
}
int bs(int k, int t) {
	int i = 0;
	int j = k - 1;
	int mid;
	while (i <= j) {
		mid = (i + j) >> 1;
		if (segUnion(mid, t, k)) j = mid - 1;
		else i = mid + 1;
	}
	int d = j + 1;
	while (d >= 0 && segUnion(d, t, k)) --d;
	return d+1;
}
int main() {
	int m, n, k, t; scanf("%d %d %d %d", &m, &n, &k, &t);
	for (int i = 0; i < m; ++i) {
		scanf("%d", soldier + i);
	}
	for (int i = 0; i < k; ++i) {
		int li, ri, di; scanf("%d %d %d", &li, &ri, &di);
		traps[i].first = di;
		traps[i].second.first = li-1;
		traps[i].second.second = ri;
	}
	sort(traps, traps + k);
/*	for (int i = 0; i < k; ++i) {
		printf("tr1:%d %d %d\n", traps[i].first, traps[i].second.first, traps[i].second.second);
	}*/
	t -= (n + 1);
	int j = 0;
	j = bs(k, t);
	if (j > k) {
		printf("%d\n", 0);
	}
	else if (j <= 1) {
		printf("%d\n", m);
	}
	else {
		int r = 0;
		j = traps[j-1].first;
		for (int i = 0; i < m; ++i) {
			if (soldier[i] >= j) ++r;
		}
		printf("%d\n", r);
	}
/*	for (int i = 0; i < k; ++i) {
		segUnion(i, t, k);
	}*/
}