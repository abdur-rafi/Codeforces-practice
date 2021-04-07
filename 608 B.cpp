#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200 + 10;
char str[MAX];
int frew, freb;


int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	vector <int> res;
	queue<int> w, b;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'W') {
			w.push(i);
		}
		else b.push(i);
	}
	if (w.size() % 2 == 1 && b.size() % 2 == 1) {
		printf("-1\n");
		return 0;
	}
	queue<int> even;
	if (w.size() % 2 == 0) even = w;
	else even = b;
	if (even.size() % 2 == 0) {
		while (!even.empty()) {
			int a = even.front();
			even.pop();
			int b = even.front();
			even.pop();
			for (int j = a; j < b; ++j) {
				res.push_back(j);
			}
		}
	}
	cout << res.size() << "\n";
	for (auto p : res) {
		cout << p+1 << ' ';
	}
	return 0;
}