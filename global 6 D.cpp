#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 100;
typedef long long ll;
ll nodes[MAX];
int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; ++i) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		nodes[a] += c;
		nodes[b] -= c;
	}
	vector<ll> in, out;
	for (int i = 1; i <= n; ++i) {
		if (nodes[i] > 0) out.push_back(i);
		else if (nodes[i] < 0) in.push_back(i);
	}
	vector<pair<ll, ll>> res;
	vector<ll> cst;
	int i = 0, j = 0;
	while (i < out.size() && j < in.size()) {
		ll u = out[i];
		ll v = in[j];
		ll z = min(nodes[u], -nodes[v]);
		nodes[u] -= z;
		nodes[v] += z;
		res.push_back({ u,v });
		cst.push_back(z);
		if (nodes[u] == 0) ++i;
		if (nodes[v] == 0) ++j;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%lld %lld %lld\n", res[i].first, res[i].second, cst[i]);
	}
}