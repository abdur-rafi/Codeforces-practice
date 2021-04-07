#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define loop(x,n,a) for(int x =a; x < n;++x)
using namespace std;
const int MAX = 2000 + 10;
vector<int> adj[MAX];
int c[MAX];
int a[MAX];
int n;
int fre;
bool pos = 1;
void gaps(vector<pair<int, int>> &v) {
//	printf("fdasf");
	int i = 0;
	int N = v.size();
	for (int i = 0; i < N; ++i) {
		v[i].first += (i + 1) * n;
	}
}
vector<pair<int, int>> dfs(int u, int p) {
	vector<pair<int, int>> nodes;
	if (!pos) return nodes;
	for (auto v : adj[u]) {
		if (v != p) {
			vector<pair<int, int>> v2;
			v2 = dfs(v, u);
			if (!pos) return nodes;
			nodes.insert(nodes.end(), v2.begin(), v2.end());
		}
	}
	if (nodes.empty()) {
		if (c[u] != 0) {
			pos = 0;
			return nodes;
		}
		nodes.push_back({ n + fre * n ,u });
		++fre;
	}
	else {
		sort(nodes.begin(), nodes.end());
		if (c[u] > nodes.size()) {
			pos = 0;
			return nodes;
		}
	//	printf("%d", u);
		int d = 0;
		if(c[u] > 0) d = nodes[c[u] - 1].first;
		int e = d + n;
		if (nodes.size() > c[u]) e = nodes[c[u]].first;
	//	printf("%d", u);
		if (e - d <= 1) {
			gaps(nodes);
		}
		d = 0;
		if (c[u] > 0) d = nodes[c[u] - 1].first;
		e = d + n;
		if (nodes.size() > c[u]) e = nodes[c[u]].first;
		nodes.insert(nodes.begin() + c[u], { (e + d) / 2,u });
	}
	return nodes;
}
int main() {
	scanf("%d", &n);
	int root;
	for (int i = 0; i < n; ++i) {
		int pi, ci; scanf("%d %d", &pi, &ci);
		c[i + 1] = ci;
		if (pi == 0) root = i + 1;
		else {
			adj[pi].push_back(i + 1);
			adj[i + 1].push_back(pi);
		}
	}
	vector<pair<int, int>> pr = dfs(root, 0);
	if (!pos) {
		printf("NO");
		return 0;
	}
	for (auto p : pr) {
		a[p.second] = p.first;
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);

}