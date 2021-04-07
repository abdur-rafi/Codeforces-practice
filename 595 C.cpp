#include <cstdio>
using namespace std;
typedef long long ll;
void strrev(char a[]) {
	int i = 0;
	for (int i = 0; a[i] != '\0'; ++i) {
		;
	}
	--i;
	int j = 0;
	while (j < i) {
		char b = a[j];
		a[j] = a[i];
		a[i] = b;
		i--;
		j++;
	}
}
int main() {
	int q; scanf("%d", &q);
	while (--q >= 0) {
		ll n; scanf("%lld", &n);
		char trits[1000];
		int i = 0;
		while (n) {
			trits[i++] = (n % 3) + '0';
			n /= 3;
		}
		trits[i] = '\0';
		int ln = i;
		trits[ln + 1] = '\0';
		int b2 = ln;
		for (int j = ln-1; j >= 0; --j) {
			if (trits[j] == '0') b2 = j;
			else if (trits[j] == '2') {
				trits[b2] = '1';
				for (int k = 0; k < b2; ++k) trits[k] = '0';
			}
		}
		ll res = 0;
		ll c = 1;
		for (int j = 0; trits[j]; ++j) {
			res += (trits[j] - '0') * c;
			c *= 3;
		}
		printf("%lld\n", res);

	}
}