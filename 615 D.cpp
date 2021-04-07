#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 400000 + 10;
int fre[MAX];
int main() {
	int q, x; scanf("%d %d", &q, &x);
	int mex = 0;
	while (--q >= 0) {
		int a;
		scanf("%d", &a);
		fre[a % x]++;
		while (1) {
			int c = mex / x + 1;
			if (fre[mex % x] >= c) mex++;
			else break;
		}
		printf("%d\n", mex);
	}
}