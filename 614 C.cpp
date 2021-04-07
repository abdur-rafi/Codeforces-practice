#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000 + 10;
int path1(vector<pair<ll, ll>> &nodes, ll xs, ll ys,ll t) {
	int n = nodes.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		ll cst = 0;
		int cnt2 = 0;
		cst += abs(xs - nodes[i].first) + abs(ys - nodes[i].second);
		if (cst > t) continue;
		cnt2++;
		for (int j = i + 1; j < n; ++j) {
			cst += abs(nodes[j].first - nodes[j - 1].first) + abs(nodes[j - 1].second - nodes[j].second);
			if (cst > t) break;
			cnt2++;
		}
		cnt = max(cnt, cnt2);
	}
	return cnt;
}

int path2(vector<pair<ll, ll>>& nodes, ll xs, ll ys, ll t) {
	int n = nodes.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int cnt2 = 0;
		ll cst = 0;
		cst += abs(xs - nodes[i].first) + abs(ys - nodes[i].second);
		if (cst > t) continue;
		++cnt2;
		for (int j = i - 1; j >= 0; --j) {
			cst += abs(nodes[j].first - nodes[j + 1].first) + abs(nodes[j].second - nodes[j + 1].second);
			if (cst > t) break;
			cnt2++;
		}
		cnt = max(cnt, cnt2);
	}
	return cnt;
}

int path3(vector<pair<ll, ll>>& nodes, ll xs, ll ys, ll t) {
	int n = nodes.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int cst = 0;
		int cnt2 = 0;
		cst += abs(nodes[i].first - xs) + abs(nodes[i].second - ys);
		if (cst > t) continue;
		cnt2++;
	}
	return cnt;
}

int main() {
	ll x0, y0, ax, bx, by, ay;
	scanf("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
	ll xs, ys, t; scanf("%lld %lld %lld", &xs, &ys, &t);
	vector<pair<ll, ll>> nodes;
	ll mx = max(xs, ys);
	mx += t;
	ll x = x0, y = y0;
	while (max(x, y) <= mx) {
		nodes.push_back({ x,y });
		x = x * ax + bx;
		y = y * ay + by;
	}
	ll mn = 1e18;
	printf("%d", max(path1(nodes, xs, ys, t), path2(nodes, xs, ys, t)));
}