#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double l, h; cin >> h >> l;
	cout << std::fixed << setprecision(9) << ((l * l) - (h * h)) / (2*h);
}