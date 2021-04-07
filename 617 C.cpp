#include <cstdio>
#include <map>
#include <utility>
using namespace std;
char str[200000 + 100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		scanf("%s", str);
		map<pair<int, int>,int> loc;
		loc[{0, 0}] = 0;
		int x = 0, y = 0;
		pair<int, int> res = { -1,-1 };
		int len = 1e9;
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'L') --x;
			else if (str[i] == 'R') ++x;
			else if (str[i] == 'U') ++y;
			else --y;
			if (loc.find({ x,y }) != loc.end()) {
				int pr = loc[{x, y}];
				if (i - pr + 1 < len) {
					len = i - pr + 1;
					res.first = pr;
					res.second = i;
				}
			}
			loc[{x, y}] = i + 1;
		}
		if (res.first == -1) {
			printf("-1\n");
		}
		else {
			printf("%d %d\n", res.first + 1, res.second + 1);
		}
	}
}