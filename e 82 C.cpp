#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
#define loop(x,n,a) for(int x =a; x < n;++x)
using namespace std;
const int MAX = 200000 + 10;
char a[300];
vector<int> adj[26];
string curr;
int vis[26];
int pos = 1;
void make(int c,int pr, char w) {
	if (curr.size() == 1) {
		int l = 0;
		for (auto p : adj[c]) {
			if (vis[p]) {
				pos = 0;
				return;
			}
			vis[p] = 1;
			if (!l) {
				curr.insert(curr.begin(), 1, p + 'a');
				make(p, c, 'L');
				l = 1;
				
			}
			else {
				curr.insert(curr.end(), 1, p + 'a');
				make(p, c, 'R');
			}
		}
		return;
	}
	for (auto p : adj[c]) {
		if (p != pr) {
			if (vis[p]) {
				pos = 0;
				return;
			}
			if (w == 'L') curr.insert(curr.begin(), 1, p + 'a');
			else {
				curr.insert(curr.end(), 1, p + 'a');
			}
			vis[p] = 1;
			make(p, c, w);
		}
	}
}
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		scanf("%s", a);
		int n = strlen(a);
		if (n == 1) {
			printf("YES\nbacdefghijklmnopqrstuvwxyz\n");
		}
		else {
			pos = 1;
			for (int i = 0; i < 26; ++i) {
				adj[i].clear();
				vis[i] = 0;
			}
			curr.clear();
			set<int> st[26];
			for (int i = 1; i < n; ++i) {
				st[a[i] - 'a'].insert(a[i - 1] - 'a');
				st[a[i - 1] - 'a'].insert(a[i] - 'a');
			}
			for (int i = 0; i < 26; ++i) {
				if (st[i].size() > 2) {
					pos = 0;
					break;
				}
				for (auto p : st[i]) {
					adj[i].push_back(p);
				}
			}
			if (!pos) {
				printf("NO\n");
				continue;
			}
			string res;
			for (int i = 0; i < 26; ++i) {
				if (vis[i] == 0 && adj[i].size() != 0) {
					vis[i] = 1;
					curr.clear();
					curr.insert(curr.begin(), 1, i + 'a');
					make(i, -1, 'R');
					res += curr;
				}
			}
			for (int i = 0; i < 26; ++i) {
				if (!vis[i]) {
					res += i + 'a';
				}
			}
			if (!pos) {
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			printf("%s\n", res.c_str());

		}
	}
}