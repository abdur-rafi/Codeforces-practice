#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() {
	ll t; cin >> t;
	while (--t >= 0) {
		ll n, k; cin >> n >> k;
		string s1; cin >> s1;
		string s2;
		ll i;
		for (i = 0; i < n; ++i) {
			if (s1[i] == '1') break;
		}
		for (; i < n; ++i) {
			s2 += s1[i];
		}
		if (!s2.size()) {
			cout << s1<<"\n";
			continue;
		}
		ll pos = 0;
		bool done = 0;
		for (i = 0; i < s2.size(); ++i) {
			if (s2[i] == '0') {
				if (k >= (i - pos)) {
					k -= i - pos;
					++pos;
				}
				else {
					for (int j = 0; j < s1.size() - s2.size(); ++j) cout << "0";
					for (int j = 0; j < pos; ++j) cout << "0";
					for (int j = pos; j <= i; ++j) {
						if (j == i - k ) cout << "0";
						else cout << "1";
					}
					for (int j = i + 1; j < s2.size(); ++j) {
						cout << s2[j];
					}
					done = 1;
					break;
				}
			}
		}
		if (!done) {
			int fre1 = 0, fre0 = 0;
			for (int i = 0; i < s1.size(); ++i) {
				if (s1[i] == '0') ++fre0;
				else fre1++;
			}
			for (int i = 0; i < fre0; ++i) cout << "0";
			for (int i = 0; i < fre1; ++i) cout << "1";
		}
		cout << "\n";
	}
	return 0;
}