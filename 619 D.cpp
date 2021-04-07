#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, string>> res;
int main() {
	ll n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	ll tot = 4 * n * m - 2 * n - 2 * m;
	if (k > tot) {
		printf("NO");
		return 0;
	}
	if (n == 1) {
		ll fr = min(m - 1, k);
		k -= fr;
		res.push_back({ fr,"R" });
		if (k > 0) res.push_back({ k,"L" });
	}
	else if (m == 1) {
		ll fr = min(n - 1, k);
		k -= fr;
		res.push_back({ fr,"D" });
		if (k > 0) res.push_back({ k,"U" });
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (!k) break;
			if (i != n - 1) {
				if ((m - 1) * 3 <= k) {
					k -= (m - 1) * 3;
					res.push_back({ m - 1,"RDU" });
				}
				else {
					ll fr = k / 3;
					ll ext = k % 3;
					k = 0;
					if (fr) res.push_back({ fr,"RDU" });
					if (ext == 1) res.push_back({ 1,"R" });
					else if (ext == 2) res.push_back({ 1,"RD" });
				}
				ll fr = min(k, m - 1);
				k -= fr;
				if (fr) res.push_back({ fr,"L" });
				if (k) {
					res.push_back({ 1,"D" });
					--k;
				}
			}
			else {
				ll fr = min(m - 1, k);
				k -= fr;
				if (fr) res.push_back({ fr,"R" });
				fr = min(m - 1, k);
				k -= fr;
				if (fr) res.push_back({ fr,"L" });
			}
		}
		if (k) res.push_back({ k,"U" });
	}
	printf("YES\n");
	printf("%d\n", res.size());
	for (auto p : res) {
		printf("%lld %s\n", p.first, p.second.c_str());
	}
}