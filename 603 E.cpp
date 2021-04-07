#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int const MAX = 1000000 + 10;

class segTree {
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
segTree::segTree(int arr[], int N) {
	n = N;
	int x = (int)(ceil(log2(n)));
	int s = 2 * (int)pow(2, x) - 1;
	segarr = new int[s];
	lazy = new int[s];
	for (int i = 0; i < s; ++i) {
		lazy[i] = 0;
		segarr[i] = 0;
	}
	constructTreeUtil(arr, 0, 0, n - 1);
}
int segTree::constructTreeUtil(int arr[], int si, int as, int ae) {
	return 1;
}
int segTree::query(int qs, int qe) {
	return queryUtil(qs, qe, 0, n - 1, 0);
}
int segTree::queryUtil(int qs, int qe, int ss, int se, int si) {
	if (lazy[si] != 0) {
		segarr[si] += lazy[si];
		if (ss != se) {
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss >= qs && se <= qe)
		return segarr[si];
	if (ss > se || ss > qe || se < qs)
		return INT_MIN;
	int m = (ss + se) >> 1;
	int l = queryUtil(qs, qe, ss, m, 2 * si + 1);
	int r = queryUtil(qs, qe, m + 1, se, 2 * si + 2);
	return max(l, r);
}
void segTree::update(int i, int val, int arr[]) {
	return updateUtil(i, 0, 0, n - 1, val, arr);
}
void segTree::updateUtil(int i, int si, int ss, int se, int val, int arr[]) {
	if (ss == se) {
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
			lazy[si * 2 + 1] += inc;
			lazy[si * 2 + 2] += inc;
		}
		return;
	}
	int mid = (ss + se) >> 1;
	updateRangeUtil(l, r, inc, 2 * si + 1, ss, mid);
	updateRangeUtil(l, r, inc, 2 * si + 2, mid + 1, se);
	segarr[si] = max(segarr[2 * si + 1], segarr[2 * si + 2]);

}

class minsegTree {
	int* segarr;
	int n;
	int* lazy;
	int constructTreeUtil(int arr[], int si, int as, int ae);
	int queryUtil(int qs, int qe, int ss, int se, int si);
	void updateUtil(int i, int si, int ss, int se, int val, int arr[]);
	void updateRangeUtil(int l, int r, int inc, int si, int ss, int se);
public:
	minsegTree(int arr[], int N);
	void update(int i, int val, int arr[]);
	int query(int as, int ae);
	void updateRange(int l, int r, int inc);
};
minsegTree::minsegTree(int arr[], int N) {
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
int minsegTree::constructTreeUtil(int arr[], int si, int as, int ae) {
	if (as == ae) {
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
int minsegTree::query(int qs, int qe) {
	return queryUtil(qs, qe, 0, n - 1, 0);
}
int minsegTree::queryUtil(int qs, int qe, int ss, int se, int si) {
	if (lazy[si] != 0) {
		segarr[si] += lazy[si];
		if (ss != se) {
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 2] += lazy[si];
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
void minsegTree::update(int i, int val, int arr[]) {
	return updateUtil(i, 0, 0, n - 1, val, arr);
}
void minsegTree::updateUtil(int i, int si, int ss, int se, int val, int arr[]) {
	if (ss == se) {
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
void minsegTree::updateRange(int l, int r, int inc) {
	updateRangeUtil(l, r, inc, 0, 0, n - 1);
}
void minsegTree::updateRangeUtil(int l, int r, int inc, int si, int ss, int se) {
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
			lazy[si * 2 + 1] += inc;
			lazy[si * 2 + 2] += inc;
		}
		return;
	}
	int mid = (ss + se) >> 1;
	updateRangeUtil(l, r, inc, 2 * si + 1, ss, mid);
	updateRangeUtil(l, r, inc, 2 * si + 2, mid + 1, se);
	segarr[si] = min(segarr[2 * si + 1], segarr[2 * si + 2]);

}

class fenwick_tree {
	int N;
	int* ftree;
public:
	fenwick_tree(int n);
	void build_tree(int a[]);
	int get_next(int v);
	int get_parent(int v);
	int query(int i);
	void update(int i, int val);
};
fenwick_tree::fenwick_tree(int n) {
	N = n;
	ftree = new int[N + 1];
}
int fenwick_tree::get_parent(int v) {
	int org = v;
	v = ~v;
	v += 1;
	v = org & v;
	return org - v;
}
int fenwick_tree::get_next(int v) {
	int org = v;
	v = ~v;
	v += 1;
	v = org & v;
	return org + v;
}
void fenwick_tree::build_tree(int a[]) {
	for (int i = 0; i <= N; ++i) {
		ftree[i] = 0;
	}
}
int fenwick_tree::query(int i) {
	int parent = i + 1;
	int res = 0;
	while (parent > 0) {
		res += ftree[parent];
		parent = get_parent(parent);
	}
	return res;
}
void fenwick_tree::update(int i, int val) {
	int k = i + 1;
	while (k <= N) {
		ftree[k] += val;
		k = get_next(k);
	}
}

char inp[MAX];
int a[MAX];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", inp);
	int pre = 0;
	int cr = 0;
	fenwick_tree ftr(n);
	ftr.build_tree(a);
	minsegTree mntr(a, n);
	segTree mxtr(a, n);
	for (int i = 0; i < n; ++i) {
		if (inp[i] == 'L') {
			cr = max(cr - 1, 0);
			printf("%d ", pre);
		}
		else if (inp[i] == 'R') {
			cr++;
			printf("%d ", pre);
		}
		else if (inp[i] == '(' || inp[i] == ')') {
			int ch = 1 - a[cr];
			if (inp[i] == ')') ch = -1 - a[cr];
			if (inp[i] == '(') {
				ftr.update(cr, ch);
				a[cr] = 1;
			}
			else {
				ftr.update(cr, ch);
				a[cr] = -1;
			}
			mntr.updateRange(cr, n - 1, ch);
			mxtr.updateRange(cr, n - 1, ch);
			if ((ftr.query(n - 1) == 0) && (mntr.query(0, n - 1) >= 0)) {
				pre = mxtr.query(0, n - 1);
			}
			else pre = -1;
			printf("%d ", pre);
		}
		else {
			if (a[cr] == 0) printf("%d ", pre);
			else {
				int ch = 0-a[cr];
				a[cr] = 0;
				ftr.update(cr, ch);
				mntr.updateRange(cr, n - 1, ch);
				mxtr.updateRange(cr, n - 1, ch);
				if ((ftr.query(n - 1) == 0) && (mntr.query(0, n - 1) >= 0)) {
					pre = mxtr.query(0, n - 1);
				}
				else pre = -1;
				printf("%d ", pre);

			}
		}
	}
}