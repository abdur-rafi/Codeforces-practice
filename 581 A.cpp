#include <cstdio>
#include <iostream>
#include <cstring>	
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 2000 + 10;
char str[MAX];
int main() {
	scanf("%s", str);
	int n = strlen(str);
	int c = n / 2;
	if (n % 2) ++c;
	--c;
	bool one = 0;
	for (int i = 1; i < n; ++i) {
		if (str[i] == '1') {
			one = 1;
			break;
		}
	}
	if (one || n % 2 == 0) c++;
	printf("%d", c);
}