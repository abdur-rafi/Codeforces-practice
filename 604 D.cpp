#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string r1, r2;
	int mn = min(a, b);
	a -= mn;
	b -= mn;
	for (int i = 0; i < mn; ++i) r1 += "01";
	mn = min(c, d);
	c -= mn;
	d -= mn;
	for (int i = 0; i < mn; ++i) r2 += "23";
	mn = min(b, c);
	b -= mn;
	c -= mn;
	string rm;
	for (int i = 0; i < mn; ++i) rm += "21";
	string res;
	string as, bs, cs, ds;
	for (int i = 0; i < a; ++i) as += "0";
	for (int i = 0; i < b; ++i) bs += "1";
	for (int i = 0; i < c; ++i) cs += "2";
	for (int i = 0; i < d; ++i) ds += "3";
	r1 += as;
	r1 = bs + r1;
	r2 += cs;
	r2 = ds + r2;
	res = r1 + rm + r2;
	bool pos = true;
	for (int i = 0; i + 1 < res.size(); ++i) {
		int e = res[i] - '0';
		int f = res[i + 1] - '0';
		if (abs(e - f) != 1) {
			pos = false;
			break;
		}
	}
	if (!pos) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (auto p : res) cout << p << ' ';
}