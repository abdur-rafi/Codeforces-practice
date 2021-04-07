#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> inp;
bool palin(string& s) {
	int i = 0;
	int j = s.size() - 1;
	while (i <= j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else return 0;
	}
	return 1;
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str; cin >> str;
		inp.push_back(str);
	}
	vector<string>res;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			string rev = inp[j];
			reverse(rev.begin(), rev.end());
			if (inp[i] == inp[j] || inp[i] == rev) {
				res.push_back(inp[i]);
			}
		}
	}
	string pal;
	for (int i = 0; i < n; ++i) {
		if (palin(inp[i]) && pal.size() < inp[i].size()) pal = inp[i];
	}
	string r;
	for (auto p : res) r += p;
	string l = r;
	if (pal.size()) r += pal;
	reverse(l.begin(), l.end());
	r += l;
	cout << r.size() << "\n";
	cout << r;
}