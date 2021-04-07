#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
const int MAX = 5000 + 10;
vector<int> adj[MAX];
vector<pair<int, int >> adj2[MAX];
struct castles {
	int a, b, c;
};
int cost[MAX];
castles inp[MAX];
bool vis[MAX];
int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		int c, d, e; scanf("%d %d %d", &c, &d, &e);
		inp[i] = { c,d,e };
		cost[i] = e;
	}
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		--a;
		--b;
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		adj[i].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		sort(adj[i].begin(), adj[i].end(), greater<int>());
	}
	for (int i = 0; i < n; ++i) {
		int u = i;
		int v = adj[i][0];
		adj2[v].push_back({ cost[u],u });
	}
	for (int i = 0; i < n; ++i) {
		sort(adj2[i].begin(), adj2[i].end(), greater<pair<int, int>>());
	}
	multiset<pair<int,int>> defend;
	bool pos = 1;
	for (int i = 0; i < n; ++i) {
		if (k + defend.size() < inp[i].a) {
			pos = 0;
			break;
		}
		if (k > inp[i].a && i > 0) {
			int extra = k - inp[i].a;
			int j;
			for (j = 0; j < extra && j < adj2[i - 1].size(); ++j) {
				defend.insert(adj2[i - 1][j]);
			}
			k -= j;
		}
		else if (k < inp[i].a) {
			int need = inp[i].a - k;
			for (auto p = defend.begin(); p != defend.end();) {
				if (!need) break;
				p = defend.erase(p);
				--need;
			}
			k = inp[i].a;
		}
		k += inp[i].b;
		if (i > 0) {
			for (int j = 0; j < adj2[i - 1].size() && defend.size() > 0; ++j) {
				auto p = defend.begin();
				int c = adj2[i - 1][j].first;
				if (defend.find(adj2[i-1][j]) == defend.end() && c > (*p).first) {
					defend.erase(p);
					defend.insert(adj2[i-1][j]);
				}
			}
		}
	}
	if (!pos) printf("-1");
	else {
		for (int j = 0; j < k && j < adj2[n - 1].size(); ++j) {
			int c = adj2[n - 1][j].first;
			defend.insert(adj2[n-1][j]);
		}
		for (int j = 0; j < adj2[n - 1].size() && defend.size() > 0; ++j) {
			auto p = defend.begin();
			int c = adj2[n - 1][j].first;
			if (defend.find(adj2[n-1][j]) == defend.end() && c > (*p).first) {
				defend.erase(p);
				defend.insert(adj2[n-1][j]);
			}
		}

		int r = 0;
		for (auto p : defend) r += p.first;
		printf("%d", r);
	}

}