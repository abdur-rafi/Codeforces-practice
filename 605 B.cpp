#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int const MAX = 100000 + 100;
char str[MAX];
int fre[100];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		for (int i = 0; i < 26; ++i) fre[i] = 0;
		scanf("%s", str);
		int i = 0;
		while (str[i]) {
			fre[str[i] - 'A']++;
			i++;
		}
		int r = 0;
		int diff = min(fre['D' - 'A'], fre['U' - 'A']);
		fre['D' - 'A'] = diff;
		fre['U' - 'A'] = diff;
		diff = min(fre['R' - 'A'], fre['L' - 'A']);
		fre['R' - 'A'] = diff;
		fre['L' - 'A'] = diff;
		if (fre['R' - 'A'] == 0 && fre['D' - 'A'] == 0) {
			printf("0\n");
		}
		else if (fre['R' - 'A'] == 0) {
			printf("2\nUD\n");
		}
		else if (fre['D' - 'A'] == 0) {
			printf("2\n\RL\n");
		}
		else {
			r = fre['D' - 'A'] + fre['R' - 'A'] + fre['L' - 'A'] + fre['U' - 'A'];
			printf("%d\n", r);
			for (int i = 0; i < fre['D' - 'A']; ++i) printf("D");
			for (int i = 0; i < fre['R' - 'A']; ++i) printf("R");
			for (int i = 0; i < fre['U' - 'A']; ++i) printf("U");
			for (int i = 0; i < fre['L' - 'A']; ++i) printf("L");
			printf("\n");
		}
	}
}