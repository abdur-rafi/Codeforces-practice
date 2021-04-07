#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll; 
ll const MAX = 200000 + 10;
char str[MAX];
ll zero_count[MAX];
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		scanf("%s", str);
		ll res = 0;
		ll n = strlen(str);
		for (int i = 0; i < MAX; ++i) zero_count[i] = 0;
		for (int i = 1; i <= n; ++i) {
			if (str[i - 1] == '0') zero_count[i] = zero_count[i - 1] + 1;
			else zero_count[i] = 0;
		}
	//	for (int i = 0; i < n; ++i) printf("%lld ", zero_count[i + 1]);
		for (int i = 0; i < n; ++i) {
			if (str[i] == '1') {
			//	printf("z:%lld\n", zero_count[i]);
				ll fr = 0;
				for (int j = i; j < n && fr <= MAX; ++j) {
					fr = fr << 1;
					if (str[j] == '1') fr++;
					if (fr == (j - i + 1)) ++res;
					else if ((j - i + 1) + zero_count[i] >= fr) ++res;
					
				}
			}
		}
		printf("%lld\n", res);
	}
}
