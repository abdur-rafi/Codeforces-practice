#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int const MAX = 200000 + 10;
vector<int> id[MAX];
vector<int> a[26];
string inp[MAX];
int parent[26];
int Rank[26];
int findset(int u) {
	if(parent[u] != u) {
		parent[u] = findset(parent[u]);
	}
	return parent[u];
}
void mergeset(int u,int v) {
	int a = findset(u);
	int b = findset(v);
	if (Rank[a] > Rank[b]) {
		parent[b] = a;
	}
	else
		parent[a] = b;
	if (Rank[a] == Rank[b]) Rank[b]++;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		inp[i] = s;
		int fre[26];
		for (int i = 0; i < 26; ++i) fre[i] = 0;
		for (auto p : s) {
			fre[p - 'a']++;
		}
		for (int j = 0; j < 26; ++j) {
			if (fre[j]) {
				a[j].push_back(i);
				id[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < 26; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < id[i].size(); ++j) {
			mergeset(id[i][j], id[i][j - 1]);
		}
	}
	set<int> s;
	for (int i = 0; i < 26; ++i) {
		if (a[i].size() == 0) continue;
		s.insert(findset(i));
	}
	printf("%d", s.size());

}