#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#define loop(x,n,a) for(int x =a; x < n;++x)
using namespace std;
const int MAX = 200000 + 10;
int sp[MAX];
vector<int> adj[MAX];
int vis[MAX];
int lvs[MAX];
int lvn[MAX];
int spa[MAX];
void bfs(int i,int level[],int vis[]) {
	queue<int> q;q.push(i);
	vis[i] = 1;
	int l = 0;
	q.push(-1);
	level[i] = l;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == -1) {
			if(q.size())
			q.push(-1);
			++l;
			continue;
		}
		for (auto v : adj[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				level[v] = l + 1;
				q.push(v);
			}
		}
	}
}
int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", sp + i);
		spa[sp[i]] = 1;
	}
	int one = 0;
	for (int i = 0; i < m; ++i) {
		int c, d; scanf("%d %d", &c, &d);
		adj[c].push_back(d);
		adj[d].push_back(c);
		if (spa[c] && spa[d]) {
			one = 1;
		}
	}
	bfs(1,lvs,vis);
	for (int i = 0; i <= n; ++i) vis[i] = 0;
	bfs(n,lvn,vis);
	vector<pair<int, int>> v;
	for (int i = 0; i < k; ++i) {
		v.push_back({ lvs[sp[i]] - lvn[sp[i]],sp[i] });
	}
	sort(v.begin(), v.end());
	int res = 0;
	int xa = -(1e9);
	for (auto p : v) {
		int b = p.second;
		res = max(res, xa + lvn[b]);
		xa = max(xa, lvs[b]);
	}
	printf("%d\n", min(lvs[n], res + 1));
}