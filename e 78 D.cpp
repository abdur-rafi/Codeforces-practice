#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int MAX = 1000000 + 10;
vector<int> adj[MAX];
int seg[MAX];
int rev_seg[MAX];
set<int> curr;
int index[MAX];
bool vis[MAX];
int dfs(int u, int p) {
	int pos = 1;
	for (auto v : adj[u]) {
		if (vis[v] && v != p) return 0;
		else if (v != p) {
			vis[v] = 1;
			pos = pos && dfs(v, u);
		}
	}
	return pos;
}
int main() {
	int edges = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		seg[a] = b;
		rev_seg[b] = a;
		index[a] = i + 1;
	}
	for (int i = 1; i <= 2 * n; ++i) {
		if (seg[i]) curr.insert(i);
		else if (rev_seg[i]) {
			auto p = curr.find(rev_seg[i]);
			p++;
			int u = index[rev_seg[i]];
			while (p != curr.end()) {
				int v = index[*p];
				adj[u].push_back(v);
				adj[v].push_back(u);
				p++;
				++edges;
				if (edges > 2 * n - 1) {
					printf("No");
					return 0;
				}
			}
			curr.erase(rev_seg[i]);
		}
	}
	vis[1] = 1;
	int pos = dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			pos = 0;
			break;
		}
	}
	if (pos) printf("YES");
	else printf("NO");
}