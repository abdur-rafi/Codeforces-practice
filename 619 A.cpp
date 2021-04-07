#include <cstdio>
#include <set>
#include <vector>
using namespace std;
char a[110], b[110], c[110];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		scanf("%s %s %s", a, b, c);
		int pos = 1;
		int i = 0;
		while (a[i]) {
			if (c[i] != a[i] && b[i] != c[i]) {
				pos = 0;
				break;
			}
			++i;
		}
		if (pos) printf("YES\n");
		else printf("NO\n");
	}
}