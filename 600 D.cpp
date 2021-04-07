#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int const MAX = 200000 + 10;
vector<int> adj[MAX];
int comp[MAX];
bool vis[MAX];
vector<int> elements[MAX];
int cmpi = 0;
void bfs(int i) {
	queue<int> q;
	q.push(i);
	vis[i] = true;
	while (!q.empty()) {
		int u = q.front();
		elements[cmpi].push_back(u);
		comp[u] = cmpi;
		q.pop();
		for (auto p : adj[u]) {
			if (vis[p] == false) {
				vis[p] = true;
				q.push(p);
			}
		}
	}
	++cmpi;
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int b, c;
		scanf("%d %d", &b, &c);
		adj[b].push_back(c);
		adj[c].push_back(b);
	}
	for (int i = 1 ; i <= n; ++i) {
		if (!vis[i]) {
			bfs(i);
		}
	}
	for (int i = 0; i <= n; ++i) {
		if(elements[i].size())
			sort(elements[i].begin(), elements[i].end());
	}
	int mx = -1;
	int curr = -1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if ((i > mx) && (elements[comp[i]].size() > 1)) {
			mx = elements[comp[i]].back();
			curr = comp[mx];
		}
		else if ((i < mx) && (comp[i] != curr)) {
			++res;
			for (auto p : elements[comp[i]]) {
				mx = max(p, mx);
				comp[p] = curr;

			}
		}
	}
	printf("%d", res);
}