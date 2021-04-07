#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 200000 + 10;

int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n; cin >> n;
		set<string> s[4];
		map<string, int> m;
		vector<string> inp;
		m["00"] = 3;
		m["01"] = 0;
		m["10"] = 1;
		m["11"] = 2;
		vector<int> adj[4];
		for (int i = 0; i < n; ++i) {
			string s1; cin >> s1;
			if (s1.size() < 2) s1 += s1;
			string s2;
			s2 += s1[0];
			s2 += s1[s1.size() - 1];
			adj[m[s2]].push_back(i);
			s[m[s2]].insert(s1);
			inp.push_back(s1);
		}
		if (adj[1].size() + adj[0].size() == 0) {
			if (adj[2].size() != 0 && adj[3].size() != 0) {
				cout << "-1\n";
			}
			else cout << "0\n";
			continue;
		}
		if (abs((int)adj[0].size() -(int) adj[1].size()) <= 1) {
			cout << "0\n";
			continue;
		}
		int mn, id,mx;
		if (adj[0].size() > adj[1].size()) {
			mn = adj[1].size();
			id = 0;
			mx = adj[0].size();
		}
		else {
			mn = adj[0].size();
			id = 1;
			mx = adj[1].size();
		}
		int fr = 0;
		while (mx - mn > 1) {
			mn++;
			mx--;
			fr++;
		}
		vector<int>res;
		
		for (auto p : adj[id]) {
			reverse(inp[p].begin(), inp[p].end());
			//	cout << inp[p] << "\n";
			if (fr == 0) break;
			if (s[(id + 1) % 2].find(inp[p]) == s[(id + 1) % 2].end()) {
				res.push_back(p);
				--fr;
			}
		}
			
		
		if (fr != 0) cout << "-1\n";
		else {
			cout << res.size() << "\n";
			for (auto p : res) {
				cout << p + 1 << ' ';
			}
			cout << "\n";
		}

	}
}