#include <cstdio>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const int MAX = 2000+10;
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		int n,k; scanf("%d %d", &n,&k);
		char str[MAX];
		scanf("%s", str);
		vector<pair<int, int>> res;
		for (int i = 0; i < k-1; ++i) {
			if (str[2 * i] == ')') {
				for (int j = 2 * i + 1; j < n; ++j) {
					if (str[j] == '(') {
						int i1 = i * 2;
						int i2 = j;
						while (i1 <= i2) {
							char c = str[i1];
							str[i1] = str[i2];
							str[i2] = c;
							i1++;
							i2--;
						}
						res.push_back({ 2*i,j });
						break;
					}
				}
			}
			else if (str[2 * i + 1] == '(') {
				for (int j = 2 * i + 2; j < n; ++j) {
					if (str[j] == ')') {
						int i1 = i * 2 + 1;
						int i2 = j;
						while (i1 <= i2) {
							char c = str[i1];
							str[i1] = str[i2];
							str[i2] = c;
							i1++;
							i2--;
						}
						res.push_back({ 2*i+1,j });
						break;
					}
				}
			}
		}

		int b = (k - 1) * 2;
		int rem = (n - 1) - b + 1;
		for (int i = b; i < b + (rem / 2); i++) {
			if (str[i] == ')') {
				for (int j = i + 1; j < n; ++j) {
					if (str[j] == '(') {
						int i1 = i;
						int i2 = j;
						while (i1 <= i2) {
							char c = str[i1];
							str[i1] = str[i2];
							str[i2] = c;
							i1++;
							i2--;
						}
						res.push_back({ i,j });
						break;
					}
				}
			}
		}
		for (int i = b + (rem / 2); i < n; ++i) {
			if (str[i] == '(') {
				for (int j = i + 1; j < n; ++j) {
					if (str[j] == ')') {
						int i1 = i;
						int i2 = j;
						while (i1 <= i2) {
							char c = str[i1];
							str[i1] = str[i2];
							str[i2] = c;
							i1++;
							i2--;
						}
						res.push_back({ i,j });
						break;
					}
				}
			}
		}
		printf("%d\n", res.size());
		for (auto p : res) {
			printf("%d %d\n", p.first+1, p.second+1);
		}

	}

}