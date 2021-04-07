#include <iostream>
#include <cstdio>
#include<vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> adj[200000 + 10];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i <= n; ++i) adj[i].clear();
		for (int i = 0; i < n; ++i) {
			int k; scanf("%d", &k);
			adj[k].push_back(i);
		}
		int b = 0;
		for (int i = 0; i <= n; ++i) {
			if (adj[i].size() > 1) b = 1;
		}
		int res = n + 1;
		if (!b) printf("-1\n");
		else {
			for (int i = 0; i <= n; ++i) {
				if (adj[i].size() > 1) {
					for (int j = 1; j < adj[i].size(); ++j) res = min(res, adj[i][j] - adj[i][j - 1]);
				}
			}
			printf("%d\n", res + 1);
		}
	}

}