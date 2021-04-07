#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;
const int MAX = 200000 + 10;
int p[MAX];
map<pair<int, int>,vector<int>> mp;
map<int, pair<int, int>> ms;
int fre[MAX];
int main() {
	int n; scanf("%d", &n);
	n -= 2;
	for (int i = 0; i < n; ++i) {
		int a[3];
		scanf("%d %d %d", a + 0, a + 1, a + 2);
		sort(a, a + 3);
		ms[a[0]] = { a[1],a[2] };
		ms[a[1]] = { a[0],a[2] };
		ms[a[2]] = { a[0],a[1] };
		mp[{a[0], a[1]}].push_back(a[2]);
		mp[{a[0], a[2]}].push_back(a[1]);
		mp[{a[1], a[2]}].push_back(a[0]);
		fre[a[0]]++;
		fre[a[1]]++;
		fre[a[2]]++;
	}
	int f1 = 0;
	for (int i = 0; i <= n + 2; ++i) {
		if (fre[i] == 1) {
			f1 = i; break;
		}
	}
	p[0] = f1;
	if (fre[ms[f1].first] == 2) {
		p[1] = ms[f1].first;
		p[2] = ms[f1].second;
	}
	else {
		p[1] = ms[f1].second;
		p[2] = ms[f1].first;
	}
	for (int i = 3; i < n + 2; ++i) {
		int c, d;
		if (p[i - 1] > p[i - 2]) {
			c = p[i - 1];
			d = p[i - 2];
		}
		else {
			d = p[i - 1];
			c = p[i - 2];
		}
		vector<int> v = mp[{d, c}];
		if (v[0] == p[i - 3]) p[i] = v[1];
		else p[i] = v[0];
	}
	for (int i = 0; i < n + 2; ++i) {
		printf("%d ", p[i]);
	}
	
}