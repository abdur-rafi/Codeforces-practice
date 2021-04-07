#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int MX = 1000000000;
int main() {
	int n, sx, sy; scanf("%d %d %d", &n, &sx, &sy);
	vector<pair<int, int>> st;
	for (int i = 0; i < n; ++i) {
		int c, d; scanf("%d %d", &c, &d);
		st.push_back({ c,d });
	}
	vector<pair<int, int>> loc;
	if (sx - 1 >= 0)loc.push_back({ sx - 1,sy });
	if (sy - 1 >= 0)loc.push_back({ sx,sy -1 });
	if (sx + 1 <= MX)loc.push_back({ sx + 1,sy });
	if (sy + 1 <= MX)loc.push_back({ sx,sy + 1 });
	int res = 0;
	pair<int, int> fpos;
	for (auto pos : loc) {
		int c = 0;
		int x = pos.first;
		int y = pos.second;
		for (int i = 0; i < n; ++i) {
			int mn, mx;
			mn = min(sx, st[i].first);
			mx = max(sx, st[i].first);
			int mny, mxy;
			mny = min(sy, st[i].second);
			mxy = max(sy, st[i].second);
			if (x >= mn && x <= mx && y >= mny && y <= mxy) {
				++c;
			}
		}
		if (c >= res) {
			res = c;
			fpos = { x,y };
		}
	}
	printf("%d\n", res);
	printf("%d %d", fpos.first, fpos.second);
}