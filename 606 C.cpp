#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 200000 + 10;
char str[MAX];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		scanf("%s", str);
		int n = strlen(str);
		vector<int> r;
		for (int i = 0; i < n - 2;) {
			char cmp[4];
			cmp[0] = str[i];
			cmp[1] = str[i + 1];
			cmp[2] = str[i + 2];
			cmp[3] = '\0';
			if ((!strcmp(cmp, "one"))) {
				r.push_back(i + 1);
				i += 3;
			}
			else if (!strcmp(cmp, "two")) {
				if (i + 3 < n && str[i + 3] == 'n') {
					r.push_back(i + 2);
					i += 4;
				}
				else {
					r.push_back(i + 1);
					i += 3;
				}
			}
			else ++i;

		}
		printf("%d\n", r.size());
		for (auto p : r) {
			printf("%d ", p+1);
		}
		printf("\n");
	}
}