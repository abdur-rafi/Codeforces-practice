#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 200000 + 100;
pair<int, int> input[MAX];
int dp[MAX];
int dpp[MAX];
int res[MAX];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input[i].first;
		input[i].second = i;
	}
	sort(input, input + n);
	if (n < 6) {
		cout << input[n - 1].first - input[0].first << " 1\n";
		for (int i = 0; i < n; ++i) cout << "1 ";
		return 0;
	}
	for (int i = 5; i < n; ++i) {
		dp[i] = input[i - 2].first - input[i - 3].first + dp[i - 3];
		if (dp[i - 1] >= dp[i]) {
			dpp[i] = dpp[i - 1];
			dp[i] = dp[i - 1];
		}
		else {
			dpp[i] = i - 2;
		}
	}
	int curr = 1;
	int k = n - 1;
	int t = n ;
	cout << input[n - 1].first - input[0].first - dp[n - 1] << ' ';
	while(k > 0){
		for (int i = dpp[k]; i < t; ++i) {
			res[input[i].second] = curr;
		}
		t = dpp[k];
		k = dpp[k]-1;
		++curr;

	}
	cout << curr-1 << "\n";
/*	for (int i = 0; i < k; ++i) {
		res[input[i].second] = curr;
	}*/
	//for (int i = 0; i < n; ++i) cout << dpp[i] << ' ';

	for (int i = 0; i < n; ++i) cout << res[i] << ' ';
}
