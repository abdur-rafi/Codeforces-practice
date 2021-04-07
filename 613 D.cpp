#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int solve(vector<int>& a, int bit) {
	if (bit < 0) return 0;
	vector<int> l, r;
	for (auto& p : a) {
		if (p & (1 << bit)) l.push_back(p);
		else r.push_back(p);
	}
	if (!l.size()) return solve(r, bit - 1);
	if (!r.size()) return solve(l, bit - 1);
	return min(solve(r, bit - 1), solve(l, bit - 1)) + (1 << bit);
}
int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (auto& p : a) scanf("%d", &p);
	printf("%d", solve(a, 30));
}