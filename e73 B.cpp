#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[100][100];
int main() {
	int n; scanf("%d", &n);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) a[i][j] = -1;
	}
	a[0][0] = 1;
	while (!q.empty()) {
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		if (u + 2 < n && v + 1 < n && a[u + 2][v + 1] == -1) {
			a[u + 2][v + 1] = (a[u][v] + 1) % 2;
			q.push({ u + 2,v + 1 });
		}
		if (u + 2 < n && v - 1 >= 0 && a[u + 2][v - 1] == -1) {
			a[u + 2][v - 1] = (a[u][v] + 1) % 2;
			q.push({ u + 2,v - 1 });
		}
		if (u + 1 < n && v + 2 < n && a[u + 1][v + 2] == -1) {
			a[u + 1][v + 2] = (a[u][v] + 1) % 2;
			q.push({ u + 1,v + 2 });
		}
		if (u + 1 < n && v - 2 >= 0 && a[u + 1][v - 2] == -1) {
			a[u + 1][v - 2] = (a[u][v] + 1) % 2;
			q.push({ u + 1,v - 2 });
		}


		if (u - 2 >= 0 && v + 1 < n && a[u - 2][v + 1] == -1) {
			a[u - 2][v + 1] = (a[u][v] + 1) % 2;
			q.push({ u - 2,v + 1 });
		}
		if (u - 2 >= 0 && v - 1 >= 0 && a[u + 2][v - 1] == -1) {
			a[u - 2][v - 1] = (a[u][v] + 1) % 2;
			q.push({ u - 2,v - 1 });
		}
		if (u - 1 >= 0 && v + 2 < n && a[u + 1][v + 2] == -1) {
			a[u - 1][v + 2] = (a[u][v] + 1) % 2;
			q.push({ u - 1,v + 2 });
		}
		if (u - 1 >= 0 && v - 2 >= 0 && a[u + 1][v - 2] == -1) {
			a[u - 1][v - 2] = (a[u][v] + 1) % 2;
			q.push({ u - 1,v - 2 });
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) printf("W");
			else printf("B");
		}
		printf("\n");
	}

}