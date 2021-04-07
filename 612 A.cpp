#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		char str[110]; scanf("%s", str);
		int res = 0;
		int e = n;
		for (int i = n - 1; i >= 0; --i) {
			if (str[i] == 'A') {
				res = max(res, e - i);
				e = i;
			}
		}
		printf("%d\n", max(res-1,0));
	}
}