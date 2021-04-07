#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const long long MAX = 200000 + 10;
const long long MOD = 1000000000 + 7;
int main() {
	long long t; cin >> t;
	while (--t >= 0) {
		long long res = 0;
		long long x;
		cin >> x;
		--x;
		string s1; cin >> s1;
		res = s1.size();
		if (s1.size() == 1) {
			cout << "1\n";
			continue;
		}
		long long c = 0;
		while (c <= x) {
			string s2;
			long long fre = s1[c] - '0';
			--fre;
			if (s1.size() < x + 1 && fre > 0) {
				for (long long i = c + 1; i < s1.size(); ++i) {
					s2 += s1[i];
				}
			}
			res += (fre * ((MOD + res - (c + 1)) % MOD)) % MOD;
			res = res % MOD;
			while (fre > 0) {
				if (s1.size() > x + 1) break;
				s1 += s2;
				--fre;
			}
			++c;
		}
		cout << res << '\n';
	}
}