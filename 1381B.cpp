#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2001][4001];

bool DP(int i, vector<int> &num, int currSum){
	if(currSum < 0) return false;
	if(currSum == 0) return true;
	if(i < 0) return false;
	if(dp[currSum][i] != -1) return dp[currSum][i];
	dp[currSum][i] = DP(i - 1, num, currSum) || DP(i - 1, num, currSum - num[i]);
	return dp[currSum][i];
} 

int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n;scanf("%d", &n);
		int arr[2 * n];
		for(int i = 0; i < 2 * n; ++i)
			scanf("%d", arr + i);
		vector<int> num;

		int c = 1;
		int b = arr[0];
		int i = 1;
		while(i < 2 * n){
			if(arr[i] > b){
				num.push_back(c);
				c = 1;
				b = arr[i];
			}
			else{
				++c;
			}
			++i;
		}
		num.push_back(c);
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= num.size(); ++j){
				dp[i][j] = -1;
			}
		}
		bool res = DP(num.size() - 1, num, n);

		if(res) printf("YES\n");
		else printf("NO\n");
	}

}