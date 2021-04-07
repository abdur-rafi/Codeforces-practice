#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
const int MAX = 200000 + 10;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int a[10];
		string inp[10];
		for (int i = 0; i < 10; ++i) a[i] = 0;
		int n; cin >> n;
		map<string, int> mp;
		map<string, vector<int>> mpi;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			inp[i] = s;
			mp[s]++;
			mpi[s].push_back(i);
		}
		string res[10];
		if (mp.size() == n) {
			cout << "0\n";
			for (int i = 0; i < n; ++i) cout << inp[i] << '\n';
		}
		else {
			string un[10];
			int k = 0;
			int i1 = 0;
			for (auto p : mp) {
				un[i1++] = p.first;
			}
			for (int i = 0; i < i1; ++i) {
				a[un[i][3] - '0'] = 1;
			}
			for (int i = 0; i < i1; ++i) {
				for (int j = 1; j < mp[un[i]]; ++j) {
					string str = un[i];
					for (int i2 = 0; i2 < 10; ++i2) {
						if (a[i2] == 0) {
							a[i2] = 1;
							str[3] = i2 + '0';
							++k;
							res[mpi[un[i]].back()] = str;
							mpi[un[i]].pop_back();
							break;
						}
					}
				}
				res[mpi[un[i]].back()] = un[i];
			}
			cout << k << '\n';
			for (int i = 0; i < n; ++i) cout << res[i] << '\n';
			
		}
	}
}