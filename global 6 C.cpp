#include <cstdio>
int a[510][510];
int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	if (r == 1 && c == 1) {
		printf("0");
		return 0;
	}
	else if (r == 1) {
		for (int i = 0; i < c; ++i) a[0][i] = i + 2;
	}
	else if (c == 1) {
		for (int i = 0; i < r; ++i) a[i][0] = i + 2;
	}
	else {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				a[i][j] = (r + j + 1) * (i + 1);
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) printf("%d ", a[i][j]);
		printf("\n");
	}
}