#include<cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
const int MAX = 200000 + 10;
class segTree
{
	ll* segarr;
	ll n;
	ll constructTreeUtil(ll arr[], ll si, ll as, ll ae);
	ll queryUtil(ll qs, ll qe, ll ss, ll se, ll si);
	void updateUtil(ll i, ll si, ll ss, ll se, ll val, ll arr[]);
public:
	segTree(ll arr[], ll N);
	void update(ll i, ll val, ll arr[]);
	ll query(ll as, ll ae);
};
segTree::segTree(ll arr[], ll N)
{
	n = N;
	ll x = (ll)(ceil(log2(n)));
	ll s = 2 * (ll)pow(2, x) - 1;
	segarr = new ll[s];
	constructTreeUtil(arr, 0, 0, n - 1);
}
ll segTree::constructTreeUtil(ll arr[], ll si, ll as, ll ae)
{
	if (as == ae)
	{
		segarr[si] = arr[as];
		return arr[as];
	}
	ll mid = (as + ae) >> 1;
	ll l = constructTreeUtil(arr, 2 * si + 1, as, mid);
	ll r = constructTreeUtil(arr, 2 * si + 2, mid + 1, ae);
	ll h = max(l, r);
	segarr[si] = h;
	return h;
}
ll segTree::query(ll qs, ll qe)
{
	return queryUtil(qs, qe, 0, n - 1, 0);
}
ll segTree::queryUtil(ll qs, ll qe, ll ss, ll se, ll si)
{
	if (qs <= ss && qe >= se)
		return segarr[si];
	if (se < qs || ss > qe)
		return LLONG_MIN;
	ll m = (ss + se) >> 1;
	ll l = queryUtil(qs, qe, ss, m, 2 * si + 1);
	ll r = queryUtil(qs, qe, m + 1, se, 2 * si + 2);
	return max(l, r);
}
void segTree::update(ll i, ll val, ll arr[])
{
	return updateUtil(i, 0, 0, n - 1, val, arr);
}
void segTree::updateUtil(ll i, ll si, ll ss, ll se, ll val, ll arr[])
{
	if (ss == se)
	{
		arr[i] = val;
		segarr[si] = val;
		return;
	}
	ll mid = (ss + se) >> 1;
	if (ss <= i && i <= mid)
		updateUtil(i, 2 * si + 1, ss, mid, val, arr);
	else
		updateUtil(i, 2 * si + 2, mid + 1, se, val, arr);
	segarr[si] = max(segarr[2 * si + 1], segarr[2 * si + 2]);

}
ll a[MAX];
ll last_balance[MAX];
ll last_balance_index[MAX];
ll query[MAX];
int main() {
	ll n; scanf("%lld", &n);
	loop(i, n, 0) scanf("%lld", a + i);
	ll q; scanf("%lld", &q);
	loop(i, MAX, 0) last_balance_index[i] = -1;
	loop(i, q, 0) {
		ll c, d; scanf("%lld %lld", &c, &d);
		if (c == 1) {
			ll e; scanf("%lld", &e);
			last_balance[d - 1] = e;
			last_balance_index[d - 1] = i;
		}
		else {
			query[i] = d;
		}
	}
	segTree stree(query, q);
	loop(i, n, 0) {
		if (last_balance_index[i] == -1) {
			printf("%lld ", max(a[i], stree.query(0, q - 1)));
		}
		else {
			ll ind = last_balance_index[i];
			ll res = last_balance[i];
			if (ind != q - 1) {
				res = max(res, stree.query(ind + 1, q - 1));
			}
			printf("%lld ", res);
		}
	}
	return 0;
}