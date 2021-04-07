#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int bs(int n,int d) {
	if (d <= n) return 1;
	int i = 0;
	int j = n;
	int mid;
	while (i <= j) {
		mid = (i + j) >> 1;
		int s = d / (mid + 1);
		if (d % (mid + 1)) s++;
		if (mid + s <= n) return 1;
		else j = mid - 1;
	}
	return 0;
	
}
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n, d; scanf("%d %d", &n, &d);
		if (bs(n, d)) printf("YES\n");
		else printf("NO\n");
	}
}