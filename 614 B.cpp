#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	double res = 0;
	for (int i = 1; i <= n; ++i) {
		double k = i;
		res += (1.0 / k);
	}
	cout << res;
}