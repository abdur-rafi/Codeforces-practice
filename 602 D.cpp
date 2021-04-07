#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
const int MAX = 200000 + 10;
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return (a.second > b.second);
	return (a.first < b.first);
}
pair<int, int> a[MAX];
pair<int, int> b[MAX];
vector<int> seg[3 * MAX];

void createTree(int ci, int as, int ae) {
	if (as == ae) {
		seg[ci].push_back(b[ae].second);
		return;
	}
	int mid = (as + ae) >> 1;
	createTree(2 * ci + 1, as, mid);
	createTree(2 * ci + 2, mid + 1, ae);
	merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(),back_inserter(seg[ci]));
}
int query(int ci, int l, int r, int k, int cs, int ce) {
	if (cs == ce) return seg[ci][0];
	int p = upper_bound(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), r) - lower_bound(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), l);
	int mid = (cs + ce) >> 1;
	if (p >= k) {
		return query(2 * ci + 1, l, r, k, cs, mid);
	}
	return query(2 * ci + 2, l, r, k-p, mid + 1, ce);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	int m; scanf("%d", &m);
	sort(a, a + n, comp);
	for (int i = 0; i < n; ++i) {
		b[i].first = a[i].second;
		b[i].second = i;
	}
	sort(b, b + n);
	createTree(0, 0, n - 1);
	for (int i = 0; i < m; ++i) {
		int k, p;
		scanf("%d %d", &k, &p);
		int v = 0;
		v = query(0, n - k, n - 1, p, 0, n - 1);
		printf("%d\n", a[b[v].first].first);
	}
}
