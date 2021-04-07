#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


class segTree
{
	int* segarr;
	int n;
	int constructTreeUtil(int arr[], int si, int as, int ae);
	int queryUtil(int qs, int qe, int ss, int se, int si);
	void updateUtil(int i, int si, int ss, int se, int val, int arr[]);
public:
	segTree(int arr[], int N);
	void update(int i, int val, int arr[]);
	int query(int as, int ae);
};
segTree::segTree(int arr[], int N)
{
	n = N;
	int x = (int)(ceil(log2(n)));
	int s = 2 * (int)pow(2, x) - 1;
	segarr = new int[s];
	constructTreeUtil(arr, 0, 0, n - 1);
}
int segTree::constructTreeUtil(int arr[], int si, int as, int ae)
{
	if (as == ae)
	{
		segarr[si] = arr[as];
		return arr[as];
	}
	int mid = (as + ae) >> 1;
	int l = constructTreeUtil(arr, 2 * si + 1, as, mid);
	int r = constructTreeUtil(arr, 2 * si + 2, mid + 1, ae);
	int h = max(l, r);
	segarr[si] = h;
	return h;
}
int segTree::query(int qs, int qe)
{
	return queryUtil(qs, qe, 0, n - 1, 0);
}
int segTree::queryUtil(int qs, int qe, int ss, int se, int si)
{
	if (qs <= ss && qe >= se)
		return segarr[si];
	if (se < qs || ss > qe)
		return INT_MIN;
	int m = (ss + se) >> 1;
	int l = queryUtil(qs, qe, ss, m, 2 * si + 1);
	int r = queryUtil(qs, qe, m + 1, se, 2 * si + 2);
	return max(l, r);
}
void segTree::update(int i, int val, int arr[])
{
	return updateUtil(i, 0, 0, n - 1, val, arr);
}
void segTree::updateUtil(int i, int si, int ss, int se, int val, int arr[])
{
	if (ss == se)
	{
		arr[i] = val;
		segarr[si] = val;
		return;
	}
	int mid = (ss + se) >> 1;
	if (ss <= i && i <= mid)
		updateUtil(i, 2 * si + 1, ss, mid, val, arr);
	else
		updateUtil(i, 2 * si + 2, mid + 1, se, val, arr);
	segarr[si] = max(segarr[2 * si + 1], segarr[2 * si + 2]);

}


int const MAX = 200000 + 10;
pair<int, pair<int, int>> traps1[MAX];
pair<int, int> traps2[MAX];
int soldiers[MAX];
map<pair<int, int>, int> mp;
int a[MAX];

int bs(int k, int val) {
	if (val < traps2[0].first) return -1;
	int i = 0;
	int j = k - 1;
	int m;
	while (i <= j) {
		m = (i + j) >> 1;
		if (traps2[m].first > val) j = m - 1;
		else i = m + 1;
	}
	return i - 1;
}


int main() {
	int m, n, k, t; scanf("%d %d %d %d", &m, &n, &k, &t);
	for (int i = 0; i < m; ++i) scanf("%d", soldiers + i);
	for (int i = 0; i < k; ++i) {
		int li, ri, di; scanf("%d %d %d", &li, &ri, &di);
		traps1[i] = { di, {li-1, ri} };
		traps2[i] = { li-1, ri };
	}
	sort(traps1, traps1 + k,greater<pair<int,pair<int,int>>>());
	sort(traps2, traps2 + k);
	for (int i = 0; i < k; ++i) {
		mp[traps2[i]] = i;
	}
	for (int i = 0; i < k; ++i) {
		a[i] = -1;
	}
/*	for (int i = 0; i < k; ++i) {
		printf("tr2:%d %d\n", traps2[i].first, traps2[i].second);
	}
	for (int i = 0; i < k; ++i) {
		printf("tr1:%d %d %d\n", traps1[i].first, traps1[i].second.first,traps1[i].second.second);
	}*/
	segTree stree(a, k);
	t -= (n + 1);
	int i = 0;
	for (i = 0; i < k; ++i) {
	//	printf("%d\n", i);
		int li = traps1[i].second.first;
		int ri = traps1[i].second.second;
		int c = 0;
		for (int j = li; j <= ri;) {
			int i2 = bs(k, j);
		//	printf("j:%d i2b:%d ",j, i2);
			if (i2 != -1) i2 = stree.query(0, i2);
		//	printf("i2a:%d\n", i2);
			if (i2 != -1 && i2 > j)
				j = i2;
			else {
				j++;
				if (j <= ri) ++c;
			}

		}
		c = 2 * (c);
	//	printf("c:%d ", c);  
		if (c <= t) {
			t -= c;
			stree.update(mp[{traps1[i].second.first,traps1[i].second.second}], ri, a);
		//	printf("q:%d %d\n", stree.query(0, mp[traps1[i].second]),mp[traps1[i].second]);
		}
		else break;
	}
	int r = 0;
	i = traps1[i].first;
	for (int j = 0; j < m; ++j) {
		if (soldiers[j] >= i) ++r;
	}
	printf("%d", r);
}