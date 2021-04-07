#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 5000 + 100;
int color[MAX];
int edge_color[MAX];
map<pair<int, int>, int> index;
vector<int> adj[MAX];
int two = 0;
void dfs(int u) {
	color[u] = 1;
	for (auto v : adj[u]) {
		if (!color[v])
			dfs(v);
		else if (color[v] == 1) {
			edge_color[index[{u, v}]] = 1;
			two = 1;
		}
	}
	color[u] = 2;
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		index[{a, b}] = i;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) dfs(i);
	}
	printf("%d\n", two + 1);
	for (int i = 0; i < m; ++i) printf("%d ", edge_color[i] + 1);
}