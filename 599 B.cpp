#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		int diff = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				diff++;
			}
		}
		if ((diff > 2) || (diff == 1)) {
			printf("No\n");
			continue;
		}
		int sf = -1, ss = -1, tf = -1, ts = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				if (sf == -1) {
					sf = s[i];
					tf = t[i];
				}
				else {
					ss = s[i];
					ts = t[i];
				}
			}
		}
		if ((ss == sf) && (ts == tf)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}