#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			int d; scanf("%d", &d);
			if (d % 2 == 0) m[d]++;
			
		}
		int res = 0;
		for (auto p = m.rbegin(); p != m.rend(); ++p) {
			int numb = p->first;
	//		printf("n:%d\n", numb);
			int fre = p->second;
			++res;
			if ((numb / 2) % 2 == 0 ) m[numb / 2]++;
		}
		printf("%d\n", res);
	}
}