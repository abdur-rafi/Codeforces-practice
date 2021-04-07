#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 200000 + 10;
int Search(string &s, char c,int i) {
	int n = s.size();
	for (; i < n; ++i) {
		if (s[i] == c) return i;
	}
	return -1;
}
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n; scanf("%d", &n);
		string s, t;
		vector<pair<int, int>> res;
		cin >> s >> t;
		bool p = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				int j = Search(s, s[i], i + 1);
				if (j != -1) {
					char d = t[i];
					t[i] = s[j];
					s[j] = d;
					res.push_back({ j,i });
				}
				else {
					j = Search(t, t[i], i + 1);
					if (j != -1) {
						char d = s[i];
						s[i] = t[j];
						t[j] = d;
						res.push_back({ i,j });
					}
					else {
						j = Search(t, s[i], i + 1);
						if (j != -1) {
							char d = s[n - 1];
							s[n - 1] = t[i];
							t[j] = d;
							t[i] = s[i];
							res.push_back({ n - 1,j });
							res.push_back({ n - 1,i });
						}
						else {
							j = Search(s, t[i], i + 1);
							if (j != -1) {
								char d = t[n - 1];
								t[n - 1] = s[i];
								s[j] = d;
								s[i] = t[i];
								res.push_back({ j,n - 1 });
								res.push_back({ i,n - 1 });
								
							}
							else {
								p = false;
								break;
							}
						}
					}
				}
			}
		}
		if (p) {
			printf("Yes\n");
			printf("%d\n", res.size());
			for (auto d : res) {
				printf("%d %d\n", d.first+1, d.second+1);
			}
		}
		else {
			printf("No\n");
		}
	}
}