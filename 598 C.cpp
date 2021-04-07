#include <iostream>
#include <string>
using namespace std;
const int MAX = 1010;
int main() {
	int n, m, d; cin >> n >> m >> d;
	int platform[MAX];
	int sum[MAX];
	for (int i = 0; i < m; ++i) cin >> platform[i];
	for (int i = 0; i < MAX; ++i) sum[i] = 0;
	for (int i = 0; i < m; ++i) {
		sum[i + 1] = sum[i] + platform[i];
	}
//	for (int i = 0;i < m; ++i) cout << sum[i+1] << ' ';
	int res[MAX];
	for (int i = 0; i < MAX; ++i) res[i] = 0;
	int curr = 0;
	bool p = 1;
	for (int i = 0; i < m && curr <= n; ++i) {
		if (n - curr - platform[i] <= (d - 1) * (m - i) + sum[m] - sum[i + 1]) {
			for (int j = curr + 1; j <= curr + platform[i]; ++j) {
				res[j] = i+1;
			}
			curr += platform[i];
		}
		else {
			++curr;
			--i;
		}
	}
	int fr = 0;
	for (int i = 1; i <= n; ++i) {
		if (!res[i]) {
			++fr;
			if (fr > d - 1) p = 0;
		}
		else fr = 0;
	}
	if (p) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			cout << res[i] << ' ';
		}
	}
	else cout << "NO\n";
	return 0;
}