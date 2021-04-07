#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
int const MAX = 200000 + 10;
int pre[MAX], mid[MAX], last[MAX];
int pre_fre[MAX], mid_fre[MAX], last_fre[MAX];
int precal[MAX];
pair<int, int> a[MAX];

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
	int h = min(l, r);
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
		return INT_MAX;
	int m = (ss + se) >> 1;
	int l = queryUtil(qs, qe, ss, m, 2 * si + 1);
	int r = queryUtil(qs, qe, m + 1, se, 2 * si + 2);
	return min(l, r);
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
	segarr[si] = min(segarr[2 * si + 1], segarr[2 * si + 2]);

}

int bs(pair<int, int> a[], int n, int val) {
	int i = 0;
	int j = n - 1;
	int m;
	while (i <= j) {
		m = (i + j) >> 1;
		if (a[m].first > val)j = m - 1;
		else i = m + 1;
	}
	return a[i-1].second;
}
int main() {
	int n1, n2, n3; scanf("%d %d %d", &n1, &n2, &n3);
	int n = n1 + n2 + n3;
	for (int i = 0; i < n1; ++i) {
		scanf("%d", pre + i);
		pre_fre[pre[i]]++;
	}
	for (int i = 0; i < n2; ++i) {
		scanf("%d", mid + i); mid_fre[mid[i]]++;
	}
	for (int i = 0; i < n3; ++i) {
		scanf("%d", last + i); last_fre[last[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		pre_fre[i] += pre_fre[i - 1];
		mid_fre[i] += mid_fre[i - 1];
		last_fre[i] += last_fre[i - 1];
	} 
//	for (int i = 1; i <= n; ++i) printf("%d ", mid_fre[i]);
	for (int i = 0; i <= n; ++i) {
		precal[i] = last_fre[i] + mid_fre[n] - mid_fre[i];
	}
	for (int i = 0; i <= n; ++i) {
		a[i].first = precal[i];
		a[i].second = i;
	}
	sort(a, a + n + 1);
	segTree stree(precal, n+1);
	int res = INT_MAX;
	for (int i = 0; i <= n; ++i) {
		int cost = stree.query(i, n);
		int m = bs(a, n + 1, cost);
		cost += mid_fre[i] + pre_fre[n] - pre_fre[i];
		res = min(res, cost);
	}
	printf("%d\n", res);
	//for (int i = 0; i <= n; ++i) printf("%d %d\n", precal[i],i);
}