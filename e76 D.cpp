#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 200000 + 10;
int bs1(pii a[], int n, int val) {
	int i = 0;
	int j = n - 1;
	int m;
	while (i <= j) {
		m = (i + j) >> 1;
		if (a[m].first < val)i = m + 1;
		else j = m - 1;
	}
	return j + 1;
}
int bs2(pii a[], int n, int val) {
	int i = 0;
	int j = n - 1;
	int m;
	while (i <= j) {
		m = (i + j) >> 1;
		if (a[m].first > val)j = m - 1;
		else i = m + 1;
	}
	return i - 1;
}
class segTree{
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
pii spower[MAX];
pii sendurance[MAX];
int monsters[MAX];
int spowersEndurance[MAX];
int main() {
	int t; scanf("%d", &t);
	for(int i1=0;i1<t;++i1) {
		int hm = 0, hp = 0;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", monsters + i);
			hm = max(hm, monsters[i]);
		}
		int m; scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int c, d; scanf("%d %d", &c, &d);
			spower[i].first = sendurance[i].second = c;
			spower[i].second = sendurance[i].first = d;
			hp = max(hp, c);
		}
		if (hp < hm) {
			printf("-1\n");
			continue;
		}
		sort(spower, spower + m);
		sort(sendurance, sendurance + m);
		int res = 0;
		int curr_power = 0;
		int curr_endurence = 0; 
		int rem_endurance = 0;
		for (int i = 0; i < m; ++i) {
			spowersEndurance[i] = spower[i].second;
		}
		segTree stree(spowersEndurance, m);
		for (int i = 0; i < n; ++i) {
		 	if (rem_endurance == 0) {
				int j = bs1(spower, m, monsters[i]);
				j = stree.query(j, m - 1);
				int new_endurance = j;
				int new_power = sendurance[bs2(sendurance, m, j)].second;
				++res;
				curr_endurence = new_endurance ;
				rem_endurance = curr_endurence - 1;
				curr_power = new_power;
			}
			else if (monsters[i] > curr_power) {
				int j = bs1(spower, m, monsters[i]);
				j = stree.query(j, m - 1);
				int new_endurance = j;
				int new_power = sendurance[bs2(sendurance, m, j)].second;
				if (new_endurance > (curr_endurence - rem_endurance)) {
					rem_endurance = new_endurance - (curr_endurence - rem_endurance);
					curr_endurence = new_endurance;
					curr_power = new_power;
					--rem_endurance;
				}
				else {
					curr_endurence = new_endurance;
					rem_endurance = curr_endurence - 1;
					++res;
					curr_power = new_power;
				}
			}
			else {
				--rem_endurance;
			}
		}
		printf("%d\n", res); 
		
	}
}