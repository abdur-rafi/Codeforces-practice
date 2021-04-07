#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100000 + 10;
char str[MAX];
ll res[26][26];
ll fr[26];
int main() {
	scanf("%s", str);
	int i = 0;
	while (str[i]) {
		fr[str[i] - 'a']++;
		for (int j = 0; j < 26; ++j) res[j][str[i] - 'a'] += fr[j];
		i++;
	}
	ll r = 0;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (i == j) continue;
			r = max(r, res[i][j]);
		}
	}
	for (int i = 0; i < 26; ++i) {
		r = max(r, (fr[i] * (fr[i] - 1)) / 2);
		r = max(r, fr[i]);
	}
	printf("%lld", r);
}