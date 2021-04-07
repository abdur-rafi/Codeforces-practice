#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 200000 + 10;
int a[MAX];
vector<int> adj[MAX];
vector<int> odd, even;
int res[MAX];
int d[MAX];
void bfs(vector<int>& v1, vector<int>& v2,int n) {
	for (int i = 0; i <= n; ++i) d[i] = INT_MAX;
	queue<int> q;
	for (auto v : v1) {
		q.push(v);
		d[v] = 0;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (d[v] == INT_MAX) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	for (auto v : v2) {
		if(d[v] != INT_MAX)
			res[v] = d[v];
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		if (a[i] + i <= n) {
			adj[a[i] + i].push_back(i);
		}
		if (i - a[i] > 0) {
			adj[i - a[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i] % 2;
		if (a[i]) odd.push_back(i);
		else even.push_back(i);
	}
	bfs(odd, even, n);
	bfs(even, odd, n);
	for (int i = 1; i <= n; ++i) {
		if (res[i] == 0) printf("-1 ");
		else printf("%d ", res[i]);
	}

}