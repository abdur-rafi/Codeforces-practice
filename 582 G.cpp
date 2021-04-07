#include <cstdio>
#include <algorithm>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
struct Edge {
	ll a, b, c;
};
ll const MAX = 200000 + 10;
ll parent[MAX];
ll set_size[MAX];
ll height[MAX];
Edge edges[MAX];
pair<ll,ll> query[MAX];
ll ans[MAX];
bool comp(Edge a, Edge b) {
	if (a.c == b.c) return (a.a < b.a);
	return (a.c <= b.c);
	
}
ll get_rep(ll a) {
	if (parent[a] != a) {
		parent[a] = get_rep(parent[a]);
	}
	return parent[a];
}
void merge_set(ll a, ll b) {
	ll c = get_rep(a);
	ll d = get_rep(b);
	if (height[c] > height[d]) {
		parent[d] = c;
		set_size[c] += set_size[d];
	}
	else{
		parent[c] = d;
		set_size[d] += set_size[c];
	}
	if (height[c] == height[d]){
		height[d]++;
	}
}
ll bs(ll val,ll n) {
	if (val < edges[0].c) return -1;
	if (val > edges[n - 2].c) return n - 1;
	ll i = 0, j = n - 2;
	ll m;
	while (i <= j){
		m = (i + j) >> 1;
		if (edges[m].c <= val) i = m + 1;
		else j = m - 1;
	}
	return i- 1;
}
int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	loop(i, n + 1, 0) parent[i] = i,set_size[i]=1;
	loop(i, n-1, 0) {
		scanf("%lld %lld %lld", &edges[i].a, &edges[i].b, &edges[i].c);
	}
	loop(i, m, 0) {
		scanf("%lld",&query[i].first);
		query[i].second = i;
	}
	sort(edges , edges + n - 1, comp);
	sort(query, query + m);
//	printf("Asdas");
	ll curr = 0;
	ll res = 0;
	ll pre = 0;
/*	loop(i, n - 1, 0) {
		printf("%lld %lld %lld\n", edges[i].c, edges[i].a, edges[i].b);
	}*/
//	loop(i, m, 0) printf("%lld %lld\n", query[i].first, query[i].second);

	loop(i, m , 0) {
		ll nxt = bs(query[i].first, n);
	//	printf("nxt:%lld\n", nxt);
		if (nxt == -1) {
			continue;
		}
	//	printf("%lld\n", nxt);
		nxt = min(nxt, n - 2);
		for (int i = pre; i <= nxt; ++i) {
			if (get_rep(edges[i].a) != get_rep(edges[i].b)) {
				ll d = set_size[get_rep(edges[i].a)];
				d = (d * (d - 1)) / 2;
				res -= d;
				d = set_size[get_rep(edges[i].b)];
				res -= (d * (d - 1)) / 2;
				merge_set(edges[i].a, edges[i].b);
				d = set_size[get_rep(edges[i].a)];
				res += (d * (d - 1)) / 2;
			}
		}
		pre = nxt + 1;
		ans[query[i].second] = res;
	}
	loop(i, m, 0) printf("%lld ", ans[i]);

	return 0;
}
