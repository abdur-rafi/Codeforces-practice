#include <cstdio>
#include <vector>
using namespace std;
char a[200];
int main() {
	int t; scanf("%d", &t);
	while (--t >= 0) {
		scanf("%s", a);
		int i = 0;
		vector<int> adj;
		while (a[i]) {
			if (a[i] == '1') adj.push_back(i);
			i++;
		}
		int res = 0;
		for (int i = 1; i < adj.size(); ++i) {
			res += adj[i] - adj[i - 1]-1;
		}
		printf("%d\n", res);
	}
}