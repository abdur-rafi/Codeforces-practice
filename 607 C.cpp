#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
char a[100][100];
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		bool four = false;
		bool  zero = true;
		int r, c; cin >> r >> c;
		for (int i = 0; i < r; ++i) {
			string s1; cin >> s1;
			for (int j = 0; j < c; ++j) {
				a[i][j] = s1[j];
				if (s1[j] == 'A')
					four = true;
				if (s1[j] == 'P')
					zero = false;
			}
		}
		int res = INT_MAX;

		if (zero) {
			cout << "0\n";
			continue;
		}

		bool one = true;
		for (int i = 0; i < r; ++i) {
			if (a[i][0] == 'P') {
				one = false;
				break;
			}
		}
		if (one) res = 1;
		one = true;
		for (int i = 0; i < r; ++i) {
			if (a[i][c-1] == 'P') {
				one = false;
				break;
			}
		}
		if (one) res = 1;
		one = true;
		for (int i = 0; i < c; ++i) {
			if (a[0][i] == 'P') {
				one = false;
				break;
			}
		}
		if (one) res = 1;
		one = true;
		for (int i = 0; i < c; ++i) {
			if (a[r-1][i] == 'P') {
				one = false;
				break;
			}
		}
		if (one) res = 1;



		if (a[0][0] == 'A' || a[0][c - 1] == 'A' || a[r - 1][0] == 'A' || a[r - 1][c - 1] == 'A') res = min(res, 2);
		for (int i = 0; i < r; ++i) {
			bool t = true;
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == 'P') {
					t = false;
					break;
				}
			}
			if (t) {
				res = min(res, 2);
				break;
			}
		}
		for (int i = 0; i < c; ++i) {
			bool t = true;
			for (int j = 0; j < r; ++j) {
				if (a[j][i] == 'P') {
					t = false;
					break;
				}
			}
			if (t) {
				res = min(res, 2);
				break;
			}
		}



		bool three = false;
		for (int i = 0; i < r; ++i) {
			if (a[i][0] == 'A' || a[i][c-1] == 'A') {
				three = true;
				break;
			}
		}
		for (int i = 0; i < c; ++i) {
			if (a[0][i] == 'A' || a[r-1][i] == 'A') {
				three = true;
				break;
			}
		}
		if (three) {
			res = min(res, 3);
		}

		if (four) {
			res = min(res, 4);
		}


		if (res == INT_MAX) {
			cout << "MORTAL\n";
		}
		else cout << res << "\n";

	}
}