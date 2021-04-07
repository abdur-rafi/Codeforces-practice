#include <string>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
char str[2000000 + 100];
int n;
void cost(int begin, int x, int y, int a[]) {
	queue<int> q;
	q.push((begin + x) % 10);
	q.push((begin + y) % 10);
	q.push(-1);
	int l = 0;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		if (f == -1) {
			l++;
			if (q.size()) q.push(-1);
		}
		else if (a[f] == -1) {
			a[f] = l;
			q.push((f + x) % 10);
			q.push((f + y) % 10);
		}
	}

}
int cost2(int x, int y) {
	int path[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) path[i][j] = -1;
	}
	for (int i = 0; i < 10; ++i) cost(i, x, y, path[i]);

	int res = 0;
	int i = 0;
	while (str[i]) {
		if (str[i + 1]) {
			if (path[str[i] - '0'][str[i + 1] - '0'] != -1) {
				res += path[str[i] - '0'][str[i + 1] - '0'];
			}
			else {
				res = -1;
				break;
			}
		}
		++i;
	}
	return res;
}
int main() {
	scanf("%s", str);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("%d ", cost2(i, j));
		}
		printf("\n");
	}
}