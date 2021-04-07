#include <iostream>
#include <utility>
#include<algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if (a > b) swap(a,b);
		int diff = b - a;
		diff += min(x, a - 1);
		x -= min(x, a - 1);
		diff += min(n - b, x);
		cout << diff << "\n";

	}
}