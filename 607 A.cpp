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
	int t; cin >> t;
	while (--t >= 0) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 < s2) {
			cout << s1<<"\n"; 
			continue;
		}
		else {
			int c = 0;
			for (int i = 0; i < s2.size(); ++i) {
				bool f = false;
				int fc;
				for (int j = i; j < s1.size(); ++j) {
					if (s1[j] < s2[i]) {
						f = true;
						fc = j;
						++c;
						break;
					}
				}
				if (f) {
					char t = s1[i];
					s1[i] = s1[fc];
					s1[fc] = t;
					break;
				}
				if (i >= s1.size()) break;
				else if (s1[i] == s2[i]) continue;
				f = false;
				for (int j = i; j < s1.size(); ++j) {
					if (s1[j] == s2[i]) {
						f = true;
						fc = j;
						++c;
					}
				} 
				if (f) {
					char t = s1[i];
					s1[i] = s1[fc];
					s1[fc] = t;
				}
				break;
					 

			}
		}
		if (s1 < s2) {
			cout << s1 <<"\n";
		}
		else cout << "---\n";
	}
}