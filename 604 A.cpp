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
	getchar();
	while (--t >= 0) {
		scanf("%s", str);
		int n = strlen(str);
		if (str[0] == '?') {
			for (int j = 0; j < 3; ++j) {
				char c = 'a' + j;
				if (str[1] != c) {
					str[0] = c;
					break;
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			if (str[i] == '?') {
				for (int j = 0; j < 3; ++j) {
					char c = 'a' + j;
					if (str[i - 1] != c && str[i + 1] != c) {
						str[i] = c;
						break;
					}
				}
			}
		}
		bool pos = 1;
		for (int i = 0; i+1 < n; ++i) {
			if (str[i] == str[i + 1]) {
				pos = false;
				break;
			}
		}
		if (pos) {
			printf("%s\n", str);
		}
		else
			printf("-1\n");

	}
}