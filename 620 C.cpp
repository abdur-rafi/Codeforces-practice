#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
struct cust {
	ll ti, li, hi;
};
vector<cust> inp;
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		inp.clear();
		ll n, m; scanf("%lld %lld", &n, &m);
		bool pos = 1;
		for (int i = 0; i < n; ++i) {
			ll ti, li, hi;
			scanf("%lld %lld %lld", &ti, &li, &hi);
			if (inp.size() == 0 || inp[inp.size() - 1].ti != ti) inp.push_back({ ti,li,hi });
			else {
				pair<ll, ll> curr = { inp[inp.size() - 1].li,inp[inp.size() - 1].hi };
				if (curr.first <= li && curr.second >= hi) {
					curr.first = li;
					curr.second = hi;
				}
				else if (li <= curr.first && hi >= curr.second) {
					;
				}
				else if (li <= curr.first && hi >= curr.first) {
					curr.second = hi;
				}
				else if (li <= curr.second && hi >= curr.second) {
					curr.first = li;
				}
				else {
					pos = 0;
				}
				inp[inp.size() - 1].li = curr.first;
				inp[inp.size() - 1].hi = curr.second;

			}
		}
		if (!pos) {
			printf("NO\n");
			continue;
		}
		pair<ll, ll> curr;
		curr = { m,m };
		ll pr = 0;
		for (int i = 0; i < inp.size(); ++i) {
			ll ti, li, hi;
			ti = inp[i].ti;
			hi = inp[i].hi;
			li = inp[i].li;
			curr.first -= ti - pr;
			curr.second += ti - pr;
			pr = ti;
			if (curr.first <= li && curr.second >= hi) {
				curr.first = li;
				curr.second = hi;
			}
			else if (li <= curr.first && hi >= curr.second) {
				;
			}
			else if (li <= curr.first && hi >= curr.first) {
				curr.second = hi;
			}
			else if (li <= curr.second && hi >= curr.second) {
				curr.first = li;
			}
			else {
				pos = 0;
			}
		}
		if (pos) printf("YES\n");
		else printf("NO\n");
	}
}