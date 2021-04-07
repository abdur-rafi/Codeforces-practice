#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#define loop(x,n,a) for(int x = a; x < n;++x)
using namespace std;
const int MAX = 200000 + 10;
char str[MAX];
int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);
	int sum_a = 0, sum_b = 0;
	int blank_a = 0, blank_b = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (str[i] == '?') ++blank_a;
		else sum_a += str[i] - '0';
	}
	for (int i = n / 2; i < n; ++i) {
		if (str[i] == '?') ++blank_b;
		else sum_b += str[i] - '0';
	}
	if (blank_a == blank_b) {
		if (sum_a == sum_b) {
			printf("Bicarp");
		}
		else printf("Monocarp");
		return 0;
	}
	int big = 0, small = 0;
	int bs = 0, ss = 0;
	if (blank_a > blank_b) {
		big = blank_a;
		small = blank_b;
		bs = sum_a;
		ss = sum_b;
	}
	else {
		big = blank_b;
		small = blank_a;
		bs = sum_b;
		ss = sum_a; 
	}
	if (bs > ss || bs == ss ) {
		printf("Monocarp");
		return 0;
	}
	if ((big / 2 + big % 2) * 9 + bs == (small / 2 + small % 2) * 9 + ss) {
		printf("Bicarp");
	}
	else {
		printf("Monocarp");
	}

}