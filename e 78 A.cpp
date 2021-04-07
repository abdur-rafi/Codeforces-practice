#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		string p, h;
		bool pos = false;
		cin >> p >> h;
		sort(p.begin(), p.end());
		int n = h.size();
		for (int i = 0; i < n; ++i) {
			string tmp;
			for(int j = i; j < n; ++j) {
				tmp += h[j];
				sort(tmp.begin(), tmp.end());
				if (tmp == p) {
					pos = true;
					break;
				}
			}
			if (pos) break;
			
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
}