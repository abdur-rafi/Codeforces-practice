#include <cstdio>
#include <cstring>
char str[200];
int main() {
	int n; scanf("%d", &n);
	while (--n >= 0) {
		scanf("%s", str);
		int N = strlen(str);
		int sum = 0;
		int i = 0;
		while (str[i]) sum += str[i++] - '0';
		if (sum % 3 != 0) {
			printf("cyan\n");
			continue;
		}
		int p = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				int s = (str[i] - '0') * 10 + str[j] - '0';
				if (s % 4 == 0 && s % 5 == 0) {
					p = 1;
					break;
				}
			}
			if (p) break;
		}
		if (p) printf("red\n");
		else printf("cyan\n");
	}
}