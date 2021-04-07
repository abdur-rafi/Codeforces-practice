#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000 + 10;
bool p[100];
char str[MAX];
int arr[MAX];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", str);
	getchar();
	for (int i = 0; i < k; ++i) {
		char c; scanf("%c", &c);
		getchar();
		p[c - 'a'] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (p[str[i] - 'a']) {
			arr[i] = 1;
		}
	}
//	for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
	ll res = 0;
	ll c = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			res += (c * (c + 1)) / 2;
			c = 0;
		}
		else c++;
	}
	res += (c * (c + 1)) / 2;
	printf("%lld\n", res);
}