#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1500 + 100;
typedef long long ll;
string inp[MAX];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	ll res = 0;
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		char str[100];
		scanf("%s", str);
		string s(str);
		inp[i] = s;
		mp[s] += 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			string search;
			for (int l = 0; l < k; ++l) {
				if (inp[i][l] == inp[j][l])
					search += inp[i][l];
				else
					search += ('S' + 'E' + 'T') - (inp[i][l] + inp[j][l]);
			}
			res += mp[search];
			if (search == inp[i]) res -= 2;
		}
	}
	res /= 3;
	printf("%lld", res);
}