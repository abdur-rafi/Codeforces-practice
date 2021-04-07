#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
	ll t; scanf("%lld", &t);
	while (--t >=0) {
		ll s; scanf("%lld", &s);
		ll res = 0;
		ll curr = s;
		while (curr) {
			if (curr < 10) {
				res += curr;
				break;
			}
			else {
				res += (curr / 10) * 10;
				curr = (curr / 10) + curr % 10;
			}
		}
		printf("%lld\n", res);
		
	}
}