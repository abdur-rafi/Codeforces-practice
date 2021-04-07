#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int a[MAX];
int res[MAX];
char str[MAX];
vector<int> adj[MAX];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", str);
	for (int i = 0; i < n; ++i) {
		a[i] = str[i] - '0';
	}
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < n; j += k) {
			adj[i].push_back(a[j]);
		}
	}
	int eq = 1;
	for (int i = k - 1; i >= 0; --i) {
		int first = a[i];
		for (int j = i; j < n; j += k) {
			if (a[j] != first) {
				eq = 0;
				break;
			}
		}
	}
	if (eq) {
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) printf("%d", a[i]);
		return 0;
	}
	bool done = false;
	for (int i = k - 1; i >= 0; --i) {
		int first = adj[i][0];
		if (done) break;
		for (int j = 0; j < adj[i].size(); ++j) {
			if (adj[i][j] == first) continue;
			else if (adj[i][j] > first) {
				done = true;
				break;
			}
			else {
				break;
			}
		}
		
	}
	if (done) {
		for (int i = k - 1; i >= 0; --i) {
			if (adj[i][0] == 9) {
				adj[i][0] = 0;
			}
			else {
				adj[i][0]++;
				break;
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < n; j += k) {
			res[j] = adj[i][0];
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) printf("%d", res[i]);
	return 0;
}