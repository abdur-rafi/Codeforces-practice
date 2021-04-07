#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 101;
int main() {
	int t; cin >> t;
	while (--t >= 0) {
		int n; cin >> n;
		int a[MAX];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int mark = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[j] == i ) {
					if (j == mark) ++mark;
					else if (j > mark) {
						for (int k = j; k > mark; --k) {
							a[k] = a[k - 1];
						}
						a[mark] = i;
						mark = j ;

					}

				}
			}
		}
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << "\n";
	}
}
