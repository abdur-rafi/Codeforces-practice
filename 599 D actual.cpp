#include <iostream>
#include <cstdio>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

int const MAX = 100000 + 10;
vector<int> adj[MAX];
vector<int> adj2[MAX];
bool vis[MAX];
bool vis2[MAX];
list <int> lst;


void creategraph(int i) {
	queue<int> q;
	q.push(i);
	vis2[i] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int i = 0;
		int cn = adj[u].size();
		for (auto l = lst.begin(); l != lst.end();) {
			if (*l == u) {
				l = lst.erase(l);
			}
			else if (i >= cn) {
				vis2[*l] = 1;
				q.push(*l);
				l = lst.erase(l);
			}
			else if (adj[u][i] == *l) {
				i++;
				l++;
			}
			else if (adj[u][i] < *l)
				++i;
			else {
				vis2[*l] = 1;
				q.push(*l);
				l = lst.erase(l);
			}
		}
	}
}


int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int c, d; scanf("%d %d", &c, &d);
		adj[c].push_back(d);
		adj[d].push_back(c);
	}
	for (int i = 1; i <= n; ++i) {
		lst.push_back(i);
	}
	vector<pair<int, int>> sz;
	for (int i = 1; i <= n; ++i) {
		sort(adj[i].begin(), adj[i].end());
		sz.push_back({ adj[i].size() ,i});
	}
	sort(sz.begin(), sz.end());
	int c = 0;
	for (auto p : sz) {
		if (!vis2[p.second]) {
			++c;
			creategraph(p.second);
		}
	}
	printf("%d\n", c - 1);
}