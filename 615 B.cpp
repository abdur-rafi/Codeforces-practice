#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n; cin >> n;
		vector<pair<int, int >> package;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			package.push_back({ a,b });
		}
		sort(package.begin(), package.end());
		string res;
		int mxy = 0;
		bool pos = 1;
		for (int i = 0; i < package[0].first; ++i) res += 'R';
		for (int i = 0; i < package[0].second; ++i) res += 'U';
		mxy = package[0].second;
		for (int i = 1; i < n; ++i) {
			int diff = package[i].first - package[i - 1].first;
			for (int j = 0; j < diff; ++j) res += 'R';
			diff = package[i].second - package[i - 1].second;
			if (diff < 0) {
				pos = 0;
				break;
			}
			for (int j = 0; j < diff; ++j) res += 'U';
		}
		if (pos) {
			cout << "YES\n";
			cout << res << "\n";
		}
		else
			cout << "NO\n";
	}
}