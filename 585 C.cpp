#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
char s[MAX], t[MAX];
int main() {
	int n; scanf("%d", &n);
	scanf("%s %s", s, t);
	vector<int> abi, bai;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a' && t[i] == 'b') abi.push_back(i);
		else if (s[i] != t[i]) bai.push_back(i);
	}
	int b = 0;
	if (abi.size() % 2) b = 1;
	vector<pair<int, int>> res;
	for (int i = b; i < abi.size(); i += 2) {
		res.push_back({ abi[i],abi[i + 1] });
	}
	int p = 1;
	b = 0;
	if (bai.size() % 2) b = 1;
	for (int i = b; i < bai.size(); i += 2) {
		res.push_back({ bai[i],bai[i + 1] });
	}
	if (abi.size() % 2 == 1 && bai.size() % 2 == 1) {
		res.push_back({ bai[0],bai[0] });
		res.push_back({ abi[0],bai[0] });
	}
	else if (abi.size() % 2 == 1 || bai.size() % 2 == 1) p = 0;
	if (p) {
		printf("%d\n", res.size());
		for (auto m : res) printf("%d %d\n", m.first + 1, m.second + 1);
	}
	else printf("-1");
}