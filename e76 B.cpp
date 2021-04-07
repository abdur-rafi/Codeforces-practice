#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int x, y; cin >> x >> y;
		if (y <= x || x > 3) cout << "YES\n";
		else if (x == 1 && y > 1) cout << "NO\n";
		else if (y <= 3) cout << "YES\n";
		else cout << "NO\n";
	}
}