#include <cstdio>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
ll inp[200000 + 100];
int main() {
	ll n, a, b, k; scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
	priority_queue<ll> pq;
	int res = 0;
	for (int i = 0; i < n; ++i) scanf("%lld", inp + i);
	for (int i = 0; i < n; ++i) {
		ll cr = inp[i];
		if (cr <= a + b ) {
			;
		}
		else {
			if (cr % (a + b) == 0) {
				cr = a + b;
			}
			else
				cr = cr % (a + b);
		}
		ll fr = cr / a;
		if (cr % a) ++fr;
		--fr;
		if (!fr) {
			res++;
			continue;
		}
		if (fr <= k) {
			k -= fr;
			pq.push(fr);
		}
		else {
			if (!pq.empty() && pq.top() > fr) {
				k += pq.top();
				k -= fr;
				pq.pop();
				pq.push(fr);
			}
		}
	}
	printf("%d", res + pq.size());
	
}