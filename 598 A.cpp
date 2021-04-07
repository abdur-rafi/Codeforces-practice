#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b, n, s;
		cin >> a >> b >> n >> s;
		int acta = min(s / n, a);
		int actb = min(s - acta * n, b);
		if (acta * n + actb == s) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
