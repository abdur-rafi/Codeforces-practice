#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
class fenwick_tree {
	ll N;
	ll* ftree;
public:
	fenwick_tree(ll n);
	void build_tree();
	ll get_next(ll v);
	ll get_parent(ll v);
	ll query(ll i);
	void update(ll i, ll val);
};
fenwick_tree::fenwick_tree(ll n) {
	N = n;
	ftree = new ll[N + 1];
}
ll fenwick_tree::get_parent(ll v) {
	ll org = v;
	v = ~v;
	v += 1;
	v = org & v;
	return org - v;
}
ll fenwick_tree::get_next(ll v) {
	ll org = v;
	v = ~v;
	v += 1;
	v = org & v;
	return org + v;
}
void fenwick_tree::build_tree() {
	for (int i = 0; i <= N; ++i) ftree[i] = 0;
}
ll fenwick_tree::query(ll i) {
	ll parent = i + 1;
	ll res = 0;
	while (parent > 0) {
		res += ftree[parent];
		parent = get_parent(parent);
	}
	return res;
}
void fenwick_tree::update(ll i, ll val) {
	ll k = i + 1;
	while (k <= N) {
		ftree[k] += val;
		k = get_next(k);
	}
}

int str1[26];
int str2[26];
int adj[26];
int main() {
	int q; cin >> q;
	while (--q >= 0) {
		for (int i = 0; i < 26; ++i) str1[i] = str2[i] = 0;
		int n; cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		for (auto p : s1) str1[p - 'a']++;
		for (auto p : s2) str2[p - 'a']++;
		bool b1 = true, b2 = false;
		for (int i = 0; i < 26; ++i) {
			if (str1[i] != str2[i]) b1 = false;
			if (str1[i] > 1) b2 = true;
		}
		if (!b1) {
			cout << "NO\n";
			continue;
		}
		else if (b2) {
			cout << "YES\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			adj[s2[i] - 'a'] = i;
		}
		fenwick_tree ftree(n);
		ftree.build_tree();
		int c = 0;
		for (int i = 0; i < n; ++i) {
			int j = adj[s1[i] - 'a'];
			ftree.update(j, 1);
			j += ftree.query((ll)n - 1)-ftree.query(j);
			c += j - i;
		}
		if (c % 2 == 1) cout << "NO\n";
		else cout << "YES\n";
	}
}