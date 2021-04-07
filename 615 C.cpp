#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 10;
bool prime[MAX+100];
void SieveOfEratosthenes()
{
	for (int i = 0; i <= MAX; ++i) prime[i] = 1;
	for (int p = 2; p * p <= MAX ; p++)
	{
		if (prime[p] == 1)
		{
			for (int i = p * p; i <= MAX ; i += p)
				prime[i] = 0;
		}
	}
}
int main() {
	int t; scanf("%d", &t);
	SieveOfEratosthenes();
	vector<int> pr;
	for (int i = 2; i <= MAX; ++i) {
		if (prime[i]) pr.push_back(i);
	}
	//	printf("%d \n", pr[pr.size() - 1]);
	while (--t >= 0) {
		int n; scanf("%d", &n);
		map<int, int> mp;
		for (auto p : pr) {
			int c = 0;
			while (n % p == 0) {
				n /= p;
				++c;
			}
			if (c) mp[p] += c;
		}
		if (n > 1) {
			mp[n] += 1;
		}
		int tot = 0;
		for (auto p : mp) {
			tot += p.second;
		}
		vector<int> v;
		for (auto p : mp) {
			for (int i = 0; i < p.second; ++i) v.push_back(p.first);
		}
		if (mp.size() == 1) {
			if (tot < 6) {
				printf("NO\n");
				continue;
			}
		}
		else if (mp.size() == 2) {
			if (tot < 4) {
				printf("NO\n");
				continue;
			}
			if (tot == 5) {
				if (mp[v[4]] == 4) {
					printf("YES\n%d %d %d\n", v[3], v[3] * v[3] * v[3], v[0]);
					continue;
				}
			}
		}
		printf("YES\n");
		if (tot < 4) {

			for (auto p : mp) {
				printf("%d ", p.first);
			}
			printf("\n");
			continue;
		}
		int f = 1;
		for (int i = 0; i < tot; ++i) {
			f *= v[i];
			if (i == 0) { printf("%d ", f); f = 1; }
			else if (i == 2) { printf("%d ", f); f = 1; }
		}
		printf("%d\n", f);

	}
}