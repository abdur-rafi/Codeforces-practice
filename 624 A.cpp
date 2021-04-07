#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define loop(x,n,a) for(int x =a; x < n;++x)
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int a, b; scanf("%d %d", &a, &b);
		int res = 0;
		if (a == b) {
			;
		}
		else if (b > a) {
			int diff = b - a;
			if (diff % 2) {
				res = 1;
			}
			else res = 2;
		}
		else {
			int diff = a - b;
			if (diff % 2 == 0) res = 1;
			else {
				res = 2;
			}
		}
		printf("%d\n", res);
	}
}