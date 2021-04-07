#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class segTree{
	int* segarr;
	int n;
	int* lazy;
	int constructTreeUtil(int arr[], int si, int as, int ae);
	int queryUtil(int qs, int qe, int ss, int se, int si);
	void updateUtil(int i, int si, int ss, int se, int val, int arr[]);
	void updateRangeUtil(int l, int r, int inc, int si, int ss, int se);
public:
	segTree(int arr[], int N);
	void update(int i, int val, int arr[]);
	int query(int as, int ae);
	void updateRange(int l, int r, int inc);
};
segTree::segTree(int arr[], int N){
	n = N;
	int x = (int)(ceil(log2(n)));
	int s = 2 * (int)pow(2, x) - 1;
	segarr = new int[s];
	lazy = new int[s];
	for (int i = 0; i < s; ++i) {
		lazy[i] = segarr[i] = 0;
	}
	constructTreeUtil(arr, 0, 0, n - 1);
}
int segTree::constructTreeUtil(int arr[], int si, int as, int ae){
	if (as == ae){
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
int segTree::query(int qs, int qe){
	return queryUtil(qs, qe, 0, n - 1, 0);
}
int segTree::queryUtil(int qs, int qe, int ss, int se, int si){
	if (lazy[si] != 0) {
		segarr[si] += lazy[si];
		if (ss != se) {
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (qs <= ss && qe >= se)
		return segarr[si];
	if (se < qs || ss > qe)
		return INT_MAX;
	int m = (ss + se) >> 1;
	int l = queryUtil(qs, qe, ss, m, 2 * si + 1);
	int r = queryUtil(qs, qe, m + 1, se, 2 * si + 2);
	return min(l, r);
}
void segTree::update(int i, int val, int arr[]){
	return updateUtil(i, 0, 0, n - 1, val, arr);
}
void segTree::updateUtil(int i, int si, int ss, int se, int val, int arr[]){
	if (ss == se){
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
void segTree::updateRange(int l, int r, int inc) {
	updateRangeUtil(l, r, inc, 0, 0, n - 1);
}
void segTree::updateRangeUtil(int l, int r, int inc, int si, int ss, int se) {
	if (lazy[si] != 0) {
		segarr[si] += lazy[si];
		if (se != ss) {
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (l > se || r < ss) return;
	if (l <= ss && r >= se) {
		segarr[si] += inc;
		if (ss != se) {
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}
		return;
	}
	int mid = (ss + se) >> 1;
	updateRangeUtil(l, r, inc, 2 * si + 1, ss, mid);
	updateRangeUtil(l, r, inc, 2 * si + 2, mid + 1, se);
	segarr[si] = min(segarr[2 * si + 1], segarr[2 * si + 2]);

}
int main() {
	int a[6] = { 2,3,-1,6,-2,3 };
	segTree s(a, 6);
	s.updateRange(0, 0, -10);
	cout << s.query(3, 5);
}